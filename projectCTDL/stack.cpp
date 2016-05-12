#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};
struct Stack {
	Node *top;
};
void initStack(Stack &s) {
	s.top = NULL;
}
Node *initNode(int x) {
	Node *node = new Node;
	node->data = x;
	return node;
}
bool isEmpty(Stack &s) {
	if(s.top == NULL) {
		return true;
	}
	return false;
}
void push(Stack &s, int x) {
	Node *node = initNode(x);
		node->next = s.top;
		s.top = node;
}
void pop(Stack &s) {
	if(isEmpty(s) == true) {
		cout<<"Ngan xep rong ! \n";
	} else {
		Node *p = s.top;
		s.top = s.top->next;
		cout<<p->data<<"\t";
	}
}
void display(Stack &s) {
	if(isEmpty(s) == true) {
		cout<<"Ngan xep rong ! \n";
	} else {
		Node *i = s.top;
		while(i != NULL) {
			cout<<i->data<<"\t";
			i = i->next;
		}
	}
}
int main() {
	Stack s1;
	initStack(s1);
	int data, t1 = 1, t2 = 1;
	while (t1==1) {
		cout<<"\nNhap data : "; cin>>data;
		push(s1, data);
		cout<<"\nNhap 1 de tiep tuc : ";
		cin>>t1;
	}
	display(s1);
	while (t2==1) {
		cout<<"\nNhap 1 de tiep tuc : ";
		cin>>t2;
		pop(s1);
	}
}
