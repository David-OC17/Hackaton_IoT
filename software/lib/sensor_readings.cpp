/**************************************************************************
 * Libreria para lectura de sensores
 * Autor: David Ortiz Cota
 * Fecha: 26/10/2023
 * 
 * Descripcion:
 * Este archivo contiene funciones útiles para la lectura de dos tipos de 
 * sensores, fotoresistencias y sensores ultrasónicos.
 * 
 * Credits:
 * Some of the code functions in the library where taken from from:
 * https://github.com/ParzivalStark/TallerIRS by ParzivalStark
 * and
 * https://www.instructables.com/Arduino-Flashlight-Following-Robot/ by joesinstructables
 * Due credit to them for their work.
 **************************************************************************/

#include <Arduino.h>

//////////////////// Light resistances ////////////////////

struct lightSensors {
    int lightSensorPinRight;
    int lightSensorPinCenter;
    int lightSensorPinLeft;

    // Parameterized constructor
    lightSensors(int right, int center, int left)
        : lightSensorPinRight(right), lightSensorPinCenter(center), lightSensorPinLeft(left) {
    }
};

struct lightReadings {
    int lightReadingRight;
    int lightReadingCenter;
    int lightReadingLeft;

    // Parameterized constructor
    lightReadings(int right, int center, int left)
        : lightReadingRight(right), lightReadingCenter(center), lightReadingLeft(left) {
    }
};

struct lightTolerances {
    int lightToleranceRight;
    int lightToleranceCenter;
    int lightToleranceLeft;

    // Parameterized constructor
    lightTolerances(int right, int center, int left)
        : lightToleranceRight(right), lightToleranceCenter(center), lightToleranceLeft(left) {
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
int maxIntensityLight(lightSensors &sensors, lightReadings &readings, lightTolerances &tolerances) {
    readings.lightReadingRight = analogRead(sensors.lightSensorPinRight);
    readings.lightReadingCenter = analogRead(sensors.lightSensorPinCenter);
    readings.lightReadingLeft = analogRead(sensors.lightSensorPinLeft);

    if (readings.lightReadingRight > readings.lightReadingCenter && readings.lightReadingRight > readings.lightReadingLeft) {
        return 0; // Right has the highest intensity
    }
    else if (readings.lightReadingCenter > readings.lightReadingRight && readings.lightReadingCenter > readings.lightReadingLeft) {
        return 1; // Center has the highest intensity
    }
    else {
        return 2; // Left has the highest intensity (or they are equal)
    }
}

//////////////////// Ultrasonic sensors ////////////////////
struct ultrasonic{
    long duration;
    long distance; // Either in milimeters or inches
    const int pin;

    ultrasonic(long durationVal, long distanceVal, int pinVal)
        : duration(durationVal), distance(distanceVal), pin(pinVal){
    }
};

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