/**************************************************************************
 * Main Script
 * Author: David Ortiz Cota
 * Date: 10/28/2023
 * 
 * Description:
 * This file contains the central implementation for guiding the robot
 * through the maze.
 **************************************************************************/


#include <Arduino.h>
#include "../include/motor_control.h"
#include "../include/navigation.h"
#include "../include/sensor_readings.h"
#include "../include/blynk_cloud.h"

//////////////////// Pin configuration ////////////////////

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

///////// Light resistance configuration /////////
// Set up the sensor pins, the readings variables, and the tolerances for each sensor
// Change these values as needed**
lightSensors L_sensors(2, 3, 4);
lightReadings L_readings(0, 0, 0);
lightTolerances L_tolerances(1000, 1000, 1000); 

///////// Ultrasonic sensors configuration /////////
ultrasonic U_sensorLeft(0, 0, 5);
ultrasonic U_sensorFront(0, 0, 6);
ultrasonic U_sensorRight(0, 0, 7);

ultrasonicSensors U_sensors(U_sensorLeft, U_sensorFront, U_sensorRight);

// Initialize variables for the control and decision making
int minDistanceFront = 50; // Milimiters
bool moveForwardLock = false;


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
    delay(1500);

    // Start the Blynk connection to cloud
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


/*
1. Check which of the light sensors is the highest
  1.1 Rotate as needed so the front of the robot faces forward

2. Check the path to the front
  A. If it is clear, move until it is not
  B. If not clear, check which of the two sides has most clearance
    B.1 Rotate towards that side
    B.2 Move towards that side, looking for an opening on the side
      B.2.b If opening is found, rotate forward and repeat from step 1
      B.2.b If opening not found, rotate 180 degrees and look for new opening
*/

void loop(int minDistanceFront, bool moveForwardLock) {
  Blynk.run();
  Blynk.virtualWrite(V1, "New exploration step!");

  if(!moveForwardLock){
    int lightSensor = maxIntensityLight(L_sensors, L_readings);

    // Initial correction to look forward - check the time needed for the robot to rotate 90 degrees
    if (lightSensor == 0) {
      // Right sensor has the highest intensity
      rotate90('L', motorA, motorB);
    }
    else if (lightSensor == 2) {
      // Left sensor has the highest intensity (or they are equal)
      rotate90('R', motorA, motorB);
    }// else the robot is already centered

    // Now, you are facing forward. Check the path to the front.
    readUltrasonic(U_sensorFront);
    while(U_sensorFront.distance > minDistanceFront){
      // Path is clear, move forward
        moveForward(255, motorA, motorB);
        delay(250); // Time to move forward
        stop(motorA, motorB);
    }

    // The path is no longer clear, rotate to look for new path
    readUltrasonic(U_sensorLeft);
    readUltrasonic(U_sensorRight);
    char rotate = U_sensorRight.distance >= U_sensorLeft.distance ? 'L' : 'R'; // Determine which side to explore first
    bool moveForwardLock =  lookForSideOpening(rotate, motorA, motorB, U_sensors, minDistanceFront);

    // We take the lock and use it to determine if we should stop the robot completelly or to continue with the next loop iteration
  }else{ // Do not move further if no path was found
    stop(motorA, motorB);
    //Serial.print("Error after exploration, no path found.");
    Blynk.virtualWrite(V1, "Error after exploration, no path found.");
  }
}