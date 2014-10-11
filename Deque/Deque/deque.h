struct dref {
	int d;
	dref* next;
	dref* prev;
};

struct deque {
	dref* begin;
	dref* end;
};

extern void Init(deque*& q);
extern bool isEmpty(deque*& q);
extern void AddBegin(deque*& q, int n);
extern void AddEnd(deque*& q, int n);
extern int TakeBegin(deque*& q);
extern int TakeEnd(deque*& q);
extern void Output(deque*& q);
extern void Invers(deque*& q);
// add deque b to deque a
extern void concat(deque*& a, deque*& b);
// returns 1 if a == b and 0 if a != b
//extern bool isEquals(deque*& a, deque*& b);