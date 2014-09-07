#include <iostream>
using namespace std;

bool Q(double x, double a, double b) {
	if (a<=x && x<=b) {
		return true;
	}
	return false;
}

int *inputVector(int n) {
	int *vector = new int[n];
	for (int i=0; i<n; i++) {
		cout << "x[" << i << "]: ";
		cin >> vector[i];
	}
	return vector;
}

int findCoordinate (int *vector, int n, double a, double b) {
	cout << endl;
	for (int i=0; i<n; i++) {
		if (Q(vector[i],a,b)) {
			cout << "x[" << i << "] = " << vector[i] << endl;
		}
	}
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
	int *(*s)(int) = NULL;
	s = inputVector;
	int *vector = s(n);

	int (*p)(int *, int, double, double) = NULL;
	p = findCoordinate;
	p(vector,n,a,b);
	system("pause");
}