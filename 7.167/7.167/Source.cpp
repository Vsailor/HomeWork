#include <iostream>
#include <math.h>
#define eps 0.01
using namespace std;

double f(double x) {
	return pow(x,3)-7*x-1; 
}

double intersectionOfTheChordAndTheAxis(double x1, double y1, double x2, double y2){
	double k = (y1-y2)/(x1-x2)*1.0;
	double b = y1-k*x1;
	// y = kx + b - chord equation
	return (-b)/k;
}

double findRoot(double a, double b) {
	double x = intersectionOfTheChordAndTheAxis(a,f(a),b,f(b));
	if (abs(f(x))<eps) {
		return x;
	}
	if (f(x)<0) {
		return findRoot(x,b);
	} else if (f(x)>0) {
		return findRoot(a,x);
	}
}

int setBorders(double &a, double &b) {
	bool badInput = false;
	do {
		cout << "a,b must be so that one root exist" << endl;
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		if ((f(a)*f(b)>0) || (a<-2.57 && b>2.71) || (b<-2.57 && a>2.71) || a>=b) {
			badInput = true;
			cout << "Try again" << endl;
		} else {
			badInput = false;
		}
	} while (badInput);
	return 0;
}

void main() {
	cout << "Roots of the equation x^3-7x-1=0 : {-2.57; -0.14; 2.71}" << endl;
	double a, b; // borders to find only one root

	int (*p)(double &, double &) = NULL;
	p = setBorders;
	p(a,b);
	double (*t)(double, double) = NULL;
	t = findRoot;
	double root = t(a,b);
	cout << "Root: x = " << root << "; y = " << f(root) << endl;
	system("pause");
}