#include <Arduino.h>
#include <FreqCount.h>
#include <iostream>


void setup() {
  // erzeugung der Objekte
}

void loop() {

  // 1. RoboterController fragt die Daten von SensorData ab z.B.: getCurrentSensorData()
  //    1.1. SensorData holt sich den aktuellen Zustand des Arduinos über das Pininterface
  //    1.2. SensorData muss die Daten verarbeiten (Umrechnungen der Drehzahl, ...)
  // 2. RoboterController entscheidet, welches Movement nötig ist und errechnet das Korrekturdelta
  // 3. RoboterController übergibt das Korrketurdelta an die Movement und führt die entsprechende bewegung aus
  // 4. Movement steuert über das Pininteface die Motoren an

}


class Robot {
  private:
    SensorData sensorData;
    Movement movement;

  public:
    void next(){
      // Berechnet den nächsten Schirtt des Roboters
    }
};


class ArduinoPinInterface{
  /**
   * Diese Klasse bildet das Interface zur ansteuerung der
   * Arduino-Pins.
   * out -> Ausgangspin
   * in -> Eingangspin
   * 
   * TODO: die Werte der setter Methoden sollen in einer internen Map
   * gespeichert werden (siehe Klasse SensorDaten).
   */

  private:
  public:
    // Bewegunsmotoren Links
    const int PWM_PIN_OUT_MOTOR_L_BACK = 1;
    const int PWM_PIN_OUT_MOTOR_L_FORW = 2;

    // Bewegunsmotoren Rechts
    const int PWM_PIN_OUT_MOTOR_R_BACK = 3;
    const int PWM_PIN_OUT_MOTOR_R_FORW = 4;

    // Servomotor zum drehen der Ultraschallsensoren
    const int PWM_PIN_OUT_POSITION_SERVO_TURN_R = 5;
    const int PWM_PIN_OUT_POSITION_SERVO_TURN_L = 5;

    // messwert des Drehzahlsensors rechts und links(Pegelwechsel)
    const int D_PIN_IN_SPEED_SENSOR_R = 6;
    const int D_PIN_IN_SPEED_SENSOR_L = 6;

    // Tigger für alle drei Ultraschallsensoren
    const int D_PIN_OUT_TRIGGER = 7;

    // Ultraschallsensor vorne, links, rechts
    const int D_PIN_IN_ECHO_F = 8;
    const int D_PIN_IN_ECHO_L = 9;
    const int D_PIN_IN_ECHO_R = 10;

    // abstrakte Methoden
    virtual void setDigitalPin(int pin, bool value) = 0;
    virtual bool getDigitalPin(int pin) = 0;
    virtual void setAnalogPin(int pin, int value) = 0;
    virtual int getAnalogPin(int pin) = 0;
};

class Arduino: public ArduinoPinInterface{
  public:
    void setDigitalPin(int pin, bool value) override {
      digitalWrite(pin, value? HIGH : LOW);
    }

    bool getDigitalPin(int pin) override {
      return digitalRead(pin);
    }

    void setAnalogPin(int pin, int value) override {
      analogWrite(pin, value);
    }

    int getAnalogPin(int pin) override {
      return analogRead(pin);
    }
};

class ArduinoMock: public ArduinoPinInterface{
  public:
    void setDigitalPin(int pin, bool value) override {
      std::cout << "set pin: " << pin << "set value: " << value << std::endl;
    }

    bool getDigitalPin(int pin) override {
      std::cout << "get pin: " << pin << std::endl;
      return true;
    }

    void setAnalogPin(int pin, int value) override {
      std::cout << "set pin: " << pin << "set value: " << value << std::endl;
    }

    int getAnalogPin(int pin) override {
      std::cout << "get pin: " << pin  << std::endl;
      return 1;
    }
};


class SensorData{
  private:
    // Bewegunsmotoren
    const int out_MotorRight = 0.0;
    float out_MotorLeft = 0.0;

    // Servomotor zum drehen der Ultraschallsensoren
    float out_PositionServo = 0.0;

    // messwert des Drehzahlsensors (Pegelwechsel)
    bool in_digitalSpeedSensor = false;

    // Ultraschallsensor vorne
    bool out_triggerSensorF = false;
    float in_echoSensorF = 0.0;

    // Ultraschallsensor rechts
    bool out_triggerSensorR = false;
    float in_echoSensorR = 0.0;

    // Ultraschallsensor links
    bool out_triggerSensorL = false;
    float in_echoSensorL = 0.0;
  public:
};


class Movement {
  private:
    /* data */
  public:
    Movement(/* args */);
    void turnLeft(float delta);
    void turnRight(float delta);
    void forward(float delta);
};


Movement::Movement(/* args */)
{
  //Konstruktor
}

void::Movement::turnLeft(float delta=0.0){
float pinMotorLeft = 0.0;

}

void::Movement::turnRight(float delta=0.0){

}

void::Movement::forward(float delta=0.0){
// Movment liest bei SensorData aus und übergibt an Arduino
}




