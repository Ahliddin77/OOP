#include <iostream>
#include <string>
#include <stdexcept>
#include "Header.h"
using namespace std;

PizzeriaOrder::PizzeriaOrder(string modCustomerName) {
	customerName = modCustomerName;
	nameDishes = nullptr;
	priceDishes = nullptr;
	arraySize = 0;
}

PizzeriaOrder::PizzeriaOrder(const PizzeriaOrder& po) {
	customerName = po.customerName;
	arraySize = po.arraySize;
	if (po.nameDishes == nullptr || po.priceDishes == nullptr) {
		nameDishes = nullptr;
		priceDishes = nullptr;
	}
	else {
		nameDishes = new string[arraySize];
		priceDishes = new float[arraySize];
		for (int i = 0; i < arraySize; i++) {
			nameDishes[i] = po.nameDishes[i];
			priceDishes[i] = po.priceDishes[i];
		}
	}
}

PizzeriaOrder& PizzeriaOrder::operator=(const PizzeriaOrder &po) {
	if (this != &po) {
		customerName = po.customerName;
		arraySize = po.arraySize;
		if (nameDishes != nullptr || priceDishes != nullptr) {
			delete[] nameDishes;
			delete[] priceDishes;
		}
		if (po.nameDishes == nullptr || po.priceDishes == nullptr) {
			nameDishes = nullptr;
			priceDishes = nullptr;
		}
		else {
			nameDishes = new string[arraySize];
			priceDishes = new float[arraySize];
			for (int i = 0; i < arraySize; i++) {
				nameDishes[i] = po.nameDishes[i];
				priceDishes[i] = po.priceDishes[i];
			}
		}
	}
	return *this;
}

PizzeriaOrder::~PizzeriaOrder() {
	if (nameDishes != nullptr || priceDishes != nullptr) {
		delete[] nameDishes;
		delete[] priceDishes;
	}
	cout << customerName << " deleted\n";
}

void PizzeriaOrder::setCustomer(string newCustomeName) {
	for (int i = 0; i < newCustomeName.length();i++) {
		if (newCustomeName[i] != ' ' && !isalpha(newCustomeName[i])) throw logic_error("Incorrect name");
	}
	customerName = newCustomeName;
}

string PizzeriaOrder::getCustomer() const {
	return customerName;
}

void PizzeriaOrder::addDish(string newDishName, float newDishPrice) {
	string* tempName;
	float* tempPrice;
	tempName = new string[arraySize+1];
	tempPrice = new float[arraySize+1];
	for (int i = 0; i < arraySize; i++) {
		tempName[i] = nameDishes[i];
		tempPrice[i] = priceDishes[i];
	}
	tempName[arraySize] = newDishName;
	tempPrice[arraySize] = newDishPrice;
	delete[] nameDishes;
	delete[] priceDishes;
	nameDishes = tempName;
	priceDishes = tempPrice;
	arraySize++;
	countGenerator++;
	dishesCount = countGenerator;
}

void PizzeriaOrder::removeDish(string searchDishName) {
	int found = 0;
	for (int i = 0; i < arraySize; i++) {
		if (nameDishes[i] == searchDishName)
			found++;
	}
	if (found > 0) {
		string* tempName;
		float* tempPrice;
		tempName = new string[arraySize - found];
		tempPrice = new float[arraySize - found];
		int j = 0;
		for (int i = 0; i < arraySize; i++) {
			if (nameDishes[i] != searchDishName) {
				tempName[j] = nameDishes[i];
				tempPrice[j] = priceDishes[i];
				j++;
			}
		}
		delete[] nameDishes;
		delete[] priceDishes;
		nameDishes = tempName;
		priceDishes = tempPrice;
		arraySize -= found;
		countGenerator -= found;
		dishesCount = countGenerator;
	}
	else throw logic_error("No matching Found");
}

float PizzeriaOrder::totalCost() const{
	float total = 0;
	for (int i = 0; i < arraySize; i++) {
		total += priceDishes[i];
	}
	return total;
}

int PizzeriaOrder::getDishesCount() {
	return countGenerator;
}

bool PizzeriaOrder::operator<(const PizzeriaOrder& po) {
	if (arraySize < po.arraySize) return true;
	return false;
}

float& PizzeriaOrder::operator[](string searchNameDish) {
	for (int i = 0; i < arraySize; i++)
		if (nameDishes[i] == searchNameDish)
			return priceDishes[i];
	throw logic_error("No matching Found");
}

ostream& operator<<(ostream& os, const PizzeriaOrder& po) {
	os << "customer:  " << po.customerName << endl;
	for (int i = 0; i < po.arraySize; i++) {
		cout << i + 1 << ".  " << po.nameDishes[i] << ",  " << po.priceDishes[i] << endl;
	}
	cout << "Total cost:  " << po.totalCost() << endl;
	return os;
}