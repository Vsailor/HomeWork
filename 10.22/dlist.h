//�����'����� ������ (������ �10.22).

typedef struct dlelem *dlref;				// �������� �� ������� ������

struct dlelem{								// ������� ������
	int data;
	dlref next, prev;
};

struct dlist{								// ������
	dlref bg, cur, en;
};

extern void init(dlist &dl);					// ������ ������
extern int empty(dlist dl);				// �� ������� ������?
extern int empty_beg(dlist dl);			// �� ������� ������� ������?
extern int empty_end(dlist dl);			// �� ������� ����� ������?
extern void add_beg(dlist &dl, int n);				// ������ �� ������� ������
extern void add_end(dlist &dl, int n);				// ������ �� ���� ������
extern void Next(dlist &dl);				// ������� �� ���������� ��������
extern void prev(dlist &dl);				// ������� �� ������������ ��������
extern int current(dlist dl);				// �������� �������
extern void ins_before(dlist &dl, int n);	// �������� ������� ����� ��������
extern void ins_after(dlist &dl, int n);	// �������� ������� ���� ���������
extern void del(dlist &dl);					// �������� �������
extern void input(dlist &dl);
extern void output(dlist dl);
