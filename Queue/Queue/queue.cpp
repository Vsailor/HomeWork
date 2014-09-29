#include "queue.h"
#include <iostream>
using namespace std;
void Init(queue*& q) {
	q = new queue;
	q->begin = NULL;
	q->end = NULL;
}

bool isEmpty(queue q) {
	if (q.begin == NULL && q.end == NULL) {
		return true;
	}
	return false;
}

void Add(queue*& q, int n) {
	qref* p;
	p = new qref;
	p->d = n;
	p->next = NULL;
	q->end = p;
}

int Take(queue*& q) {
	if (isEmpty(*q)) {
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
			qref* p = q->begin;
			q->begin = q->begin->next;
			int c = p->d;
			delete[] p;
			return c;
		}
	}
	return 0;
}

void Output(queue*& q) {
	while (q != NULL) {
		cout << Take(q);
	}
}
