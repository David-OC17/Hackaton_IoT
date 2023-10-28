/**************************************************************************
 * Libreria para control de motores
 * Autor: David Ortiz Cota
 * Fecha: 27/10/2023
 * 
 * Descripcion:
 * Este archivo contiene funciones útiles para el control de los dos motores
 * del robot. Se utiliza un struct para cada motor, y funciones para
 * traslación y roatación sencilla del robot.
 * 
 * Credits:
 * Some of the code functions in the library where taken from from:
 * https://github.com/ParzivalStark/TallerIRS by ParzivalStark
 * and
 * https://www.instructables.com/Arduino-Flashlight-Following-Robot/ by joesinstructables
 * Due credit to them for their work.
 **************************************************************************/

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