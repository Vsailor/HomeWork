#include "stack.h"
int Push(stack &s, char c) {
	stack p;
	p = new selem;
	(*p).d = c; // p->d = c; разименовывание указателя
	p->next = s;
	s = p;
}

int Pop(stack &s) {
	stack p;
	p = s;
	s = s->next;
	delete p;
}