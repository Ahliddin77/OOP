#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    Student Will(1,"WIll","Smith");
    Student John(Will);
    Student Bob;
    Bob = John;
    Will.setFirtsname("Johnson");
    Will.setIndex(23);
    Will.setSurname("Williams");
    cout << Will.getFirstname() << " " << Will.getSurname() << " " << Will.getIndex() << endl;
    Will.addMark(4.5);
    Will.addMark(3.5);
    Will.addMark(3);
    cout << "Average marks of " << Will.getFirstname() << " " << Will.getSurname() << ": " << Will.avgMark() << endl;
    cout << Will;

    return 0;
}

