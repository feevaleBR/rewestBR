
#include <main.hpp>
#include <Arduino.hpp>

#define REQUEST_TIME_SEC 300

using namespace std;
bool Stop = false;

void stopApp(int signal){
  Stop = true;
}

//Request Thread
void requestSensorsData(int signal){
  while(!Stop){
    #ifdef DEBUG
    std::cout << "----------------------" << std::endl;
    std::cout << "Executing requestSensorsData thread" << std::endl;
    #endif

    //std::cout << "Temperature" << std::endl;
    std::cout << "Temperature = " << Temperature.readData() << std::endl;
    std::cout << "Wind = " << Wind.readData() << std::endl;
    std::cout << "Humidity = " << Humidity.readData() << std::endl;
    #ifdef DEBUG
    std::cout << "----------------------" << std::endl;
    #endif

    char *test;
    //sprintf(test,"/usr/bin/python ~/IPSmartV01/pyCode/MySQLcom.py -t %s -u %s -w %s",Temperature.getLastData(),Humidity.getLastData(), Wind.getLastData());

    //test << "curl --data 'api_key=JGM1NMX516RG9UVF&field1=0&field2=" << Temperature.getLastData() << "&field3=" << Humidity.getLastData() << "&field4=" << Wind.getLastData() << "' https://api.thingspeak.com/update.json";
    sprintf(test,"curl --data 'api_key=GTYRPZWB2TI6I17H&field1=%f&field2=%f&field3=%f&latitude=-29.6662001&longitude=-51.12196535' https://api.thingspeak.com/update.json",Temperature.getLastData(),Humidity.getLastData(), Wind.getLastData());
    system(test);
    sleep(REQUEST_TIME_SEC);
  }
}

int main (void){

//ctrl+C interruption
  signal(SIGINT, &stopApp);

//Initilization of Serial
  Arduino.serialYun.initialize();

  sleep(1);

//TODO create timer, do not use sleep inside thread!!!!
  std::thread RequestThread(requestSensorsData,1);
  std::cout << "Thread created: OK" << std::endl;

//Infinite loop
  while(!Stop){
    //std::cout << "mainloop" << std::endl;
    sleep(1000);
  }

//Stop Thread
  RequestThread.detach();

//Stop serial
  Arduino.serialYun.stop();
  return 0;
}
