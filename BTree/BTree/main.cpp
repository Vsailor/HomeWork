#include <iostream>
#include "btree.h"
using namespace std;



void main()
{
	int n;
	cout << "How many nodes do you want?" << endl;
	cin >> n;
	btree t = makeTree(n);
	Print(t);
	system("pause");
}