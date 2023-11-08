#include "../include/sensor_readings.h"

// Turn the sensor on, get a reading, convert time into distance
void readUltrasonic(ultrasonic &U_sensor);

///////// Light resistance configuration /////////
lightSensors L_sensors(2, 3, 4);
lightReadings L_readings(0, 0, 0);
lightTolerances L_tolerances(1000, 1000, 1000); 

///////// Ultrasonic sensors configuration /////////
// Set all the trigger pins equal
ultrasonic U_sensorLeft(0, 0, 5);
ultrasonic U_sensorFront(0, 0, 6);
ultrasonic U_sensorRight(0, 0, 7);

ultrasonicSensors U_sensors(U_sensorLeft, U_sensorFront, U_sensorRight);

void setup() {
    Serial.begin(115200); // Check for the particual baud rate of your microcontroller
}

void loop(){
    ///////// Light resistance /////////
    // Sense each lightSensor
    L_readings.right = analogRead(L_sensors.right);
    L_readings.center = analogRead(L_sensors.center);
    L_readings.left = analogRead(L_sensors.left);

    Serial.print("Right light: ");
    Serial.println(L_readings.right);

    Serial.print("Center light: ");
    Serial.println(L_readings.center);

    Serial.print("Left light: ");
    Serial.println(L_readings.left);

    // Test the decision of maxIntensityLight
    Serial.print(maxIntensityLight(L_sensors, L_readings));


    ///////// Ultrasonic sensors /////////
    readUltrasonic(U_sensors.center);
    Serial.print(U_sensors.center.distance);
}