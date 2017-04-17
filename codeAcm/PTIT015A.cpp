#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k;
	cin >> k;
	string a, b, c, x;
	vector<string> vt_str;
	cin.ignore();
	for(int i = 0; i < k; i++) {
		getline(cin, a, ' ');
		getline(cin, b, ' ');
		getline(cin, c);
		x = a + b + c;
		sort(x.begin(), x.end());
		reverse(x.begin(), x.end());
		vt_str.push_back(x);
	}
	vector<string>::iterator iter;
	for (iter = vt_str.begin(); iter != vt_str.end(); iter++) {
		cout << *iter << endl;
	}
	return 0;
}

// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// // void sort_string(string &s) {
// // 	char tmp;
// // 	for(int i = 0; i < s.length() - 1; i++) {
// // 		for(int j = i + 1; j < s.length(); j++) {
// // 			if(s[i] > s[j]) {
// // 				tmp = s[i];
// // 				s[i] = s[j];
// // 				s[j] = tmp;
// // 			}
// // 		}
// // 	}
// // }

// int main() {
// 	int k;
// 	cin >> k;
// 	string a, b, c, x;
// 	string *s;
// 	cout << "k = " << k << endl;
// 	cin.ignore();
// 	for(int i = 0; i < k; i++) {
// 		getline(cin, a);
// 		getline(cin, b);
// 		getline(cin, c);
// 		x = a + b + c;
// 		sort(x.begin(), x.end());
// 		reverse(x.begin(), x.end());
// 		*(s+i) = x;
// 	}
// 	int num = 0;
// 	// while (num < 10) {
// 	// 	num++;
// 	// }
// 	// for (num = 0; num < 10; num++) cout << "a" << endl;
// 	// cout << "end loop" << endl;

// 	return 0;
// }