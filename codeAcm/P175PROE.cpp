#include <iostream>
#include <string>
using namespace std;

int main() {
	int n = 0, tmp = 0;
	int count = 0;
	string s = "";
	cin >> s;
	cin.ignore();
	if(s.length() == 1) {
		cout << 0;
		return 0;
	} 
	for(int i=0; i<s.length(); i++) { 
		tmp = s.at(i) - 48;
		n += tmp;
	}
	count++;
	if(n <= 10) cout << count <<endl;
	else {
		int m;
		while(n >= 10) {
			m = 0;
			while(n > 0) {
				m += n%10;
				n = n/10;
			}
			n = m;
			count++;
		}
		cout << count;
	}
	
	return 0;
}