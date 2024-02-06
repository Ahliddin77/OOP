#include <iostream>
#include <string>
#include "Header.h"
#include <stdexcept>
using namespace std;


int ConsumerOrder::generateNumOrder = 0;

int main()
{
	cout << ConsumerOrder::getOrderCount() << endl; //should be 0
	ConsumerOrder o1("John Smith");
	cout << o1.getCustomer() << endl; //should be John Smith
	o1.addDish("vegetable soup", 20);
	o1.addDish("apple pie", 19);
	cout << o1.length() << endl; //should be 2
	o1[1] = 21; //changes the price of the first dish
	cout << o1 << endl; //should print for example:
	ConsumerOrder oo("Andrew Taylor");
	oo.addDish("tomato soup", 20);
	oo.addDish("grilled chicken", 45);
	oo.addDish("tomato soup", 20);
	oo.addDish("ice cream", 15);
	if (oo > o1)
		cout << "order " << oo.getID() << " is more expensive than " << o1.getID() << endl;
	oo.removeDish("tomato soup");
	cout << oo;
	cout << ConsumerOrder::getOrderCount()<<endl;
}


