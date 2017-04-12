#include <iostream>
#include <cmath>
using namespace std;

int is_ngto(long long n) {
	if(n < 2) return 0;
	if(n == 2 || n == 3) return 1;
	for(long long i = 2; i <= sqrt(n); i++) {
		if(n%i == 0) return 0;
	}
	return 1;
}

int main() {
	long n;
	cin >> n;
	long long a[n], x;
	for(long i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(long i = 0; i < n; i++) {
		x = sqrt(a[i]);
		if(is_ngto(x) == 1 && x*x == a[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}