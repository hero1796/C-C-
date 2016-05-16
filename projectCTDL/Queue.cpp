#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};
struct Queue {
	Node *head, *tail;
};
void initQueue(Queue &q) {
	q.head = q.tail = NULL;
}
Node *initNode(int x) {
	Node *node = new Node;
	node->data = x;
	return node;
}

void push(Queue &q, int x) {
	if(q.head == NULL) {
		q.head = initNode(x);
		q.tail = q.head;
	} else {
		q.tail->next = initNode(x);
		q.tail = q.tail->next;
	}
}
void get(Queue &q) {
	if(q.head == NULL) {
		cout<<"Hang doi rong !\n";
	} else {
		Node *p = q.head;
		q.head = q.head->next;
		cout<<p->data<<"\t";
	}
}
void display(Queue &q) {
	Node *i = q.head;
	q.tail->next = NULL;
	while(i != NULL) {
		cout<<i->data<<"\t";
		i = i->next;
	}
}
int main() {
	Queue q1;
	initQueue(q1);
	int t1 = 1, data;
	while(t1 == 1) {
		cout<<"\nNhap data cua node : ";
		cin>>data;
		push(q1, data);
		cout<<"\nNhap 1 de tiep tuc, 0 de dung lai : ";
		cin>>t1;
	}
	display(q1);
 	cout<<"-------Lay ra cac phan tu cua Queue------------\n";
	while(t1 == 0) {
		cout<<"\nNhap 0 de tiep tuc 1 de dung lai: ";
		cin>>t1;
		get(q1);
	}
	return 0;
}
