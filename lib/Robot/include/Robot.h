#include "globals.h"
#include "SensorData.h"
#include "Movement.h"

class Robot {
    private:
      /* Schwellwerte für das Erfassen eines Hindernisses*/
      static const int THRESHOLD_FREE_F;
      static const int THRESHOLD_FREE_L;
      static const int THRESHOLD_FREE_R;
  
      

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

      void moveForward(float distanceDelta, unsigned long ms = 100);

      void visualizeLeftAndRightDistance(float distanceL, float distanceR);
  
    public:
      Movement movement;
      /* Berechnet den nächsten Schritt des Roboters beruhend auf den Messdaten der Sensoren */
      void next();
      SensorData sensorData;
  };