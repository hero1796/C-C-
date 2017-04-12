#include <stdio.h>
void reset(int a[], int n, int x, int y) {
	for(int i = 0; i < n; i++) {
		if(i == x || i == y) continue;
		else a[i] = 0;	
	}
}
void display(int a[], int n) {
	for(int i = 0; i < n; i++) printf("%d\n", a[i]);
}

int main() {
	int n;
	scanf("%d\n", &n);
	int a[2*n];
	for(int i = 0; i < 2*n; i+=2) {
		scanf("%d %d", &a[i], &a[i+1]);
	}
	int resX = 0;
	int resY = 0;
	if(n == 1) {
		resX = 1;
		resY = a[0] >= a[1] ? a[1] : a[0];
		printf("%d %d", resX, resY);
		return 0;
	}

	int max[6], tmp[6];
	reset(max, 6, 0, 0);
	reset(tmp, 6, 0, 0);
	bool check1, check2;
	for (int i = 0; i < 2*n; i+=2) {
		check1 = false;
		check2 = false;
		if(a[i] == a[i+2] || a[i] == a[i+3]) {
			check1 = true;
			tmp[a[i]]++;
			if(tmp[a[i]] > max[a[i]]) max[a[i]] = tmp[a[i]];
		}
		if(a[i+1] != a[i]) {
			if(a[i+1] == a[i+2] || a[i+1] == a[i+3]) {
				check2 = true;
				tmp[a[i+1]]++;
				if(tmp[a[i+1]] > max[a[i+1]]) max[a[i+1]] = tmp[a[i+1]];
			}
		}
		if(check1 == true && check2 == true) reset(tmp, 6, a[i], a[i+1]);
		else if(check1 == true && check2 == false) reset(tmp, 6, a[i], 0);
		else if(check1 == false && check2 == true) reset(tmp, 6, 0, a[i+1]);
	}
	resX = max[1];
	resY = 1;
	for(int i = 1; i < 6; i++) {
		if(max[i] > resX) {
			resX = max[i];
			resY = i;
		}
	}
	if(resX != 0) resX++;
	else resX = 1;
	printf("%d %d", resX, resY);
	return 0;
}