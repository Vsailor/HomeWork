#include "queue.h"
#include <iostream>

using namespace std;

void main() {
	queue* q;
	Init(q);
	Add(q, 1);
	Add(q, 2);
	Add(q, 3);
	Add(q, 4);

	Output(q);


	system("pause");
}