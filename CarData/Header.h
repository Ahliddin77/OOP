#pragma once
#include <string>
#include <stdbool.h>
using namespace std;

class CarData {
private:
	string registNum;
	string brand;
	string* customerName;
	int* rentLength;
	int arraySize;
	static int countGenerator;
public:
	CarData(string modRegistNum="NN", string modBrand="NN");
	CarData(const CarData &cd);
	CarData& operator=(const CarData &cd);
	~CarData();
	void addRental(string newCustomername, int newRentLength);
	void removeRentals(string searchName);
	int sum()const;
	float averageTime()const;
	static int getRentalsCount();
	bool operator<(const CarData &cd);
	int& operator[](int position);
	friend ostream& operator<<(ostream &os, const CarData &cd);
	void setRegistrationNumber(string newNumber);
	string getRegistrationNumber()const;
	string getBrand()const;
};
ostream& operator<<(ostream& os, const CarData& cd);