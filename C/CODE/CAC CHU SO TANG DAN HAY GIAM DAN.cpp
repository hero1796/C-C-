#include<stdio.h>
main()
{
   int n,t=0,a=0,b=0;
   scanf("%d",&n);
   while(n>0)
     {
   	   n=n/10;
   	   t++;
     }
   while(n>=10)
     {
     	int i=n%10, j=n/10 ,k=j%10;
     	if(i>k) a=a+1;
     	else if(i<k) b=b+1;
     	n=n/10;
     }	
    if(a == t-1) printf("cac chu so tang dan");
	if(b == t-1) printf("cac chu so giam dan");
	if(a != t-1 && b!=t-1) printf("khong co quy luat"); 
}

