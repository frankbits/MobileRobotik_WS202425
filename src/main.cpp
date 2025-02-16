#include <Arduino.h>
#include <iostream>
#include <util/atomic.h> // Diese Bibliothek fügt das ATOMIC_BLOCK-Makro ein.

#include <NewPing.h> // Abstand berechnen
#include <L298NX2.h> // Motoren ansteuern

class ArduinoPinInterface{
  /**
   * Diese Klasse bildet das Interface zur Ansteuerung der Arduino-Pins.
   * OUT -> Ausgangspin
   * INT -> Eingangspin
   * D -> digial
   * PWM -> Pulsweitenmodulation.
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
    Arduino(){
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
      pinMode(D_PIN_IN_ECHO_R, INPUT);
    }

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
Robot robot;

void setup(){
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

class Robot {
  private:
    SensorData sensorData;
    Movement movement;

  public:
    void next(){
      sensorData.update();
      sensorData.getDistanceR();
      // if right is free
        movement.turnRight(100, 0);
      // Berechnet den nächsten Schirtt des Roboters
    }
};

class DistanceSensor {
  private:
    const int MAX_DISTANCE = 100;
    NewPing sensor;

  public:
    // Konstruktor mit Initialisierungsliste
    DistanceSensor(int trigger, int echo) 
      : sensor(trigger, echo, MAX_DISTANCE) {  // Initialisiere sensor und distance
    }

    float getCurrentDistance() {
      return sensor.ping_cm();
    }
};

class SensorData{
  private:
    // Drehzahlsensor links und rechts
    unsigned long lasttime_left;
    unsigned long lasttime_right;
    volatile float roundsPerMinute_L;
    volatile float roundsPerMinute_R;

    // Ultraschallsensor vorne, links, rechts
    DistanceSensor sensorFront;
    DistanceSensor sensorLeft;
    DistanceSensor sensorRight;
    /** Abstand nach vorne in cm */
    float distanceF = 0.0;
    /** Abstand nach links in cm */
    float distanceL = 0.0;
    /** Abstand nach rechts in cm */
    float distanceR = 0.0;

    float calcDistance(){
      // berechnet den Abstand mit Ultraschall
      distanceF = sensorFront.getCurrentDistance();
      distanceL = sensorLeft.getCurrentDistance();
      distanceR = sensorRight.getCurrentDistance();
    }

    void RPM_left () {
      unsigned long timer_left = micros();
      if (!lasttime_left) return;
      roundsPerMinute_L = 60000000 / timer_left - lasttime_left;
      lasttime_left = timer_left;
    }
    
    void RPM_right() {
      unsigned long timer_right = micros();
      if (!lasttime_right) return;
      roundsPerMinute_R = 60000000 / timer_right - lasttime_right;
      lasttime_right = timer_right;
    }

  public:
    const int MAX_DISTANCE = 100;

    static SensorData* instance; // Für Zugriff in ISR für Drehzahlsensoren

    SensorData() 
      : sensorFront(arduino.D_PIN_OUT_TRIGGER, arduino.D_PIN_IN_ECHO_F),
      sensorRight(arduino.D_PIN_OUT_TRIGGER, arduino.D_PIN_IN_ECHO_R),
      sensorLeft(arduino.D_PIN_OUT_TRIGGER, arduino.D_PIN_IN_ECHO_L) {
        // Drehzahlsensoren-Pins als Eingangspins setzen
        pinMode(arduino.D_PIN_IN_SPEED_SENSOR_L, INPUT);
        pinMode(arduino.D_PIN_IN_SPEED_SENSOR_R, INPUT);

        // Interrupts auf Drehzahlsensoren-Pins setzen
        SensorData::instance = this;
        attachInterrupt(digitalPinToInterrupt(arduino.D_PIN_IN_SPEED_SENSOR_L), []() { instance->RPM_left(); }, RISING);
        attachInterrupt(digitalPinToInterrupt(arduino.D_PIN_IN_SPEED_SENSOR_R), []() { instance->RPM_left(); }, RISING);
    }

    void update(){
      // RoundsPerMinute werden über kontinuierliche Interrupts aktualisiert
      calcDistance();
    }

    float getRoundsPerMinute_L(){
      ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        // Code mit geblockten Interrupts hier (siehe https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/)
        return roundsPerMinute_L;
      }
    }

    float getRoundsPerMinute_R(){
      ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        // Code mit geblockten Interrupts hier (siehe https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/)
        return roundsPerMinute_R;
      }
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
      arduino.PWM_PIN_OUT_MOTOR_L_ENA,
      arduino.D_PIN_OUT_MOTOR_L_FORW,
      arduino.D_PIN_OUT_MOTOR_L_BACK,
      arduino.PWM_PIN_OUT_MOTOR_R_ENB,
      arduino.D_PIN_OUT_MOTOR_R_FORW,
      arduino.D_PIN_OUT_MOTOR_R_BACK
    ){};
    
    /**
     * Drehe den Roboter mit der gegebenen Geschwindigkeit und Korrektur nach links.
     * 
     * Die Geschwindigkeit ist der absolute Wert für den linken Motor und der Korrekturfaktor 
     * ist der relative Wert, der die Drehzal des rechten Motor an die des linken Motors anpassen soll.
     * Ein positiver Korrekturfaktor beschleunigt den rechten Motor, ein negativer verlangsamt ihn.
     * 
     * Der Korrekturfaktor kann auch genutzt werden, um den Roboter stärker, oder weniger stark abbiegen zu lassen.
     * So ist es beispielsweise möglich, die Positionierung des Roboters im Feld zu verbessern.
     * 
     * @param speed Die gewunschte Geschwindigkeit der Motoren
     * @param delta der Korrekturfaktor in Prozent (-1.0 bis 1.0)
     */
    void turnLeft(unsigned short speed, float delta){
      if (delta > 1.0) delta = 1.0;
      if (delta < -1.0) delta = -1.0;
      motors.setSpeedA(speed);
      motors.setSpeedB(speed + (delta * speed));
      motors.backwardA();
      motors.forwardB();
    }

    /**
     * Drehe den Roboter mit der gegebenen Geschwindigkeit und Korrektur nach rechts.
     * 
     * Die Geschwindigkeit ist der absolute Wert für den linken Motor und der Korrekturfaktor 
     * ist der relative Wert, der die Drehzal des rechten Motor an die des linken Motors anpassen soll.
     * Ein positiver Korrekturfaktor beschleunigt den rechten Motor, ein negativer verlangsamt ihn.
     * 
     * Der Korrekturfaktor kann auch genutzt werden, um den Roboter stärker, oder weniger stark abbiegen zu lassen.
     * So ist es beispielsweise möglich, die Positionierung des Roboters im Feld zu verbessern.
     * 
     * @param speed Die gewunschte Geschwindigkeit der Motoren
     * @param delta der Korrekturfaktor in Prozent (-1.0 bis 1.0)
     */
    void turnRight(unsigned short speed, float delta){
      if (delta > 1.0) delta = 1.0;
      if (delta < -1.0) delta = -1.0;
      motors.setSpeedA(speed);
      motors.setSpeedB(speed + (delta * speed));
      motors.forwardA();
      motors.backwardB();
    }

    /**
     * Bewege den Roboter mit der gegebenen Geschwindigkeit und Korrektur vorwärts.
     * 
     * Die Geschwindigkeit ist der absolute Wert für den linken Motor und der Korrekturfaktor 
     * ist der relative Wert, der die Drehzal des rechten Motor an die des linken Motors anpassen soll.
     * Ein positiver Korrekturfaktor beschleunigt den rechten Motor, ein negativer verlangsamt ihn.
     * 
     * Der Korrekturfaktor kann auch genutzt werden, um den Roboter in eine bestimmte Richtung zu bewegen.
     * So ist es beispielsweise möglich, die Positionierung des Roboters im Feld zu verbessern.
     * 
     * @param speed Die gewünschte Geschwindigkeit der Motoren
     * @param delta der Korrekturfaktor in Prozent (-1.0 bis 1.0)
     */ 
    void forward(unsigned short speed, float delta){
      if (delta > 1.0) delta = 1.0;
      if (delta < -1.0) delta = -1.0;
      motors.setSpeedA(speed);
      motors.setSpeedB(speed + (delta * speed));
      motors.forward();
    }
};
