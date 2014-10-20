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
	if (l.current == NULL || l.current->next == NULL) {
		return NULL;
	}
	list a;
	Init(a);
	a = l;
	while (a.begin->next != l.current) {
		a.begin = a.begin->next;
	}
	l = a;
}

void Insert(list &l, int n) {
	refl e = new element;
	if (emptyEnd(l)) {
		e->n = n;
		e->next = NULL;
		l.begin = e;
		l.current = e;
	}
	else if (l.begin->next == NULL) {
		e->n = n;
		e->next = l.begin;
		l.current = l.begin;
		l.begin = e;
	}
	else {
		e->next = NULL;
		e->n = n;
		l.current->next = e;
	}
}