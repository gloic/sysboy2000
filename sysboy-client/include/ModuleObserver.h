#pragma once

#include "Arduino.h"

class ModuleObserver {
public:
    virtual void onMessageReceived(const String& message) = 0;
};
