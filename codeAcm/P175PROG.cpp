#include <iostream>
#include <string>
using namespace std;

int str_compare(string s1, string s2) {
	if(s1.length() > s2.length()) {
		return 1;
	} else if(s1.length() == s2.length()) {
		if(s1.compare(s2) > 0) return 1;
		else if(s1.compare(s2) < 0) return -1;
		else return 0;
	} else return -1;
}

int main() {
	int n;
	string id, hero, res, min_id;
	bool check = false;
	cin >> n;
	cin.ignore();
	for(int i=0; i<n; i++) {
		getline(cin, id, ' ');
		getline(cin, hero, ' ');
		getline(cin, res);
		if(hero.compare("AM") == 0 && res.compare("W") == 0) {
			if(check) { 
				if(str_compare(id, min_id) == -1) min_id = id;
			} else {
				min_id = id;
				check = true;
			}
		}
	}
	cout << min_id;
	return 0;
}