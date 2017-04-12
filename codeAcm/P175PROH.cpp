#include <iostream>
using namespace std;
typedef long long ll;
ll res() {
	ll l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	if(r1 < l2 || r2 < l1) return 0;
	if(r1 == l2) {
		if(k == l2) return 0;
		else return 1;
	}
	if(r2 == l1) {
		if(k == l1) return 0;
		else return 1;
	}
	if(l2 >= l1 && r1 > l2) {
		if(r2 >= r1) {
			if(k >= l2 && k <= r1) return (r1 - l2);
			else return (r1 - l2 + 1);
		} else {
			if(k >= l2 && k <= r2) return (r2 - l2);
			else return (r2 -l2 + 1);
		}
	}
	if(l2 < l1) {
		if(r2 > l1 && r2 <= r1) {
			if(k >= l1 && k <= r2) return (r2 - l1);
			else return (r2 - l1 + 1);
		}
		if(r2 > r1) {
			if(k >= l1 && k <= r1) return (r1 - l1);
			else return (r1 - l1 + 1);
		}
	}
}
int main() {
	cout << res();
	return 0;
}