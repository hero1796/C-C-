#include <iostream>
#include <cstring>
using namespace std;
int main() {
	string s;
	int i, j, cnt = 0;
	getline(cin, s);
	for(i = 0; i < s.length() - 1; i++)
		for(j = i + 1; j < s.length();) {
			if(s[i] == 'V' && s[j] == 'K') {
				cnt++;
				i++;
			}
			break;
		}
	for(i = 0; i < s.length() - 1; i++)
		for(j = i + 1; j < s.length();) {
			if(s[i] == 'K' && s[j] == 'K' && s[i-1] != 'V') {
				cnt++;
				cout << cnt;
				return 0;
			} else if(s[i] == 'V' && s[j] == 'V' && s[j+1] != 'K') {
				cnt++;
				cout << cnt;
				return 0;
			} else break;
		}
	cout << cnt;
	return 0;
}