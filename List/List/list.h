typedef struct elem* list;

struct elem {
	int d;
	list next;
};

extern list Init();
extern bool isEmpty(list l);
extern int Head(list l);
extern list Tail(list l);
extern list Add(list l, int n);
extern list input();
extern void output(list l);