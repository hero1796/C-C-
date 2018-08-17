#include <iostream>
#include <cstring>
using namespace std;
char min(char c1, char c2) {
	return c1 > c2 ? c2 : c1;
}
int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string s3;
	for(int i = 0; i < s1.length(); i++) {
		if(s1[i] == s2[i]) s3 += s1[i];
		else if(s1[i] < s2[i]) {
			cout << "-1";
			return 0;
		} else s3 += min(s1[i], s2[i]);
	}
	cout << s3;
	return 0;
}