#include <Arduino.h>
#include <FreqCount.h>
#include <iostream>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}


class Movement {
  private:
    /* data */
  public:
    Movement(/* args */);
    void turnLeft(float delta);
    void turnRight(float delta);
    void forward(float delta);
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
    // Bewegunsmotoren
    const int A_PIN_OUT_MOTOR_R = 1;
    const int A_PIN_OUT_MOTOR_L = 2;

    // Servomotor zum drehen der Ultraschallsensoren
    const int A_PIN_OUT_POSITION_SERVO = 3;

    // messwert des Drehzahlsensors (Pegelwechsel)
    const int D_PIN_IN_SPEED_SENSOR = 4;

    // Ultraschallsensor vorne
    const int D_PIN_OUT_TRIGGER_F = 5;
    const int D_PIN_IN_ECHO_F = 6;

    // Ultraschallsensor rechts
    const int D_PIN_OUT_TRIGGER_R = 7;
    const int D_PIN_IN_ECHO_R = 8;

    // Ultraschallsensor links
    const int D_PIN_OUT_TRIGGER_L = 9;
    const int D_PIN_IN_ECHO_L = 10;

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


Movement::Movement(/* args */)
{
  //Konstruktor
}

void::Movement::turnLeft(float delta=0.0){
float pinMotorLeft = 0.0

}

void::Movement::turnRight(float delta=0.0){

}

void::Movement::forward(float delta=0.0){

}




