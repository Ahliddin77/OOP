#include <iostream>
#include "Header.h"
using namespace std;
int PizzeriaOrder::countGenerator = 0;
int main() 
{
	cout << PizzeriaOrder::getDishesCount()<<endl;
	PizzeriaOrder o1("John Smith");
	cout << o1.getCustomer() << endl;
	o1.addDish("garlic bread", 10);
	o1.addDish("Margherita pizza", 25);
	cout << o1.totalCost() << endl;
	o1["Margherita pizza"] = 23;
	cout << o1;
	PizzeriaOrder oo("Andrew Taylor");
	oo.addDish("fried zucchini", 15);
	oo.addDish("tuna pizza", 35);
	oo.addDish("beer", 5);
	if (o1 < oo)
		cout << "order " << o1.getCustomer() << " ordered smaller number of dishes than " << oo.getCustomer() << endl;
	oo.removeDish("fried zucchini");
	cout << oo;
	cout << PizzeriaOrder::getDishesCount()<<endl;
}

