#include "deque.h"
#include <iostream>

using namespace std;

void main() {
	deque* d;
	Init(d);
	AddEnd(d, 1);
	AddEnd(d, 2);
	AddEnd(d, 3);
	AddBegin(d, 9);
	AddBegin(d, 8);
	AddBegin(d, 7);
	AddBegin(d, 6);


	system("pause");
}