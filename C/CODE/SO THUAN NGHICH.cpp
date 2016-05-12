#include<stdio.h>
#include<conio.h>
main()
{
	int n,i=0,m=n;
	scanf("%d",&n);
	for(;n>0;)
	  {
	  	i=i*10+n%10;
	  	n=n/10;
	  }
	if(i==m)
	printf("yes");
	else printf("no"); 
	
}
