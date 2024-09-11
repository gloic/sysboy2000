#pragma once

#include "Arduino.h"

class WifiManager {
    public:
        WifiManager() {}
        void setup(String ssid, String password);
    private:
        void connect(String ssid, String password);
};