#include "deque.h"
#include <iostream>
using namespace std;
void Init(deque& q) {
	q.begin = NULL;
	q.end = NULL;
}

bool isEmpty(deque q) {
	if (q.begin == NULL || q.end == NULL) {
		return true;
	}
	return false;
}

void AddEnd(deque& q, int n) {
	dref* a = new dref;
	a->d = n;
	a->next = NULL; 
	a->prev = q.end;
	if (q.end == NULL) {
		q.end = new dref;
		q.begin = new dref;
		q.begin = a;
	}
	q.end->next = a;
	a->prev = q.end; 
	q.end = a;
}

void AddBegin(deque& q, int n) {
	dref* a = new dref;
	a->d = n;
	a->prev = NULL;
	if (q.begin == NULL) {
		q.end = new dref;
		q.begin = new dref;
		q.begin = a;
	}
	else {
		a->next = q.begin;
	}
	a->prev = NULL;
	q.begin = a;
}

int TakeBegin(deque& q) {
	int n = q.begin->d;
	dref* k = new dref;
	k->d = q.begin->d;
	k->next = q.begin->next;

	q.begin = q.begin->next;
	k->next = NULL;
	delete[] k->next;
	return n;
}

int TakeEnd(deque& q) {
	int n;
	if (q.begin == q.end) {
		deque d = q;
		n = q.begin->d;
		q.begin = NULL;
		q.end = NULL;
	}
	else {

		n = q.end->d;
		dref* d = new dref;

		d = q.end;
		q.end = q.end->prev;
		q.end->next = NULL;
		delete[] d;
	}

	return n;
}

void Output(deque& q) {
	while (!isEmpty(q)) {
		cout << TakeBegin(q) << endl;
	}
}

void Invers(deque q) {
	deque s;
	Init(s);
	int count = 0;
	while (!isEmpty(q)) {
		count = TakeEnd(q);
		AddEnd(s, count);
	}
	q = s;
}

void concat(deque& a, deque& b) {
	while (!isEmpty(b)) {
		AddEnd(a, TakeBegin(b));
	}
}

//bool isEquals(deque*& a, deque*& b) {
//	deque* new_a;
//	deque* new_b;
//	Init(new_a);
//	Init(new_b);
//	while (!isEmpty(a) && !isEmpty(b)) {
//		if (!isEmpty(a)) {
//			AddEnd(new_a, TakeBegin(a));
//		}
//		if (!isEmpty(b)) {
//			AddEnd(new_b, TakeBegin(b));
//		}
//		if (new_a->end->d != new_b->end->d) {
//
//			return false;
//		}
//		
//	}
//}
