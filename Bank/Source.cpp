#include <iostream>
#include "Header.h"
#include <stdexcept>
using namespace std;
Account::Account(string newAccNum) {
    accNum = newAccNum;
    listOfOperations = nullptr;
    numOfOperations = 0;
    balance = 0;
}
Account::Account(const Account &acc) {
    accNum = acc.accNum;
    balance = acc.balance;
    numOfOperations = acc.numOfOperations;
    if(acc.listOfOperations == nullptr)
        listOfOperations = nullptr;
    else {
        listOfOperations = new float[acc.numOfOperations];
            for (int i = 0; i < numOfOperations; i++)
                listOfOperations[i] = acc.listOfOperations[i];
    }
}
Account& Account::operator = (const Account &acc) {
    if (this != &acc) {
        accNum = acc.accNum;
        balance = acc.balance;
        numOfOperations = acc.numOfOperations;
        if (listOfOperations != nullptr)
            delete[] listOfOperations;
        if (acc.listOfOperations == nullptr)
            listOfOperations = nullptr;
        else {
            listOfOperations = new float[acc.numOfOperations];
            for (int i = 0; i < numOfOperations; i++)
                listOfOperations[i] = acc.listOfOperations[i];
        }
        
    }
    return *this;
}
Account::~Account() {
    if (listOfOperations != nullptr)
        delete[] listOfOperations;
    cout << "Account " << accNum << " Removed " << endl;
}
string Account::getNumber() const{
    return accNum;
}
void Account::setNumber(string nameToAssign) {
    for (int i = 0;i < nameToAssign.length();i++)
    {
        if (nameToAssign[i] == ' ' || isalpha(nameToAssign[i])) throw logic_error("incorrect number");
    }

    accNum = nameToAssign;
}
int Account::getBalance() const{
    return balance;
}
void Account::addOperation(float newOp) {
    if (newOp == 0) throw logic_error("Incorrect operation");

    float* temp;
    temp = new float[numOfOperations + 1];
    for (int i = 0; i < numOfOperations; i++)
        temp[i] = listOfOperations[i];
    temp[numOfOperations] = newOp;

    delete[] listOfOperations;
    listOfOperations = temp;
    numOfOperations++;

    balance += listOfOperations[numOfOperations - 1];
 
}
float Account::getIncomes() const {
    float sum = 0;
    for (int i = 0; i < numOfOperations;i++) {
        if (listOfOperations[i] > 0)
            sum += listOfOperations[i];
    }
    return sum;
}
float Account::getOutcomes() const {
    float sum = 0;
    for (int i = 0; i < numOfOperations;i++) {
        if(listOfOperations[i] < 0)
        sum += listOfOperations[i];
    }
    return sum;
}
float& Account::operator[](int n) {
    if (n <= 0 || n > numOfOperations) throw logic_error("Incorrect position");
    return listOfOperations[n - 1];
}
ostream& operator <<(ostream& os, const Account& acc) {
    os << "Account number:       " << acc.accNum << endl;
    os << "Balance:              " << acc.balance << endl;
    if (acc.numOfOperations > 0) {
        os << "Operation:  ";
        for (int i = 0; i < acc.numOfOperations; i++)
            cout << acc.listOfOperations[i] << " ";
        cout << endl;
    }
    else
        cout << "No transaction history";
    cout << endl;
    return os;
}