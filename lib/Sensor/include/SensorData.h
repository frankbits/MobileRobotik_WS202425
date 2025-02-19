#include "globals.h"
#include "DistanceSensor.h"

class SensorData{
    private:
      /** Objekt zum Auslesen der Distanz über den vorderen Ultraschallsensor */
      DistanceSensor sensorFront;
      /** Objekt zum Auslesen der Distanz über den linken Ultraschallsensor */
      DistanceSensor sensorLeft;
      /** Objekt zum Auslesen der Distanz ober den rechten Ultraschallsensor */
      DistanceSensor sensorRight;

      /** Abstand nach vorne in cm */
      float distanceF = 0.0;
      /** Abstand nach links in cm */
      float distanceL = 0.0;
      /** Abstand nach rechts in cm */
      float distanceR = 0.0;
  
      /**
       * Ruft den aktuellen Abstand zu Hindernissen über die Ultraschallsensoren ab.
       * 
       * Aktualisiert die Abstandsvariablen distanceF, distanceL und distanceR.
       */
      void calcDistance();

    public:
      /** Initialisiert die Objekte zum Auslesen der Distanz */
      SensorData();
  
      /** Aktualisiert die Sensorwerte */
      void update();
  
      /** Gibt den Abstand nach vorne zurueck */
      float getDistanceF();

      /** Gibt den Abstand nach links zurueck */
      float getDistanceL();
  
      /** Gibt den Abstand nach rechts zurueck */
      float getDistanceR();
  };