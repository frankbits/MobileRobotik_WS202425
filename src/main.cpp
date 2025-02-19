#include "globals.h"
#include "Robot.h"

Robot robot;

/**
 * Initialisiere den seriellen Port für Debugausgaben auf der Konsole.
 */
void setup() {
  Serial.begin(115200);
}

void loop() {
  robot.next();
}
