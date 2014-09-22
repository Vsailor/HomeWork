typedef struct selem* stack;

struct selem {
	char d;
	stack next;
};

extern int Init(stack &s);
extern int Empty(stack s);
extern int Push(stack &s, char c);
extern int Pop(stack &s);