#include "WifiManager.h"

#include <ArduinoLog.h>
#include <WiFi.h>

void WifiManager::setup(String ssid, String password) {
    this->connect(ssid, password);
}

void WifiManager::connect(String ssid, String password) {
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Log.infoln("Wifi connected");
    Log.infoln("IP= %s", WiFi.localIP().toString());
    Log.infoln("Gateway=%s", WiFi.gatewayIP().toString());
}