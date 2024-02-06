#include "Header.h"
#include <stdexcept>
#include <iostream>

using namespace std;
Fraction::Fraction(int N, int D)
{
    if (D == 0) throw runtime_error("Denominator is zero");
    num = N;
    denom = D;
    if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }
}
void Fraction::print()
{
    cout << num << "/" << denom << endl;
}
void Fraction::read()
{
    int a, b;
    cout << "Enter the numerator " << endl;
    cin >> a;
    while (true)
    {
        cout << "Enter the denominator" << endl;
        cin >> b;
        if (b != 0) break;
        cout << "Wrong try again" << endl;
    }


    if (denom < 0)
    {
        a = -a;
        b = -b;
    }
    num = a;
    denom = b;
}
Fraction Fraction::simpler(Fraction a) {
    if (a.num % a.denom == 0) {
        int x = a.num / a.denom;
        a.num /= x;
        a.denom /= x;
    }
    else if (a.denom % a.num == 0) {
        int x = a.denom / a.num;
        a.num /= x;
        a.denom /= x;
    }
    else {
        int g = 0;
        if (a.num > a.denom) g = a.denom;
        else if (a.num < a.denom) g = a.num;
        for (int i = 2; i < g; i++) {
            if (a.num % i == 0 && a.denom % i == 0) {
                a.num /= i;
                a.denom /= i;
                break;
            }
        }
    }
    return a;
}
int Fraction::cmn(Fraction b) {
    Fraction a = *this;
    int z;
    if (a.denom % b.denom == 0) {
        z = a.denom;
    }
    else if (b.denom % a.denom == 0) {
        z = b.denom;
    }
    else z = a.denom * b.denom;
    return z;
}
bool Fraction::isGreater(Fraction c) {
    Fraction a = *this;
    Fraction b = c;
    a = simpler(a);
    b = simpler(b);
    int z = a.cmn(b);
    a.num = a.num * (z / a.denom);
    b.num = b.num * (z / b.denom);
    if (a.num > b.num) return true;
    else if (a.num <= b.num) return false;
}
Fraction Fraction::sum(Fraction c) {
    Fraction a = *this;
    Fraction b = c;
    a = simpler(a);
    b = simpler(b);
    int z = a.cmn(b);
    a.num = a.num * (z / a.denom);
    b.num = b.num * (z / b.denom);
    a.num = a.num + b.num;
    a.denom = z;
    a = simpler(a);
    return a;
}
Fraction Fraction::product(Fraction c) {
    Fraction a = *this;
    Fraction b = c;
    a = simpler(a);
    b = simpler(b);
    a.num = a.num * b.num;
    a.denom = a.denom * b.denom;
    a = simpler(a);
    return a;
}
