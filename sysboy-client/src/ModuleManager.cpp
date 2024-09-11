#include "ModulesManager.h"
#include "ArduinoLog.h"


void ModulesManager::setup() {
    Log.infoln("Setup modules");

    this->vumeter.setup();

    Log.infoln("> modules ready");
}

void ModulesManager::onDataReceived(const Data& data) {
    Log.infoln("Data received");
    Log.info("- vram: %p", data.vram);

    showVumeterValue(data.vram);
}

void ModulesManager::showVumeterValue(int value) {
    this->vumeter.showValue(value);
}