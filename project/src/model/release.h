//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_RELEASE_H
#define PROJECT_RELEASE_H

#include <string>
#include <ctime>

using namespace std;

namespace project {

class Account;

class Release {
public:
    Release(double _value, Account& _account,
            string _ReleaseType, string _paymentType,
            string _description, time_t _date);
    ~Release();
    
    size_t getId();
    double getValue();
    Account& getAccount();
    string getReleaseType();
    string getPaymentType();
    string getDescription();
    time_t getDate();
    
    void changeValue(double _value);
    void changeAccount(Account& _account);
    void changeReleaseType(string _type);
    void changePaymentType(string _type);
    void changeDescription(string _description);
    void changeDate(time_t _date);
    
private:
    size_t id{0};
    double value;
    Account* account;
    string releaseType, paymentType, description;
    time_t date;
    
};
    
}  // namespace project

#endif
