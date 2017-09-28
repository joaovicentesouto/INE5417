//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_CREATOR_H
#define PROJECT_CONTROL_CREATOR_H

#include <stdexcept>

namespace project {

template<class T>
class Creator {
public:
    Creator();
    ~Creator();

    virtual bool isValid() = 0;
    virtual T* build() = 0;
    
private:

};
    
}  // namespace project

#endif
