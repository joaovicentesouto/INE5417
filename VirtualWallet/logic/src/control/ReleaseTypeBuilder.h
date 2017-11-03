//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_RELEASE_TYPE_CREATOR_H
#define PROJECT_RELEASE_TYPE_CREATOR_H

#include <string>
#include <stdexcept>
#include "../model/releasetype.h"

namespace project {

class ReleaseTypeBuilder {
public:
    ReleaseTypeBuilder(std::string _name, int _id);
    ~ReleaseTypeBuilder();

    bool isValid();
    ReleaseType * build();

private:
    int id;
    std::string name;

};

}  // namespace project

#endif
