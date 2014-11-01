#include <iostream>
#include "btree.h"
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