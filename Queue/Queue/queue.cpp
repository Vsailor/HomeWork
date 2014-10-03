#include "queue.h"
#include <iostream>
using namespace std;
void Init(queue*& q) {
	q = new queue;
	q->begin = NULL;
	q->end = NULL;
}

bool isEmpty(queue*& q) {
	if (q->begin == NULL) {
		return true;
	}
	return false;
}

void Add(queue*& q, int n) {

	qref* a = new qref;
	a->d=n;
	a->next=NULL;
	if (q->end == NULL) {
		q->end = new qref;
		q->begin = new qref;
		q->begin = a;
	}
	q->end->next=a;
	q->end = a;


}

int Take(queue*& q) {
	int n=q->begin->d;
	qref* k = new qref;
	k->d=q->begin->d;
	k->next=q->begin->next;

	q->begin=q->begin->next;
	k->next=NULL;
	delete[] k->next;
	return n;
}

void Output(queue*& q) {
	while (!isEmpty(q)) {
		cout << Take(q);
	}
}


