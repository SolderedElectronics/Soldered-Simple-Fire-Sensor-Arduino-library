/**
 **************************************************

   @file        Read_values.ino
   @brief       Example for using the digital and analog read functions for Simple fire sensor.

                For this example, you will need any Dasduino board, a USB-c cable, and Simple fire sensor.
                Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 

                This example will show you how to read values and detect fire using the sensor. 
                Connect the Simple sensor to the Dasduino and upload the code.
                Open the Serial Monitor at 115200 baud rate to see the analog values. 
                You can use a lighter to set the fire threshold. 

  product: www.solde.red/333079

   @authors     Goran Juric for Soldered.com
 ***************************************************/

// Connecting diagram
//
// Breakout      Arduino
//  |-------------|
// D0------------D9
// A0------------A0
// GND-----------GND
// VCC-----------5V

#include "Simple-fire-sensor-easyC-SOLDERED.h"

#define ANALOG_PIN  A0 // Pin for analog read
#define DIGITAL_PIN 9  // Pin for digital read

// Declare the sensor object and set pin on which sensor is connected
SimpleFireSensor sensor(ANALOG_PIN);

void setup()
{
    // Initialize the serial communication via UART
    Serial.begin(115200);

    // Initialize the sensor
    sensor.begin();
}

void loop()
{
    Serial.print("IR light sensor reading: "); // Print information message
    Serial.print(sensor.getValue());           // Prints percent value of fire sensor
    Serial.print("% ");
    Serial.println(sensor.getRawValue()); // Prints raw value of fire sensor

    if (digitalRead(DIGITAL_PIN)) // Potentiometer on breakout board is used to
                                  // set treshold value. This function checks if
                                  // treshold value is passed and determines if there
                                  // is a fire nearby.
    {
        Serial.println("Fire is not detected.");
    }

    else
    {
        Serial.println("Fire is detected!!");
    }

    // You can also use thresholds (except threshold for LED) like in Read_values_easyC example to detect fire.

    // Wait a bit before next reading
    delay(200);
}
