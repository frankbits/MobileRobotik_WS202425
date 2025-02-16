#include "Movement.h"

Movement::Movement(): motors(
    arduino.PWM_PIN_OUT_MOTOR_L_ENA,
    arduino.D_PIN_OUT_MOTOR_L_FORW,
    arduino.D_PIN_OUT_MOTOR_L_BACK,
    arduino.PWM_PIN_OUT_MOTOR_R_ENB,
    arduino.D_PIN_OUT_MOTOR_R_FORW,
    arduino.D_PIN_OUT_MOTOR_R_BACK
) {};

void Movement::turnLeft(unsigned short speed, float delta) {
    if (delta > 1.0) delta = 1.0;
    if (delta < -1.0) delta = -1.0;
    motors.setSpeedA(speed);
    motors.setSpeedB(speed + (delta * speed));
    motors.backwardA();
    motors.forwardB();
}

void Movement::turnRight(unsigned short speed, float delta) {
    if (delta > 1.0) delta = 1.0;
    if (delta < -1.0) delta = -1.0;
    motors.setSpeedA(speed);
    motors.setSpeedB(speed + (delta * speed));
    motors.forwardA();
    motors.backwardB();
}

void Movement::forward(unsigned short speed, float delta) {
    if (delta > 1.0) delta = 1.0;
    if (delta < -1.0) delta = -1.0;
    motors.setSpeedA(speed);
    motors.setSpeedB(speed + (delta * speed));
    motors.forward();
}
