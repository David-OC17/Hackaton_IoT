/*
In order to be able to compile and test using Arudino IDE, use this script.
This is simply the sensor testing files all into one, facilitating compiling.
*/

#include <Arduino.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    START -> sensor_readings.h                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    END-> sensor_readings.h                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    START -> sensor_readings.cpp                                //
////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    END -> sensor_readings.cpp                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    START -> sensor_testing.cpp                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////

///////// Light resistance configuration /////////
lightSensors L_sensors(2, 3, 4); // Assign pin 2, 3 and 4
lightReadings L_readings(0, 0, 0); // Values start at zero
lightTolerances L_tolerances(1000, 1000, 1000); // Tolerance for activation

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
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    END-> sensor_testing.cpp                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////