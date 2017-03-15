#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void import_array(long a[], long b[], long n) {
	for(long i = 0; i < n; i++)
		scanf("%ld %ld", &a[i], &b[i]);
}
void export_array(long a[], long b[], long n) {
	printf("\n");
	for(long i = 0; i < n; i++)
		printf("%ld %ld\n", a[i], b[i]);
}

void heapify(long arr[], long b[], long n, long i)
{
    long largest = i; 
    long l = 2*i + 1;
    long r = 2*i + 2;
    long tmp;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;

        tmp = b[i];
        b[i] = b[largest];
        b[largest] = tmp;

        heapify(arr, b, n, largest);
    }
}

void heapSort(long arr[], long b[], long n)
{
	long tmp;
    for (long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, b, n, i);

    for (long i=n-1; i>=0; i--)
    {
    	tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        tmp = b[0];
        b[0] = b[i];
        b[i] = tmp;
        heapify(arr, b, i, 0);
    }
}
long max(long a, long b) {
	if(a > b) return a;
	else return b;
}
int main() {
	long n, cnt = 0;
	scanf("%ld", &n);
	long a[n], b[n];
	import_array(a, b, n);
	heapSort(a, b, n);
	export_array(a, b, n);
	long max1 = b[0], max2 = 0;
	for(long i = 1; i < n; i++) {
		 //if(a[i] != a[]) max2 = max1;
		max1 = max(max1, b[i-1]);
		//printf("max1 la %ld\n",max1);
		//printf("max2 la %ld\n",max2);
		if(a[i] != a[i-1]) {
			max2 = max1;
			if(b[i] < max1) cnt++;
		} else {
			if(b[i] < max2) cnt++;
		}
	}	
	printf("%ld", cnt);
	return 0;
}
