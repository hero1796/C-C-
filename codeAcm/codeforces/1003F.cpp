#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

#define PRIME 1e9 + 7
ull cal_hash(string t, string p) {
	
}

int main() {
	int minLength, k = 1;
	string s;
	getline(cin, s);
	int sizeS = s.length();
	vector<int> v;
	for(int i = 0; i < sizeS; i++) {
		if(s[i] == ' ')
			v.push_back(i);
	}
	while(k <= v.size() / 2) {
		
	}
}