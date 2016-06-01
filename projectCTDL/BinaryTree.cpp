#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int item;
struct Node{
	item key;
	Node *left, *right;
};
typedef Node *tree;
int insertNode(tree &t, item x) {
	if(t != NULL) {
		if(t->key == x) {
			return -1;
		}
		if(t->key > x) {
			return insertNode(t->left, x);
		}
		if(t->key < x) {
			return insertNode(t->right, x);
		}
	} else {
		t = new Node;
		t->key = x;
		t->left = t->right = NULL;
		return 1;
	}
}


void creatTree(tree &t) {
	int x;
	while(1) {
		cout<<"Nhap key cho Node : ";
		cin>>x;
		if(x == -1) {
			break;
		}
		int check = insertNode(t, x);
		if(check == -1){
			cout<<"Node nay da co ! \n";
		}
	}
}

void LNR(tree t) {
	if(t != NULL) {
		LNR(t->left);
		cout<<t->key<<"\t";
		LNR(t->right);
	}
}

Node *searchNode(tree t, item x) {
	if(t != NULL) {
		if(t->key == x) {
			Node *p = t;
			return p;
		}
		if(t->key < x) {
			return searchNode(t->right, x);
		}
		if(t->key > x) {
			return searchNode(t->left, x);
		}
	} else return NULL; 
}

int delNode(tree &t, item x) {
	if(t == NULL) {
		return 0;
	} else {
		if(t->key == x) {
			Node *p = t;
			if(t->left == NULL) {
				t = t->right;
			} else if(t->right == NULL) {
				t = t->left;
			} else {
				Node *q = t, *s = q->left;
				while(s->right != NULL) {
					q = s;
					s = s->right;
				}
				p->key = s->key;
				q->right = s->left;
				delete s;
			}
			return 1;
		}
		if(t->key > x) {
			return delNode(t->left, x);
		}
		if(t->key < x) {
			return delNode(t->right, x);
		}
	}
}
int main() {
	tree t;
	t = NULL;
	creatTree(t);
	LNR(t);
	
	int x;
	cout<<"\nNhap node can tim : ";
	cin>>x;
	Node *p = searchNode(t, x);
	if(p != NULL) {
		cout<<"Cay con trai la : ";
		LNR(p->left); cout<<"\n";
		cout<<"Cay con phai la : ";
		LNR(p->right);cout<<"\n";
		cout<<"Cay co khoa "<<x<<" la : ";
		LNR(p);
	} else {
		cout<<"\nDeo co nut nao nhu the ca !";
	}
	
	int y;
	cout<<"Nhap node can xoa : ";
	cin>>y;
	int check = delNode(t, y);
	if(check == 0) {
		cout<<"Khong tim thay Node can xoa ! \n";
	} else {
		cout<<"Cay sau khi xoa la : ";
		LNR(t);
	}
	return 0;
}
