#include "complex.h"
#include <iostream>
#include <math.h>

using namespace std;

void input(Complex &z){
	cout << "Enter Re z and Im z:" << endl;
	cout << "Enter a: ";
	cin >> z.a;
	cout << "Enter b: ";
	cin >> z.b;
}

void show(Complex z) {
	cout << z.a;
	if (z.b >= 0) {
		cout << " + " << z.b << "i;" << endl;
	}
	else {
		cout << " " << z.b << "i;" << endl;
	}
}

bool isTheSame(Complex a, Complex b) {
	if (a.a == b.a && a.b == b.b) {
		return true;
	}
	return false;
}

Complex sum(Complex a, Complex b) {
	a.a += b.a;
	a.b += b.b;
	return a;
}

Complex sub(Complex a, Complex b) {
	a.a -= b.a;
	a.b -= b.b;
	return a;
}

Complex mult(Complex a, Complex b) {
	Complex z;
	z.a = b.a*a.a - a.b*b.b;
	z.b = a.b*b.a + a.a*b.b;
	return z;
}

Complex div(Complex a, Complex b) {
	Complex z;
	z.a = (a.a*b.a + a.b*b.b) / (b.a*b.a + b.b*b.b);
	z.b = (a.b*b.a - a.a*b.b) / (b.a*b.a + b.b*b.b);
	return z;
}

double abs(Complex z) {
	return sqrt(z.a*z.a+z.b*z.b);
}

Complex pow(Complex a, int n) {
	Complex z = a;
	for (int i = 0; i < n; i++) {
		z = mult(z, a);
	}
	return z;
}

Complex mult(Complex a, double b) {
	Complex z;
	z.a = a.a*b;
	z.b = a.b*b;
	return z;
}

Complex toAlgForm(ComplexInTrigonomForm a) {
	Complex z;
	z.a = a.r*cos(a.angle);
	z.b = a.r*sin(a.angle);
	return z;
}

ComplexInTrigonomForm toTrigonomForm(Complex z) {
	ComplexInTrigonomForm a;
	double t = z.a*z.a + z.b*z.b;
	a.r = std::sqrt(t);
	double cosinus = z.a / a.r*1.0;
	double sinus = z.b / a.r*1.0;
	double cangle = acos(cosinus);
	double sangle = asin(sinus);

	if (cangle*sangle < 0) {
		a.angle = -acos(cosinus);
	}
	else {
		a.angle = acos(cosinus);
	}
	return a;
}

ComplexInTrigonomForm sqrt(Complex a, int n) {
	// sqrt[n](a+bi) = (sqrt[^n](r))*(cos(angle/n) + isin(angle/n))
	ComplexInTrigonomForm z;
	z = toTrigonomForm(a);
	z.angle = z.angle / n;
	z.r = pow(z.r, 1/n*1.0);
	return z;
}
