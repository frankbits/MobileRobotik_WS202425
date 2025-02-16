#include "ArduinoBoard.h"
#include <Arduino.h>

ArduinoBoard::ArduinoBoard() {
  /** Pins für Motoren als Ausgang definieren */
  pinMode(D_PIN_OUT_MOTOR_L_BACK, OUTPUT);
  pinMode(D_PIN_OUT_MOTOR_L_FORW, OUTPUT);
  pinMode(PWM_PIN_OUT_MOTOR_L_ENA, OUTPUT); // PWM
  pinMode(D_PIN_OUT_MOTOR_R_BACK, OUTPUT);
  pinMode(D_PIN_OUT_MOTOR_R_FORW, OUTPUT);
  pinMode(PWM_PIN_OUT_MOTOR_R_ENB, OUTPUT); // PWM

  /** Pins für Drehzahlsensor als Eingang definieren */
  pinMode(D_PIN_IN_SPEED_SENSOR_L, INPUT);
  pinMode(D_PIN_IN_SPEED_SENSOR_R, INPUT);

  /** Pin Trigger für Ultraschallsensor als Ausgang definieren */
  pinMode(D_PIN_OUT_TRIGGER, OUTPUT);

  /** Pins Echo für Ultraschallsensoren als Eingang definieren */
  pinMode(D_PIN_IN_ECHO_F, INPUT);
  pinMode(D_PIN_IN_ECHO_L, INPUT);
}

void ArduinoBoard::setDigitalPin(int pin, bool value) {
  digitalWrite(pin, value? HIGH : LOW);
}

bool ArduinoBoard::getDigitalPin(int pin) {
  return digitalRead(pin);
}

void ArduinoBoard::setAnalogPin(int pin, int value) {
  analogWrite(pin, value);
}

int ArduinoBoard::getAnalogPin(int pin) {
  return analogRead(pin);
}
