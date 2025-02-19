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
  // 1. RoboterController fragt die Daten von SensorData ab z.B.: getCurrentSensorData()
  //    1.1. SensorData holt sich den aktuellen Zustand des Arduinos über das Pininterface
  //    1.2. SensorData muss die Daten verarbeiten (Umrechnungen der Drehzahl, ...)
  // 2. RoboterController entscheidet, welches Movement nötig ist und errechnet das Korrekturdelta
  // 3. RoboterController übergibt das Korrketurdelta an die Movement und führt die entsprechende bewegung aus
  // 4. Movement steuert über das Pininteface die Motoren an

  robot.next();

}
