#pragma once
#include <iostream>
#include <string>
using namespace std;

class ConsumerOrder {
private:
	string customerName;
	string* nameDishes;
	float* priceDishes;
	int size;
	int numOrder;
	
	static int generateNumOrder;
public:
	ConsumerOrder(string modCustomerName ="NN");
	ConsumerOrder(const ConsumerOrder &co);
	ConsumerOrder& operator=(const ConsumerOrder &co);
	~ConsumerOrder();
	void setCustomer(string modCustomerName);
	string getCustomer()const;
	int getID()const;
	void addDish(string newDishName, float newDishPrice);
	void removeDish(string rmDishName);
	int length()const;
	static int getOrderCount();
	bool operator>(const ConsumerOrder& co);
	float& operator[](int n);
	float total()const;
	friend ostream& operator <<(ostream &os, const ConsumerOrder& co);
};
ostream& operator <<(ostream& os, const ConsumerOrder& co);
