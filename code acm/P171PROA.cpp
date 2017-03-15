#include <stdio.h>
#include <math.h>
#include <limits>
#include <iostream>
typedef long long lo;
using namespace std;
bool check (lo a, lo b) {
	return b > (numeric_limits<long long>::max() / a);
}

lo pow_xy(lo x, int y) {
	lo res = 1;
	for(int i = 1; i <= y; i++) {
		if(check(res, x) == true) return -1;
		else res*=x;
	}
	return res;
}



int main() {
	lo x;
	lo l, r;
	//cout <<numeric_limits<long long>::max();
	scanf("%lld %lld %lld", &l, &r, &x);
	//printf("%lld\t%lld\t%ld\n",l, r, x);
	int dem = 0;
	for(int i = 0; i <= 60; i++) {
		if(pow_xy(x, i) >= l && pow_xy(x, i) <= r) {
			printf("%lld ",pow_xy(x, i));
			dem++;
		}
	}
	if(dem == 0) printf("-1");
	return 0;
}