/**
 **************************************************
 *
 * @file        Simple-fire-sensor-easyC-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/

#ifndef _SIMPLE_FIRE_SENSOR_EASYC_
#define _SIMPLE_FIRE_SENSOR_EASYC_

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.h"

#define R 10000

class SimpleFireSensor : public SIMPLE_FIRE_SENSOR_EASYC::EasyC
{
  public:
    SimpleFireSensor();
    SimpleFireSensor(int);
    uint16_t getValue(void);
    uint16_t lowerTresh(void);
    uint16_t upperTresh(void);
    void setLowerTresh(uint16_t);
    void setuppertresh(uint16_t);

  protected:
    void initializeNative();

  private:
    int pin;
    uint16_t treshold_low = 256, treshold_high = 768;
    char raw[2];
};

#endif
