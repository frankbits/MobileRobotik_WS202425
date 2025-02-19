#include "Robot.h"

const int Robot::THRESHOLD_FREE_F = 25;
const int Robot::THRESHOLD_FREE_L = 25;
const int Robot::THRESHOLD_FREE_R = 25;

bool Robot::frontIsFree(){
    if(sensorData.getDistanceF() >= THRESHOLD_FREE_F){
        return true;
    } else {
        return false;
    }
}

bool Robot::leftIsFree(){
    if(sensorData.getDistanceL() >= THRESHOLD_FREE_L){
        return true;
    } else {
        return false;
    }
}

bool Robot::rightIsFree(){
    if(sensorData.getDistanceR() >= THRESHOLD_FREE_R){
        return true;
    } else {
        return false;
    }
}

void Robot::enterMaze() {
    movement.forward(90, 0);
    delay(500);
}

void Robot::next(){
    sensorData.update();

    float distanceF = sensorData.getDistanceF();
    float distanceL = sensorData.getDistanceL();
    float distanceR = sensorData.getDistanceR();

    if (DEBUG_LEVEL == DEBUG_DISTANCE_LR)
    {
        visualizeLeftAndRightDistance(distanceL, distanceR);
    }

    float distanceDelta = distanceL - distanceR;

    if (distanceF < 3 || distanceL < 3 || distanceR < 3) {
        if (!frontIsFree() && !leftIsFree() && !rightIsFree()) {
            movement.turnRight(90);
            delay(100);
        }
        movement.backward(90);
        delay(500);
    }

    if (rightIsFree())
    {
        if (DEBUG_LEVEL == DEBUG_MOVE_STATE)
        {
            Serial.println("__________>>>>>");
        }
        
        moveForward(distanceDelta);

        movement.turnRight(90);
        delay(25);

        moveForward(distanceDelta);
    }
    else if (frontIsFree())
    {
        if (DEBUG_LEVEL == DEBUG_MOVE_STATE)
        {
            Serial.println("_____|||||_____");
        }

        moveForward(distanceDelta, 250);
    }
    else if (leftIsFree())
    {
        if (DEBUG_LEVEL == DEBUG_MOVE_STATE)
        {
            Serial.println("<<<<<__________");
        }

        moveForward(distanceDelta);

        movement.turnLeft(90);
        delay(25);

        moveForward(distanceDelta);
    }
    else {
        if (DEBUG_LEVEL == DEBUG_MOVE_STATE)
        {
            Serial.println("VVVVVVVVVVVVVVV");
        }

        moveForward(distanceDelta);

        movement.turnRight(90);
        delay(25);

        moveForward(distanceDelta);
    }
    
    movement.stop();
    delay(250);
    
}

void Robot::moveForward(float distanceDelta, unsigned long ms) {
    if (abs(distanceDelta) > 1) {
        if (abs(distanceDelta) < 6) {
            float kp = 2;
            float ki = 0;
            distanceDeltaIntegrator = distanceDeltaIntegrator + distanceDelta;
            delta = (distanceDelta * kp) + (distanceDeltaIntegrator * ki);
        }
        else if (distanceDelta > 0)
        {
            movement.turnLeft(90);
            delay(100);
            movement.stop();
        }
        else {
            movement.turnRight(90);
            delay(100);
            movement.stop();
        }
    }

    movement.forward(90, delta);
    delay(ms);
}

void Robot::visualizeLeftAndRightDistance(float distanceL, float distanceR) {
    String str = "";
    for (int i = 0; i < distanceL; i++) {
        str += "L";
    }
    str += " | ";
    for (int i = 0; i < distanceR; i++) {
        str += "R";
    }
    Serial.println(str);
}