#include <NewPing.h> // Abstand berechnen

/**
 * Klasse zum Auslesen der Distanz über jeweils einen Ultraschallsensor.
 */
class DistanceSensor {
  private:
    /** Maximal zu messende Distanz in cm */
    static const int MAX_DISTANCE;

    /** Objekt zum Auslesen der Distanz über einen Ultraschallsensor */
    NewPing sensor;

  public:
    /** 
     * Initialisiert einen Ultraschallsensor mit gegebenem Trigger- und Echo-Pin
     * 
     * @param trigger Trigger-Pin des Ultraschallsensors
     * @param echo Echo-Pin des Ultraschallsensors
     */
    DistanceSensor(int trigger, int echo);

    /** Gibt die aktuelle Distanz zurueck */
    float getCurrentDistance();
};