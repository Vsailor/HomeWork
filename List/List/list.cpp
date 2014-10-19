#include "list.h"
#include <iostream>

using namespace std;


list Init() {
	return NULL;
}

bool isEmpty(list l) {
	if (l == NULL) {
		return true;
	}
	return false;
}


int Head(list l) {
	return l->d;
}


list Tail(list l) {
	return l->next;
}

list Add(list l, int n) {
	list s = new elem;
	s->d = n;
	s->next = l;
	return s;
}

list input() {
	list l = Init();
	cout << "How many numbers?" << endl;
	int n;
	cin >> n;
	int elem;
	cout << "Enter elements:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> elem;
		l = Add(l, elem);
	}
	return l;
}

void output(list l) {
	while (!isEmpty(l)) {
		cout << l->d;
		l = l->next;
	}
}
