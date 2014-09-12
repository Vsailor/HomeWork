#include <iostream>
#include "complex.h"

using namespace std;

void findRoots(Complex a, Complex b, Complex c) {
	Complex D = sub(pow(b, 2), mult(mult(a, c), 4));
	Complex x1 = div(sum(mult(b, -1), toAlgForm(sqrt(D, 2))), mult(a, 2));
	Complex x2 = div(sub(mult(b, -1), toAlgForm(sqrt(D, 2))), mult(a, 2));
	cout << "x1 = ";
	show(x1);	
	cout << "x2 = ";
	show(x2);
}

void main() {
	Complex a, b, c;
	input(a);
	input(b);
	input(c);
	findRoots(a, b, c);
	system("pause");
}