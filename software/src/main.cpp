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
  // put your main code here, to run repeatedly

  /*
  1. Check which of the light sensors is the highest
    1.1 Rotate as needed so the front of the robot faces forward
      
  2. Check the path to the front
    a. If it is clear, move until it is not
    b. If not clear, check which of the two sides has most clearance
      b.1 Rotate towards that side
      b.2 Move towards that side, looking for an opening on the side


  */
}