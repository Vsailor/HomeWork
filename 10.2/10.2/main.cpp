#include "stack.h"
#include <iostream>
using namespace std;

void sort(stack& s, int n) {
	int *elem = new int[n];
	for (int i = 0; i < n; i++) {
		elem[i] = Pop(s);
	}
	int x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (elem[i] > elem[j]) {
				x = elem[i];
				elem[i] = elem[j];
				elem[j] = x;
			}
		}
	}
	while (!Empty(s)) {
		Pop(s);
	}
	for (int i = 0; i < n; i++) {
		Push(s, elem[i]);
	}

}

int stackLength(stack &s) {
	stack t;
	Init(t);
	int count = 0;
	while (!Empty(s)) {
		Push(t, Pop(s));
		count++;
	}
	while (!Empty(t)) {
		Push(s, Pop(t));
	}
	return count;
}

void inversion(stack &s) {
	stack t;
	Init(t);
	while (!Empty(s)) {
		Push(t, Pop(s));
	}
	s = t;
}

void takeElementsFromStack(stack &s, int n) {
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			if (!Empty(s)) {
				Pop(s);
			}
		}
	}
}

void main() {
	int n = 0; // element numbers
	stack s;
	Init(s);
	Input(s, n);
	cout << "Stack length: " << stackLength(s) << endl;
	inversion(s);
	cout << "How many elements to take?" << endl;
	int k;
	cin >> k;
	takeElementsFromStack(s, k);
	Output(s);
	cout << endl;
	system("pause");
}