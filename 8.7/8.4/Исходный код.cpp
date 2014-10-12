#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(string fileName, int& n) {
	ofstream f(fileName);
	cout << "How many numbers do you want?" << endl;
	cin >> n;
	int number;
	cout << "Type numbers:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> number;
		f << number << "\n";
	}
	f.close();
}

void outputFile(string fileName) {
	ifstream f(fileName);
	int number;
	// while it's not the end file
	while (!f.eof()) {
		f >> number;
		cout << number << " ";
	}
	cout << endl;
}

void makeUnion(string A, int n, string B, int k, string fileName) {
	ofstream f(fileName);
	ifstream fA(A);
	ifstream fB(B);
	int* a = new int[n];
	int* b = new int[k];
	int s;
	for (int i=0; i<n; i++) {
		fA >> s;
		a[i] = s;
	}
	
	for (int i=0; i<k; i++) {
		fB >> b[i];
	}
	int* c = new int[n+k];
	for (int i=0; i<n; i++) {
		c[i] = a[i];
	}
	for (int i=n, t=0; i<n+k; i++, t++) {
		c[i] = b[t];
	}
	int* hmas = new int[n+k];
	bool repeat;
	int size = 0;
	for (int i=0; i<n+k; i++) {
		repeat = false;
		for (int j=0; j<size; j++) {
			if (c[i] == hmas[j]) {
				repeat = true;
			}
		}
		if (!repeat) {
			hmas[size] = c[i];
			size++;
		}
	}
	for (int i=0; i<size; i++) {
		f << hmas[i] << "\n";
	}
	f.close();
	fA.close();
	fB.close();
}

void sortC() {
	ifstream cCount("C.txt");
	int a;
	int count = 0;
	while (!cCount.eof()) {
		cCount >> a;
		count++;
	}
	count -= 1;
	cCount.close();
	ifstream c("C.txt");
	int* mas = new int[count];
	for (int i = 0; i < count; i++) {
		c >> mas[i];
	}
	c.close();
	int save = mas[0];
	for (int i = 0; i < count-1; i++) {
		for (int j = 0; j < count-1; j++) {
			if (mas[j] > mas[j+1]) {
				save = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = save;
			}
		}
	}
	ofstream newc("C.txt");

	for (int i = 0; i < count; i++) {
		newc << mas[i] << endl;
	}
	newc.close();
}



void main() {
	string F;
	cout << "Enter first file name: ";
	getline(cin, F);
	string G;
	cout << "Enter second file name: ";
	getline(cin, G);
	int n = 0;
	writeFile(F, n);
	int k = 0;
	writeFile(G, k);
	makeUnion(F, n, G, k, "C.txt");
	sortC();
	system("pause");
}