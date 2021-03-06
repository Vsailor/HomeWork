typedef struct element* btree;
struct element {
	int d;
	btree ls;
	btree rs;
};

extern btree Init();
extern bool isEmpty(btree t);
extern int root(btree t);
extern btree leftSon(btree t);
extern btree rigthSon(btree t);
extern btree makeTree(int n);
extern void Print(btree t);
extern bool Search(btree t, int n);
extern int Height(btree t);