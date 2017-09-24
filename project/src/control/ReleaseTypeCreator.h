//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_RELEASE_TYPE_CREATOR_H
#define PROJECT_RELEASE_TYPE_CREATOR_H

#include <string>

namespace project {

class ReleaseTypeCreator {
public:
    ReleaseTypeCreator(std::string _name);
    ~ReleaseTypeCreator();

    bool isValid();
    std::string build();
    
private:
    std::string name;

};
    
}  // namespace project

#endif
