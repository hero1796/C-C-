#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long i, j;
int main() {
	long long t, n, sum;
	cin >> t;
	vector<long long> vt;
	for(j = 0; j < t; j++) {
		sum = 0;
		cin >> n;
		long a[n], b[n];
		for(i = 0; i < n; i++) cin >> a[i];
		for(i = 0; i < n; i++) cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		for(i = 0; i < n; i++) {
			sum += (a[i] * b[n - 1 - i]);
		}
		vt.push_back(sum);
	}
	i = 1;
	for (vector<long long>::iterator it = vt.begin(); it != vt.end(); it++) {
		cout << "Case #" << i << ": " << *it << endl;
		i++;
	}
	return 0;
}