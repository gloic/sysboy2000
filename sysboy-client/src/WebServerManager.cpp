#include "WebServerManager.h"

#include <ArduinoJson.h>

WebServerManager* WebServerManager::instance = nullptr;

WebServerManager& WebServerManager::getInstance() {
    if (!instance) {
        instance = new WebServerManager();
    }
    return *instance;
}

void WebServerManager::handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    String message = String((char*)data);

    // StaticJsonDocument<200> doc;  // Taille du document à ajuster selon tes besoins

    // DeserializationError error = deserializeJson(doc, message);
    // if (error) {
    // Serial.println("Erreur de parsing JSON");
    // return;
    // }

    // // Extraire les valeurs depuis le JSON
    // int vramUsage = doc["vram_usage"];  // Récupère la valeur associée à "vram_usage"
    // int cpuTemp = doc["cpu_temp"];      // Récupère la valeur associée à "cpu_temp"


    notifyObservers(message);

    // if (strcmp((char*)data, "taggle") == 0) {
    //   ledState = !ledState;
    //   notifyClients();
    // }
  }
}

void WebServerManager::onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      instance->handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void WebServerManager::setup() {
    ws.onEvent(onEvent);
    server.addHandler(&ws);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", "ok");
        // request->send_P(200, "text/html", index_html, processor);
    });

    server.begin();
}


void WebServerManager::addObserver(ModuleObserver* observer) {
    observers.push_back(observer);
}

void WebServerManager::notifyObservers(const String& message) {
    for (ModuleObserver* observer : observers) {
        observer->onMessageReceived(message);
    }
}
