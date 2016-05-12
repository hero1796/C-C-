#include<iostream>
#include<cstring>

using namespace std;
struct Node {
	char data;
	Node *next;
};
struct Stack {
	Node *top;
};
void initStack(Stack &s) {
	s.top = NULL;
}
Node *initNode(char x) {
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
void push(Stack &s, char x) {
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
		cout<<p->data;
	}
}
void display(Stack &s) {
	if(isEmpty(s) == true) {
		cout<<"Ngan xep rong ! \n";
	} else {
		Node *i = s.top;
		while(i != NULL) {
			cout<<i->data;
			i = i->next;
		}
	}
}
int main() {
	Stack s1;
	initStack(s1);
	string c;
	getline(cin, c);
	fflush(stdin);

	for(int i=0; i< c.length(); i++) {
		push(s1, c[i]);
	}
	display(s1);
}
