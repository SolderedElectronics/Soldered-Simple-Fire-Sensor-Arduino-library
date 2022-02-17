/**
 **************************************************

    @file        Read_values_easyC.ino
    @brief       Example for using the digital and analog read functions for Simple fire sensor with easyC


  	product: www.solde.red/333077

    @authors     Goran Juric for Soldered.com
 ***************************************************/

#include "Simple-fire-sensor-easyC-SOLDERED.h"

// Declare the sensor object
SimpleFireSensor sensor;

void setup()
{
  // Initialize the serial communication via UART
  Serial.begin(115200);

  // Initialize the sensor
  sensor.begin();

  sensor.setLowerTresh(850); // You should set these two values, this is value when fire is present (you can use lighter at 1m distance)
  sensor.setUpperTresh(1000); // This is value when no fire is present
}

void loop()
{

  Serial.print("IR light sensor reading: "); // Print information message
  Serial.println(sensor.getValue());  // Prints percent value of fire sensor
  
  //This function checks to which value is closer value that has been read from sensor
  if (abs(sensor.getValue() - sensor.lowerTresh()) < abs(sensor.getValue() - sensor.upperTresh()))
  {
    Serial.println("Fire is detected!!");   //If sensor value is closer to lowerTresh value, fire is present
  }

  else
  {
    Serial.println("Fire is not detected.");    //If sensor value is closer to upperTresh value, fire is present
  }

}
