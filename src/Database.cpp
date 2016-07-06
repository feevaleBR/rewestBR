#include <Database.hpp>

//DATABASE localDb("127.0.0.1", "root", "arduino");
//DATABASE remoteDb("", "", "");

DATABASE::DATABASE(int8 *host, int8 *user, int8* password){
  this->host = host;
  this->user = user;
  this->password = password;
}

DATABASE::~DATABASE(){

}

int8* DATABASE::getHost(){
  return this->host;
}
int8* DATABASE::getUser(){
  return this->user;
}
int8* DATABASE::getPassword(){
  return this->password;
}

void DATABASE::readTableData(int8 *pDatabase, int8 *pTable){

}
