#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(string fileName, string text) {
	ofstream f(fileName);
	f << text;
	f.close();
}

string fileString(string fileName) {
	ifstream f(fileName);
	string text;
	string text2;
	f >> text;
	// while it's not the end file
	while (!f.eof()) {
		f >> text2;
		text = text + text2;
	}
	return text;
}

void amountOfWordEntering(string f, string g) {
	ifstream F(f);
	string s1;
	string s2;
	int count;
	while (!F.eof()) {
		count = 0;
		ifstream G(g);
		F >> s1;
		while (!G.eof()) {
			G >> s2;
			if (s1 == s2) {
				count++;
			}
		}
		cout << s1 << " - " << count << endl;
	}
}

void main() {
	string F;
	cout << "Enter first file name: ";
	getline(cin,F);
	string G;
	cout << "Enter second file name: ";
	getline(cin, G);
	string text1;
	string text2;
	cout << "Enter string of " << F << " file:" << endl;
	getline(cin, text1);
	cout << "Enter string of " << G << " file:" << endl;
	getline(cin, text2);
	writeFile(F, text1);
	writeFile(G, text2);
	amountOfWordEntering(F, G);

	system("pause");
}