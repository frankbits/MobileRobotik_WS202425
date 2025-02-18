#include "globals.h"
#include "Robot.h"

Robot robot;

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

  // robot.sensorData.update();
  // float rpmL = robot.sensorData.getRoundsPerMinute_L();
  // float rpmR = robot.sensorData.getRoundsPerMinute_R();
  // if (rpmL > 0 || rpmR > 0) {
  //   Serial.println("Rounds per minute left: " + (String)rpmL);
  //   Serial.println("Rounds per minute right: " + (String)rpmR);
  // }

  //delay(100);
  robot.next();

  // robot.movement.motors.forward();
  // delay(1000);
  // robot.movement.motors.backward();
  // delay(1000);
  // robot.movement.turnLeft(100, 0.0);
  // delay(1000);
  // robot.movement.turnRight(100, 0.0);
  // delay(1000);
}
