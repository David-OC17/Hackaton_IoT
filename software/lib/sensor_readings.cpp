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
 * Proper credit goes to them for their contributions.
 **************************************************************************/

#include <Arduino.h>
#include "../include/sensor_readings.h"

//////////////////// Light resistances ////////////////////
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
int maxIntensityLight(lightSensors &sensors, lightReadings &readings) {
    readings.right = analogRead(sensors.right);
    readings.center = analogRead(sensors.center);
    readings.left = analogRead(sensors.left);

    if (readings.right > readings.center && readings.right > readings.left) {
        return 0; // Right has the highest intensity
    }
    else if (readings.center > readings.right && readings.center > readings.left) {
        return 1; // Center has the highest intensity
    }
    else {
        return 2; // Left has the highest intensity (or they are equal)
    }
}

//////////////////// Ultrasonic sensors ////////////////////

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToMillimeters(long microseconds) {
    return microseconds / 2.91;
}

// Turn the sensor on, get a reading, convert time into distance
void readUltrasonic(ultrasonic &U_sensor){
	pinMode(U_sensor.pin, OUTPUT);
	digitalWrite(U_sensor.pin, LOW);
	delayMicroseconds(2);

	digitalWrite(U_sensor.pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(U_sensor.pin, LOW);

	pinMode(U_sensor.pin, INPUT);
	U_sensor.duration = pulseIn(U_sensor.pin, HIGH, 1000000); // pin, mode, timeout

	U_sensor.distance = microsecondsToMillimeters(U_sensor.duration);
}