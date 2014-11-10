#include <iostream>
#include "btree.h"
#define ZERO -1
using namespace std;

btree Init() {
	return NULL;
}

bool isEmpty(btree t){
	return (t == NULL);
}
int root(btree t) {
	return t->d;
};

btree leftSon(btree t) {
	return t->ls;
};
btree rigthSon(btree t) {
	return t->rs;
}

void addNode(int x, btree& t)
{
	if (t == NULL)
	{
		t = new element;
		t->d = x;
		t->ls = NULL;
		t->rs = NULL;
	}

	if (x < t->d)
	{
		if (t->ls != NULL) {
			addNode(x, t->ls);
		}
		else
		{
			t->ls = new element;
			t->ls->ls = NULL;
			t->ls->rs = NULL;
			t->ls->d = x;
		}
	}

	if (x > t->d)
	{
		if (t->rs != NULL)
		{
			addNode(x, t->rs);
		}
		else {
			t->rs = new element;
			t->rs->ls = NULL;
			t->rs->rs = NULL;
			t->rs->d = x;
		}
	}

}


btree makeTree(int n) {
	btree t = Init();
	int k;
	for (int i = 0; i <n; i++) {
		cin >> k;
		addNode(k, t);

	}
	return t;
}
void Print(btree t)
{
	if (t != NULL) {
		cout << t->d<<"   ";
		Print(t->rs);
		Print(t->ls);
	}
}
/*void Print(btree t)
{
	if (t != NULL)
	{
		Print(t->ls);
		cout << t->d << endl;
		Print(t->rs);
	}
	cout << " | ";
}
*/
bool Search(btree t, int n)
{
	bool a1=0, a2=0;
	if (t != NULL)
	{
		a1 = Search(t->ls, n);
		if (t->d == n) {
			return 1;
		}
		a2 = Search(t->rs, n);
	}
	return a1 || a2;
}

int Height(btree t) 
{
	int l = ZERO;
	int r = ZERO;
	if (t != NULL)
	{
		l = Height(t->ls);
		r = Height(t->rs);
	}
	if (l > r) {
		return ++l;		
	}
	else {
		return ++r;
	
	}
}
