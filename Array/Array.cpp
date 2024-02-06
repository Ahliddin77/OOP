#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int N;
    cout << "Give the length to array ";
    cin >> N;
    Array A(N);
    A.read();
    cout << "Average of A array " << A.avg() << endl;
    cout << "Min value of A array " << A.minum() << endl;
    cout << "Max value of A array " << A.maxim() << endl;
    A.reverseArr();
    A.print();
    Array C(A);
    C.print();
    cout << "Give new values to A" << endl;
    A.read();
    cout << "Values of A" << endl;
    A.print();
    cout << "Values of C" << endl;
    C.print();
    Array D(C.sort(false));
    D.print();




    return 0;
}
