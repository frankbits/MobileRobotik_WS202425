#include <Arduino.h>
#include <FreqCount.h> // drehzal ermitteln
#include <iostream>
#include <NewPing.h> // Abstand berechnen
#include <L298NX2.h> // Motoren ansteuern

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
    /** Digitaler Pin, zur Steuerung des linken Motors (Vorwaerts) */
    const unsigned int D_PIN_OUT_MOTOR_L_FORW = 4;
    /** Digitaler Pin, zur Steuerung des linken Motors (Rueckwaerts) */
    const unsigned int D_PIN_OUT_MOTOR_L_BACK = 5;
    /** PWM Pin, zur Steuerung der Geschwindigkeit des linken Motors */
    const unsigned int PWM_PIN_OUT_MOTOR_L_ENA = 6;

    /** Digitaler Pin, zur Steuerung des rechten Motors (Vorwaerts) */
    const unsigned int D_PIN_OUT_MOTOR_R_FORW = 7;
    /** Digitaler Pin, zur Steuerung des rechten Motors (Rueckwaerts) */
    const unsigned int D_PIN_OUT_MOTOR_R_BACK = 8;
    /** PWM Pin, zur Steuerung der Geschwindigkeit des rechten Motors */
    const unsigned int PWM_PIN_OUT_MOTOR_R_ENB = 9;

    /** Digitaler Pin, zur Steuerung des Servos */
    // const int D_PIN_OUT_POSITION_SERVO = 1; //TODO: können PIN 0 oder 1 als digitaler Pin verwendet werden?

    /** Digitaler Pin, zur Messung des Pegelwechsels des linken Drehzahlsensors */
    const int D_PIN_IN_SPEED_SENSOR_L = 2;
    /** Digitaler Pin, zur Messung des Pegelwechsels des rechten Drehzahlsensors */
    const int D_PIN_IN_SPEED_SENSOR_R = 3;

    /** Digitaler Pin, zum Senden des Triggers aller drei Ultraschallsensoren */
    const int D_PIN_OUT_TRIGGER = 10;

    /** Digitaler Pin, zum Empfang des Echos des vorderen Ultraschallsensors */
    const int D_PIN_IN_ECHO_F = 11;
    /** Digitaler Pin, zum Empfang des Echos des linken Ultraschallsensors */
    const int D_PIN_IN_ECHO_L = 12;
    /** Digitaler Pin, zum Empfang des Echos des rechten Ultraschallsensors */
    const int D_PIN_IN_ECHO_R = 13;

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

Arduino arduino;


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


  Robot robot;
  robot.next();
}

class Robot {
  private:
    SensorData sensorData;
    Movement movement;

  public:
    void next(){
      sensorData.update();
      sensorData.getDistanceR();
      // if right is free
        movement.turnRight(0);
      // Berechnet den nächsten Schirtt des Roboters
    }
};


class SensorData{
  private:
    // Drehzahlsensor rechts und links
    float velocityR = 0.0;
    float velocityL = 0.0;

    // Ultraschallsensor vorne
    float distanceF = 0.0;

    // Ultraschallsensor rechts
    float distanceR = 0.0;

    // Ultraschallsensor links
    float distanceL = 0.0;

    float calcDistance(){
      // berechnet den abstand mit Ultraschall
    }

    float calcVelocity(){
      // berechnet die geschwindigkeit der Räder
    }

  public:
    const int MAX_DISTANCE = 100;

    void update(){
      calcDistance();
      calcVelocity();
    }

    float getVelocityR(){
      return velocityL;
    }

    float getVelocityL(){
      return velocityL;
    }

    float getDistanceF(){
      return distanceF;
    }

    float getDistanceR(){
      return distanceR;
    }

    float getDistanceL(){
      return distanceL;
    }
};


class Movement {
  private:
    L298NX2 motors;

  public:
    Movement(): motors(
      1,
      arduino.PWM_PIN_OUT_MOTOR_L_BACK,
      arduino.PWM_PIN_OUT_MOTOR_L_FORW,
      2,
      arduino.PWM_PIN_OUT_MOTOR_R_BACK,
      arduino.PWM_PIN_OUT_MOTOR_R_FORW
    ){};
    
    void turnLeft(float delta){
      //delta ist der unterschied zwischen links und rechts
  
    }

    void turnRight(float delta){
      
    }

    void forward(float delta){
      motors.forwardA();
      motors.forwardB();
    }
};





