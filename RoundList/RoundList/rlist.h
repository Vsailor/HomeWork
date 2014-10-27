typedef struct element* rlist;

struct element {
	int n;
	rlist next;
};

extern void Init(rlist& r);
extern int Length(rlist r);
extern void toNext(rlist& r);
extern int cur(rlist r);
extern void Insert(rlist& r, int n);
extern void Delete(rlist& r);