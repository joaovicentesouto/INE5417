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
    Release(int _id, double _value, Account* _account,
            string _releaseType, string _paymentType,
            string _description, string _operation, string _date);
    ~Release();
    
    size_t getId();
    double getValue();
    Account* getAccount();
    string getReleaseType();
    string getPaymentType();
    string getDescription();
    string getOperation();
    string getDate();
    
    void changeValue(double _value);
    void changeAccount(Account* _account);
    void changeReleaseType(string _type);
    void changePaymentType(string _type);
    void changeDescription(string _description);
    void changeOperation(string _operation);
    void changeDate(string _date);
    
private:
    int id;
    double value;
    Account* account;
    string releaseType, paymentType, description, operation, date;
    
};

}  // namespace project

#endif
