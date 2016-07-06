#include <Serial.hpp>
#include <iostream>

//Constructor must be filled with baud rate and serial file.
/*
serialBaudRate: B1200, B2400, B4800, B9600, B19200, B38400, B57600,
                B115200, B230400, B460800, B500000, B576000, B921600,
                B1000000, B1152000, B1500000, B2000000, B2500000,
                B3000000, B3500000, B4000000
*/

using namespace std;

UART::UART(speed_t serialBaudRate, int8 *pPort){
  this->baudRate = serialBaudRate;
  this->pPortComm = pPort;
  this->serialHandle = 0;
  this->portIsOpen = false;
}

UART::~UART(void){

}

SERIAL_ERROR UART::initialize(void){
  this->serialHandle = open(pPortComm, O_RDWR | O_NOCTTY | O_NDELAY);   //O_NDELAY

	if(this->serialHandle == -1){
		std::cout << "Open Serial Port: FAIL\n";
		return NOT_OPEN_SERIAL;
	} else{
    std::cout << "Open Serial Port: OK\n";
  }

  struct termios options;
	tcgetattr(serialHandle, &options);
	options.c_cflag = this->baudRate | CS8 | CLOCAL | CREAD;		//<Set baud rate
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(this->serialHandle, TCIOFLUSH);
	tcsetattr(this->serialHandle, TCSANOW, &options);

  this->portIsOpen = true;
  return SERIAL_SUCCESS;
}

int16 UART::stop(void){
  if (this->serialHandle != -1){
      close (serialHandle);
  }
  this->portIsOpen = false;
  return SERIAL_SUCCESS;
}

bool UART::isOpen(void){
  return this->portIsOpen;
}

SERIAL_ERROR UART::readData(int8 *pDestBuff, Uint8 size, Uint8 startPos){
  if (!pDestBuff){
    return BUFFER_NULL_SERIAL;
  }

  if (this->portIsOpen){
    read(this->serialHandle, &pDestBuff[startPos], size);
    #ifdef DEBUG
      //std::cout << "received data = " << pDestBuff << "\n";
    #endif
    //tcflush(this->serialHandle, TCIOFLUSH);
  }

  return SERIAL_SUCCESS;
}


SERIAL_ERROR UART::sendData(int8 *pSourceBuff, Uint8 size, Uint8 startPos){
  if (!pSourceBuff){
    return BUFFER_NULL_SERIAL;
  }

  if (this->portIsOpen){
    write(this->serialHandle, &pSourceBuff[startPos], size);
    #ifdef DEBUG
      //std::cout << "sent data = " << pSourceBuff << "\n";
    #endif
  }

  return SERIAL_SUCCESS;
}
