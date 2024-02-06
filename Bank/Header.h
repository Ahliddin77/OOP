
#pragma once
#include <string>
using namespace std;

class Account {
private:
    string accNum;
    float balance;
    float* listOfOperations;
    int numOfOperations;
public:
    Account(string newAccNum = " ");
    Account(const Account& acc);
    Account& operator = (const Account& acc);
    ~Account();
    string getNumber() const;
    void setNumber(string nameToAssign);
    int getBalance() const;
    void addOperation(float newOp);
    float getIncomes() const;
    float getOutcomes() const;
    float& operator[](int n);
    friend ostream& operator <<(ostream &os, const Account &acc);
};

ostream& operator <<(ostream &os, const Account &acc);