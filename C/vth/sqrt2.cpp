#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	int n ;
	float s=0 ;
	scanf ("%d",&n) ;
	for (int i=n ; i>=1 ;i--)
	{ 
	   s = sqrt( i + sqrt(s) ) ;
    }
    printf("%f",s) ;
    getch() ;
}
