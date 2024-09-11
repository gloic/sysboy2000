#include <Arduino.h>

#include "WifiManager.h"
#include "WebServerManager.h"
#include "ModulesManager.h"
#include "ArduinoLog.h"

#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>

WifiManager wifiManager = WifiManager();
WebServerManager webserverManager = WebServerManager::getInstance();
ModulesManager modulesManager = ModulesManager();

void setup() {
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    Log.infoln("Setup");

    wifiManager.setup("wifiduvoisin", "passdemerde");
    webserverManager.setup();
    modulesManager.setup();

    webserverManager.addObserver(&modulesManager);

    Log.infoln("Device ready");
}

void loop() {
    delay(5000);
    webserverManager.requestInfos();
}
