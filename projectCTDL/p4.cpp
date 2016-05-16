#include<iostream>
//#include<stdlib.h>
using namespace std;
struct Node {
	int item;
	Node *next;
};
struct List {
	Node *head, *tail;
};

void addFirst(List &list, int x) {
	int t=1;
	while(t==1) {
		Node *node = new Node;
		cout<<"\nNhap item : ";
		cin>>x;
		node->item = x;
		if(list.head == NULL) {
			list.head = list.tail = node;
		} else {
			node->next = list.head;
			list.head = node;
		}
		cout<<"\nNhap 1 de tiep tuc, 0 de dung lai : ";
		cin>>t;
	}
}

void addTail(List &list, int x) {
	int t=1;
	while(t==1) {
		Node *node = new Node;	
		cout<<"\nNhap item : ";
		cin>>x;
		node->item = x;
		if(list.head == NULL) {
			list.head  = node;
			list.tail = list.head;
		} else {
			list.tail->next = node;
			list.tail = node;
		}
		cout<<"\nNhap 1 de tiep tuc, 0 de dung lai : ";
		cin>>t;
	}
}

void addMiddle(List &list, int x, int position) {
	cout<<"\nNhap vi tri can them : ";
	cin>>position;
	Node *node = new Node;
	cout<<"\nNhap item : ";
	cin>>x;
	node->item = x;
	Node *i = list.head;
	int count = 0;
	while(i != NULL) {
		count++;
		if(count == (position -1)) {
			node->next = i->next;
			i->next = node;
			break;
		}
		i = i->next;
	}
}

void deleteNode(List &list, int position) {
	cout<<"\nNhap vi tri can xoa : ";
	cin>>position;
	Node *i = list.head;
	int count = 0;
	while(i->next != NULL) {
		count++;
		if(count == (position -1)) {
			Node *temp = i->next;
			i->next = temp->next;
			delete(temp);
			break;
		}
		i = i->next;
	}
}

void scanList(List &list) {
	Node *i = list.head;
	list.tail->next= NULL;
	cout<<"Head : "<<list.head->item<<"  Tail: "<<list.tail->item;
	cout<<"\n";
	while(i != NULL) {
		cout<<i->item<<"\t";
		i = i->next;
	}
}
int main() {
	int x, position;
	List list;
	list.head = list.tail = NULL;
	
	addTail(list, x);
	scanList(list);
	cout<<"\nThem vao dau DS : ";
	addFirst(list, x);
	cout<<"\nThem vao cuoi DS : ";
	addTail(list, x);
	scanList(list);
	
	addMiddle(list, x, position);
	scanList(list);
	
	deleteNode(list, position);
	scanList(list);
	return 0;
}
