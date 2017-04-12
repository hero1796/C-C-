#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

void sort(ll a[]) {
	ll tmp;
	for(int i=0; i<2; i++)
		for(int j=i+1; j<3; j++)
			if(a[i] > a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		
}
int main() {

	ll a[3], n;
	cin >> n;
	ll b[n];
	for(ll  i=0; i<n; i++) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a);
		b[i] = a[2] - a[0];
	}
	for(ll i=0; i<n; i++)
		cout << b[i] << "\n";
	return 0;
}