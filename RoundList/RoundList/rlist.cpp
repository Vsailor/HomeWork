#include "rlist.h"
#include <iostream>
using namespace std;

void Init(rlist& r) {
	r = NULL;
}

int Length(rlist r) {
	int count = 0;
	if (r == NULL) {
		return count;
	}
	else {
		do {
			count++;
			
		} while ()
	}
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