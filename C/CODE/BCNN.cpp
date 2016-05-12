#include<stdio.h>
#include<conio.h>
main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	i=a*b;
	while(b!=0)
	  {
	  	int tmp=b;
	  	b=a%b;
	  	a=tmp;
	  }
	printf(" boi chung lon nhat la: %d",i/a);  
}
