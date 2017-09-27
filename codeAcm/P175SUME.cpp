#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long n;
	cin >> n;
	if(n <= 5) {
		if(n == 1) {
			cout << "1";
		} else if(n == 2) {
			cout << "2";
		} else if(n == 3) {
			cout << "3";
		} else if(n == 4) {
			cout << "4";
		} else if(n == 5) {
			cout << "5";
		}
	} else {
		long cnt = 1; // so lan lap lai mot vong den khi gap so 1 o dau
		long x, s;
		x = s = 5;
		while((s = x * 2 + s) < n) {
			cnt++;
			x *= 2;
		}
		long p = pow(2, cnt);
		long y = n - (s - x * 2);
		//cout << cnt << endl << y << endl;
		if((y / p) == 0) {
			cout << "1";
		} else if((y / p) == 1) {
			if(y == (p * 1)) {
				cout << "1";
			} else {
				cout << "2";
			}
		} else if((y / p) == 2) {
			if(y == (p * 2)) {
				cout << "2";
			} else {
				cout << "3";
			}
		} else if((y / p) == 3) {
			if(y == (p * 3)) {
				cout << "3";
			} else {
				cout << "4";
			}
		} else if((y / p) == 4) {
			if(y == (p * 4)) {
				cout << "4";
			} else {
				cout << "5";
			}
		} else if((y / p) == 5) {
			cout << "5";
		}
	}
	return 0;
}