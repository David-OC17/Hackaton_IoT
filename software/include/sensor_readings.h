/**************************************************************************
 * Sensor Reading Library
 * Author: David Ortiz Cota
 * Date: 10/26/2023
 * 
 * Description:
 * This file contains useful functions for reading two types of sensors:
 * photoresistors and ultrasonic sensors.
 * 
 * Credits:
 * Some of the code functions in the library were inspired by:
 * https://github.com/ParzivalStark/TallerIRS by ParzivalStark
 * and
 * https://www.instructables.com/Arduino-Flashlight-Following-Robot/ by joesinstructables
 * Proper credit goes to them for their code.
 **************************************************************************/

#ifndef SENSOR_READINGS_H
#define SENSOR_READINGS_H

#include <Arduino.h>

//////////////////// Infrared photodiode ////////////////////

struct infraredPhotodiode{
    int pin; // Analog pin number
    int value; // Value of the reading
};

// Compare the readings of both the diodes, return which has the heighest reading
char maxIntensityInfraredPhotoDiode(infraredPhotodiode diodeA, infraredPhotodiode diodeB);

//////////////////// Light resistances ////////////////////

struct lightSensors {
    int right;
    int center;
    int left;

    // Parameterized constructor
    lightSensors(int rightVal, int centerVal, int leftVal)
        : right(rightVal), center(centerVal), left(leftVal) {
    }
};

struct lightReadings {
    int right;
    int center;
    int left;

    // Parameterized constructor
    lightReadings(int rightVal, int centerVal, int leftVal)
        : right(rightVal), center(centerVal), left(leftVal) {
    }
};

struct lightTolerances {
    int right;
    int center;
    int left;

    // Parameterized constructor
    lightTolerances(int rightVal, int centerVal, int leftVal)
        : right(rightVal), center(centerVal), left(leftVal) {
    }
};

/*
maxIntensityLight

Toma 3 lecturas para las 3 fotoresistencias
Regresa un valor entre 0 y 2:
    0 --> izquierda mayor intensidad
    1 --> centro mayor intensidad
    2 --> derecha mayor intensidad
Solamente regresa un valor válido si existe mínimo una resistencia con una lectura
mayor la mínimo.
*/
int maxIntensityLight(lightSensors &sensors, lightReadings &readings);

//////////////////// Ultrasonic sensors ////////////////////
struct ultrasonic{
    long duration; // Time the sound took to come back
    long distance; // Either in milimeters or inches
    const int pin;
    // const int trigger; // We may not use a trigger pin by switching the state of the pin input <--> output

    ultrasonic(long durationVal, long distanceVal, int pinVal)
        : duration(durationVal), distance(distanceVal), pin(pinVal){
    }
};

struct ultrasonicSensors{
    ultrasonic left;
    ultrasonic center;
    ultrasonic right;

    ultrasonicSensors(ultrasonic &rightSensor, ultrasonic &centerSensor, ultrasonic &leftSensor)
        : right(rightSensor), center(centerSensor), left(leftSensor) {
    }
};

long microsecondsToInches(long microseconds);

long microsecondsToMillimeters(long microseconds);

// Turn the sensor on, get a reading, convert time into distance
void readUltrasonic(ultrasonic &U_sensor);

#endif //SENSOR_READINGS_H