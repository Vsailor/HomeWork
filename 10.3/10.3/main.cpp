#include <iostream>
#include "queue.h"

using namespace std;

int Length(queue q) {
	int count = 0;
	queue a;
	Init(a);
	while (!isEmpty(q)) {
		Add(a, Take(q));
		count++;
	}
	q = a;
	return count;
}

void main() {
	queue a;
	Init(a);
	cout << "How many elements?" << endl;
	int n;
	cin >> n;
	int element;
	for (int i = 0; i < n; i++) {
		cout << "Enter element #" << i << ":";
		cin >> element;
		Add(a, element);
	}
	cout << "Length: " << Length(a) << endl;
	while (!isEmpty(a)) {
		cout << Take(a) << endl;
	}
	cout << endl;

	system("pause");
}