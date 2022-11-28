/**
 **************************************************
 *
 * @file        Simple-fire-sensor-easyC-SOLDERED.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/


#include "Simple-fire-sensor-easyC-SOLDERED.h"

/**
 * @brief                   Default constructor.
 *
 */
SimpleFireSensor::SimpleFireSensor()
{
}

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Pin on which is sensor connected.
 */
SimpleFireSensor::SimpleFireSensor(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void SimpleFireSensor::initializeNative()
{
    pinMode(pin, INPUT);
}

/**
 * @brief       Function for reading value of IR light sensor
 *
 * @return      value of IR light sensor
 */
uint16_t SimpleFireSensor::getValue()
{
    if (!native)
    {
        Wire.beginTransmission(address);
        Wire.requestFrom(address, 2);

        if (Wire.available())
        {
            Wire.readBytes(data, 2);
        }
        Wire.endTransmission();

        resistance = *(uint16_t *)data;
        return resistance;
    }
    return analogRead(pin);
}

/**
 * @brief       Function for setting lower treshold of sensing
 *
 * @return      lower treshold of sensing
 */
uint16_t SimpleFireSensor::lowerTresh(void)
{
    return treshold_low;
}

/**
 * @brief       Function for setting upper treshold of sensing
 *
 * @return      upper treshold of sensing
 */
uint16_t SimpleFireSensor::upperTresh(void)
{
    return treshold_high;
}

/**
 * @brief       Function for setting lower treshold of sensing
 *
 * @param       uint16_t _treshold_low - value to set treshold
 */
void SimpleFireSensor::setLowerTresh(uint16_t _treshold_low)
{
    treshold_low = _treshold_low;
}

/**
 * @brief       Function for setting upper treshold of sensing
 *
 * @param       uint16_t _treshold_high - value to set treshold
 */
void SimpleFireSensor::setUpperTresh(uint16_t _treshold_high)
{
    treshold_high = _treshold_high;
}

/**
 * @brief       Function to set threshold value to turn on the LED
 * 
 * @param       byte _threshold value in %
*/
void SimpleFireSensor::setThreshold(byte _threshold)
{
    if(_threshold > 100)
    {
        return;
    }
    threshold = _threshold;
    Wire.beginTransmission(address);
    Wire.write(threshold);
    Wire.endTransmission();
}
