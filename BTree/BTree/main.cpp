#include <iostream>
#include "btree.h"
using namespace std;

btree input(btree t) {
	int c;
	cin >> c;
	if (c != 0) {
		if (t == NULL) {
			t = new element;
			t->ls = NULL;
			t->rs = NULL;
		}
		if (t->ls == NULL) {
			t->d = c;
			t = input(t->ls);
		}
		if (t->rs == NULL) {
			t->d = c;
			t = input(t->rs);
		}

	}
	else {
		//if (t->ls!=NULL) {
		//	if (t->rs!=NULL) {
		//		cout << "DONE!";
		//		return NULL;
		//	} else {
		//		return input(t->rs);
		//	}
		//} else {
		//	return input(t->ls);
		//}
	}

	return t;
}

void main() {
	btree t = Init();
	input(t);
	system("pause");
}