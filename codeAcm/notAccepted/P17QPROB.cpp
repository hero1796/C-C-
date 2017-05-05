#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<string> vt;
	vector<string> vtResult;
	vector<string>::iterator it, it1, it2;
	string str1, str2, strRes;
	long t, m, max;
	bool check;
	long temp;
	cin >> t;
	for(long i = 0; i < t; ++i) {
		cin >> m;
		cin.ignore();
		vt.clear();
		max = 0;
		for(long j = 0; j < m; ++j) {
			if(j != (m - 1)) getline(cin, str1, ' ');
			else getline(cin, str1);
			vt.push_back(str1);
			temp = str1.length();
			if(temp > max) max = temp;
		}
		for(long index = 0; index < max; ++index) {
			for(it1 = vt.begin(); it1 != (vt.end() - 1); ++it1) {
				for(it2 = (it1 + 1); it2 != vt.end(); ++it2) {
					check = false;
					str1 = *it1;
					str2 = *it2;
					for(long k = 0; k < index; k++) {
						if(str1[k] < str2[k]) {
							check = true;
							break;	
						}
					}
					if(check == false && str1[index] > str2[index]) iter_swap(it1, it2);
				}
			}
		}
		for (it = vt.begin(); it != vt.end(); ++it) {
			strRes += *it;
		}
		vtResult.push_back(strRes);
		strRes = "";
	}
	for (it = vtResult.begin(); it != vtResult.end(); ++it) {
			if(it != (vtResult.end() - 1) ) cout << *it << endl;
			else cout << *it;
	}
	return 0;
}