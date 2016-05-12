#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	int n ;
	float s=0 ;
	scanf ("%d",&n) ;
	for (int i=1 ; i<=n ;i++)
	{ 
	   s = sqrt( i + sqrt(s) ) ;
    }
    printf("%0.2f",s) ;
    getch() ;
}
