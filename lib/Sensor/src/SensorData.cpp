#include "SensorData.h"
#include <util/atomic.h> // Diese Bibliothek fügt das ATOMIC_BLOCK-Makro ein.

void SensorData::calcDistance() {
  // berechnet den Abstand mit Ultraschall
  distanceF = sensorFront.getCurrentDistance();
  distanceL = sensorLeft.getCurrentDistance();
  distanceR = sensorRight.getCurrentDistance();
}

void SensorData::RPM_left () {
  unsigned long timer_left = micros();
  if (!lasttime_left) return;
  roundsPerMinute_L = 60000000 / timer_left - lasttime_left;
  lasttime_left = timer_left;
}

void SensorData::RPM_right() {
  unsigned long timer_right = micros();
  if (!lasttime_right) return;
  roundsPerMinute_R = 60000000 / timer_right - lasttime_right;
  lasttime_right = timer_right;
}

const int SensorData::MAX_DISTANCE = 100;

SensorData* SensorData::instance;

SensorData::SensorData() 
  : sensorFront(arduino.D_PIN_OUT_TRIGGER, arduino.D_PIN_IN_ECHO_F),
  sensorLeft(arduino.D_PIN_OUT_TRIGGER, arduino.D_PIN_IN_ECHO_L),
  sensorRight(arduino.D_PIN_OUT_TRIGGER, arduino.D_PIN_IN_ECHO_R) {
    // Interrupts auf Drehzahlsensoren-Pins setzen
    SensorData::instance = this;
    attachInterrupt(digitalPinToInterrupt(arduino.D_PIN_IN_SPEED_SENSOR_L), []() { instance->RPM_left(); }, RISING);
    attachInterrupt(digitalPinToInterrupt(arduino.D_PIN_IN_SPEED_SENSOR_R), []() { instance->RPM_left(); }, RISING);
}

void SensorData::update(){
  // RoundsPerMinute werden über kontinuierliche Interrupts aktualisiert
  calcDistance();
}

float SensorData::getRoundsPerMinute_L(){
  float rpmLeft;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    // Code mit geblockten Interrupts hier (siehe https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/)
    rpmLeft = roundsPerMinute_L;
  }
  return rpmLeft;
}

float SensorData::getRoundsPerMinute_R(){
  float rpmRight;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    // Code mit geblockten Interrupts hier (siehe https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/)
    rpmRight = roundsPerMinute_R;
  }
  return rpmRight;
}

float SensorData::getDistanceF(){
  return distanceF;
}

float SensorData::getDistanceR(){
  return distanceR;
}

float SensorData::getDistanceL(){
  return distanceL;
}