/**************************************************************************
 * Libreria para navegación
 * Autor: David Ortiz Cota
 * Fecha: 27/10/2023
 * 
 * Descripcion:
 * Este archivo contiene funciones útiles para la navegación del roboto
 * dentro del laberinto.
 **************************************************************************/

#include <Arduino.h>
#include "./motor_control.cpp"
#include "./sensor_readings.cpp"

void exploreLeft(){

};

void lookForSideOpening(char firstRotation, motor &motorA, motor &motorB, ultrasonicSensors &U_sensors, int minDistanceFront){
    // Rotates to the desired side, explores until it finds a side opening and returns the robot to center
    // If it does not find an opening on that side, rotates 180 and explores to the other end
    // If no opening is found, an error is printed to serial monitor

    if(firstRotation == 'L'){
        rotate90(firstRotation, motorA, motorB);
        readUltrasonic(U_sensors.right);

        int originalDistance = firstRotation == 'L' || firstRotation == 'R' ? U_sensors.right.distance : U_sensors.left.distance;
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
        }else{
            // We must rotate 180 degrees and explore the other way
            rotate180(motorA, motorB);
        }
        
    }
    
    
    
    
    else if(firstRotation == 'R'){
        rotate90(firstRotation, motorA, motorB);
        readUltrasonic(U_sensors.left);
    }else{
        Serial.print("Not a valid rotation direction.");
    }

    int originalDistance = firstRotation == 'L' || firstRotation == 'R' ? U_sensors.right.distance : U_sensors.left.distance;
    readUltrasonic(U_sensors.center);

    // While the front is clear and we have not found an opening, continue exploring
    while (originalDistance == U_sensor.distance)
    {
        /* code */
    }
    


    
}
