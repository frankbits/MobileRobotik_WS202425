#include "Robot.h"

const int Robot::THRESHOLD_FREE_F = 5;
const int Robot::THRESHOLD_FREE_L = 5;
const int Robot::THRESHOLD_FREE_R = 5;

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
    if(frontIsFree()){
        movement.forward(1, 0.0);
        return;
    }
    if(rightIsFree() && !frontIsFree()){
        movement.turnRight(1, 0.0);
        return;
    }
    if (!rightIsFree() && !frontIsFree()) {
        movement.turnLeft(1, 0.0);
        return;
    }
}