#include <iostream>
#include <algorithm>
using namespace std;
long a[(long)2e5 + 7];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	long min, cnt, dis;
	min = a[2] - a[1];
	cnt = 1;
	for (int i = 2; i < n; ++i) {
		dis = (a[i + 1] - a[i]);
		if(dis < min) {
			min = dis;
			cnt = 1;
		} else if(dis == min) {
			cnt++;
		}
	}
	cout << min << " " << cnt;
	return 0;
}