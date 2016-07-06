#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <Types.hpp>
#include <string.h>
#include <stdio.h>

typedef enum{
  NOT_OPEN_SERIAL = -1000,
  BUFFER_NULL_SERIAL,
  SERIAL_SUCCESS = 0
}SERIAL_ERROR;

//CONFIGURE THE UART
//The flags (defined in /usr/include/termios.h - see http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
//	Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
//	CSIZE:- CS5, CS6, CS7, CS8
//	CLOCAL - Ignore modem status lines
//	CREAD - Enable receiver
//	IGNPAR = Ignore characters with parity errors
//	ICRNL - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
//	PARENB - Parity enable
//	PARODD - Odd parity (else even)

class UART{
public:
  //Constructors and deconstructors of class
  UART(speed_t serialBaudRate, int8 *pPort);
  ~UART(void);

  //Class used to start UART
  SERIAL_ERROR initialize(void);
  //Class used to close UART
  int16 stop(void);
  bool isOpen(void);

  SERIAL_ERROR readData(int8 *pDestBuff, Uint8 size, Uint8 startPos);
  SERIAL_ERROR sendData(int8 *pSourceBuff, Uint8 size, Uint8 startPos);
private:
  int serialHandle;
  speed_t baudRate;
  int8 *pPortComm;
  bool portIsOpen;
};

#endif //_SERIAL_H_
