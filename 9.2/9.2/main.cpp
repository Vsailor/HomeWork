#include <iostream>
#include <math.h>
#include "segment.h"

using namespace std;

// return of not solutions!!!
Segment** solveInequality(double **coeficients, int n) {
	Segment* borders = new Segment[n];
	double D;
	double x1;
	double x2;

	for (int i = 0; i < n; i++) {

		D = pow(coeficients[i][0], 2) - 4 * coeficients[i][1];

		if (D < 0) {
			setEmpty(borders[i]);
		}
		else if (D == 0) {
			setEmpty(borders[i]);
		}
		else {
			x1 = (-coeficients[i][0] - sqrt(D)) / 2;
			x2 = (-coeficients[i][0] + sqrt(D)) / 2;
			borders[i].a = x1;
			borders[i].b = x2;
		}
	}

	Segment** intersection = new Segment*[n];
	for (int i = 0; i < n; i++) {
		intersection[i] = new Segment[n];
	}
	for (int i = 0; i < n; i++) {
		for (int t = 0; t < n; t++) {

			setIntersectionLength(intersection[i][t], borders[i], borders[t]);

		}
	}
	return intersection;
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
	Segment **mas = solveInequality(coeficients, n);
	bool haveRoots = false;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (mas[i][k].isNotEmpty && mas[i][k].a != mas[i][k].b) {
				if (!haveRoots) {
					cout << "These are not roots:" << endl;
					haveRoots = true;
				}
				cout << "(" << mas[i][k].a << "; " << mas[i][k].b << ") " << endl;
			}
		}
	}
	if (!haveRoots) {
		cout << "No roots" << endl;
	}
	system("pause");
}