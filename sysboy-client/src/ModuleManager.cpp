#include "ModulesManager.h"

void ModulesManager::setup() {
    this->vumeter.setup();
}

void ModulesManager::onMessageReceived(const String& message) {
    if (message == "taggle") {
        showVumeterValue(100);
    }
}

void ModulesManager::showVumeterValue(int value) {
    this->vumeter.showValue(value);
}

