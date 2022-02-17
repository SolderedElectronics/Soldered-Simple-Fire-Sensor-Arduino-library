/**
 **************************************************

   @file        Read_values.ino
   @brief       Example for using the digital and analog read functions for Simple fire sensor


 	product: www.solde.red/333079

   @authors     Goran Juric for Soldered.com
 ***************************************************/

//Connecting diagram
//
//Breakout      Arduino
//|-------------|
//D0------------D9
//A0------------A0
//GND-----------GND
//VCC-----------5V

#include "Simple-fire-sensor-easyC-SOLDERED.h"

#define ANALOG_PIN A0       //Pin for analog read
#define DIGITAL_PIN 9       //Pin for digital read

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


  Serial.print("IR light sensor reading: "); 	// Print information message
  Serial.println(sensor.getValue());  			// Prints percent value of fire sensor

  if (digitalRead(DIGITAL_PIN))					//Potentiometer on breakout board is used to
    //set treshold value. This function checks if
    //treshold value is passed and determines if there
    //is a fire nearby.
  {
    Serial.println("Fire is not detected.");
  }

  else
  {
    Serial.println("Fire is detected!!");
  }
  delay(1000);

}
