
#include "Arduino.h"

#define LED_BUILTIN 2

void passetup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void shaloop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
