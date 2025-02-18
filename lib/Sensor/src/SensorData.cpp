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
  if (!lasttime_left) {
    lasttime_left = timer_left;
    return;
  };
  float delta = timer_left - lasttime_left;
  //roundsPerMinute_L = (60 / (20 * (delta / 1000000)));
  roundsPerMinute_L = (timer_left - lasttime_left) / 1000;
  lasttime_left = timer_left;
}

void SensorData::RPM_right() {
  unsigned long timer_right = micros();
  if (!lasttime_right) {
    lasttime_right = timer_right;
    return;
  };


  float delta = timer_right - lasttime_right;
  //roundsPerMinute_R = (60 / (20 * (delta / 1000000)));  
  roundsPerMinute_R = (timer_right - lasttime_right) / 1000;
  lasttime_right = timer_right;
}

void SensorData::resetRPMIfZero() {
  if (micros() - lasttime_left > 1000000) {
    lasttime_left = 0;
    roundsPerMinute_L = 0;
  }

  if (micros() - lasttime_right > 1000000) {
    lasttime_right = 0;
    roundsPerMinute_R = 0;
  }
}

const int SensorData::MAX_DISTANCE = 100;

SensorData* SensorData::instance;

SensorData::SensorData() 
  : sensorFront(arduino.D_PIN_OUT_TRIGGER_F, arduino.D_PIN_IN_ECHO_F),
  sensorLeft(arduino.D_PIN_OUT_TRIGGER_L, arduino.D_PIN_IN_ECHO_L),
  sensorRight(arduino.D_PIN_OUT_TRIGGER_R, arduino.D_PIN_IN_ECHO_R) {
    // Interrupts auf Drehzahlsensoren-Pins setzen
    SensorData::instance = this;
    // attachInterrupt(digitalPinToInterrupt(arduino.D_PIN_IN_SPEED_SENSOR_L), []() { instance->RPM_left(); }, RISING);
    // attachInterrupt(digitalPinToInterrupt(arduino.D_PIN_IN_SPEED_SENSOR_R), []() { instance->RPM_right(); }, RISING);
}

void SensorData::update(){
  // RoundsPerMinute werden über kontinuierliche Interrupts aktualisiert
  calcDistance();

  resetRPMIfZero();
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