/**************************************************************************
 * Blynk cloud connection
 * Autor: David Ortiz Cota
 * Fecha: 28/10/2023
 * 
 * Descripcion:
 * Este archivo contiene las definiciones y funciones necesarias para 
 * generar una conexión con Blynk cloud. Se proporciona una función para
 * actualizar el reporte de exploración del robot.
 **************************************************************************/

// Contains the BLYNK_AUTH_TOKEN, WIFI_NAME and WIFI_PSW to keep them private
#include "../lib/passwords.h"

#define BLYNK_TEMPLATE_ID "TMPL2fMCHDDbp"
#define BLYNK_TEMPLATE_NAME "esp8266IOT"
#define BLYNK_AUTH_TOKEN MY_BLYNK_AUTH_TOKEN;

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h> // Change for use of ESP8266 instead

char ssid[] = WIFI_NAME;
char pass[] = WIFI_PSW;

// The template is setup to use the virtual pin V255 in order to send the status
// Data can be sent at any moment (do not send more than 10 values per second)