#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

#define PRIME 1e9 + 7
#define BASE 26
ull cal_pad(ull x, ull y, ull q) {
	ull h = 1;
	for(int i = 1; i <= y; ++i) {
		h = (h * x) % q;
	}
	return h;
}

int main() {
	string txt;
	getline(cin, txt);
	int txtSize = txt.length();
	vector<int> v;
	for(int i = 0; i < txtSize; ++i) {
		if(txt[i] == ' ')
			v.push_back(i);
	}
	if(v.empty()) {
		cout<<txt.length();
		return 0;
	}
	int minLength = txtSize, vtSize = v.size();
	for (int j = 0; j <= vtSize; j++) {
		int startIdx = j == 0 ? 0 : v.at(j - 1) + 1, n = txtSize - startIdx, k = 1, limit = (vtSize + 1 - j) / 2;
		while(k <= limit) {
			ull hashP = 0;
    		ull hashT = 0;
			int m = v.at(j - 1 + k) - startIdx;
			ull pad = cal_pad(BASE, m - 1, PRIME);
			for(int i = 0; i < m; i++) {
    			hashP = fmod(BASE * hashP + txt[startIdx + i], PRIME);
    			hashT = fmod(BASE * hashT + txt[startIdx + i], PRIME);
  			}
  			for (int i = 0; i <= n - m; i++) {
		        if (hashP == hashT) {
		            
		        }
		        if (i < n-m) {
		            hashT = fmod(BASE * (hashT - txt[startIdx + i] * pad) + txt[startIdx + i + m], PRIME);
		            if (hashT < 0)
		            hashT = (hashT + PRIME);
		        }
		    }
			k++;
		}
	}
}