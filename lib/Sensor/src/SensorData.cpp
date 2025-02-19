#include "SensorData.h"
#include <util/atomic.h> // Diese Bibliothek fügt das ATOMIC_BLOCK-Makro ein.

void SensorData::calcDistance() {
  // berechnet den Abstand mit Ultraschall
  distanceF = sensorFront.getCurrentDistance();
  distanceL = sensorLeft.getCurrentDistance();
  distanceR = sensorRight.getCurrentDistance();
}

SensorData::SensorData() 
  : sensorFront(arduino.D_PIN_OUT_TRIGGER_F, arduino.D_PIN_IN_ECHO_F),
  sensorLeft(arduino.D_PIN_OUT_TRIGGER_L, arduino.D_PIN_IN_ECHO_L),
  sensorRight(arduino.D_PIN_OUT_TRIGGER_R, arduino.D_PIN_IN_ECHO_R) {}

void SensorData::update(){
  calcDistance();
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