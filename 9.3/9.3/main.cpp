#include <iostream>
#include <string>
#include "set.h"

using namespace std;

char maxSymbol(Set a) {
	int max = 0;
	int maxIndex = 0;
	for (int i = 0; i < charSize; i++) {
		if (max < a.set[i]) {
			max = a.set[i];
			maxIndex = i;
		}
	}
	return char(maxIndex);
}

string inputString() {
	string s;
	cout << "Enter string: ";
	getline(cin, s);
	return s;
}

void fillSet(Set &a, string s) {
	for (int i = 0; i < s.length(); i++) {
		for (int k = 0; k < charSize; k++) {
			if (s[i] == char(k)) {
				a.set[k]++;
			}
		}
	}
}

void showSet(Set set) {
	for (int i = 0; i < charSize; i++) {
		cout << set.set[i] << endl;
	}
}

bool isSimilar(string s1, string s2) {
	Set set1, set2;
	setEmpty(set1);
	setEmpty(set2);
	fillSet(set1,s1);
	fillSet(set2,s2);
	for (int i=0; i<charSize; i++) {
		if (set1.set[i] != set2.set[i]) {
			return false;
		}
	}

	return true;
}

bool isIncluded(string s1, string s2) {
	Set set1, set2;
	setEmpty(set1);
	setEmpty(set2);
	fillSet(set1,s1);
	fillSet(set2,s2);
	for (int i=0; i<charSize; i++) {
		if ((set1.set[i] != set2.set[i])) {
			if (set1.set[i]<set2.set[i]) {
				return false;
			}
		}
	}
}

void main() {
	Set set;
	setEmpty(set);
	string s = inputString();
	fillSet(set, s);
	cout << maxSymbol(set) << endl;
	string s1,s2;
	s1 = inputString();
	s2 = inputString();
	
	if (isSimilar(s1,s2)) {
		cout << s1 << " is similar to " << s2 << endl;
	} else {
		cout << s1 << " isn't similar to " << s2 << endl;
	}
	
	if (isIncluded(s1,s2)) {
		cout << s1 << " are included into " << s2 << endl;
	} else {
		cout << s1 << " aren't included into " << s2 << endl;
	}


	system("pause");
}