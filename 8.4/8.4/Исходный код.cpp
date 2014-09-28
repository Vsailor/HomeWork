#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(string fileName, string text) {
	ofstream f(fileName);
	f << text;
	f.close();
}

void readFile(string fileName) {
	ifstream f(fileName);
	string text;
	string text2;
	f >> text;
	while (!f.eof()) {
		f >> text2;
		text += " ";
		text += text2;
	}
	cout << text << endl;
}

void main() {
	string text;
	string fileName;
	getline(cin,fileName);
	getline(cin, text);
	writeFile(fileName, text);
	readFile(fileName);


	system("pause");
}