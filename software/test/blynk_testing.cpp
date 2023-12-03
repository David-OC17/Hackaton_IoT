/**************************************************************************
 * Blynk Cloud connection testing
 * Author: David Ortiz Cota
 * Date: 11/07/2023
 * 
 * Description:
 * Use this file to verify that your connection to the Blynk cloud is
 * working as expected and that values are being sent.
 **************************************************************************/

#include "../include/blynk_cloud.h"


void setup() {
    // Start the Blynk connection to cloud
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop(){
    Blynk.run();
    Blynk.virtualWrite(V1, "New exploration step!");

    // Send data to the cloud to see the connection working
    Blynk.virtualWrite(V1, "Test message 1!");
    delay(1000);
    Blynk.virtualWrite(V1, "Test message 2!");
    delay(1000);
    Blynk.virtualWrite(V1, "Test message 3!");
    delay(1000);
    Blynk.virtualWrite(V1, "Test message 4!");
}