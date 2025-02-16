#include "DistanceSensor.h"

const int DistanceSensor::MAX_DISTANCE = 100;

DistanceSensor::DistanceSensor(int trigger, int echo)
  : sensor(trigger, echo, MAX_DISTANCE) {}

float DistanceSensor::getCurrentDistance() {
  return sensor.ping_cm();
}
