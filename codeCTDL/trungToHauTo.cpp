#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main() {
	stack<char> s;
	string x;
	string y;
	cout<<"Nhap bieu thuc dang trung to : ";
	fflush(stdin);
	getline(cin, x);
	cout<<x<<"\n";
	fflush(stdin);
	for(int i =0; i< x.length(); i++) {
		if(x[i] == '(') {

		}
		if(x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/') {
			s.push(x[i]);

		}
		if(x[i] == '1' || x[i] == '2' || x[i] == '3' || x[i] == '4' || x[i] == '5' || x[i] == '6' || x[i] == '7' || x[i] == '8' || x[i] == '9' || x[i] == '0' ) {
			cout<<x[i];
		}
		if(x[i] == ')') {
			cout<<s.top();
			s.pop();
		}
	}
	return 0;
}

