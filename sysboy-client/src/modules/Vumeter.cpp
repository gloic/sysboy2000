#include "modules/Vumeter.h"
#include <Arduino.h>

const int DAC_PIN = 25;  // or 26, depends on the bug on the wifi library

void Vumeter::setup() {
    pinMode(DAC_PIN, OUTPUT);
}

void Vumeter::showValue(int value) {
    value = constrain(value, 0, 255);
    dacWrite(DAC_PIN, value);
}