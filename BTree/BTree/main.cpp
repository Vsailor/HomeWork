#include <iostream>
#include "btree.h"
using namespace std;

btree input(btree t) {
	int c;

	if (t == NULL) {
		t = new element;
		t->ls = NULL;
		t->rs = NULL;
		t = input(t);
		if (t->d == 0)
			return t;
	}
	cin >> c;
	if (t->ls == NULL) {
		t->d = c;
		if (c == 0)
			return t;
		t = input(t->ls);
	}
	if (t->rs == NULL) {
		t->d = c;
		if (c == 0)
			return t;
		t = input(t->rs);
	}
	return t;
}

void main() {
	btree t = Init();
	input(t);
	system("pause");
}