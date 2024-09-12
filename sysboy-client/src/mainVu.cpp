#include "modules/Vumeter.h"
#include "Arduino.h"

Vumeter vumeter;

void petup() {
    Serial.begin(115200);
    vumeter.setup();
}

#define MIN 0
#define MAX 50

void bloop() {
    
    for (int i = MIN; i <= MAX; i++) {
        vumeter.showMapValue(MIN, MAX, i);
        delay(200);
    }

    for (int i = MAX; i >= MIN; i--) {
        vumeter.showMapValue(MIN, MAX, i);
        delay(200);
    }

    delay(1000);
    vumeter.showValue(0);
    delay(1000);
    vumeter.showValue(128);
    delay(1000);
    vumeter.showValue(256);
    delay(1000);
}
