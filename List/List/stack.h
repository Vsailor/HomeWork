#include "list.h"
struct stack {
	list d;
	stack* next;
};

extern void Init(stack*& s);
extern bool Empty(stack*& s);
extern void Push(stack*& s, list c);
extern list Pop(stack*& s);
