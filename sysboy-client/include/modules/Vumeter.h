#pragma once
#include "Module.h"

class Vumeter : public Module {
    public:
        Vumeter() {}
        void setup() override;
        void showValue(int value);
        void showMapValue(int min, int max, int value);
};