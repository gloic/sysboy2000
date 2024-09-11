#pragma once

#include <ESPAsyncWebServer.h>
#include "ModuleObserver.h"
#include <vector>

class WebServerManager {
    public: 
        static WebServerManager &getInstance();
        void setup();
        void addObserver(ModuleObserver* observer);

    private:
        static WebServerManager *instance;
        std::vector<ModuleObserver*> observers;

        WebServerManager(): server(80), ws("/ws") {}
        
        AsyncWebServer server;
        AsyncWebSocket ws;

        void notifyObservers(const String& message);
        void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
        static void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
};