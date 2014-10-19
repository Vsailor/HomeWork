#include <iostream>
#include <random>
#include "queue.h"
using namespace std;

void main() {
	queue q;
	Init(q);
	cout << "How many elements to put in queue?" << endl;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		Add(q, i);
		cout << i << " added to queue" << endl;
	}
	cout << "How many tests do you want?" << endl;
	int n;
	cin >> n;
	int a;
	int e;
	for (int i = 0; i < n; i++) {
		if (isEmpty(q)) {
			cout << "Queue is empty!" << endl;
			break;
		}
		a = rand() % 2;
		cout << "Random = " << a << endl;
		if (a == 0) {
			cout << "Element " << Take(q) << " has been taken" << endl;
		}
		if (a == 1) {
			cout << "Enter new element: ";
			cin >> e;
			Add(q, e);
			cout << endl;
		}
	}
	cout << endl << "Finally queue:" << endl;
	while (!isEmpty(q)) {
		cout << Take(q) << endl;
	}
	system("pause");
}