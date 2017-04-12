#include "stdio.h"
#include "math.h"
typedef unsigned long l;

l arr1[10001], arr2[10001];

l findMin(l arr[], l n) {
	l min = arr[1];
	for(l i = 1; i <= n; i++) {
		if(arr[i] < min) min = arr[i];
	}
	return min;
}

l findN(l a, l b) {
	if(a == b || a == 0 || b == 0) return 1;
	if(a%b == 0 && b != 1) return b;
	if(b%a == 0 && a != 1) return a;
	l c, dem = 0, k;
	if(a < b) {
		c = b - a;
		for(l i = 1; i <= sqrt(c); i++) {
			if(c%i == 0) {
				dem++;
				k = 0;
				while(i*((b/i) + k) <= b) k++;
				arr1[dem] = i*((b/i) + k) - b;
				arr2[dem] = ((a+arr1[dem])/i)*(b+arr1[dem]);
				dem++;
				k = 0;
				while((c/i)*(((b/c)*i) + k) <= b) k++;
				arr1[dem] = (c/i)*(((b/c)*i) + k) - b;
				arr2[dem] = ((a+arr1[dem])/(c/i))*(b+arr1[dem]);
			}
		}
	} else {
		c = a - b;
		for(l i = 1; i <= sqrt(c); i++) {
			if(c%i == 0) {
				dem++;
				k = 0;
				while(i*((a/i) + k) <= a) k++;
				arr1[dem] = i*((a/i) + k) - a;
				arr2[dem] = ((a+arr1[dem])/i)*(b+arr1[dem]);
				dem++;
				k = 0;
				while((c/i)*(((a/c)*i) + k) <= a) k++;
				arr1[dem] = (c/i)*(((a/c)*i) + k) - a;
				arr2[dem] = ((a+arr1[dem])/(c/i))*(b+arr1[dem]);
			}
		}
	}
	for(l i = 1; i <= dem; i++) {
		if(arr2[i] == findMin(arr2, dem)) return arr1[i];
	}
}
int main() {
	l a , b;
	scanf("%lu %lu", &a, &b);
	printf("%lu", findN(a, b));
	return 0;
}