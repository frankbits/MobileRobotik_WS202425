#include <NewPing.h> // Abstand berechnen

class DistanceSensor {
  private:
    static const int MAX_DISTANCE;
    NewPing sensor;

  public:
    DistanceSensor(int trigger, int echo);
    float getCurrentDistance();
};