/**************************************************************************
 * Motor Control Library
 * Author: David Ortiz Cota
 * Date: 10/27/2023
 * 
 * Description:
 * This file contains useful functions for controlling the two motors of the robot. 
 * It utilizes a struct for each motor and provides functions for simple robot 
 * translation and rotation.
 * 
 * Credits:
 * Some of the code functions in this library were adapted from the following sources:
 * - https://github.com/ParzivalStark/TallerIRS by ParzivalStark
 * - https://www.instructables.com/Arduino-Flashlight-Following-Robot/ by joesinstructables
 * Proper credit goes to them for their code.
 **************************************************************************/

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

struct motor {
    int en;
    int in1;
    int in2;

    // Constructor for the motor struct
    motor(int enValue, int in1Value, int in2Value) {
        en = enValue;
        in1 = in1Value;
        in2 = in2Value;
    }
};

void moveForward(int speed, motor motorX, motor motorY);

void moveLeft(int speed, motor &motorA, motor &motorB);

void moveRight(int speed, motor &motorA, motor &motorB);

void moveBackward(int speed, motor &motorA, motor &motorB);

void stop(motor &motorA, motor &motorB);


///////// Common distance movement and rotations /////////

// The rotation direction is considered looking the robot from above
void rotate90(char direction, motor &motorA, motor &motorB);

void rotate180(motor &motorA, motor &motorB);

// Moves an estimate of the length of the robot to the front
void moveOneRobotLength(motor &motorA, motor &motorB);

void moveHalfRobotLength(motor &motorA, motor &motorB);

#endif //MOTOR_CONTROL_H