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
    motors.setSpeedA(speed + 25);
    motors.setSpeedB(speed + (delta * speed));
    motors.backwardA();
    motors.forwardB();
}

void Movement::turnRight(unsigned short speed, float delta) {
    if (delta > 1.0) delta = 1.0;
    if (delta < -1.0) delta = -1.0;
    motors.setSpeedA(speed + 25);
    motors.setSpeedB(speed + (delta * speed));
    motors.forwardA();
    motors.backwardB();
}

void Movement::forward(unsigned short speed, float delta) {
    if (speed > 255) speed = 255;
    if (delta > 0) {
        // delta = delta * 0.6;
    }
    float speedB = speed + delta;
    if (speedB > 255) speedB = 255;
    motors.setSpeedA(speed + 25);
    motors.setSpeedB(speedB);
    motors.forward();
}

void Movement::stop() {
    motors.stop();
}
