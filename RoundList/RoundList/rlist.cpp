#include "rlist.h"
#include <iostream>
using namespace std;

void Init(rlist& r) {
	r = NULL;
}

int Length(rlist r) {
	int count = 0;
	rlist b = r;
	if (r == NULL) {
		return count;
	}
	else {
		do {
			count++;
			r = r->next;
		} while (r != b);
	}
	return count;
}

void Insert(rlist& r, int n) {
	rlist a = new element;
	if (r == NULL) {
		a->n = n;
		a->next = a;
	}
	else {
		*a = *r;
		r->next = a;
		r->n = n;
	}
	r = a;
}

int cur(rlist r) {
	return r->n;
}

void Delete(rlist& r) {
	rlist a;
	if (Length(r) == 1) {
		a = r;
		Init(r);
		delete a;
	}
	else {
		a = r->next;
		*r = *a;
		delete a;
	}
}

void toNext(rlist& r) {
	r=r->next;
}