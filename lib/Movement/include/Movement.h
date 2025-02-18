#include "globals.h"
#include "L298NX2.h"

class Movement {
    private:
      
  
    public:
      L298NX2 motors;
      Movement();
      
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
      void turnLeft(unsigned short speed, float delta);
  
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
      void turnRight(unsigned short speed, float delta);
  
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
      void forward(unsigned short speed, float delta);

      void stop();
  };