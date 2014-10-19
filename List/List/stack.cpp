#include "stack.h"
#include <iostream>
using namespace std;
void Push(stack*& s, list c) {
	stack* p;
	p = new stack;
	p->d = c;
	p->next = s;
	s = p;
}

list Pop(stack*& s) {
	stack* p = s;
	s = s->next;
	list c = p->d;
	delete[] p;
	return c;
}

bool Empty(stack*& s) {
	if (s == NULL) {
		return true;
	}
	return false;
}

void Init(stack*& s) {
	s = NULL;
}

