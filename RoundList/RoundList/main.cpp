#include <iostream>
#include "rlist.h"
using namespace std;

void main() {
	rlist a;
	Init(a);
	Insert(a, 1);
	Insert(a, 2);
	Insert(a, 3);
	Insert(a, 4);
	while (Length(a) != 0) {
		cout << cur(a);
		toNext(a);
	}
	cout << Length(a);

	system("pause");
}