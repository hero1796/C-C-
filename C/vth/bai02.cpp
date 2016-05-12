#include<stdio.h>
#include<conio.h>
main()
{
	int x,y,max,a ;
	scanf("%d",&a) ;
    while(a!=0)
	{
		x = a%10 ;
		max = x ;
		a=a/10 ;
		y = a%10 ;
		if (y>x)
		max = y ;
	}
	printf ("%d",max) ;
	getch() ;
}
	
