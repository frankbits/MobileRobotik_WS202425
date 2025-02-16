/**
 * Diese Klasse bildet das Interface zur Ansteuerung der Arduino-Pins.
 * Pin-Namensstruktur: `(D|PWM|A)_PIN_(OUT|IN)_{NAME}`
 * - Art des Pins: `D` = Digital, `PWM` = PulseWidthModulation, `A` = Analog
 * - Richtung des Pins: `OUT` = Ausgang, `IN` = Eingang
 * - Name des Pins: `{NAME}` bezeichnet die Funktion des Pins
 * 
 */
class ArduinoPinInterface {
    private:
    public:
      /** Digitaler Pin, zur Steuerung des linken Motors (Vorwaerts) */
      static const unsigned int D_PIN_OUT_MOTOR_L_FORW;
      /** Digitaler Pin, zur Steuerung des linken Motors (Rueckwaerts) */
      static const unsigned int D_PIN_OUT_MOTOR_L_BACK;
      /** PWM Pin, zur Steuerung der Geschwindigkeit des linken Motors */
      static const unsigned int PWM_PIN_OUT_MOTOR_L_ENA;
  
      /** Digitaler Pin, zur Steuerung des rechten Motors (Vorwaerts) */
      static const unsigned int D_PIN_OUT_MOTOR_R_FORW;
      /** Digitaler Pin, zur Steuerung des rechten Motors (Rueckwaerts) */
      static const unsigned int D_PIN_OUT_MOTOR_R_BACK;
      /** PWM Pin, zur Steuerung der Geschwindigkeit des rechten Motors */
      static const unsigned int PWM_PIN_OUT_MOTOR_R_ENB;
  
      /** Digitaler Pin, zur Steuerung des Servos */
      // const int D_PIN_OUT_POSITION_SERVO; //TODO: können PIN 0 oder 1 als digitaler Pin verwendet werden?
  
      /** Digitaler Pin, zur Messung des Pegelwechsels des linken Drehzahlsensors */
      static const unsigned int D_PIN_IN_SPEED_SENSOR_L;
      /** Digitaler Pin, zur Messung des Pegelwechsels des rechten Drehzahlsensors */
      static const unsigned int D_PIN_IN_SPEED_SENSOR_R;
  
      /** Digitaler Pin, zum Senden des Triggers aller drei Ultraschallsensoren */
      static const unsigned int D_PIN_OUT_TRIGGER;
  
      /** Digitaler Pin, zum Empfang des Echos des vorderen Ultraschallsensors */
      static const unsigned int D_PIN_IN_ECHO_F;
      /** Digitaler Pin, zum Empfang des Echos des linken Ultraschallsensors */
      static const unsigned int D_PIN_IN_ECHO_L;
      /** Digitaler Pin, zum Empfang des Echos des rechten Ultraschallsensors */
      static const unsigned int D_PIN_IN_ECHO_R;
  
      /**
       * Konstruktor der ArduinoPinInterface-Klasse.
       */
      ArduinoPinInterface();

      /**
       * Setzt einen digitalen Pin auf den angegebenen Wert.
       * @param pin Der zu setzende Pin. Muss ein digitaler Ausgangs-Pin sein.
       * @param value Der Wert, auf den der Pin gesetzt werden soll. `true` = HIGH, `false` = LOW
       */
      virtual void setDigitalPin(int pin, bool value) = 0;
      /**
       * Liest den Wert eines digitalen Pins.
       * @param pin Der zu lesende Pin. Muss ein digitaler Eingangs-Pin sein.
       * @return Der gelesene Wert des Pins. `true` = HIGH, `false` = LOW.
       */
      virtual bool getDigitalPin(int pin) = 0;
      /**
       * Setzt einen analogen Pin auf den angegebenen Wert.
       * @param pin Der zu setzende Pin. Muss ein analoger Ausgangs-Pin sein.
       * @param value Der Wert, auf den der Pin gesetzt werden soll. Gibt die Stärke des Signals an.
       *              Gültige Werte sind `0` (kein Signal) bis `255` (maximales Signal).
       */
      virtual void setAnalogPin(int pin, int value) = 0;
      /**
       * Liest den Wert eines analogen Pins.
       * @param pin Der zu lesende Pin. Muss ein analoger Eingangs-Pin sein.
       * @return Der gelesene Wert des Pins. Gibt die Stärke des Signals an.
       *         Typischerweise zwischen `0` (kein Signal) und `255` (maximales Signal).
       */
      virtual int getAnalogPin(int pin) = 0;
  };