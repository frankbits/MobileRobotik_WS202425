#include "Movement.h"

Movement::Movement(): motors(
    arduino.PWM_PIN_OUT_MOTOR_L_ENA,
    arduino.D_PIN_OUT_MOTOR_L_FORW,
    arduino.D_PIN_OUT_MOTOR_L_BACK,
    arduino.PWM_PIN_OUT_MOTOR_R_ENB,
    arduino.D_PIN_OUT_MOTOR_R_FORW,
    arduino.D_PIN_OUT_MOTOR_R_BACK
) {};

void Movement::turnLeft(unsigned short speed) {
    if (speed > MAX_SPEED) speed = MAX_SPEED;

    motors.setSpeedA(speed + MECHANICAL_DIFFERENCE);
    motors.setSpeedB(speed);

    motors.backwardA();
    motors.forwardB();
}

void Movement::turnRight(unsigned short speed) {
    if (speed > MAX_SPEED) speed = MAX_SPEED;

    motors.setSpeedA(speed + MECHANICAL_DIFFERENCE);
    motors.setSpeedB(speed);

    motors.forwardA();
    motors.backwardB();
}

void Movement::forward(unsigned short speed, float delta) {
    if (speed > MAX_SPEED) speed = MAX_SPEED;
    float speedB = speed + delta;
    if (speedB > MAX_SPEED) speedB = MAX_SPEED;

    motors.setSpeedA(speed + MECHANICAL_DIFFERENCE);
    motors.setSpeedB(speedB);

    motors.forward();
}

void Movement::backward(unsigned short speed) {
    if (speed > MAX_SPEED) speed = MAX_SPEED;

    motors.setSpeedA(speed + MECHANICAL_DIFFERENCE);   
    motors.setSpeedB(speed);

    motors.backward();
}

void Movement::stop() {
    motors.stop();
}
