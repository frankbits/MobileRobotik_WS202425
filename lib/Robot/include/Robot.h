#include "globals.h"
#include "SensorData.h"
#include "Movement.h"

class Robot {
    private:
      /** Schwellwert der Distanz nach vorne, über den der Weg geradeaus frei ist */
      static const int THRESHOLD_FREE_F;
      /** Schwellwert der Distanz nach links, über den der Weg links frei ist */
      static const int THRESHOLD_FREE_L;
      /** Schwellwert der Distanz nach rechts, über den der Weg rechts frei ist */
      static const int THRESHOLD_FREE_R;

      /** Objekt zur Ansteuerung beider Motoren mit verschiedenen definierten Manövern */
      Movement movement;

      /** Objekt zur Aktualisierung und Abfrage der Sensorwerte */
      SensorData sensorData;

      /* Integrator der Drehzahlabweichung */
      float distanceDeltaIntegrator = 0;
      /* Korrekturfaktor */
      float delta = 0;
  
      /* Prüft, ob der Weg geradeaus frei ist für den Roboter */
      bool frontIsFree();
  
      /* Prüft, ob der Weg links frei ist für den Roboter */
      bool leftIsFree();
  
      /* Prüft, ob der Weg rechts frei ist für den Roboter */
      bool rightIsFree();

      /**
       * Bewegt den Roboter vorwärts durch das Labyrinth.
       * 
       * Die Differenz zwischen dem Abstand zur linken Wand und dem Abstand zur rechten Wand wird verwendet, um den Roboter mittig zu halten.
       * 
       * @param distanceDelta die Differenz zwischen dem Abstand zur linken Wand und dem Abstand zur rechten Wand
       * @param ms die Zeit, die der Roboter sich bewegen soll
       */
      void moveForward(float distanceDelta, unsigned long ms = 100);

      /**
       * Visualisiert den gegebenen Abstand nach links und rechts in der Konsole,
       * indem 'L' und 'R' jeweils so oft aufgeführt werden, wie der
       * Abstand in cm beträgt.
       * 
       * @param distanceL der Abstand in cm von links
       * @param distanceR der Abstand in cm von rechts
       */
      void visualizeLeftAndRightDistance(float distanceL, float distanceR);
  
    public:
      /* Berechnet den nächsten Schritt des Roboters beruhend auf den Messdaten der Sensoren */
      void next();
  };