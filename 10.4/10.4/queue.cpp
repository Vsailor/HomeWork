#include "queue.h"
#include <iostream>

using namespace std;

void Init(queue& q) {
	q.begin = NULL;
	q.end = NULL;
}

bool isEmpty(queue q) {
	if (q.begin == NULL) {
		return true;
	}
	return false;
}

void Add(queue& q, int n) {
	elem* e = new elem;
	e->d = n;
	e->next = NULL;
	if (q.end == NULL) {
		q.end = new elem;
		q.begin = new elem;
		q.begin = e;
	}
	q.end->next = e;
	q.end = e;
}

int Take(queue& q) {
	int k;
	k = q.begin->d;
	elem* e = q.begin;
	q.begin = q.begin->next;
	delete[] e;
	return k;
}