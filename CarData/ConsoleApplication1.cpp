#include "Header.h"
#include <iostream>
int CarData::countGenerator = 0;
int main()
{
    cout << CarData::getRentalsCount()<<endl;
    CarData c1("EL12345", "Toyota Yaris");
    cout << c1.getRegistrationNumber() << endl;
    c1.addRental("John Smith", 7);
    c1.addRental("Jonathon Taylor", 10);
    cout << c1.averageTime() << endl;
    c1[1] = 12;
    cout << c1;
    CarData c2("EL12233", "Opel Astra");
    c2.addRental("Mark Johnson", 10);
    c2.addRental("Elizabeth Smith", 3);
    c2.addRental("Mark Johnson", 2);
    if (c1 < c2)
        cout << c1.getBrand() << " is used less often that " << c2.getBrand() << endl;
    c2.removeRentals("Mark Johnson");
    cout << c2;
    cout << CarData::getRentalsCount() << endl;
}


