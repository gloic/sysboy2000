#pragma once

#include "Arduino.h"
#include "Data.h"

class ModuleObserver {
public:
    virtual void onDataReceived(const Data& data) = 0;
};
