#pragma once
struct Fraction {
private:
    int num;
    int denom;
public:
    Fraction(int N = 0, int D = 1);
    void print();
    void read();
    Fraction simpler(Fraction a);
    int cmn(Fraction a);
    bool isGreater(Fraction c);
    Fraction sum(Fraction c);
    Fraction product(Fraction c);
};
