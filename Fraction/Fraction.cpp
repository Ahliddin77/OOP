#include <iostream>
#include "Header.h"


using namespace std;

int main()
{
	Fraction x;
	x.print();
	Fraction y(7, 3);
	y.print();
	Fraction z(46,14);
	z.print();
	Fraction d;
	cout  << boolalpha << z.isGreater(y) << endl;
	d = z.sum(y);
	Fraction p;
	p = z.product(y);
	z.print();
	y.print();
	d.print();
	p.print();

	return 0;
}
