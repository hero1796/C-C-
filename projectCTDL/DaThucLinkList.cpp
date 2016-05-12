#include<iostream>
using namespace std;
struct Node {
	int soMu;
	int heSo;
	Node *next;
};
struct List {
	Node *head, *tail;
};

Node *initNode(int heSo, int soMu) {
	Node *node = new Node;
	node->heSo = heSo;
	node->soMu = soMu;
	return node;
}

//void creatListFirst(List &list, Node *node) {
//	int t=1;
//	while(t==1) {
//		Node *node = new Node;
//		cout<<"\nNhap he So : ";
//		cin>>node->heSo;
//		cout<<"\nNhap so mu : ";
//		cin>>node->soMu;
//		if(list.head == NULL) {
//			list.head = list.tail = node;
//		} else {
//			node->next = list.head;
//			list.head = node;
//		}
//		cout<<"\nNhap 1 de tiep tuc, 0 de dung lai : ";
//		cin>>t;
//	}
//}

void creatListTail(List &list) {
	int t=1;
	while(t==1) {
		Node *node = new Node;
		cout<<"\nNhap he So : ";
		cin>>node->heSo;
		cout<<"\nNhap so mu : ";
		cin>>node->soMu;
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
void addTail(List &list, Node *node) {
		if(list.head == NULL) {
			list.head  = node;
			list.tail = list.head;
		} else {
			list.tail->next = node;
			list.tail = node;
		}
}

//void addMiddle(List &list, int position) {
//	cout<<"\nNhap vi tri can them : ";
//	cin>>position;
//	Node *node = new Node;
//	cout<<"\nNhap he So : ";
//	cin>>node->heSo;
//	cout<<"\nNhap so mu : ";
//	cin>>node->soMu;
//	Node *i = list.head;
//	int count = 0;
//	while(i != NULL) {
//		count++;
//		if(count == (position -1)) {
//			node->next = i->next;
//			i->next = node;
//			break;
//		}
//		i = i->next;
//	}
//}

//void deleteNode(List &list, int position) {
//	cout<<"\nNhap vi tri can xoa : ";
//	cin>>position;
//	Node *i = list.head;
//	if(position = 1) {
//		Node *temp = list.head;
//		list.head = list.head->next;
//		delete(temp);
//	} else {
//		int count = 0;
//		while(i->next != NULL) {
//			count++;
//			if(count == (position -1)) {
//				Node *temp = i->next;
//				i->next = temp->next;
//				delete(temp);
//				break;
//			}
//			i = i->next;
//		}
//	}
//}
void sortList(List &list) {
	for(Node *i = list.head; i != NULL; i = i->next) {
		for(Node *j = i->next; j!= NULL; j = j->next) {
			if(j->soMu < i->soMu) {
				int hesoTemp = i->heSo;
				i->heSo = j->heSo;
				j->heSo = hesoTemp;
				
				int soMuTemp = i->soMu;
				i->soMu = j->soMu;
				j->soMu = soMuTemp;
			}
		}
	}
}
void addition(List &listC, List listA, List listB) {
	Node *i = listA.head;
	Node *j = listB.head;
	Node *pC;
	while(i != NULL || j!= NULL) {
		if(i != NULL && j == NULL) {
			pC = initNode(i->heSo, i->soMu);
			addTail(listC, pC);
			i = i->next;
			continue;
		}
		if(i == NULL && j!= NULL) {
			pC = initNode(j->heSo, j->soMu);
			addTail(listC, pC);
			j = j->next;
			continue;
		}
		if(i->soMu == j->soMu) {
			pC = initNode(i->heSo + j->heSo, i->soMu);
			addTail(listC, pC);
			j = j->next;
			i = i->next;
		} else if(i->soMu > j->soMu) {
			pC = initNode(j->heSo, j->soMu);
			addTail(listC, pC);
			j= j->next;
			continue;
		} else if(i->soMu < j->soMu){
			pC = initNode(i->heSo, i->soMu);
			addTail(listC, pC);
			i = i->next;
			continue;
		}
	}
}

void subtraction(List &listC, List listA, List listB) {
	Node *i = listA.head;
	Node *j = listB.head;
	Node *pC;
	while(i != NULL || j!= NULL) {
		if(i != NULL && j == NULL) {
			pC = initNode(i->heSo, i->soMu);
			addTail(listC, pC);
			i = i->next;
			continue;
		}
		if(i == NULL && j!= NULL) {
			pC = initNode(0-j->heSo, j->soMu);
			addTail(listC, pC);
			j = j->next;
			continue;
		}
		if(i->soMu == j->soMu) {
			pC = initNode(i->heSo - j->heSo, i->soMu);
			addTail(listC, pC);
			j = j->next;
			i = i->next;
		} else if(i->soMu > j->soMu) {
			pC = initNode(0-j->heSo, j->soMu);
			addTail(listC, pC);
			j= j->next;
			continue;
		} else if(i->soMu < j->soMu){
			pC = initNode(i->heSo, i->soMu);
			addTail(listC, pC);
			i = i->next;
			continue;
		}
	}
}

void scanList(List list) {
	Node *i = list.head;
	list.tail->next= NULL;
	cout<<"\n";
	while(i != NULL) {
		cout<<i->heSo<<"X^"<<i->soMu;
		if(i->next != NULL) {
			cout<<" + ";
		}
		i = i->next;
	}
}
int main() {
	int position;
	List list1, list2, list3, list4;
	list1.head = list1.tail = NULL;
	list2.head = list2.tail = NULL;
	list3.head = list3.tail = NULL;
	list4.head = list4.tail = NULL;
	cout<<"\nNhap da thuc A : ";
	creatListTail(list1);
	cout<<"\nNhap da thuc B : ";
	creatListTail(list2);
	scanList(list1);
	scanList(list2);
	sortList(list1);
	sortList(list2);
	scanList(list1);
	scanList(list2);
	addition(list3, list1, list2);
	scanList(list3);
	subtraction(list4, list1, list2);
	scanList(list4);
	return 0;
}
