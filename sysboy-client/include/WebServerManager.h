#pragma once

#include <ESPAsyncWebServer.h>
#include "ModuleObserver.h"
#include <vector>
#include "Data.h"

#include <ArduinoWebsockets.h>
using namespace websockets;


class WebServerManager {
    public: 
        static WebServerManager &getInstance();
        void setup();
        void addObserver(ModuleObserver* observer);
        void requestInfos();
        
    private:
        static WebServerManager *instance;
        std::vector<ModuleObserver*> observers;

        WebServerManager(): server(1532), ws("/") {}
        
        AsyncWebServer server;
        AsyncWebSocket ws;
        WebsocketsClient client;
        
        void notifyObservers(const Data& data);

        static void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
        static void WebServerManager::handleMessageCallback(WebsocketsMessage message);
};