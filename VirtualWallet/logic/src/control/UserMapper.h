//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_USER_MAPPER_H
#define PROJECT_CONTROL_USER_MAPPER_H

#include "../model/User.h"

namespace project {

class UserMapper  {
public:
    UserMapper(mysqlpp::Connection & _conn);
    ~UserMapper();

    void put(User * user);
    User * get(std::string nomeChavePrimaria);
    void remove(std::string nomeChavePrimaria);

private:
    void putNew(User * user);
    void putUpdate(User * user);

    mysqlpp::Connection conn(false); // ou o query??

};

}  // namespace project

#endif
