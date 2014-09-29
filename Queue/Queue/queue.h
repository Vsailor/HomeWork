struct qref {
	int d;
	qref* next;
};

struct queue {
	qref* begin;
	qref* end;
};

extern void Init(queue*& q);
extern bool isEmpty(queue q);
extern void Add(queue*& q, int n);
extern int Take(queue*& q);
extern void Output(queue*& q);