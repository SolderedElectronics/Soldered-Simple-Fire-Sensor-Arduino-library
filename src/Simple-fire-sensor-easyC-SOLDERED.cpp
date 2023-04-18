/**
 **************************************************
 *
 * @file        Simple-fire-sensor-easyC-SOLDERED.cpp
 * @brief       Functions for simple fire sensor.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric & Karlo Leksic @ soldered.com
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
 * @return      Value of IR light sensor in percentage (0 - 100%)
 */
float SimpleFireSensor::getValue()
{
    return (getRawValue() / float(1023) * 100);
}

/**
 * @brief       Function for reading raw value of IR light sensor
 *
 * @return      Raw value of IR light sensor (0 - 1023)
 */
int SimpleFireSensor::getRawValue()
{
    if (!native)
    {
        // Read 2 bytes of raw  data
        char data[2];
        readData(data, 2);

        // Convert it to uint16_t
        uint16_t value = 0;
        value = *(uint16_t *)data;

        // Return converted value
        return value;
    }
    return analogRead(pin);
}

/**
 * @brief       Function for getting raw lower treshold of sensing
 *
 * @return      Raw lower treshold of sensing (0 - 1023)
 */
int SimpleFireSensor::getRawLowerTresh(void)
{
    return treshold_low;
}

/**
 * @brief       Function for getting raw upper treshold of sensing
 *
 * @return      Raw upper treshold of sensing (0 - 1023)
 */
int SimpleFireSensor::getRawUpperTresh(void)
{
    return treshold_high;
}

/**
 * @brief       Function for getting lower treshold of sensing in percentage
 *
 * @return      Upper treshold of sensing (0 - 100 %)
 */
float SimpleFireSensor::getLowerTresh(void)
{
    return (treshold_low / float(1023) * 100);
}

/**
 * @brief       Function for getting upper treshold of sensing in percentage
 *
 * @return      Upper treshold of sensing (0 - 100 %)
 */
float SimpleFireSensor::getUpperTresh(void)
{
    return (treshold_high / float(1023) * 100);
}

/**
 * @brief       Function for setting raw lower treshold of sensing
 *
 * @param       uint16_t _treshold_low - value to set treshold
 */
void SimpleFireSensor::setRawLowerTresh(uint16_t _treshold_low)
{
    treshold_low = _treshold_low;
}

/**
 * @brief       Function for setting raw upper treshold of sensing
 *
 * @param       uint16_t _treshold_high - value to set treshold (0 - 1023)
 */
void SimpleFireSensor::setRawUpperTresh(uint16_t _treshold_high)
{
    treshold_high = _treshold_high;
}

/**
 * @brief       Function for setting upper treshold of sensing in percentage
 *
 * @param       float _treshold_high - value to set treshold (0 - 100%)
 */
void SimpleFireSensor::setUpperTresh(float _treshold_high)
{
    treshold_high = _treshold_high * 0.01 * 1024;
}


/**
 * @brief       Function for setting upper treshold of sensing in percentage
 *
 * @param       float _treshold_low - value to set treshold (0 - 100%)
 */
void SimpleFireSensor::setLowerTresh(float _treshold_low)
{
    treshold_low = _treshold_low * 0.01 * 1024;
}

/**
 * @brief       Function to set threshold value in percentage to turn on the LED
 *
 * @param       float _threshold value in %
 */
void SimpleFireSensor::setThreshold(float _threshold)
{
    // Check if the threshold is the proper value
    if (_threshold < 0 || _threshold > 100)
    {
        return;
    }

    // Convert percentage threshold to raw value and send it
    uint16_t rawThreshold = _threshold * 0.01 * 1024;
    setRawThreshold(rawThreshold);
}

/**
 * @brief       Function to set raw threshold value to turn on the LED
 *
 * @param       uint16_t _threshold from 0 to 1023 (raw)
 */
void SimpleFireSensor::setRawThreshold(uint16_t _treshold)
{
    // Check if the threshold is the proper value
    if (_treshold < 0 || _treshold > 1023)
    {
        return;
    }

    // Convert raw threshold value into 2 bytes for sending
    uint8_t *rawThreshold = (uint8_t *)&_treshold;

    // Send raw threshold
    sendData(rawThreshold, 2);
}
