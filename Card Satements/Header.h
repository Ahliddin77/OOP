#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <stdbool.h>
#include "Header.h"
using namespace std;
class CardStatement {
private:
    static int cardNum;
    float limit;
    string* desOfOperations;
    float* prices;
    int arraySize;
public:
    CardStatement(float newLimit = 0)
    {
        limit = newLimit;
        desOfOperations = nullptr;
        prices = nullptr;
        arraySize = 0;
        cardNum++;
    }
    CardStatement(const CardStatement& cs) 
    {
        limit = cs.limit;
        arraySize = cs.arraySize;
        cardNum++;
        if (cs.desOfOperations == nullptr || cs.prices == nullptr) {
            desOfOperations = nullptr;
            prices = nullptr;
        }
        else {
            desOfOperations = new string[arraySize];
            prices = new float[arraySize];
            for (int i = 0; i < arraySize; i++) {
                desOfOperations[i] = cs.desOfOperations[i];
                prices[i] = cs.prices[i];
            }
        }
    }
    CardStatement& operator = (const CardStatement& cs)
    {
        if (this != &cs) {
            limit = cs.limit;
            arraySize = cs.arraySize;
            if (desOfOperations != nullptr || prices != nullptr) {
                delete[]desOfOperations;
                delete[]prices;
            }
            if (cs.desOfOperations == nullptr || cs.prices == nullptr) {
                desOfOperations = nullptr;
                prices = nullptr;
            }
            else {
                desOfOperations = new string[arraySize];
                prices = new float[arraySize];
                for (int i = 0; i < arraySize; i++) {
                    desOfOperations[i] = cs.desOfOperations[i];
                    prices[i] = cs.prices[i];
                }
            }
        }
        return *this;
    }
    ~CardStatement()
    {
        if (arraySize > 0) {
            delete[]desOfOperations;
            delete[]prices;
            cout << "Card statement number " << cardNum << " deleted" << endl;
        }
    }
    int getNumber() const
    {
        return cardNum;
    }
    float getLimit() const
    {
        return limit;
    }
    void increaseLimit(float newLimit)
    {
        if (newLimit > limit) {
            limit = newLimit;
        }
        else {
            throw logic_error("Invalid limit");
        }
    }
    void addOperation(string newDesofOperation, float cost)
    {
        if ((totalCost() + cost) > limit) {
            throw logic_error("exceding limit");
        }
        string* tempName;
        float* tempPrice;
        tempName = new string[arraySize + 1];
        tempPrice = new float[arraySize + 1];
        for (int i = 0; i < arraySize; i++) {
            tempName[i] = desOfOperations[i];
            tempPrice[i] = prices[i];
        }
        tempName[arraySize] = newDesofOperation;
        tempPrice[arraySize] = cost;
        delete[] desOfOperations;
        delete[] prices;
        desOfOperations = tempName;
        prices = tempPrice;
        arraySize++;
    }
    void removeDish(string searchDishName)
    {
        int found = 0;
        for (int i = 0; i < arraySize; i++)
        {
            if (prices[i] == 0)
                found++;
            if (found > 0)
            {
                string* tempName;
                float* tempPrice;
                tempName = new string[arraySize - found];
                tempPrice = new float[arraySize - found];
                int j = 0;
                for (int i = 0; i < arraySize; i++)
                {
                    if (prices[i] != 0)
                    {
                        tempName[j] = desOfOperations[i];
                        tempPrice[j] = prices[i];
                        j++;
                    }
                }
                delete[] desOfOperations;
                delete[] prices;
                desOfOperations = tempName;
                prices = tempPrice;
                arraySize -= found;
            }
            else throw logic_error("No 0 Found");
        }
    }
    
    float totalCost() const {
        float total = 0;
        for (int i = 0; i < arraySize; i++) {
            total += prices[i];
        }
        return total;
    }

    float max() const
    {
        int max = 0;
        for (int i = 0; i < arraySize; i++) {
            if (max < prices[i])
                max = prices[i];
        }
        return max;
    }

    friend ostream& operator <<(ostream& os, const CardStatement& cs)
    {
        os << "Card no. " << cs.cardNum << "; limit: "<< cs.limit<< " PLN" << endl;
        for (int i = 0; i < cs.arraySize; i++) {
            cout << i + 1 << ".  " << cs.desOfOperations[i] << ",  " << cs.prices[i] << " PLN" << endl;
        }
        cout << "Total :  " << cs.totalCost() <<", remaining: "<< cs.limit - cs.totalCost() << ", most expensive: " << cs.max() << " PLN" << endl;
        return os;
    }
    
    string& operator[](int n)
    {
        if(n > arraySize)
            throw logic_error("No matching Found");
        for (int i = 0; i == n - 1; i++)
            return desOfOperations[i];
    }
};

ostream& operator <<(ostream& os, const CardStatement& cs);