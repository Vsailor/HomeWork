#include <iostream>
#include "rlist.h"
using namespace std;
void output(rlist a) {
	int save = cur(a);
	do {
		cout << cur(a);
		toNext(a);
	} while (save != cur(a));
}
void main() {
	rlist a;
	Init(a);
	Insert(a, 1);
	Insert(a, 2);
	Insert(a, 3);
	Insert(a, 4);
	output(a);
	cout << endl << Length(a) << endl;

	system("pause");
}