#ifndef RELEASETYPE_H
#define RELEASETYPE_H

#include <string>

using namespace std;

namespace project {

class ReleaseType
{
public:
    explicit ReleaseType(string _name, int _id);
    ReleaseType();
    ~ReleaseType();

    int getId();
    string getName();
    void setId(int _id);
    void setTypeName(string _typeName);

private:
    int id{-1};
    string typeName;
};

}  // namespace

#endif // RELEASETYPE_H
