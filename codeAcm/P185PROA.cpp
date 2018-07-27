#include<iostream>
using namespace std;

string makeMinimumNum(string s) {
	for (int i = 0; i < s.length(); ++i) {
		if('9' - s[i] < s[i] - '0') {
			s[i] = '9' - s[i] + '0';
		}
	}
	if(s[0] == '0'){
		s[0] = '9';
	}
	return s;
}

int main() {
	int t;
	cin>>t;
	cin.ignore();
	string n;
	string res[t];
	for (int i = 0; i < t; ++i) {
		getline(cin, n);
		res[i] = makeMinimumNum(n);
	}
	for (int i = 0; i < t; ++i) {
		cout<<res[i]<<"\n";
	}
	return 0;
}