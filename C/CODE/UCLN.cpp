#include<stdio.h>
#include<conio.h>
main()
{
   int a,b;
   scanf("%d%d",&a,&b);
   while(b!=0)
     {
     	int tmp=b;
     	b=a%b;
     	a=tmp;
     }
   printf("%d",a);  
}
