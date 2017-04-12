#include <stdio.h>
typedef  long ui;

void import_array(ui a[], ui n) {
	for(ui i = 0; i < n; i++)
		scanf("%ld", &a[i]);
}

ui partition( ui a[], ui l, ui r) {
   ui pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

void quickSort( ui a[], ui l, ui r)
{
   ui j;

   if( l < r ) 
   {
       j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}

ui res(ui a[], ui n) {
	ui total = 0, tmp = 0;
	for(ui i = 0; i < n - 1; i++) {
		total+= a[i];
		if(a[i+1] >= total) {
			if(i == n - 2) return n;
			else continue;
		}
		else {
			for(ui j = i + 1; j < n; j++) {
				if(a[j] >= total) {
					tmp = a[j];
					for(ui k = j; k > i + 1; k--) {
						a[k] = a[k - 1];
					}
					a[i+1] = tmp;
					break;
				}
				if(j == n - 1) return (i + 1);
			}
		}
	}
}

int main() {
	ui n;
	scanf("%ld", &n);
	ui a[n];
	import_array(a, n);
	if(n == 1) printf("1");
	else {
		quickSort(a, 0, n - 1);
		printf("%ld", res(a, n));
	}
	return 0;
}