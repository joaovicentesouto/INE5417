//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_RELEASE_MAPPER_H
#define PROJECT_CONTROL_RELEASE_MAPPER_H

#include "../model/Release.h"

namespace project {

class ReleaseMapper  {
public:
    ReleaseMapper(mysqlpp::Connection & _conn);
    ~ReleaseMapper();

    void put(Release * release);
    Release * get(std::string nomeChavePrimaria);
    void remove(std::string nomeChavePrimaria);

private:
    void putNew(Release * release);
    void putUpdate(Release * release);

    mysqlpp::Connection conn(false); // ou o query??

};

}  // namespace project

#endif
