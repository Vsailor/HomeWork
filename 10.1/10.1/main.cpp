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

void main() {
	int n=0; // element numbers
	stack s;
	Init(s);
	Input(s,n);
	sort(s, n);
	Output(s);
	cout << endl;
	system("pause");
}