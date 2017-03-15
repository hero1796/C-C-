#include <stdio.h>
#include <stdlib.h>
int main() {
	// int *a = new int[2];
	// scanf("%d",&a);
	// scanf("%d",&a+1);
	// printf("%d\n",sizeof(a));

	// for(int i = 0; i<2; i++)
	// 	printf("%d", a[i]);

	
	int *a;
	a = (int *) calloc(1, sizeof(int));
	// *a = 42;
	// *(a+1) = 11;
	scanf("%d", a);
	scanf("%d", a+1);
	printf("%d\n", *a);
	printf("%d\n", *(a+1));
	printf("%p\n", a);
	printf("%p\n", a+1);


	// int *px, *qx;
 //    px = (int *) malloc(sizeof(int));
 //    qx = (int *) calloc(1, sizeof(int));
     
 //    printf("Vi tri con tro px la %p \n", px);
 //    printf("Gia tri con tro px tro toi la %d \n", *px);
     
 //    printf("Vi tri con tro qx la %p \n", qx);
 //    printf("Gia tri con tro qx tro toi la %d \n", *qx);
     
	return 0;
}