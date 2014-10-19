#include "list.h"
#include <iostream>

using namespace std;
void main() {
	list l = Init();
	l = Add(l, 4);
	l = Add(l, 5);
	l = Add(l, 6);
	l = Tail(l);
	l = Tail(l);
	l = Tail(l);

	system("pause");
}
