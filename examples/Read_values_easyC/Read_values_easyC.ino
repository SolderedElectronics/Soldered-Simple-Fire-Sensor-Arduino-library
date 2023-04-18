/**
 **************************************************

    @file        Read_values_easyC.ino
    @brief       Example for using the digital and analog read functions for Simple fire sensor with easyC.

                 For this example, you will need any Dasduino board, a USB-c cable, a Simple fire sensor with easyC, and easyC cable. 
                 Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 
                 Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/

                 This example will show you how to set thresholds for detecting fire, and how to detect fire using
                 the sensor. Connect the Simple sensor to the Dasduino using easyC cable and upload the code.
                 Open the Serial Monitor at 115200 baud rate to see the values. You can use a lighter to see what
                 number you get when there is fire and then enter these values as thresholds. Now is your sensor
                 ready to detect a fire.


    product: www.solde.red/333077

    @authors     Goran Juric & Karlo Leksic for Soldered.com
 ***************************************************/

// Include Soldered library for Simple sensor
// If you don't have a library, get it here: https://github.com/SolderedElectronics/Soldered-Simple-Fire-Sensor-Arduino-library
#include "Simple-fire-sensor-easyC-SOLDERED.h"

// Declare the sensor object
SimpleFireSensor sensor;

void setup()
{
    // Initialize the serial communication via UART
    Serial.begin(115200);

    // Initialize the sensor
    // Start I2C communication on default address (0x30)
    sensor.begin();

    // If you want another I2C address, enter it in the bracket
    // You can set another I2C address (0x31 - 0x37) by changing address switches on the breakout
    // NOTE: You have to restart breakout to apply the address change by unplugging and plugging
    // the easyC or USB-c from the Dasduino 
    // sensor.begin(0x31);

    sensor.setRawLowerTresh(850);  // You should set these two values, this is value when fire is present (you can use
                                   // lighter at 1m distance)
    sensor.setRawUpperTresh(1000); // This is value when no fire is present

    // You can use percentage values by calling following functions:
    // sensor.setLowerTresh(85); // 85%
    // sensor.setUpperTresh(99); // 99%

    // Set threshold for LED on the breakout
    sensor.setRawThreshold(250); // or
    // sensor.setThreshold(25.1); // 25.1%
}

void loop()
{
    Serial.print("IR light sensor reading: "); // Print information message
    Serial.print(sensor.getValue());           // Prints percent value of fire sensor
    Serial.print("% ");
    Serial.println(sensor.getRawValue()); // Prints raw value of fire sensor

    // This function checks to which value is closer value that has been read from sensor
    if (abs(sensor.getValue() - sensor.getLowerTresh()) < abs(sensor.getValue() - sensor.getUpperTresh()))
    // You can also use raw values if you want:
    // if (abs(sensor.getRawValue() - sensor.getRawLowerTresh()) < abs(sensor.getRawValue() - sensor.getRawUpperTresh()))
    {
        Serial.println("Fire is detected!!");
    }
    else
    {
        Serial.println("Fire is not detected.");
    }

    // Wait a bit before next reading
    delay(200);
}
