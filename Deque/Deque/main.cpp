#include "deque.h"
#include <iostream>

using namespace std;

void main() {
	deque* d;
	Init(d);
	AddEnd(d, 1);
	AddEnd(d, 2);
	AddEnd(d, 3);
	cout << TakeBegin(d);
	cout << TakeEnd(d);
	cout << TakeBegin(d);


	system("pause");
}