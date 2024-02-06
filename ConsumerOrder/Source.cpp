#include <iostream>
#include <string>
#include "Header.h"
#include <stdexcept>
using namespace std;

ConsumerOrder::ConsumerOrder(string modCustomerName) {
	customerName = modCustomerName;
	nameDishes = nullptr;
	priceDishes = nullptr;
	size = 0;
	generateNumOrder++;
	numOrder = generateNumOrder;
}

ConsumerOrder::ConsumerOrder(const ConsumerOrder &co) {
	customerName = co.customerName;
	size = co.size;
	if (co.nameDishes == nullptr || co.priceDishes == nullptr) {
		nameDishes = nullptr;
		priceDishes = nullptr;
	}
	else {
		nameDishes = new string[size];
		priceDishes = new float[size];
		for (int i = 0; i < size; i++) {
			nameDishes[i] = co.nameDishes[i];
			priceDishes[i] = co.priceDishes[i];
		}
	}
	generateNumOrder++;
	numOrder = generateNumOrder;
}

ConsumerOrder& ConsumerOrder::operator=(const ConsumerOrder &co) {
	if (this != &co) {
		customerName = co.customerName;
		size = co.size;
		if (nameDishes != nullptr || priceDishes != nullptr) {
			delete []nameDishes;
			delete []priceDishes;
		}
		if (co.nameDishes == nullptr || co.priceDishes == nullptr) {
			nameDishes = nullptr;
			priceDishes = nullptr;
		}
		else {
			nameDishes = new string[size];
			priceDishes = new float[size];
			for (int i = 0; i < size; i++) {
				nameDishes[i] = co.nameDishes[i];
				priceDishes[i] = co.priceDishes[i];
			}
		}
	}
	return *this;
}

ConsumerOrder::~ConsumerOrder() {
	if (size > 0) {
		delete[]nameDishes;
		delete[]priceDishes;
		cout << "Order number " << numOrder << " deleted" << endl;
	}
}

void ConsumerOrder::setCustomer(string modCustomerName) {
	for (int i = 0; i < modCustomerName.length();i++) {
		if (modCustomerName[i] != ' ' && !isalpha(modCustomerName[i])) throw logic_error("Incorrect name");
	}
	customerName = modCustomerName;
}

string ConsumerOrder::getCustomer()const {
	return customerName;
}

int ConsumerOrder::getID()const {
	return numOrder;
}

void ConsumerOrder::addDish(string newDishName, float newDishPrice) {
	string* tempName;
	float* tempPrice;
	tempName = new string[size + 1];
	tempPrice = new float[size + 1];
	for (int i = 0; i < size; i++) {
		tempName[i] = nameDishes[i];
		tempPrice[i] = priceDishes[i];
	}
	tempName[size] = newDishName;
	tempPrice[size] = newDishPrice;
	delete[] nameDishes;
	delete[] priceDishes;
	nameDishes = tempName;
	priceDishes = tempPrice;
	size++;
}

void ConsumerOrder::removeDish(string rmDishName) {
	int found = 0;
	for (int i = 0; i < size; i++) {
		if (nameDishes[i] == rmDishName)
			found++;
	}
	if (found > 0) {
		string* tempName;
		float* tempPrice;
		tempName = new string[size - found];
		tempPrice = new float[size - found];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (nameDishes[i] != rmDishName) {
				tempName[j] = nameDishes[i];
				tempPrice[j] = priceDishes[i];
				j++;
			}
		}
		delete[] nameDishes;
		delete[] priceDishes;
		nameDishes = tempName;
		priceDishes = tempPrice;
		size -= found;
	}
}

int ConsumerOrder::length()const {
	return size;
}

int ConsumerOrder::getOrderCount() {
	return generateNumOrder;
}

float& ConsumerOrder::operator[](int n) {
	if (n < 0 || n > size) throw logic_error("Incorrect order");
	return priceDishes[n-1];
}

float ConsumerOrder::total()const {
	float total = 0;
	for (int i = 0; i < size; i++) {
		total += priceDishes[i];
	}
	return total;
}

bool ConsumerOrder::operator>(const ConsumerOrder& co) {
	if (total() > co.total()) return true;
	return false;
}

ostream& operator <<(ostream& os, const ConsumerOrder& co) {
	os << "Order no. " << co.numOrder << endl;
	os << "Customer Name: " << co.customerName << endl;
	for (int i = 0; i < co.size; i++) {
		cout << i + 1 << ".  " << co.nameDishes[i] << ",  " << co.priceDishes[i] << endl;
	}
	cout << "Total cost:  " << co.total() << endl;
	return os;
}