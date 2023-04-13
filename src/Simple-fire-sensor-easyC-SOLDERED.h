/**
 **************************************************
 *
 * @file        Simple-fire-sensor-easyC-SOLDERED.h
 * @brief       Header file for simple fire sensor.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric & Karlo Leksic @ soldered.com
 ***************************************************/

#ifndef _SIMPLE_FIRE_SENSOR_EASYC_
#define _SIMPLE_FIRE_SENSOR_EASYC_

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

#define R 10000

class SimpleFireSensor : public EasyC
{
  public:
    SimpleFireSensor();
    SimpleFireSensor(int);
    float getValue(void);
    uint16_t getRawValue(void);
    float getLowerTresh(void);
    float getUpperTresh(void);
    uint16_t getRawLowerTresh(void);
    uint16_t getRawUpperTresh(void);
    void setUpperTresh(float);
    void setLowerTresh(float);
    void setRawLowerTresh(uint16_t);
    void setRawUpperTresh(uint16_t);
    void setThreshold(float);
    void setRawThreshold(uint16_t);

  protected:
    void initializeNative();

  private:
    int pin;
    uint16_t treshold_low = 256, treshold_high = 768;
    byte data[2], threshold;
    uint16_t resistance;
};

#endif
