#pragma once

#include "ModuleObserver.h"
#include "modules/Vumeter.h"
#include "Data.h"

class ModulesManager : public ModuleObserver {
    public:
        ModulesManager() : vumeter()  {}
        void setup();
        void onDataReceived(const Data& data) override;

        void showVumeterValue(int value);
    private:
        Vumeter vumeter;
};