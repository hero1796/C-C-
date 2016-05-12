#include<stdio.h>
#include<conio.h>
main()
{
	int a,b,t,x,y ;
	scanf("%d%d",&a,&b) ;
	x=a ;
	y=b ;
	while(t>=0)
	{
	t=a%b ;
	a=b ;
	b=t ;
	if(t==0)
	break ;
    }
    printf("UCLN la : %d\n",a) ;
    printf("BCNN la : %d",(x*y)/a) ;
    getch() ;
}
