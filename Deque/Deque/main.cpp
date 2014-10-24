#include "deque.h"
#include <iostream>

using namespace std;

void main() {
	deque d;
	deque q;
	Init(d);
	Init(q);
	AddEnd(d, 1);
	AddEnd(d, 2);
	AddEnd(d, 3);
	AddEnd(q, 4);
	AddEnd(q, 5);
	AddEnd(q, 6);
	concat(d, q);
	Output(d);


	system("pause");
}