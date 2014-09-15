#include "set.h"
#include <iostream>
using namespace std;
void setEmpty(Set &a) {
	for (int i = 0; i < charSize; i++) {
		a.set[i] = 0;
	}
}

bool isEmpty(Set &a) {
	for (int i = 0; i < charSize; i++) {
		if (a.set[i] != 0) {
			return false;
		}
	}
	return true;
}

void addElement(Set &a, unsigned int element) {
	if (element >= charSize) {
		cout << "Error: element must be [0..charSize-1]" << endl;
		return;
	}
	a.set[element]++;
}

void removeElement(Set &a, unsigned int element) {
	if (element >= charSize) {
		cout << "Error: element must be [0..charSize-1]" << endl;
		return;
	}
	if (a.set[element] == 0) {
		cout << "Error: this symbol does not entry in set" << endl;
		return;
	}
	a.set[element]--;
}

int amountOfElementEntry(Set a, unsigned int element) {
	if (element >= charSize) {
		cout << "Error: element must be [0..n-1]" << endl;
		return NULL;
	}
	return a.set[element];
}

Set unionOfSets(Set set1, Set set2) {
	Set result;
	for (int i = 0; i < charSize; i++) {
		if (set1.set[i] > set2.set[i]) {
			result.set[i] = set1.set[i];
		}
		else {
			result.set[i] = set2.set[i];
		}
	}
	return result;
}

Set intersectionOfSets(Set set1, Set set2) {
	Set result;
	for (int i = 0; i < charSize; i++) {
		if (set1.set[i] < set2.set[i]) {
			result.set[i] = set1.set[i];
		}
		else {
			result.set[i] = set2.set[i];
		}
	}
	return result;
}