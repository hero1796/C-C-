#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    int t;
    long a, b, k;
    vector <long> vtPrime;
    long n = 1e7 + 20;
    long* p = NULL;
    p = new long[n]();
    p[0] = p[1] = 0;
    long num;
    for (num = 2; num < n; ++num) {
        if (num > 2 && (num % 2) == 0)
            p[num] = 0;
        else
            p[num] = 1;
    }
    num = 3;
    while (num <= sqrt(n)) {
        for (long j = num; (num * j) <= n; ++j) // chay tu j = num rat hay
            p[num * j] = 0;
        do {
            num += 2;
        } while (!p[num]);
    }
    for (num = 2; num < n; ++num) {
        if (p[num])
          vtPrime.push_back(num);
    }
    long quotient, temp, cnt;
    vector<long> vtResult;
    cin >> t;
    long *pt = NULL;
    for (int i = 0; i < t; ++i) {
        cnt = 0;
        cin >> a >> b >> k;
        pt = new long[b - a + 1]();
        for (vector<long>::iterator it = vtPrime.begin(); *it <= b; ++it) {
            quotient = b / *it;
            while((temp = (*it * quotient)) >= a && temp <= b) {
                pt[temp - a] += 1;
                quotient--;
            }
        }
        for (long j = 0; j < b - a + 1; ++j)
            if(pt[j] == k) cnt++;
        vtResult.push_back(cnt);
    }
    int i = 1;
    for (vector<long>::iterator it = vtResult.begin(); it != vtResult.end(); ++it) {
        cout <<"Case #" << i << ": " << *it << endl;
        i++;
    }
    return 0;
}
