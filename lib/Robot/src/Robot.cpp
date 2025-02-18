#include "Robot.h"

const int Robot::THRESHOLD_FREE_F = 5;
const int Robot::THRESHOLD_FREE_L = 20;
const int Robot::THRESHOLD_FREE_R = 20;

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

void Robot::next(){
    sensorData.update();

    float distanceF = sensorData.getDistanceF();
    float distanceL = sensorData.getDistanceL();
    float distanceR = sensorData.getDistanceR();

    // String str = "";
    // for (int i = 0; i < distanceL; i++) {
    //     str += "L";
    // }
    // str += " | ";
    // for (int i = 0; i < distanceR; i++) {
    //     str += "R";
    // }
    // Serial.println(str);

    float distanceDelta = distanceL - distanceR;

    if (rightIsFree()) {
        Serial.println("__________>>>>>");
        moveForward(distanceDelta);
        delay(100);
        movement.turnRight(90, 0.0);
        delay(100);
        moveForward(distanceDelta);
        delay(100);
    }
    else if (frontIsFree())
    {
        Serial.println("_____|||||_____");
        moveForward(distanceDelta);
        delay(200);
    }
    else if (leftIsFree())
    {
        Serial.println("<<<<<__________");
        movement.turnLeft(90, 0.0);
        delay(300);
    }
    else {
        Serial.println("_______________");
        movement.turnLeft(90, 0.0);
        delay(600);
    }
    
    movement.stop();
    delay(250);
    
}

void Robot::moveForward(float distanceDelta) {
    if (abs(distanceDelta) > 1) {
        if (abs(distanceDelta) < 6) {
            float kp = 2;
            float ki = 0    	;
            distanceDeltaIntegrator = distanceDeltaIntegrator + distanceDelta;
            delta = (distanceDelta * kp) + (distanceDeltaIntegrator * ki);
            // Serial.println("distanceDeltaIntegrator: " + (String) distanceDeltaIntegrator);
            // Serial.println("delta: " + (String) delta);
        }
        else if (distanceDelta > 0)
        {
            // Serial.println("turnLeft: " + (String)distanceDelta);
            movement.turnLeft(90, 0);
            delay(100);
            movement.stop();
        }
        else {
            // Serial.println("turnRight: " + (String)distanceDelta);
            movement.turnRight(90, 0);
            delay(100);
            movement.stop();
        }
    }

    movement.forward(90, delta);
}