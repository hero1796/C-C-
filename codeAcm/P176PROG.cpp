#include <iostream>
using namespace std;

int ucln(int y, int z) {
	int tmp;
	while(y != 0) {
		if(y > z) {
			y = y%z;
		} else {
			tmp = y;
			y = z%y;
			z = tmp;
		}
	}
	return z;
}

int res() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	int a;
	if(y%z == 0) return 1;
	if(z%y == 0) {
		a = z/y;
		if(n >= a) return a;
		else return n;
	}
	int m = ucln(y, z);
	a = z/m;
	if(n >= a) return a;
	else return n;
}
int main() {
	cout << res();
	return 0;
}