#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int getPriority(char c) {
	if (c == '(') {
		return 0;
	} else if (c == '+' || c == '-') {
		return 1;
	} else if (c == '*' || c == '/' || c == '^') {
		return 2;
	}
}

string convert(string infix) {
	string posfix = "";
	stack<char> s;
	for(int i = 0; i < infix.size(); i++) {
		char x = infix[i];
		if(x >= 97 && x <= 122) {
			posfix+=x;
		} else if(x == '(') {
			s.push(x);
		} else if(x == '+' || x == '-' || x == '*' || x == '/'
		 || x == '^') {
			if(s.empty()) {
				s.push(x);
			} else {
				if(getPriority(x) > getPriority(s.top())) {
					s.push(x);
				} else {
					posfix+=s.top();
					s.pop();
					s.push(x);
				}
			}
		} else if(x == ')') {
			while(s.top() != '(') {
				posfix+=s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while(!s.empty()) {
		posfix+=s.top();
		s.pop();
	}
	return posfix;
}

int main() {
	int t;
	cin>>t;
	fflush(stdin);
	string infix;
	vector<string> posfixVec;
	vector<string>::iterator iter;
	for(int i = 0; i < t; i++) {
		getline(cin, infix);
		posfixVec.push_back(convert(infix));
	}
	for(iter = posfixVec.begin(); iter != posfixVec.end(); iter++) {
		cout<<*iter<<"\n";
	}
	return 0;
}