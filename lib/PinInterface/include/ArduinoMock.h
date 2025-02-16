#include "ArduinoPinInterface.h"

class ArduinoMock: public ArduinoPinInterface{
    public:
      /**
       * Gibt eine Meldung aus, dass der Pin auf den angegebenen Wert gesetzt wurde.
       * @param pin Der zu setzende Pin. Muss ein digitaler Ausgangs-Pin sein.
       * @param value Der Wert, auf den der Pin gesetzt werden soll. `true` = HIGH, `false` = LOW
       */
      void setDigitalPin(int pin, bool value) override;
  
      /**
       * Gibt eine Meldung aus, dass der Pin gelesen wurde und liefert den Beispiel-Wert `true`.
       * @param pin Der zu lesende Pin. Muss ein digitaler Eingangs-Pin sein.
       * @return Der gelesene Wert des Pins. `true` = HIGH, `false` = LOW.
       */
      bool getDigitalPin(int pin) override;
  
      /**
       * Gibt eine Meldung aus, dass der Pin auf den angegebenen Wert gesetzt wurde.
       * @param pin Der zu setzende Pin. Muss ein analoger Ausgangs-Pin sein.
       * @param value Der Wert, auf den der Pin gesetzt werden soll. Gibt die Stärke des Signals an.
       *              Gültige Werte sind `0` (kein Signal) bis `255` (maximales Signal).
       */
      void setAnalogPin(int pin, int value) override;
  
      /**
       * Gibt eine Meldung aus, dass der Pin gelesen wurde und liefert den Beispiel-Wert `1`.
       * @param pin Der zu lesende Pin. Muss ein analoger Eingangs-Pin sein.
       * @return Der gelesene Wert des Pins. Gibt die Stärke des Signals an.
       *         Typischerweise zwischen `0` (kein Signal) und `255` (maximales Signal).
       */
      int getAnalogPin(int pin) override;
  };