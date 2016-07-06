#ifndef _REQUESTS_H_
#define _REQUESTS_H_

class REQUESTS{
public:
  REQUESTS();
  ~REQUESTS();

  void SensorsData(void);

private:
  bool sensorIsBeingExecuted;
};

extern REQUESTS GetData;

#endif //_REQUESTS_H_
