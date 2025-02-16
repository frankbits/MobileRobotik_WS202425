#include "globals.h"
#include "DistanceSensor.h"

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
  
      void calcDistance();
  
      void RPM_left ();
      
      void RPM_right();
  
    public:
      static const int MAX_DISTANCE;
  
      static SensorData* instance; // Für Zugriff in ISR für Drehzahlsensoren
  
      SensorData();
  
      void update();
  
      float getRoundsPerMinute_L();
  
      float getRoundsPerMinute_R();
  
      float getDistanceF();
  
      float getDistanceR();
  
      float getDistanceL();
  };