#include <iostream>
#include "btree.h"
using namespace std;



void main()
{
	int n;
	cout << "How many nodes do you want?" << endl;
	cin >> n;
	cout << "Enter elements" << endl;
	btree t = makeTree(n);
	Print(t);
	cout << endl;
	cout << "What number to search?" << endl;
	cin >> n;
	cout << "Is exist: " << Search(t, n);
	cout << endl;
	cout << "Height = " << Height(t) << endl;
	system("pause");
}