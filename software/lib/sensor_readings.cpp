/**************************************************************************
 * Libreria para lectura de sensores de robot 
 * Autor: David Ortiz Cota
 * Fecha: 26/10/2023
 * Descripcion:
 * Este archivo contiene una libreria de 
 **************************************************************************/

/*
Some of the code functions in the library where taken from from:
https://github.com/ParzivalStark/TallerIRS by ParzivalStark
and
https://www.instructables.com/Arduino-Flashlight-Following-Robot/ by joesinstructables

Due credit to them for their work.
*/

#include <Arduino.h>

int sensorPinRight = 0; // Right sensor pin
int sensorPinCenter = 1; // Center sensor pin
int sensorPinLeft = 2; // Left sensor pin

int lightReadingRight;
int lightToleranceRight = 1000; // Sensor reading needed to trigger right turn

int lightReadingCenter;
int lightToleranceCenter = 1000; // Sensor reading needed to trigger forward movement

int lightReadingLeft;
int lightToleranceLeft = 1000; // Sensor reading needed to trigger left turn

int readingDelay = 100; // Delay between readings


void loop()
{
// Uncomment the serial print lines for calibration purposes

// Take reading from right sensor
lightReadingRight = analogRead(sensorPinRight);
Serial.print("Right Sensor Reading :");
Serial.println(lightReadingRight);

// Take reading from center sensor
lightReadingCenter = analogRead(sensorPinCenter);
Serial.print("Center Sensor Reading :");
Serial.println(lightReadingCenter);

// Take reading from left sensor
lightReadingLeft = analogRead(sensorPinLeft);
Serial.print("Left Sensor Reading :");
Serial.println(lightReadingLeft);
}