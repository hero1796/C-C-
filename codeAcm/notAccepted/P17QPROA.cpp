#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll tmp, cnt;
ll res(ll n) {
	cnt = 0;
	for(ll i = 0; i <= sqrt(n); i++) {
		tmp = n - (i * i);
		if(tmp < (i * i)) break;
		if((sqrt(tmp) * sqrt(tmp)) == tmp) cnt++;
	}
	return cnt;
}

int main() {
	ll t;
	cin >> t;
	ll v[t];
	for(ll j = 0; j < t; j++) cin >> v[j];
	for(ll j = 0; j < t; j++) {
		if(j != (t - 1)) cout << res(v[j]) << endl;	
		else cout << res(v[j]);
	}
	return 0;
}