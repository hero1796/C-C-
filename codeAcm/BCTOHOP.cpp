#include  <iostream>
#include  <stdio.h>
#define max 20

using namespace std;

int x[max];
int n, k;

void xuat() {
    for (int i = 1; i <= k; i++)
        cout<<x[i];
    cout<<"\n";
}

void sinhToHop(int i) {
	for(int j = x[i-1] + 1; j <= n-k+i; j++) {
		x[i] = j;
		if(i == k) {
			xuat();
		} else {
			sinhToHop(i+1);
		}
	}
}

int main()  {
    n = 4; k = 2;
    x[0] = 0;  
    sinhToHop(1);
    return 0;  
}