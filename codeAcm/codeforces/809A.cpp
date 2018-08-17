/* Lam nhung khong hieu lam */

// #include <iostream>
// #include <algorithm>

// typedef long long ll;

// const ll MOD = 1000000007;

// ll toHop(long k, long n) {
// 	if(k == 0 || k == n) return 1;
// 	ll res = 1;
// 	for (long i = 1; i <= n - k; ++i) {
// 		res = res * n / i;
// 		n--;
// 	}
// 	return res;
// }

// int main() {
// 	long n;
// 	std::cin >> n;
// 	ll *x = new ll[n + 1]();
// 	for (ll i = 1; i <= n; ++i) {
// 		std::cin >> x[i];
// 	}
// 	std::sort(x + 1, x + n + 1);
// 	ll sum = 0;
// 	for (long i = 2; i <= n; ++i) {
// 		if(i == 2) {
// 			for (long j = 1; j <= n - i + 1; ++j) {
// 				for (long k = j + i - 1; k <= n; ++k) {
// 					sum += (x[k] - x[j]);
// 					sum %= MOD;
// 				}
// 			}
// 		} else {
// 			for (long j = 1; j <= n - i + 1; ++j) {
// 				for (long k = j + i - 1; k <= n; ++k) {
// 					sum += toHop(i - 2, k - j - 1) * (x[k] - x[j]);
// 					sum %= MOD;
// 				}
// 			}
// 		}
// 	}
// 	std::cout << sum;
// 	return 0;
// }

#include <stdio.h>
#include <algorithm>
typedef long long ll;
const int mod = 1e9 + 7;
int n;
long a[300005];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%ld", &a[i]);
	std::sort(a + 1, a + n + 1);
	ll p = 1;
	ll res = 0;
	for(int i = 1; i <= n; ++i) {
		res += a[i] * p % mod;
		p = (p << 1) % mod;
	}
	p = 1;
	for(int i = n; i >= 1; i--) {
		res += mod - a[i] * p % mod;
		p = (p << 1) % mod;
	}
	res %= mod;
	printf("%lld", res);
}
	// 4 7	9
	// 4-4
	// 7-7
	// 9-9
	// 7-4
	// 9-4
	// 9-7
	// res = 0, p = 1;
	// res = 0 + 4 * 1 = 4;
	// p = 2;
	// res = 4 + 7 * 2 = 18;
	// p = 4;
	// res = 18 + 9 * 4 = 54;

	// res = 54 , p = 1;
	// res = 54 + 1000 - 9 * 1 = 1045;
	// p = 2;
	// res = 1045 + 1000 - 7 * 2 = 2031;
	// p = 4;
	// res = 2031 + 1000 - 4 * 4 =  3015;