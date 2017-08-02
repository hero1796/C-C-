#include <iostream>
#include <cstring>
using namespace std;

void generateBinary(int n) {
	string s, s2;
	for (int i = 0; i < n; ++i) {
		s += '0';
		s2 += '1';
	}
	cout << s << endl;
	while(s.compare(s2) != 0) {
		for(int i = n - 1; i >=0; i--) {
			if(s[i] == '0') {
				s[i] = '1';
				break;
			} else {
				s[i] = '0';
			}
		}
		cout << s << endl;
	}
}

int main() {
	int n;
	cin >> n;
	generateBinary(n);
	return 0;
}