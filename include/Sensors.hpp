#ifndef _SENSORS_H_
#define _SENSORS_H_

#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Arduino.hpp>
#include <Types.hpp>

class SENSOR{
public:
  SENSOR(int8 deviceID, Uint8 numBytes);
  ~SENSOR(void);

  float readData(void);

  bool checkConnection(void);
  bool isConnected(void);
  float getLastData(void);
  time_t dateOfLastData(void);

private:
    int8 ID;
    time_t lastDataDate;
    bool connected;
    float data;
    Uint8 readNumBytes;
};

extern SENSOR Temperature;
extern SENSOR Wind;
extern SENSOR Humidity;

#endif      //_SENSORS_H_
