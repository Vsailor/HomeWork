#include "stack.h"

#include <iostream>

using namespace std;
void main() {
	list l = Init();
	l = Add(l, 4);
	l = Add(l, 5);
	l = Add(l, 6);
	list k = Init();
	k = Add(k, 1);
	k = Add(k, 2);
	k = Add(k, 3);

	stack* a;
	Init(a);
	Push(a, l);
	Push(a, k);
	list t;

	while (!Empty(a)) {
		t = Pop(a);
		while (!isEmpty(t)) {
			cout << Head(t);
			t = Tail(t);
		}
	}
	system("pause");
}
