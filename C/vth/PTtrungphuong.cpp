#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	float a,b,c,dt,x1,x2,x3,x4,t1,t2,t3 ;
	printf ("Nhap a b c : ") ;
	scanf ("%f %f %f",&a,&b,&c) ;
	dt = b*b-4*a*c ;
	if (a==0)
	{
		if ((b*c)==0)
		{
			if (b!=0)
			printf ("PT co nghiem x=0") ;
			else
			{
				if (c==0)
				printf ("PT co vo so nghiem") ;
				else
				printf ("PT vo nghiem") ;
			}
		}
		else
		{
			if ((b*c)<0)
			printf ("PT vo nghiem") ;
			else
			printf ("PT co 2 nghiem x1=%0.2f\n x2=%0.2f",sqrt(-c/b),-sqrt(-c/b)) ;
		}
	}
	else
	{
		if (dt<0)
		printf ("PT vo nghiem") ;
		else
		{
			if (dt==0)
			{
				t1 = -b/(2*a) ;
				if (t1<0)
				printf ("PT vo nghiem") ;
				else
				{
					if (t1==0)
				    printf ("PT co nghiem x=0") ;
				    else
				    printf ("PT co 2 nghiem x1=%0.2f\n x2=%0.2f",sqrt(t1),-sqrt(t1)) ;
				}	
			}
			else
			{
				t2 = (-b-sqrt(dt))/(2*a) ;
			    t3 = (-b+sqrt(dt))/(2*a) ;
			    if (t2==0)
			    printf ("PT co 3 nghiem x1=0\n x2=%0.2f\n x3=%0.2f",sqrt(t3),-sqrt(t3)) ;
			    else
			    {
				    if (t2<0)
				    {
					     if (t3<0)
					     printf ("PT vo nghiem") ;
					     else
					    {
						   if (t3==0)
						   printf ("PT co nghiem x=0") ;
						   else
						   printf ("PT co 2 nghiem x1=%0.2f\n x2=%0.2f",sqrt(t3),-sqrt(t3)) ;
					    }
				    }
				    else
				    printf ("PT co 4 nghiem x1=%0.2f\n x2=%0.2f\n x3=%0.2f\n x4=%0.2f",-sqrt(t3),-sqrt(t2),sqrt(t2),sqrt(t3)) ;
			    }
			}
		}
	}
	getch() ;
}

