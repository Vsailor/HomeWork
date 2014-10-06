#include "deque.h"
#include <iostream>
using namespace std;
void Init(deque*& q) {
	q = new deque;
	q->begin = NULL;
	q->end = NULL;
}

bool isEmpty(deque*& q) {
	if (q->begin == NULL) {
		return true;
	}
	return false;
}

void Add(deque*& q, int n) {

	dref* a = new dref;
	a->d = n;
	a->next = NULL;
	if (q->end == NULL) {
		q->end = new dref;
		q->begin = new dref;
		q->begin = a;
	}
	q->end->next = a;
	q->end = a;


}

int Take(deque*& q) {
	int n = q->begin->d;
	dref* k = new dref;
	k->d = q->begin->d;
	k->next = q->begin->next;

	q->begin = q->begin->next;
	k->next = NULL;
	delete[] k->next;
	return n;
}

void Output(deque*& q) {
	while (!isEmpty(q)) {
		cout << Take(q);
	}
}


