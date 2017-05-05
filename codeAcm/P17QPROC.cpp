#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
long i;
ll compute_f(long n) {
	ll res;
	if(n == 1) return 1;
	res = n;
	res -= 1;
	for(i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			res -= i;
			if(i*i != n) res -= (n/i);
		}
	}
	return abs(res);
}

int main() {
	long a, b;
	ll res = 0;
	cin >> a >> b;
	long numElementArr = b - a + 1;
	if(a >= b) res = compute_f(a);
	else {
		long* v = NULL;
		v = new long[b - a + 1]();
		ll divisor, quotient, tmp;
		for (i = 2; i <= sqrt(b); i++) {
			quotient = b / i;
			while((tmp = i * quotient) >= a && tmp <= b && i <= sqrt(tmp)) {
				v[tmp - a] -= i;
				if(i != quotient) v[tmp - a] -= quotient;
				quotient--;
			}
		}
		for(i = 0; i < numElementArr; i++) {
			v[i] += (a + i - 1);
			if(v[i] < 0) v[i] *= -1;
			res += v[i];
		}
		if(a == 1) res += 1;
	}
	cout << res;
	return 0;
}

