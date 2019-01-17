#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* top = NULL;

Node* initNode(int x) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = x;
	node->next = NULL;
	return node;
}

void push(int x) {
	Node* newNode = initNode(x);
	if(top == NULL) {
		top = newNode;
	} else {
		newNode->next = top;
		top = newNode;
	}
}

int pop() {
	Node* tmp = top;
	if(tmp == NULL) {
		return -1;
	} else {
		top = tmp->next;
		return tmp->data;
	}
	free(tmp);
}

void printAll() {
	Node* tmp = top;
	if(tmp == NULL) {
		cout<<"Empty";
	} else {
		while(tmp->next != NULL) {
			cout<<tmp->data<<"\n";
			tmp = tmp->next;
		}
		cout<<tmp->data<<"\n";
	}
}

int main() {
	int choice;
	while(1) {
		cout<<"Lua chon: ";
		cin>>choice;
		switch(choice) {
			case 1: {
				cout<<"Nhap x: ";
				int x;
				cin>>x;
				push(x);
				break;
			}	
			case 2: {
				printAll();
				break;
			}
			case 3: {
				cout<<pop();
				break;
			}
			case 0:
				return 0;
		}
	}
	return 0;
}


// #include <iostream>
// #include <string>
// using namespace std;

// struct Node {
// 	int x;
// 	Node* next;
// };

// struct Stack {
// 	Node* top;
// };

// void init(Stack* s) {
// 	s->top = NULL;
// }

// int isEmpty(Stack* s) {
// 	return s->top == NULL ? 1 : 0;
// }

// int size(Stack* s) {
// 	int cnt = 0;
// 	Node* i = s->top;
// 	while(i != NULL) {
// 		cnt++;
// 		i = i->next;
// 	}
// 	return cnt;
// }

// int peak(Stack* s) {
// 	if(isEmpty(s) == 0) {
// 		return s->top->x;
// 	} else {
// 		return -1;
// 	}
// }

// void push(int pX, Stack* s) {
// 	Node* newNode = (Node*) malloc(sizeof(Node));
// 	newNode->x = pX;
// 	newNode->next = s->top;
// 	s->top = newNode;
// }

// int pop(Stack* s) {
// 	if(isEmpty(s) == 0) {
// 		Node* tmp = s->top;
// 		s->top = s->top->next;
// 		return tmp->x;
// 	}
// }

// int main() {
// 	Stack* s = (Stack*) malloc(sizeof(Stack));
// 	string str = "";
// 	while(str != "end") {
// 		getline(cin, str);
// 		if(str == "init") {
// 			init(s);
// 		} else if(str.substr(0, str.find(" ")) == "push") {
// 			push(stoi(str.substr(str.find(" ") + 1)), s);
// 		} else if(str == "pop") {
// 			pop(s);
// 		} else if(str == "top") {
// 			cout<<peak(s)<<"\n";
// 		} else if(str == "size") {
// 			cout<<size(s)<<"\n";
// 		} else if(str == "empty") {
// 			cout<<isEmpty(s)<<"\n";
// 		}
// 	}
// 	return 0;
// }