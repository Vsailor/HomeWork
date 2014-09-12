#include <iostream>
#include "complex.h"

using namespace std;

void findRoots(Complex a, Complex b, Complex c) {
	Complex D = sub(pow(b, 2), mult(mult(a, c), 4));
	Complex x1 = div(sum(mult(b, -1), toAlgForm(sqrt(D, 2))), mult(a, 2));
	Complex x2 = div(sub(mult(b, -1), toAlgForm(sqrt(D, 2))), mult(a, 2));
	cout << "x1 = " << x1.a;
	if (x1.b >= 0) {
		cout << " + " << x1.b << "i;" << endl;
	}
	else {
		cout << " " << x1.b << "i;" << endl;
	}
	
	cout << "x2 = " << x2.a;
	
	if (x2.b >= 0) {
		cout << " + " << x2.b << "i." << endl;
	}
	else {
		cout << " " << x2.b << "i." << endl;
	}
}

void inputCoefficient(Complex &a){
	cout << "Re z = ";
	cin >> a.a;
	cout << "Im z = ";
	cin >> a.b;
}

void main() {
	Complex a, b, c;
	inputCoefficient(a);
	inputCoefficient(b);
	inputCoefficient(c);
	findRoots(a, b, c);
	system("pause");
}