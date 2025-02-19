#include "ArduinoPinInterface.h"

/**
 * Klasse, die das Interface zur Ansteuerung der Arduino-Pins implementiert.
 */
class ArduinoBoard: public ArduinoPinInterface{
    public:
    /**
     * Konstruktor der ArduinoBoard-Klasse.
     * 
     * Initialisiert die Pin-Modi für verschiedene Funktionen:
     * - Setzt die Pins für die Motorsteuerung als Ausgänge.
     * - Setzt den Pin für die Ultraschall-Trigger als Ausgang.
     * - Definiert die Pins für die Echo-Signale der Ultraschallsensoren als Eingänge.
     */
      ArduinoBoard();
  
      /**
       * Setzt einen digitalen Pin auf den angegebenen Wert.
       * @param pin Der zu setzende Pin. Muss ein digitaler Ausgangs-Pin sein.
       * @param value Der Wert, auf den der Pin gesetzt werden soll. `true` = HIGH, `false` = LOW
       */
      void setDigitalPin(int pin, bool value) override;
  
      /**
       * Liest den Wert eines digitalen Pins.
       * @param pin Der zu lesende Pin. Muss ein digitaler Eingangs-Pin sein.
       * @return Der gelesene Wert des Pins. `true` = HIGH, `false` = LOW.
       */
      bool getDigitalPin(int pin) override;
  
      /**
       * Setzt einen analogen Pin auf den angegebenen Wert.
       * @param pin Der zu setzende Pin. Muss ein analoger Ausgangs-Pin sein.
       * @param value Der Wert, auf den der Pin gesetzt werden soll. Gibt die Stärke des Signals an.
       *              Gültige Werte sind `0` (kein Signal) bis `255` (maximales Signal).
       */
      void setAnalogPin(int pin, int value) override;
  
      /**
       * Liest den Wert eines analogen Pins.
       * @param pin Der zu lesende Pin. Muss ein analoger Eingangs-Pin sein.
       * @return Der gelesene Wert des Pins. Gibt die Stärke des Signals an.
       *         Typischerweise zwischen `0` (kein Signal) und `255` (maximales Signal).
       */
      int getAnalogPin(int pin) override;
  };