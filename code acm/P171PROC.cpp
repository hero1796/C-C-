#include <stdio.h>
#include <stdlib.h>
typedef double fl;
void import_array(fl a[], long n) {
	for(long i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}
}
void export_array(fl a[], long n) {
	printf("\n\n");
	for(long i = 0; i < n; i++)
		printf("%lf\t",a[i]);
}

// void sort(fl a[], long n) {
// 	fl tmp;
// 	for(long i = 0; i < n-1; i++)
// 		for(long j=i+1; j<n; j++) {
// 			if(a[i] > a[j]) {
// 				tmp = a[i];
// 				a[i] = a[j];
// 				a[j] = tmp;
// 			}
// 		}
// }
int floatcomp(const void* elem1, const void* elem2)
{
    if(*(const double*)elem1 < *(const double*)elem2)
        return -1;
    return *(const double*)elem1 > *(const double*)elem2;
}

int main() {
	long n;
	fl l, max;
	scanf("%ld %lf", &n, &l);
	fl a[n], b[n+1];
	import_array(a, n);
	qsort(a, n, sizeof(double), floatcomp);
	//sort(a, n);
	//if(a[0] < a[n-1]) {
		b[0] = a[0];
		b[n] = l - a[n-1];
		max = 0;
		// if(n == 1) {
		// 	printf("%0.10lf", max);
		// 	return 0;
		// }
		for(long i = n-1; i >= 1; i--) {
			//printf("aaaaaaaa");
			b[i] = a[i] - a[i-1];
			if(b[i] > max) max = b[i];
		}
	// } else {
	// 	b[0] = a[n-1];
	// 	b[n] = l - a[0];
	// 	max = 0;
	// 	// if(n == 1) {
	// 	// 	printf("%0.10lf", max);
	// 	// 	return 0;
	// 	// }
	// 	for(long i = n-1; i >= 1; i--) {
	// 	//	printf("bbbbbbb");
	// 		b[n-i] = a[i-1] - a[i];
	// 		if(b[n-i] > max) max = b[n-i];
	// 	}
	// }
	fl max2 = b[0] > b[n] ? b[0] : b[n];
	  //printf("Max2  %lf\n", max2);
	  //printf("Max  %lf\n", max);
	 // export_array(b, n+1);
	if(max < 2*max2) {
	//	printf("bbbbbbb\n");
		printf("%0.10lf", max2);
	}
	else if(max >= 2*max2) {
	//	printf("aaaaaaa\n");
		printf("%0.10lf", max/2);
	}
	//else if(max > max2 && max < 2*max2) printf("%0.10lf", max2);
	//printf("\n\n\n%0.10f",max/2 );
	return 0;
}