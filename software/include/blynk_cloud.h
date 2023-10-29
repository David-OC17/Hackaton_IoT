/**************************************************************************
 * Blynk Cloud Connection
 * Author: David Ortiz Cota
 * Date: 10/28/2023
 * 
 * Description:
 * This file contains the necessary definitions and functions to establish
 * a connection with the Blynk Cloud. It provides a function for updating
 * the robot's exploration report.
 **************************************************************************/

#ifndef BLYNK_CLOUD_H
#define BLYNK_CLOUD_H

// Contains the BLYNK_AUTH_TOKEN, WIFI_NAME and WIFI_PSW to keep them private
#include "passwords.h"

#define BLYNK_TEMPLATE_ID "TMPL2fMCHDDbp"
#define BLYNK_TEMPLATE_NAME "esp8266IOT"
#define BLYNK_AUTH_TOKEN MY_BLYNK_AUTH_TOKEN

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h> // Change for use of ESP8266 instead

char ssid[] = WIFI_NAME;
char pass[] = WIFI_PSW;


// The template is setup to use the virtual pin V255 in order to send the status
// Data can be sent at any moment (do not send more than 10 values per second)

// Use the function Blynk.virtualWrite(pinNum, variable) to pass the data to the cloud

#endif //BLYNK_CLOUD_H