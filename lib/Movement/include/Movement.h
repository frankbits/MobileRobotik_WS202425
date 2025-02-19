#include "globals.h"
#include "L298NX2.h"

/**
 * Diese Klasse steuert die Motoren des Roboters.
 * Für die jeweiligen Manöver sind entsprechende Methoden definiert.
 */
class Movement {
    private:
      /** Objekt zur Ansteuerung beider Motoren */
      L298NX2 motors;

      /** Maximales PWM-Stellsignal */
      const short MAX_SPEED = 255;

      /** `+ 25`: PWM-Stellsignal-Ausgleich der Mechanikdifferenz zwischen den Motoren */
      const int MECHANICAL_DIFFERENCE = 25;
  
    public:
      /**
       * Initialisiere die Motoren unter Angabe der Pin-Nummern.
       */
      Movement();
      
      /**
       * Drehe den Roboter mit der gegebenen Geschwindigkeit nach links.
       * 
       * Die Geschwindigkeit ist der absolute Wert für beide Motoren.
       * 
       * @param speed Die gewünschte Geschwindigkeit der Motoren (0 bis 255, praktisch erst ab 70)
       */
      void turnLeft(unsigned short speed);
  
      /**
       * Drehe den Roboter mit der gegebenen Geschwindigkeit nach rechts.
       * 
       * Die Geschwindigkeit ist der absolute Wert für beide Motoren.
       * 
       * @param speed Die gewunschte Geschwindigkeit der Motoren (0 bis 255, praktisch erst ab 70)
       */
      void turnRight(unsigned short speed);
  
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
       * @param speed Die gewünschte Geschwindigkeit der Motoren (0 bis 255, praktisch erst ab 70)
       * @param delta der Korrekturwert, der zur angebenen Geschwindigkeit addiert werden soll
       *              (positiv: Korrektur nach links, negativ: Korrektur nach rechts)
       */ 
      void forward(unsigned short speed, float delta);

      /**
       * Bewege den Roboter mit der gegebenen Geschwindigkeit und Korrektur vorwärts.
       * 
       * Die Geschwindigkeit ist der absolute Wert für beide Motoren.
       * 
       * @param speed Die gewünschte Geschwindigkeit der Motoren (0 bis 255, praktisch erst ab 70)
       */
      void backward(unsigned short speed);

      /**
       * Stoppe beide Motoren des Roboters.
       */
      void stop();
  };