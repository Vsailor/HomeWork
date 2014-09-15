#include <iostream>
#include <string>
#include "set.h"

using namespace std;

char maxSymbol(Set a) {
	int max = 0;
	for (int i = 1; i < charSize; i++) {
		if (max > a.set[i]) {
			max = a.set[i];
		}
	}
	return max;
}

string inputString() {
	string s;
	cout << "Enter string: ";
	getline(cin, s);
	return s;
}

void fillSet(Set &a, string s) {
	char index;
	for (int i = 0; i < s.length(); i++) {
		for (int k = 1; k < charSize; k++) {
			index = k;
			if (s[i] == index) {
				a.set[k]++;
				cout << k;
			}
		}
	}
}

void showSet(Set set) {
	for (int i = 1; i < charSize; i++) {
		cout << set.set[i] << endl;
	}
}


void main() {
	Set set;
	setEmpty(set);
	string s = inputString();
	//fillSet(set, s);
	//cout << set.set[1];//maxSymbol(set);
	char a;
	for (int i = 0; i < 255; i++) {
		
	}
	system("pause");
}