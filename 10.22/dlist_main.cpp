#include <iostream>
#include "dlist.h"

using namespace std;

bool Search(dlist& l, int x) {
	dlist k = l;
	while (!empty(k)) {
		if (k.cur->data == x) {
			cout << "Found" << endl;
			return true;
		}
		Next(k);
	}
	cout << "Not found" << endl;
	return false;
}

void Sort(dlist& l) {
	dlist k;
	init(k);
	int count = 1;
	l.cur = l.bg;
	while (l.cur != l.en) {
		l.cur = l.cur->next;
		count++;
	}
	l.cur = l.bg;
	int* ArrayList = new int[count];
	for (int i = 0; i < count; i++) {
		ArrayList[i] = l.cur->data;
		l.cur = l.cur->next;
	}
	int t;
	for (int i = 0; i < count; i++) {
		for (int k = 0; k < count; k++) {
			if (ArrayList[i] < ArrayList[k]) {
				t = ArrayList[i];
				ArrayList[i] = ArrayList[k];
				ArrayList[k] = t;
			}
		}
	}
	while (!empty(l)) {
		del(l);
	}
	for (int i = 0; i < count; i++) {
		add_end(l, ArrayList[i]);
	}

}
// return l1 = l1+l2
void Concat(dlist& l1, dlist& l2) {
	l2.cur = l2.bg;
	while (l2.cur != NULL) {
		add_end(l1, l2.cur->data);
		l2.cur = l2.cur->next;
	}
}

void Let(dlist& l1, dlist& l2) {
	dlist t = l1;
	l1.bg = l2.bg;
	l1.cur = l2.cur;
	l1.en = l2.en;
	while (!empty(t)) {
		del(t);
	}
}
// l1 is begin of l2
bool IsBeg(dlist& l1, dlist& l2) {
	l1.cur = l1.bg;
	l2.cur = l2.bg;
	while (l1.cur != NULL) {
		if (l2.cur == NULL) {
			return false;
		}
		if (l1.cur->data != l2.cur->data) {
			return false;
		}
		l1.cur = l1.cur->next;
		l2.cur = l2.cur->next;
	}
	return true;
}


void main(){
	dlist dl1, dl2;
	input(dl1);
	input(dl2);
	Sort(dl1);
	Sort(dl2);
	Concat(dl1, dl2);
	cout << "Now dl2 is begin of dl1 : " << IsBeg(dl2, dl1) << endl;
	cout << "What to search?" << endl;
	int e;
	cin >> e;
	Search(dl1, e);
	output(dl1);
	system("pause");
}