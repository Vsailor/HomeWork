typedef struct selem* stack;

struct selem {
	int d;
	stack next;
};

extern void Init(stack &s);
extern bool Empty(stack s);
extern void Push(stack &s, int c);
extern int Pop(stack &s);
extern void Input(stack &s, int& n);
extern void Output(stack s);
extern int Head(stack s);