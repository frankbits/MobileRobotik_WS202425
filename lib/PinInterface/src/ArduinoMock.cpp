#include "ArduinoMock.h"
#include <stdio.h>

void ArduinoMock::setDigitalPin(int pin, bool value) {
    printf("set pin: %d set value: %d\n", pin, value);
}

bool ArduinoMock::getDigitalPin(int pin) {
    printf("get pin: %d\n", pin);
    return true;
}

void ArduinoMock::setAnalogPin(int pin, int value) {
    printf("set pin: %d set value: %d\n", pin, value);
}

int ArduinoMock::getAnalogPin(int pin) {
    printf("get pin: %d\n", pin);
    return 1;
}
