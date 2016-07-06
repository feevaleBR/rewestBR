#include <Sensors.hpp>

using namespace std;

#define DISCONNECTED_SENSOR_DATA -999
#define WAIT_ANSWER_TIME_SEC 2

SENSOR Temperature(0x21, 6);
SENSOR Humidity(0x22,6);
SENSOR Wind(0x23,6);

SENSOR::SENSOR(int8 deviceID, Uint8 numBytes){
  this->ID = deviceID;
  this->connected = false;
  this->lastDataDate = 0;
  this->data = DISCONNECTED_SENSOR_DATA;
  this->readNumBytes = numBytes;
}

SENSOR::~SENSOR(void){

}

float SENSOR::readData(void){
  int8 receiveBuff[10];

  memset(receiveBuff,0,sizeof(receiveBuff));

  if(Arduino.serialYun.isOpen()){
    Arduino.serialYun.sendData(&this->ID, sizeof(this->ID), 0);
    sleep(WAIT_ANSWER_TIME_SEC);
    Arduino.serialYun.readData(receiveBuff, this->readNumBytes, 0);  //5 for testing because "22.01"

    this->data = atof(receiveBuff);

    //std::cout << "data = " << this->data << "\n";
  }
  return this->data;
}

bool SENSOR::checkConnection(void){
  this->data = this->readData();

  if (data == DISCONNECTED_SENSOR_DATA){
    this->connected = false;
  }else{
    this->connected = true;
  }
  return this->connected;
}

bool SENSOR::isConnected(void){
  return this->connected;
}

float SENSOR::getLastData(void){
  return this->data;
}

time_t SENSOR::dateOfLastData(void){
  return this->lastDataDate;
}
