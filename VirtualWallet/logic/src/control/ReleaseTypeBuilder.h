//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_RELEASE_TYPE_CREATOR_H
#define PROJECT_RELEASE_TYPE_CREATOR_H

#include <string>
#include <stdexcept>

namespace project {

class ReleaseTypeBuilder {
public:
    ReleaseTypeBuilder(std::string _name);
    ~ReleaseTypeBuilder();

    bool isValid();
    std::string build();

private:
    std::string name;

};

}  // namespace project

#endif
