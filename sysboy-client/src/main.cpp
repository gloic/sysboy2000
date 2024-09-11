#include <Arduino.h>

#include "WifiManager.h"
#include "WebServerManager.h"
#include "ModulesManager.h"

#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>

WifiManager wifiManager = WifiManager();
WebServerManager webserverManager = WebServerManager::getInstance();
ModulesManager modulesManager = ModulesManager();

void setup() {
    wifiManager.setup("ssid", "password");
    webserverManager.setup();
    modulesManager.setup();

    webserverManager.addObserver(&modulesManager);
}

void loop() {}

