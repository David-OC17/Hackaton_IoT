/**************************************************************************
 * Navigation Library
 * Author: David Ortiz Cota
 * Date: 10/27/2023
 * 
 * Description:
 * This file includes useful functions for guiding the robot through a maze.
 **************************************************************************/

#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <Arduino.h>
#include "motor_control.h"
#include "sensor_readings.h"
#include "blynk_cloud.h"

bool exploreLeft(motor &motorA, motor &motorB, ultrasonicSensors &U_sensors, int minDistanceFront);

bool exploreRight(motor &motorA, motor &motorB, ultrasonicSensors &U_sensors, int minDistanceFront);

// Return true if any of the explorations where successful, else return false
bool lookForSideOpening(char firstRotation, motor &motorA, motor &motorB, ultrasonicSensors &U_sensors, int minDistanceFront);

#endif //NAVIGATION_H