#ifndef _ARDUINO_H_
#define _ARDUINO_H_

#include <Serial.hpp>

class ARDUINO{
public:
  ARDUINO(void);
  ~ARDUINO(void);

  UART serialYun;
};

extern ARDUINO Arduino;

#endif    //_ARDUINO_H_
