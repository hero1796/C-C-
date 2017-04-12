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
		b[0] = a[0];
		b[n] = l - a[n-1];
		max = 0;
	
		for(long i = n-1; i >= 1; i--) {
			b[i] = a[i] - a[i-1];
			if(b[i] > max) max = b[i];
		}
	
	fl max2 = b[0] > b[n] ? b[0] : b[n];
	
	if(max < 2*max2) {
	
		printf("%0.10lf", max2);
	}
	else if(max >= 2*max2) {
	
		printf("%0.10lf", max/2);
	}
	return 0;
}