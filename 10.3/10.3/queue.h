struct elem {
	int d;
	elem* next;
};

struct queue {
	elem* begin;
	elem* end;
};

extern void Init(queue& q);
extern bool isEmpty(queue q);
extern void Add(queue& q, int n);
extern int Take(queue& q);