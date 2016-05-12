#include<stdio.h>
#include<string.h>
main()
{  
   int i; 
   char x[100],y[100];
   gets(x);
   for( i=0;i<strlen(x);i++)
   if(x[i]>='A'&&x[i]<='Z')
   x[i]=x[i]+32;
   printf("%s",x);
}
