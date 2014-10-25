#include "deque.h"
#include <iostream>

using namespace std;

int length(deque d) {
	deque q;
	Init(q);
	int count = 0;
	while (!isEmpty(d)) {
		AddEnd(q, TakeBegin(d));
		count++;
	}
	d = q;
	return count;
}

// a will be = b
void set(deque& a, deque& b) {
	deque c = a;
	a = b;
	while (!isEmpty(c)) {
		TakeEnd(c);
	}
}

void main() {
	deque d;
	Init(d);
	AddEnd(d, 1);
	AddEnd(d, 2);
	AddEnd(d, 3);
	deque c;
	Init(c);
	AddEnd(c, 4);
	AddEnd(c, 5);
	AddEnd(c, 6);
	set(c, d);
	cout << "Length: " << length(c) << endl;
	Output(d);


	system("pause");
}