#include <Arduino.hpp>

ARDUINO Arduino;

ARDUINO::ARDUINO(void):
serialYun(B115200, const_cast<int8 *>("/dev/ttyATH0"))
{

}

ARDUINO::~ARDUINO(){

}
