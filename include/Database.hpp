#ifndef _DATABASE_H_
#define  _DATABASE_H_

#include <Types.hpp>

class DATABASE{
public:
  DATABASE(int8 *host, int8 *user, int8* password);
  ~DATABASE();

  int8 *getHost();
  int8 *getUser();
  int8 *getPassword();

  void readTableData(int8 *pDatabase, int8 *pTable);
  void addDataToTable(int8 *pDatabase, int8 *pTable);

private:
  int8 *host;
  int8 *user;
  int8 *password;
};

#endif // _DATABASE_H_
