//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "BankAccount.h"

namespace project {

BankAccount::BankAccount(string _name, double _balance) :
    Account::Account(_name, _balance, true)
{
    
}

BankAccount::BankAccount(string _name, double _balance, string _number, string _agency, string _bank) :
    Account::Account(_name, _balance, true)
{
    agency = _agency;
    accountNumber = _number;
    bank = _bank;
}

BankAccount::~BankAccount()
{
    
}

string BankAccount::getAccountNumber() {
    return accountNumber;
}

string BankAccount::getAgency() {
    return agency;
}

string BankAccount::getBank() {
    return bank;
}

void BankAccount::changeAccountNumber(string _newNumber) {
    accountNumber = _newNumber;
}

void BankAccount::changeAgency(string _newAgency) {
    agency = _newAgency;
}

void BankAccount::changeBank(string _newBank) {
    bank = _newBank;
}

}  // namespace project
