#pragma once
#include <iostream>
#include <string>

using namespace std;

class PizzeriaOrder {
private:
	string customerName;
	string* nameDishes;
	float* priceDishes;
	int arraySize;
	int dishesCount;
	static int countGenerator;
public:
	PizzeriaOrder(string modCustomerName="NN");
	PizzeriaOrder(const PizzeriaOrder& po);
	PizzeriaOrder& operator=(const PizzeriaOrder& po);
	~PizzeriaOrder();
	void setCustomer(string newCustomerName);
	string getCustomer() const;
	void addDish(string newDishName, float newDishPrice);
	void removeDish(string searchDishName);
	float totalCost()const;
	static int getDishesCount();
	bool operator<(const PizzeriaOrder& po);
	float& operator[](string searchNameDish);
	friend ostream& operator<<(ostream& os, const PizzeriaOrder& po);
};
ostream& operator<<(ostream& os, const PizzeriaOrder& po);