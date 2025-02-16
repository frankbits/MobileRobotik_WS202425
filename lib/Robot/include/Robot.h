#include "globals.h"
#include "SensorData.h"
#include "Movement.h"

class Robot {
    private:
      /* Schwellwerte für das Erfassen eines Hindernisses*/
      static const int THRESHOLD_FREE_F;
      static const int THRESHOLD_FREE_L;
      static const int THRESHOLD_FREE_R;
  
      SensorData sensorData;
      Movement movement;
  
      /* Prüft, ob der Weg geradeaus frei ist für den Roboter */
      bool frontIsFree();
  
      /* Prüft, ob der Weg links frei ist für den Roboter */
      bool leftIsFree();
  
      /* Prüft, ob der Weg links frei ist für den Roboter */
      bool rightIsFree();
  
    public:
      /* Berechnet den nächsten Schritt des Roboters beruhend auf den Messdaten der Sensoren */
      void next();
  };