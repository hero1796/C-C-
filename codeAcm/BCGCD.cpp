#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll ucln(ll a, ll b) {
	ll tmp;
	while(a != 0) {
		if(a >= b) {
			a = a%b;
		} else {
			tmp = a;
			a = b%a;
			b = tmp;
		}
	}
	return b;
}

ll bcnn(ll a, ll b, ll ucln) {
	return a*b/ucln;
}

int main() {
	ll a, b;
	vector<pair<ll, ll>> res;
	vector<pair<ll, ll>>::iterator iter;
	while(1) {
		cin>>a>>b;
		if(a == 0 && b == 0)
			break;
		pair<ll, ll> pairRes;
		pairRes.first = ucln(a, b);
		pairRes.second = bcnn(a, b, pairRes.first);
		res.push_back(pairRes);
	}
	for(iter = res.begin(); iter != res.end(); iter++) {
		pair<ll, ll> p = *iter; 
		cout<<p.first<<" "<<p.second<<"\n";
	}
	return 0;
}