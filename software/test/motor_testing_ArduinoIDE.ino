/*
In order to be able to compile and test using Arudino IDE, use this script.
This is simply the motor testing files all into one, facilitating compiling.
*/

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

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    START -> motor_control.cpp                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////

void moveForward(int speed, motor motorX, motor motorY){
  analogWrite(motorX.en, speed);
  analogWrite(motorY.en, speed);

  digitalWrite(motorX.in1, HIGH);
  digitalWrite(motorX.in2, LOW);

  digitalWrite(motorY.in1, HIGH);
  digitalWrite(motorY.in2, LOW);
}


void moveLeft(int speed, motor &motorA, motor &motorB) {
    analogWrite(motorA.en, speed);
    analogWrite(motorB.en, speed);

    digitalWrite(motorA.in1, HIGH);
    digitalWrite(motorA.in2, LOW);

    digitalWrite(motorB.in1, LOW);
    digitalWrite(motorB.in2, HIGH);
}


void moveRight(int speed, motor &motorA, motor &motorB) {
    analogWrite(motorA.en, speed);
    analogWrite(motorB.en, speed);

    digitalWrite(motorA.in1, LOW);
    digitalWrite(motorA.in2, HIGH);

    digitalWrite(motorB.in1, HIGH);
    digitalWrite(motorB.in2, LOW);
}


void moveBackward(int speed, motor &motorA, motor &motorB) {
    analogWrite(motorA.en, speed);
    analogWrite(motorB.en, speed);

    digitalWrite(motorA.in1, LOW);
    digitalWrite(motorA.in2, HIGH);

    digitalWrite(motorB.in1, LOW);
    digitalWrite(motorB.in2, HIGH);
}


void stop(motor &motorA, motor &motorB) {
    digitalWrite(motorA.in1, LOW);
    digitalWrite(motorA.in2, LOW);

    digitalWrite(motorB.in1, LOW);
    digitalWrite(motorB.in2, LOW);
}


///////// Common distance movement and rotations /////////

// The rotation direction is considered looking the robot from above
void rotate90(char direction, motor &motorA, motor &motorB){
    // Adjust speed and time for the robots to rotate 90 degrees
    if(direction == 'L' || direction == 'l'){
        moveLeft(255, motorA, motorB);
        delay(500);
        stop(motorA, motorB);
    }else if(direction == 'R' || direction == 'r'){
        moveRight(255, motorA, motorB);
        delay(500);
        stop(motorA, motorB);
    }else{
        Serial.print("Not a valid rotation direction.");
    }   
}


void rotate180(motor &motorA, motor &motorB){
    // Rotations are always done counterclokwise
    moveLeft(255, motorA, motorB);
    delay(1000);
    stop(motorA, motorB); 
}


// Moves an estimate of the length of the robot to the front
void moveOneRobotLength(motor &motorA, motor &motorB){
    moveForward(255, motorA, motorB);
    delay(500);
    stop(motorA, motorB);
}


void moveHalfRobotLength(motor &motorA, motor &motorB){
    moveForward(255, motorA, motorB);
    delay(250);
    stop(motorA, motorB);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    END -> motor_control.cpp                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    START -> motor_testing.cpp                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////

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
  
    Serial.begin(9600); // Check for the particual baud rate of your microcontroller
}

void loop(){
    ///// Test one function at a time and adjust values /////

    stop(motorA, motorB);
    delay(2000);

    // moveForward(255, motorA, motorB);
    // delay(2000);

    // moveLeft(255, motorA, motorB);
    // delay(2000);

    // moveRight(255, motorA, motorB);
    // delay(2000);

    // moveBackward(255, motorA, motorB);
    // delay(2000);

    // stop(motorA, motorB);
    // delay(2000);

    // rotate90('L', motorA, motorB);
    // delay(2000);

    // rotate90('R', motorA, motorB);
    // delay(2000);

    // rotate180( motorA, motorB);
    // delay(2000);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    END -> motor_testing.cpp                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////