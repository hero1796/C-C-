#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
	long num, n = 1e7 + 1;
   	long* prime = NULL;
   	prime = new long[n]();
   	prime[0] = prime[1] = 0;
   	for (num = 2; num < n; ++num) {
       	if (num > 2 && (num % 2) == 0)
           	prime[num] = 0;
       	else
           	prime[num] = 1;
   	}
    num = 3;
    while (num <= sqrt(n)) {
        for (long j = num; (num * j) <= n; ++j) // chay tu j = num rat hay
           	prime[num * j] = 0;
        do {
        	num += 2;
        } while (!prime[num]);
    }
    long a, b, k, quotient, temp, cnt;
    int t;
	cin >> t;
	long res[t];
	long *pt = NULL;
	for (int i = 0; i < t; ++i) {
		cnt = 0;
		cin >> a >> b >> k;
		pt = new long[b - a + 1]();
		for (long j = 2; j <= sqrt(b); ++j) {
			quotient = b / j;
			while((temp = (j * quotient)) >= a && temp <= b && j <= sqrt(temp)) {
				if(prime[j]) pt[temp - a] += 1;
				if(prime[quotient] && quotient != j) pt[temp - a] += 1;
				quotient--;
			}
		}
		for (long j = 0; j < b - a + 1; ++j) {
			if(pt[j] == k && !prime[j + a]) cnt++;
			if(pt[j] == (k - 1) && prime[j + a]) cnt++;
		}
		res[i] = cnt;
	}
	for (long i = 0; i < t; i++)
		cout <<"Case #" << i + 1 << ": " << res[i] << endl;
    return 0;
}
