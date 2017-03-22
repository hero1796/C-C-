#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n, k, a[100000], cnt = 0;
    cin>>n>>k;
    for(ll i = 1; i <= sqrt(n); i++) {
        if(n%i == 0) {
            a[++cnt] = i;
        }
    }
   // cout<<cnt;
    if(k <= cnt) { 
        cout<<a[k];
        return 0;
    }

    if(a[cnt]*a[cnt] == n) {
        if(k > cnt*2 - 1) {
            cout<<-1;
            return 0;
        } else  {
            cout<<n/a[cnt*2-k];
            return 0;
        }
    }
    if(a[cnt]*a[cnt] != n) {
        if(k > cnt*2) {
            cout<<-1;
            return 0;
        } else { 
            cout<<n/a[1 + cnt*2 - k];
            return 0;
        }
    }

    return 0;
}
