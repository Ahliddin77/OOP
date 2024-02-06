#include <iostream>
#include <string>
#include <stdexcept>
#include "Header.h"
using namespace std;

CarData::CarData(string modRegistNum, string modBrand) {
	registNum = modRegistNum;
	brand = modBrand;
	customerName = nullptr;
	rentLength = nullptr;
	arraySize = 0;
}

CarData::CarData(const CarData& cd) {
	registNum = cd.registNum;
	brand = cd.brand;
	arraySize = cd.arraySize;
	if (cd.customerName == nullptr || cd.rentLength == nullptr) {
		customerName = nullptr;
		rentLength = nullptr;
	}
	else {
		customerName = new string[cd.arraySize];
		rentLength = new int[cd.arraySize];
		for (int i = 0; i < cd.arraySize; i++) {
			customerName[i] = cd.customerName[i];
			rentLength[i] = cd.rentLength[i];
		}
	}
}

CarData& CarData::operator=(const CarData &cd) {
	if (this != &cd) {
		registNum = cd.registNum;
		brand = cd.brand;
		if (customerName != nullptr || rentLength != nullptr) {
			delete[] customerName;
			delete[] rentLength;
		}
		if (cd.customerName == nullptr || cd.rentLength == nullptr) {
			customerName = nullptr;
			rentLength = nullptr;
		}
		else {
			customerName = new string[cd.arraySize];
			rentLength = new int[cd.arraySize];
			for (int i = 0; i < cd.arraySize; i++) {
				customerName[i] = cd.customerName[i];
				rentLength[i] = cd.rentLength[i];
			}
			arraySize = cd.arraySize;
		}
	}
	return *this;
}

CarData::~CarData() {
	if (customerName != nullptr || rentLength != nullptr) {
		delete[] customerName;
		delete[] rentLength;
	}
	cout << registNum << " destroyed\n";
}

void CarData::addRental(string newCustomername, int newRentLength) {
	if (newRentLength <= 0) throw logic_error("Incorrect rental Period");
	else {
		string* tempName;
		int* tempPeriod;
		tempName = new string[arraySize+1];
		tempPeriod = new int[arraySize+1];
		for (int i=0; i < arraySize; i++) {
			tempName[i] = customerName[i];
			tempPeriod[i] = rentLength[i];
		}
		tempName[arraySize] = newCustomername;
		tempPeriod[arraySize] = newRentLength;
		delete[] customerName;
		delete[] rentLength;
		customerName = tempName;
		rentLength = tempPeriod;
		arraySize++;
		countGenerator++;
	}
}

void CarData::removeRentals(string searchName) {
	int found = 0;
	for (int i = 0; i < arraySize; i++) {
		if (customerName[i] == searchName)
			found++;
	}
	if (found > 0) {
		string* tempName;
		int* tempPeriod;
		tempName = new string[arraySize - found];
		tempPeriod = new int[arraySize - found];
		int j = 0;
		for (int i = 0; i < arraySize; i++) {
			if (customerName[i] != searchName) {
				tempName[j] = customerName[i];
				tempPeriod[j] = rentLength[i];
				j++;
			}
		}
		delete[] customerName;
		delete[] rentLength;
		customerName = tempName;
		rentLength = tempPeriod;
		arraySize -= found;
	}
	else throw logic_error("No data Matching!");
}

int CarData::sum()const {
	int sum = 0;
	for (int i = 0; i < arraySize; i++) {
		sum += rentLength[i];
	}
	return sum;
}

float CarData::averageTime() const {
	return sum() / (double)arraySize;
}

int CarData::getRentalsCount() {
	return countGenerator;
}

bool CarData::operator<(const CarData& cd) {
	if (arraySize < cd.arraySize) return true;
	return false;
}

int& CarData::operator[](int position) {
	if (position > 0 || position <= arraySize) {
		return rentLength[position - 1];
	}
	else throw logic_error("Out of Scope!");
}

ostream& operator<<(ostream& os, const CarData& cd) {
	os << "car:  " << cd.brand << "  " << cd.registNum <<endl;
	for (int i = 0; i < cd.arraySize; i++) {
		cout << i + 1 << ".  " << cd.customerName[i] << ",  " << cd.rentLength[i] << endl;
	}
	cout << "Total time:  " << cd.sum() << " hours" << endl;
	return os;
}

void CarData::setRegistrationNumber(string newNumber) {
	registNum = newNumber;
}

string CarData::getRegistrationNumber()const {
	return registNum;
}

string CarData::getBrand()const {
	return brand;
}

