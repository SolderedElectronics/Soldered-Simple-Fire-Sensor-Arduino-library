/**
 **************************************************
 *
 * @file        Read_values.ino
 * @brief       Example for using the digital and analog read functions for Simple fire sensor
 *
 *
 *	product: www.solde.red/333079
 *
 * @authors     Goran Juric for Soldered.com
 ***************************************************/

#include "Simple-fire-sensor-easyC-SOLDERED.h"

#define ANALOG_PIN A0
#define DIGITAL_PIN 9

// Declare the sensor object and set pin on which sensor is connected
SimpleLightSensor sensor(ANALOG_PIN);

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
  Serial.println(sensor.getValue());  // Prints percent value of slider potentiometer

  if (digitalRead(DIGITAL_PIN))
  {
    Serial.println("Fire is not detected.");
  }

  else
  {
    Serial.println("Fire is detected!!");
  }
  delay(1000);

}
