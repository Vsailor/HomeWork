#include <iostream>
#include <fstream>
using namespace std;

bool Q(double x, double a, double b) {
	if (a<=x && x<=b) {
		return true;
	}
	return false;
}

int inputVector(int n) {
	ofstream f;
	f.open("file.txt", ios::out);
	int *vector = new int[n];
	for (int i=0; i<n; i++) {
		cout << "x[" << i << "]: ";
		cin >> vector[i];
		f << vector[i] << "\t";
	}
	f.close();
	return 0;
}

int findCoordinate (int n, double a, double b) {
	ifstream f;
	f.open("file.txt", ios::in);
	int *vector = new int[n];
	cout << endl;
	for (int i=0; i<n; i++) {
		f >> vector[i];
		if (Q(vector[i],a,b)) {
			cout << "x[" << i << "] = " << vector[i] << endl;
		}
	}
	f.close();
	return 0;
}


void main() {
	cout << "Type a:";
	double a;
	cin >> a;
	double b;
	cout << "Type b:";
	cin >> b;
	cout << "How many vector coordinates will there be?" << endl;
	int n;
	cin >> n;

	int (*s)(int) = NULL;
	s = inputVector;
	s(n);

	int (*f)(int, double, double) = NULL;
	f = findCoordinate;
	f(n,a,b);

	system("pause");
}