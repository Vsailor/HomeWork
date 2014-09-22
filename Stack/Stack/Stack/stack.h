typedef struct selem* stack;

struct selem {
	char d;
	stack next;
};

extern void Init(stack &s);
extern bool Empty(stack s);
extern void Push(stack &s, char c);
extern char Pop(stack &s);
extern void Input(stack &s);
extern void Output(stack s);