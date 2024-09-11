#include "WebServerManager.h"

#include <ArduinoJson.h>
#include "ArduinoLog.h"

WebServerManager* WebServerManager::instance = nullptr;

WebServerManager& WebServerManager::getInstance() {
    if (!instance) {
        instance = new WebServerManager();
    }
    return *instance;
}

void WebServerManager::onMessageCallback(WebsocketsMessage message) {
    Serial.print("Got Message: ");

    // char messageStr[256];
    // deserializeJson(message, messageStr);
    Log.infoln(message.data().c_str());
    
}

void WebServerManager::setup() {
    Log.infoln("Setup web server");

    // client.connect("ws://localhost:1532"); // TOP KEK

    bool connected = client.connect("192.168.0.10", 1532, "/");

    // CPT
    client.onMessage(&WebServerManager::onMessageCallback);

    Log.infoln("");
    this->requestInfos();
    
    Log.infoln("> web server ready");
}

void WebServerManager::addObserver(ModuleObserver* observer) {
    observers.push_back(observer);
}

void WebServerManager::notifyObservers(const Data& data) {
    for (ModuleObserver* observer : observers) {
        observer->onDataReceived(data);
    }
}

void WebServerManager::requestInfos() {
  Log.infoln("Requesting infos");
  JsonDocument request;
  request["command"] = "infos";
  char json_string[256];
  serializeJson(request, json_string);
  client.send(json_string);
}
