//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_RELEASE_TYPE_MAPPER_H
#define PROJECT_CONTROL_RELEASE_TYPE_MAPPER_H


namespace project {

class ReleaseTypeMapper  {
public:
    ReleaseTypeMapper(mysqlpp::Connection & _conn);
    ~ReleaseTypeMapper();

    void put(std::string type);
    std::string get(std::string type);
    void remove(std::string type);

private:
    void putNew(std::string type);
    void putUpdate(std::string type);

    mysqlpp::Connection conn(false); // ou o query??

};

}  // namespace project

#endif
