#include <iostream>
#include "ucln.hpp"
using namespace std;

int res() {
	ucln u;
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	int a;
	if(y%z == 0) return 1;
	if(z%y == 0) {
		a = z/y;
		if(n >= a) return a;
		else return n;
	}
	int m = u.uc(y, z);
	a = z/m;
	if(n >= a) return a;
	else return n;
}
int main() {
	cout << res();
	return 0;
}