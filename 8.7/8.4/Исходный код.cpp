#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(string fileName) {
	ofstream f(fileName);
	cout << "How many numbers do you want?" << endl;
	int n;
	cin >> n;
	int number;
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

void getC(string f, string g) {
	ifstream A(f);
	ofstream C("c");
	int a;
	int b;
	ifstream included("c");
	int incl = 0;
	while (!A.eof()) {
		A >> a;
		ifstream B(g);
		while (!B.eof()) {
			B >> b;
			if ((incl != a) && (incl != b)) {
				if (a <= b) {
					ofstream search("c");
					int s=0;
					bool inc = 0;
					while (!search.eof()) {
						search << s;
						if (a == s)
							inc = 1;
					}
					if (inc == 0) {
						C << a;
						incl = a;
					}
					search.close();
				}
				else {
					ofstream search("c");
					int s=0;
					bool inc = 0;
					while (!search.eof()) {
						search << s;
						if (a == s)
							inc = 1;
					}
					if (inc == 0) {
						C << b;
						incl = b;
					}
					search.close();
				}
			}
		
		}

	}
	included.close();
	A.close();
}




void main() {
	string F;
	cout << "Enter first file name: ";
	getline(cin,F);
	string G;
	cout << "Enter second file name: ";
	getline(cin, G);
	writeFile(F);
	writeFile(G);
	outputFile(F);
	outputFile(G);
	getC(F, G);
	outputFile("c");

	system("pause");
}