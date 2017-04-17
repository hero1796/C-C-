#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int n, m, k;
	long x;
	cin >> n >> m >> k >> x;
	cin.ignore();
	string s;
	string str_array[m];
	char c[m] = "\0";
	getline(cin, s);
	for(int i = 0; i < m; i++) {
		getline(cin, str_array[i]);
		sort(str_array[i].begin(), str_array[i].end());
	}
	int thuong, du, pos_of_char;
	for(int i = m - 1; i >= 0; i--) {
		thuong = x / k;
		du = x % k;
		if(du != 0) thuong++;
		x = thuong;
		pos_of_char = (du == 0) ? (k - 1) : (du - 1);
		c[i]= str_array[i][pos_of_char];
	}
	int j = 0;
	
	for(int i = 0; i < s.length(); i++) {
		
		if(s[i] == '#') {
			s[i] = c[j];
			j++;
		}
	}
	cout << s;
	return 0;
}