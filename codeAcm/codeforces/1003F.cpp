#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ull;

#define PRIME 87188291199
#define BASE 256
ull cal_pad(ull x, ull y, ull q) {
	ull h = 1;
	for(int i = 0; i < y; i++) {
		h = (h * x) % q;
	}
	return h;
}

int main() {
	int a;
	cin>>a;
	cin.ignore();
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
	int minLength = txtSize, vtSize = v.size(), f1, f2;
	for (int j = 0; j <= vtSize; j++) {
		int startIdx = j == 0 ? 0 : v.at(j - 1) + 1, n = txtSize - startIdx, k = 1, limit = (vtSize + 1 - j) / 2;
		// cout<<"startIndex = "<<startIdx<<"\n";
		// cout<<"n = "<<n<<"\n";
		while(k <= limit) {
			ull hashP = 0;
    		ull hashT = 0;
			int m = v.at(j - 1 + k) - startIdx, tmpMinLength = txtSize, cnt = 0, intersection = -1;
			// cout<<"m = "<<m<<"\n";
			ull pad = cal_pad(BASE, m - 1, PRIME);
			for(int i = 0; i < m; i++) {
    			hashP = fmod(BASE * hashP + txt[startIdx + i], PRIME);
    			hashT = fmod(BASE * hashT + txt[startIdx + i], PRIME);
  			}
  			for (int i = 0; i <= n - m; i++) {
  				f1 = startIdx + i - 1;
  				f2 = startIdx + i + m;
  				if(!((f1 >= 0 && txt[f1] != ' ') || (f2 <= n - 1 && txt[f2] != ' '))) {
  					// cout<<"i = "<<i<<"\n";
  					if (hashP == hashT) {
			        	if(i > intersection) {
			        		// cout<<j<<" - "<<k<<" - "<<i<<"\n";
			        		cnt++;
			        		intersection = i + m - 1;
			        	}
		        	}
  				}
		        if (i < n-m) {
		            hashT = fmod(BASE * (hashT - txt[startIdx + i] * pad) + txt[startIdx + i + m], PRIME);
		            if (hashT < 0)
		            	hashT = (hashT + PRIME);
		        }
		    }
			if(cnt > 1) {
				tmpMinLength -= cnt * (m - k);
				if(tmpMinLength < minLength)
					minLength = tmpMinLength;
			}
			k++;
		}
	}
	cout<<minLength;
}