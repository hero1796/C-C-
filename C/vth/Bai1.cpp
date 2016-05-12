#include<stdio.h>
#include<conio.h>
int tonghieutichthuong (float a , float b)
{
	printf ("Tong la : %.2f\n" , a+b) ;
	printf ("Hieu la : %.2f\n" , a-b) ;
	printf ("Tich la : %.2f\n" , a*b) ;
	if (b==0)
	printf ("k chia duoc vi mau bang 0\n") ;
	else
	printf ("Thuong la : %.2f\n" , a/b) ;
}

int ucln (int a , int b)
{

    if (a!=0 && b==0)
    return a ;
	else
	{
		int t ;
		while(t>=0)
		{
			t=a%b ;
	        a=b ;
         	b=t ;
	        if(t==0)
	        break ;
		}
	    return a;
    }
}

int bcnn (int a , int b)
{
return (a*b)/ucln(a,b) ;
}

main()
{
    int a ,b ;
    printf ("Nhap 2 so a va b :") ;
    scanf ("%d%d" , &a , &b) ;
    tonghieutichthuong(a , b) ;
    if (a==0 && b==0)
    printf ("co vo so uoc chung\n") ;
    else
    printf ("ucln la : %d\n" , ucln(a,b)) ;
    if (a==0 || b==0)
    printf ("khong co bcnn") ;
    else
    printf ("bcnn la : %d" , bcnn(a,b)) ;
    getch() ;
}


