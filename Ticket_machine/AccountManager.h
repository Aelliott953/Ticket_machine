#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <string>
#include "Person.h"

class AccountManager {
private:
    Person& person;

public:
    AccountManager(Person& person);
    void createAccount(string firstName, string lastName, int birthYear, string discountReason);
    bool verifyAccount(int cardNumber);
    bool fileExists(const std::string& filename);
    
};

#endif