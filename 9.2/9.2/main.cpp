#include <iostream>
#include <math.h>
#include "segment.h"

using namespace std;

// return of not solutions!!!
Segment solveInequality(double **coeficients, int n) {
	Segment* isNotSolutions = new Segment[n];
	double D;
	double x1;
	double x2;

	for (int i = 0; i < n; i++) {

		D = pow(coeficients[i][0], 2) - 4 * coeficients[i][1];

		if (D < 0) {
			setEmpty(isNotSolutions[i]);
		}
		else if (D == 0) {
			x1 = (-coeficients[i][0]) / 2;
			isNotSolutions[i].a = x1;
			isNotSolutions[i].b = x1;
		}
		else {
			x1 = (-coeficients[i][0] - sqrt(D)) / 2;
			x2 = (-coeficients[i][0] + sqrt(D)) / 2;
			isNotSolutions[i].a = x1;
			isNotSolutions[i].b = x2;
		}
	}
	double x1_max = isNotSolutions[0].a;
	double x2_min = isNotSolutions[0].b;

	for (int i = 0; i < n; i++) {
		if (isNotSolutions[i].a > x1_max) {
			x1_max = isNotSolutions[i].a;
		}
		if (isNotSolutions[i].b < x2_min) {
			x2_min = isNotSolutions[i].b;
		}
	}
	Segment isNotSolution;
	isNotSolution.a = x1_max;
	isNotSolution.b = x2_min;
	return isNotSolution;

}

double** inputCoeficients(int n) {
	double** mas = new double*[n];
	cout << "Type coeficients:" << endl;
	for (int i = 0; i < n; i++) {
		mas[i] = new double[2];
		cout << "p[" << i << "] = ";
		cin >> mas[i][0];
		cout << "q[" << i << "] = ";
		cin >> mas[i][1];
	}
	return mas;
}

void main() {
	cout << "How many coeficients do you want?" << endl;
	int n;
	cin >> n;
	double **coeficients = inputCoeficients(n);
	Segment notSolution = solveInequality(coeficients, n);
	cout << "(-INF," << notSolution.a << ") U (" << notSolution.b << ", +INF)" << endl;
	system("pause");
}