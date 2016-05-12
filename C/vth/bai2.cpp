#include<stdio.h>
#include<conio.h>
int max(int a)
{
	int x,max=0,s=0 ;
	if(a<0)
	a=a*(-1) ;
	while(a!=0)
	{
		x = a%10 ;
		a=a/10 ;
		if (x>max)
		max = x ;
		s+=x ;
	}
	 printf ("chu so lon nhat cua so a la : %d\n" , max) ;
	 printf ("tong cac chu so cua so a la : %d" , s) ;
}
main()
{
	int a ;
	printf ("nhap so a :") ;
	scanf ("%d" , &a) ;
	max(a) ;
    getch() ;
}


