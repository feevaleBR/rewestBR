#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
#include <string>
#include <time.h>
#include <thread>
#include <Sensors.hpp>
#include <chrono>

int main(void);

void stopApp(int signal);
void requestSensorsData(int signal);

#endif    //_MAIN_H_
