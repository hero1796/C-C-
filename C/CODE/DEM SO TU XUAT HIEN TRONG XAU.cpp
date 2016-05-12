#include<stdio.h>
#include<string.h>
main()
{
   char x[100];
   int i=0;
   gets(x);
   int l=strlen(x)-1,t=0;
   while (i<=strlen(x)) 
   { 
     while(x[i] - ' ' ==0) i++;
   	 while (x[i] - ' ' !=0) 
	 i++;
   	 t++;
   }
   if (x[l]==' ')printf("%d",t-1);
   if (x[l]!=' ')printf("%d",t);		
}	
