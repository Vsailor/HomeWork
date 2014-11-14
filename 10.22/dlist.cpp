#include <iostream>
#include "dlist.h"

using namespace std;

void init(dlist &dl){
	dl.bg = dl.cur = dl.en = NULL;
}

int empty(dlist dl){
	return(dl.cur == NULL);
}

int empty_beg(dlist dl){
	return(dl.bg == NULL);
}

int empty_end(dlist dl){
	return(dl.en == NULL);
}

void add_beg(dlist &dl, int n){
	dlref p = new dlelem;
	p->data = n;
	if(empty(dl)){
		dl.en = dl.cur = dl.bg = p;
		p->next = p->prev = NULL;
	}
	else{
		p->prev = NULL;
		dl.bg->prev = p;
		p->next = dl.bg;
		dl.bg = p;
	}
}

void add_end(dlist &dl, int n){
	dlref p = new dlelem;
	p->data = n;
	if(empty(dl)){
		dl.en = dl.cur = dl.bg = p;
		p -> next = p -> prev = NULL;
	}
	else{
		p -> next = NULL;
		dl.en -> next = p;
		p -> prev = dl.en;
		dl.en = p;
	}
}

void Next(dlist &dl){
	if(empty(dl)){
		dlref l = new dlelem;
		l->prev = dl.cur;
		dl.cur->next = l;
	}
	else{
		dl.cur = dl.cur->next;
	}
}

void prev(dlist &dl){
	dl.cur = dl.cur->prev;
}

int current(dlist dl){
	return dl.cur->data;
}

void ins_before(dlist &dl, int n){
	dlref p = new dlelem;
	p->data = n;
	p->next = dl.cur;
	if(empty(dl) == true){							// ������� ������
		p->prev = NULL;
		dl.bg = dl.en = dl.cur = p;					// ���. 10.27 �)
	}
	else{
		if(dl.cur == dl.bg)							// ������� ����� ������ ���������
		{
			p->prev = NULL;
			dl.bg = p;
		}
		else{										// ������� �������� ������
			p->prev = dl.cur->prev;
			dl.cur->prev = p;
		}
		dl.cur->prev = p;
		// ���. 10.27 �), �)
	}
}

void ins_after(dlist &dl, int n){
	dlref p = new dlelem;
	p->data = n;
	p->prev = dl.cur;
	if(empty(dl)){
		p->next = NULL;
		dl.bg = dl.en = dl.cur = p;
	}
	else{
		if(dl.cur == dl.en)
		{
			p->next = NULL;
			dl.en = p;
		}
		else{
			p->next = dl.cur->next;
			dl.cur->next = p;
		}
		dl.cur->next = p;
	}
}

void del(dlist &dl){
	dlref p = new dlelem;
	if(empty(dl)){
		cout << "List is empty.\n";

	}
	p = dl.cur;
	if(dl.cur == dl.bg && dl.cur == dl.en){			// ������ � ������ ��������
		dl.bg = dl.cur = dl.en = NULL;
	}
	else if(dl.cur != dl.en){						// �������� ������� �� �������
		dl.cur = dl.cur->next;
		dl.cur->prev = p->prev;
		if (p == dl.bg){							// �������� ������� ������
			dl.bg = dl.cur;
		}
		else{										// �������� ������� �� ������
			p->prev->next = dl.cur;
		}
	}
	else{											// �������� ������� �������
		dl.cur = dl.cur->prev;
		dl.cur->next = NULL;
		dl.en = dl.cur;
	}
	delete p;
}

void input(dlist &dl){
	int elem, n;
	cout << "Enter the number of elements in list: ";
	cin >> n;
	init(dl);
	for(int i = 1; i <= n; i++){
		cout << "Enter element, which has number " << i << " : ";
		cin >> elem;
		add_end(dl,elem);
	}
}

void output(dlist dl){
	dl.cur = dl.bg;
	do{
		cout << dl.cur->data;
		Next(dl);
	}while(!empty(dl));
	cout << endl;
}

