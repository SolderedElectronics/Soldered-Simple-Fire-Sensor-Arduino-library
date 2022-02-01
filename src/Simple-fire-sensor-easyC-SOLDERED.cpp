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
        readRegister(ANALOG_READ_REG, raw, 2 * sizeof(uint8_t));
        return raw[0] | (raw[1]) << 8;
    }
    return analogRead(pin);
}

uint16_t SimpleFireSensor::lowerTresh(void)
{
    return treshold_low;
}


uint16_t SimpleFireSensor::upperTresh(void)
{
    return treshold_high;
}

/**
 * @brief       Function for reading value of IR light sensor
 *
 * @return      value of IR light sensor
 */
void SimpleFireSensor::setLowerTresh(uint16_t _treshold_low)
{
    treshold_low = _treshold_low;
}

/**
 * @brief       Function for reading value of IR light sensor
 *
 * @return      value of IR light sensor
 */
void SimpleFireSensor::setUpperTresh(uint16_t _treshold_high)
{
    treshold_high = _treshold_high;
}
