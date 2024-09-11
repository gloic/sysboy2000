#pragma once

#include "ModuleObserver.h"
#include "modules/Vumeter.h"

class ModulesManager : public ModuleObserver {
    public:
        ModulesManager() : vumeter()  {}
        void setup();
        void onMessageReceived(const String& message) override;

        void showVumeterValue(int value);
    private:
        Vumeter vumeter;
};