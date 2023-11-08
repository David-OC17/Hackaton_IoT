/*
In order to be able to compile and test using Arudino IDE, use this script.
This is simply the sensor testing files all into one, facilitating compiling.
*/

#include <Arduino.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    START -> sensor_readings.h                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////

struct ultrasonic{
    long duration; // Time the sound took to come back
    long distance; // Either in milimeters or inches
    const int pin;

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

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    END -> sensor_readings.h                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    START -> sensor_readings.cpp                                //
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    END -> sensor_readings.cpp                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    START -> sensor_testing.cpp                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////

///////// Ultrasonic sensors configuration /////////
ultrasonic U_sensorLeft(0, 0, 2);
ultrasonic U_sensorFront(0, 0, 3);
ultrasonic U_sensorRight(0, 0, 4);

ultrasonicSensors U_sensors(U_sensorLeft, U_sensorFront, U_sensorRight);

void setup() {
    Serial.begin(9600); // Check for the particual baud rate of your microcontroller
}

void loop(){
    ///////// Ultrasonic sensors /////////
    readUltrasonic(U_sensors.center);
    Serial.print(U_sensors.center.distance);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    END -> sensor_testing.cpp                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////