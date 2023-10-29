/**************************************************************************
 * Navigation Library
 * Author: David Ortiz Cota
 * Date: 10/27/2023
 * 
 * Description:
 * This file includes useful functions for guiding the robot through a maze.
 **************************************************************************/


#include <Arduino.h>
#include "./motor_control.cpp"
#include "./sensor_readings.cpp"
#include "../lib/blynk_cloud.cpp"

bool exploreLeft(motor &motorA, motor &motorB, ultrasonicSensors &U_sensors, int minDistanceFront){
    rotate90('L', motorA, motorB);
    readUltrasonic(U_sensors.right);

    int originalDistance = U_sensors.right.distance;
    readUltrasonic(U_sensors.center);
    
    // Must check right sensor for opening and center for space
    while (originalDistance == U_sensors.right.distance && U_sensors.center.distance > minDistanceFront){
        // Move forward a little
        moveForward(255, motorA, motorB);
        delay(250);
        stop(motorA, motorB);

        // Get new reading up front and to the side
        readUltrasonic(U_sensors.center);
        readUltrasonic(U_sensors.right);
    }
    // When it exists, check if we have found an opening or we face a limit
    // If we found an opening, then true
    // If we face a limit, then false
    bool nextAction = originalDistance != U_sensors.right.distance || U_sensors.center.distance < minDistanceFront ? true : false;

    if(nextAction){
        moveHalfRobotLength(motorA, motorB);
        rotate90('R', motorA, motorB); // Return to center
        // Exit the function, we have found opening and centered to it
        return true;
    }else{
        // We must rotate 180 degrees and explore the other way
        rotate180(motorA, motorB);
        return false;
    }
};

bool exploreRight(motor &motorA, motor &motorB, ultrasonicSensors &U_sensors, int minDistanceFront){
    rotate90('R', motorA, motorB);
    readUltrasonic(U_sensors.right);

    int originalDistance = U_sensors.left.distance;
    readUltrasonic(U_sensors.center);
    
    // Must check right sensor for opening and center for space
    while (originalDistance == U_sensors.left.distance && U_sensors.center.distance > minDistanceFront){
        // Move forward a little
        moveForward(255, motorA, motorB);
        delay(250);
        stop(motorA, motorB);

        // Get new reading up front and to the side
        readUltrasonic(U_sensors.center);
        readUltrasonic(U_sensors.left);
    }
    // When it exists, check if we have found an opening or we face a limit
    // If we found an opening, then true
    // If we face a limit, then false
    bool nextAction = originalDistance != U_sensors.left.distance || U_sensors.center.distance < minDistanceFront ? true : false;

    if(nextAction){
        moveHalfRobotLength(motorA, motorB);
        rotate90('L', motorA, motorB); // Return to center
        // Exit the function, we have found opening and centered to it
        return true;
    }else{
        // We must rotate 180 degrees and explore the other way
        rotate180(motorA, motorB);
        return false;  // Return to call the explore on the other side of the maze
    }
};

// Return true if any of the explorations where successful, else return false
bool lookForSideOpening(char firstRotation, motor &motorA, motor &motorB, ultrasonicSensors &U_sensors, int minDistanceFront){
    // Rotates to the desired side, explores until it finds a side opening and returns the robot to center
    // If it does not find an opening on that side, rotates 180 and explores to the other end
    // If no opening is found, an error is printed to serial monitor

    bool exploreDirections[2] = {false, false}; // Have not explored either way --> {left, right}
    bool explorationSuccess[2] = {false, false}; // Explore right and left report if their search was successful

    while(!exploreDirections[0] || !exploreDirections[1]){
        if(firstRotation == 'L' && !exploreDirections[0]){
            explorationSuccess[0] =  exploreLeft(motorA, motorB, U_sensors, minDistanceFront);
            exploreDirections[0] = true;
        }else if(!exploreDirections[1]){
            explorationSuccess[1] = exploreLeft(motorA, motorB, U_sensors, minDistanceFront);
            exploreDirections[1] = true;
        }else{
            stop(motorA, motorB);
            //Serial.print("Explored both sides!");
            Blynk.virtualWrite(V1, "Explored both sides!");
        }
    }

    // Check if any of the two explorations was successful
    if (!explorationSuccess[0] && !explorationSuccess[1]){
        //Serial.print("No valid path found!");
        Blynk.virtualWrite(V1, "No valid path found!");
        
    }else if(explorationSuccess[0]){
        //Serial.print("Left exploration successful! Continuining with path.");
        Blynk.virtualWrite(V1, "Left exploration successful! Continuining with path.");
        return true;

    }else if(explorationSuccess[1]){
        //Serial.print("Right exploration successful! Continuining with path.");
        Blynk.virtualWrite(V1, "Right exploration successful! Continuining with path.");
        return true;

    }else {
        //Serial.print("Error after exploration.");
        Blynk.virtualWrite(V1, "Error after exploration.");
        return false;
    }
}    
