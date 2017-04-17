#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int i, j, k, l;

int count(string s[], int m) {
	for (i = 0; i < m - 1; i++) {
		
	}
}

int main() {
	int test_num, m, n;
	cin >> test_num;
	int arr[test_num];
	for(l = 0; l < test_num; l++) {
		cin >> m >> n;
		string s[m];
		cin.ignore();
		
		for(j = 0; j < m; j++) {
			getline(cin, s[j]);
		}
		arr[l] = count(s, m);
	}
	for(i = 0; i < test_num; i++)
		printf("%d\n", arr[i]);
	return 0;
}
// int count(string s[], int m) {
// 	int cnt = 0;
// 	string tmp;
// 	for(i = 0; i < m - 1; i++) {
// 			j = i + 1;
// 			s[i] = s[i] + ' ';
// 			s[j] = ' ' + s[j];
// 			for(k = 0; k < s[i].length(); k++) {
// 				tmp += (int)s[i][k] - (int)s[j][k];
// 			}
// 			//cout << tmp << endl;
// 			for(k = 0; k < tmp.length(); k++) {
// 				if((int)tmp[k] == 0) {
// 					if((int)s[i][k] != (int)s[i][k-1] && k != 1) cnt++;
// 					if((int)s[j][k] != (int)s[j][k+1] && k != (tmp.length() - 1)) cnt++;
// 					//if((int)s[j][k] != (int)s[j][k+1] && (int)s[i][k] != (int)s[i][k-1]) cnt--;
// 				}
// 			}
// 			s[i] = s[i].substr(0, s[i].length() - 1);
// 			s[j] = s[j].substr(1, s[j].length() - 1);
// 			tmp = "";
// 			// cout << s[i] << endl;
// 			// cout << s[j] << endl;
// 			// cout << "here" << endl;		
// 			s[i] = ' ' + s[i];
// 			s[j] = s[j] + ' ';
// 			for(k = 0; k < s[i].length(); k++) {
// 				tmp += (int)s[i][k] - (int)s[j][k];
// 			}
// 			//cout << tmp << endl;
// 			for(k = 0; k < tmp.length(); k++) {
// 				if((int)tmp[k] == 0) {
// 					if((int)s[i][k] != (int)s[i][k+1] && k != (tmp.length() - 1)) cnt++;
// 					if((int)s[j][k] != (int)s[j][k-1] && k != 1) cnt++;
// 					//if((int)s[i][k] != (int)s[i][k+1] && (int)s[j][k] != (int)s[j][k-1]) cnt--;
// 				}
// 			}
// 			s[j] = s[j].substr(0, s[j].length() - 1);
// 			tmp = "";
// 	}
// 	//cout << cnt;
// 	return cnt;
// }
