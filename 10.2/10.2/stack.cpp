#include "stack.h"
#include <iostream>
using namespace std;

void Push(stack &s, int c) {
	stack p;
	p = new selem;
	p->d = c;
	p->next = s;
	s = p;
}

int Pop(stack &s) {
	stack p = s;
	s = s->next;
	int c = p->d;
	delete[] p;
	return c;
}

extern int Head(stack s) {
	return Pop(s);
}

bool Empty(stack s) {
	if (s == NULL) {
		return true;
	}
	return false;
}

void Init(stack &s) {
	s = NULL;
}

void Input(stack &s, int& number) {
	cout << "How many numbers?" << endl;
	cin >> number;
	int element;
	cout << "Enter elements:" << endl;
	for (int i = 0; i < number; i++) {
		cin >> element;
		Push(s, element);
	}
}

void Output(stack s) {
	while (s != NULL) {
		cout << Pop(s);
	}
}