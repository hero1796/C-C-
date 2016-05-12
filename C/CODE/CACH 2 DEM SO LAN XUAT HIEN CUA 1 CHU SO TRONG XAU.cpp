#include<stdio.h>
#include<string.h>
main()
{   
   char x[1001];
   gets(x);
   for(int i=0 ; i<=9 ; i++)
     {  
	    int dem=0;
     	for(int j=0 ; j<strlen(x) ; j++)
     	if(x[j]-'0'==i) dem++;
        printf("so %d xuat hien: %d lan \n",i,dem);
     }
}
