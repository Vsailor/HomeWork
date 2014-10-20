typedef struct element* refl;

struct element {
	int n;
	refl next;
};

struct list {
	element* begin;
	element* current;
};

extern void Init(list &l);
extern bool emptyEnd(list l);
extern void toFirst(list &l);
extern void toNext(list &l);
extern int getCurrent(list l);
extern refl findPrev(list &l);
extern void Insert(list &l, int n);
extern void Delete(list &l);