/**************************************************************************
 * Motor testing
 * Author: David Ortiz Cota
 * Date: 10/28/2023
 * 
 * Description:
 * Use this file for testing purposes. It contains a function to test that
 * both the motors move, and to calibrate the movement of the 
 * robot based on the time delay and signal given to the motors. Use it 
 * to adjust your parameters as needed.
 **************************************************************************/

#include "../include/motor_control.h"

///////// Motor configuration /////////
motor motorA(11, 12, 13);
// int enA = 11;
// int in1 = 12;
// int in2 = 13;

motor motorB(9, 10, 8);
// // Motor B
// int enB = 9;
// int in3 = 10;
// int in4 = 8;

void setup() {
    // Set pin modes for motor A
    pinMode(motorA.en, OUTPUT);
    pinMode(motorA.in1, OUTPUT);
    pinMode(motorA.in2, OUTPUT);

    // Set pin modes for motor B
    pinMode(motorB.en, OUTPUT);
    pinMode(motorB.in1, OUTPUT);
    pinMode(motorB.in2, OUTPUT);

    // Set initial states of the pins (stop the robot)
    digitalWrite(motorA.in1, LOW);
    digitalWrite(motorA.in2, LOW);

    digitalWrite(motorB.in1, LOW);
    digitalWrite(motorB.in2, LOW);
  
    Serial.begin(115200); // Check for the particual baud rate of your microcontroller
}

void loop(){
    stop(motorA, motorB);
    delay(2000);

    moveForward(255, motorA, motorB);
    delay(2000);

    moveLeft(255, motorA, motorB);
    delay(2000);

    moveRight(255, motorA, motorB);
    delay(2000);

    moveBackward(255, motorA, motorB);
    delay(2000);

    stop(motorA, motorB);
    delay(2000);

    rotate90('L', motorA, motorB);
    delay(2000);

    rotate90('R', motorA, motorB);
    delay(2000);

    rotate180( motorA, motorB);
    delay(2000);
}
