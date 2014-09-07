#include <iostream>
#include <fstream>
using namespace std;

bool Q(double x, double a, double b) {
	if (a<=x && x<=b) {
		return true;
	}
	return false;
}

void inputVector(int n) {
	ofstream f;
	f.open("file.txt", ios::out);
	int *vector = new int[n];
	for (int i=0; i<n; i++) {
		cout << "x[" << i << "]: ";
		cin >> vector[i];
		f << vector[i] << "\t";
	}
	f.close();
}

void findCoordinate (int n, double a, double b) {
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
	inputVector(n);
	findCoordinate(n,a,b);

	system("pause");
}