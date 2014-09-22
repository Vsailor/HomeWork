#include "stack.h"
#include <iostream>
using namespace std;
void Push(stack*& s, char c) {
	stack* p;
	p = new stack;
	p->d = c;
	p->next = s;
	s = p;
}

char Pop(stack*& s) {
	stack* p = s;
	s = s->next;
	char c = p->d;
	delete[] p;
	return c;
}

bool Empty(stack*& s) {
	if (s->next == NULL) {
		return true;
	}
	return false;
}

void Init(stack*& s) {
	s = NULL;
}

void Input(stack*& s) {
	cout << "Enter elements. Type '*' in the end." << endl;
	bool finish = false;
	char element;
	while (!finish) {
		cin >> element;
		if (element == '*') {
			finish = true;
			continue;
		}
		Push(s, element);
	}
}

void Output(stack*& s) {
	while (s != NULL) {
		cout << Pop(s);
	}
}