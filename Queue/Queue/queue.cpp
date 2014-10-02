#include "queue.h"
#include <iostream>
using namespace std;
void Init(queue*& q) {
	q = new queue;
	q->begin = NULL;
	q->end = NULL;
}

bool isEmpty(queue*& q) {
	if (q->begin == NULL && q->end == NULL) {
		return true;
	}
	return false;
}

void Add(queue*& q, int n) {
	/*qref* p = new qref;
	p->d = n;
	p->next = NULL;
	if (q->begin == NULL) {
		q->begin = p;
		q->begin->next = q->end;
		q->end = p;
	}
	else {
		q->end->next = p;
	}*/


}

int Take(queue*& q) {
	if (isEmpty(q)) {
		cout << "Queue is empty" << endl;
	}
	else {

		if (q->begin == q->end) {
			int c = q->begin->d;
			q->begin = NULL;
			q->end = NULL;
			return c;
		}
		else {
			int c = q->begin->d;
			qref* p = q->begin;
			// освободить память q->begin
			q->begin = q->begin->next;
			delete[] p;
			return c;
		}
	}
	return 0;
}

void Output(queue*& q) {
	while (!isEmpty(*&q)) {
		cout << Take(*&q);
	}
}
