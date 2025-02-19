#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include "ArduinoBoard.h"

extern ArduinoBoard arduino;

/**
 * Enum for deciding which debug-messages to print
 */
enum DebugLevel {
    DEBUG_NONE = 0,
    DEBUG_DISTANCE_LR = 1,
    DEBUG_MOVE_STATE = 2,
};

extern const DebugLevel DEBUG_LEVEL;

#endif
