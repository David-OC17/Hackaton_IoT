#include <Arduino.h>
#include "../lib/motor_control.cpp"
#include "../lib/sensor_readings.cpp"

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

///////// Ultrasonic sensor configuration /////////
ultrasonic U_sensor(0, 0, 5);


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

void loop() {
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

  int lightSensor = maxIntensityLight(lightSensorsObj, lightReadingsObj, lightTolerancesObj);

  if (lightSensor == 0) {
    // Right sensor has the highest intensity
    // Rotate so the front of the robot faces forward
    // Implement the rotation logic here
  }
  else if (lightSensor == 1) {
    // Center sensor has the highest intensity
    // Rotate so the front of the robot faces forward
    // Implement the rotation logic here
  }
  else if (lightSensor == 2) {
    // Left sensor has the highest intensity (or they are equal)
    // Rotate so the front of the robot faces forward
    // Implement the rotation logic here
  }

  // Now, you are facing forward. Check the path to the front.
  int frontDistance = readUltrasonic(ultrasonicObj);

  if (frontDistance > someThreshold) {
      // Path is clear, move forward
      moveForward(someSpeed, motorXObj, motorYObj);
  }
  else {
    // Path is not clear, check which side has more clearance
    int leftDistance = readUltrasonic(ultrasonicLeftObj);
    int rightDistance = readUltrasonic(ultrasonicRightObj);

    if (leftDistance > rightDistance) {
      // Rotate towards the left side
      // Implement the rotation logic here
    }
    else {
      // Rotate towards the right side
      // Implement the rotation logic here
    }

    // Move towards that side, looking for an opening
    // Implement the move logic here

    // If opening is found
    if (openingFound) {
      // Rotate forward and repeat from step 1
      // Implement the rotation logic here
    }
    // If opening not found
    else {
      // Rotate 180 degrees
      // Implement the rotation logic here
    }
  }
}