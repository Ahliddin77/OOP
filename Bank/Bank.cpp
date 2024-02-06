#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    Account rocky("72476392");
    cout << rocky << endl;
    Account john(rocky);
    cout << rocky.getNumber() << endl;
    cout << john.getNumber() << endl;
    rocky.setNumber("126591869974");
    Account will;
    will = rocky;
    cout << will.getNumber() << endl;
    cout << rocky.getNumber() << endl;
    rocky.addOperation(122.23);
    rocky.addOperation(12.5);
    rocky.addOperation(-136.99);
    rocky.addOperation(-126.12);
    rocky.addOperation(180.77);
    cout << "Incomes " << rocky.getIncomes() << endl;
    cout << "Outcomes " << rocky.getOutcomes() << endl;
    cout << "Balance: " << rocky.getBalance() << endl;
    cout << rocky[2] << endl;
    cout << rocky[4] << endl;
    cout << rocky;


    return 0;
}
