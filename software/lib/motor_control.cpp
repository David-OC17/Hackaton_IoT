/*
Some of the code functions in the library where taken from from:
https://github.com/ParzivalStark/TallerIRS by ParzivalStark
and
https://www.instructables.com/Arduino-Flashlight-Following-Robot/ by joesinstructables

Due credit to them for their work.
*/

#include <Arduino.h>

// Motor A
int enA = 11;
int in1 = 12;
int in2 = 13;

// Motor B
int enB = 9;
int in3 = 10;
int in4 = 8;

char option = '9';

void moveForward(int speed){
  analogWrite(enA, speed);
  analogWrite(enB, speed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveLeft  (int speed){
  analogWrite(enA, speed);
  analogWrite(enB, speed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveRight(int speed){
  analogWrite(enA, speed);
  analogWrite(enB, speed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward(int speed){
  analogWrite(enA, speed);
  analogWrite(enB, speed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}