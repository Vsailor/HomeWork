#include "list.h"
#include <iostream>
using namespace std;

void Init(list &l) {
	l.begin = NULL;
	l.current = NULL;
}

bool emptyEnd(list l) {
	if (l.current == NULL) {
		return true;
	}
	return false;
}

void toFirst(list &l) {
	l.current = l.begin;
}

void toNext(list &l) {
	l.current = l.current->next;
}

int getCurrent(list l) {
	return l.current->n;
}

refl findPrev(list &l) {
	refl p;

	if (l.begin == l.current) {
		p = NULL;
	}
	else
	{
		p = l.begin;
		while (p->next != l.current)
			p = p->next;
	}
	return p;
}

void Insert(list &l, int n) {
	refl p;

	p = new element;
	p->n = n;
	p->next = l.current;
	if (l.begin == l.current) {
		l.begin = p;
	}
	else findPrev(l)->next = p;
}

void Delete(list &l)
{
	refl p;

	if (l.current == NULL)
	{
		cout << "List is empty";
		return;
	}
	p = l.current;
	if (l.begin == p) {
		l.begin = l.current->next;
	}
	else {
		findPrev(l)->next = l.current->next;
	}

	l.current = l.current->next;
	delete[] p;
	/* ашё. 10.22 с), у) */
}

void outPut(list l) {
	toFirst(l);
	while (!emptyEnd(l)) {
		cout << l.current->n << endl;
		l.current = l.current->next;
	}
}