//Двозв'язний список (задача №10.22).

typedef struct dlelem *dlref;				// Вказівник на елемент списку

struct dlelem{								// Елемент списку
	int data;
	dlref next, prev;
};

struct dlist{								// Список
	dlref bg, cur, en;
};

extern void init(dlist &dl);					// Почати роботу
extern int empty(dlist dl);				// Чи порожній список?
extern int empty_beg(dlist dl);			// Чи порожній початок списку?
extern int empty_end(dlist dl);			// Чи порожній кінець списку?
extern void add_beg(dlist &dl, int n);				// Встати до початку списку
extern void add_end(dlist &dl, int n);				// Встати до кінця списку
extern void Next(dlist &dl);				// Перейти до наступного елемента
extern void prev(dlist &dl);				// Перейти до попереднього елемента
extern int current(dlist dl);				// Поточний елемент
extern void ins_before(dlist &dl, int n);	// Вставити елемент перед поточним
extern void ins_after(dlist &dl, int n);	// Вставити елемент після поточного
extern void del(dlist &dl);					// Видалити елемент
extern void input(dlist &dl);
extern void output(dlist dl);
