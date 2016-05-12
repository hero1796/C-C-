#include<stdio.h>
#include<math.h>
int a,b,c;
void nhap()
{
	printf("a =");scanf("%d",&a);
	printf("b =");scanf("%d",&b);
	printf("c =");scanf("%d",&c);
}
void ptbac2()
{
	float dt=(b*b)-(4*a*c);
	if(a==0)
	{
		if(b!=0)
		printf("PT co nghiem x=%.2f\n",-c/b);
		else
		{
			if(c==0)
			printf("PT co vo so nghiem\n");
			else
			printf("PT vo nghiem\n");
		}
	}
	else
	{
		if(dt<0)
		printf("PT vo nghiem\n");
		else
		{
			if(dt==0)
			printf("PT co nghiem kep x= %.2f\n",float((-b)/(2*a)));
			else
			printf("PT co 2 nghiem phan biet x1=%.2f\tx2=%.2f\n",float((-b+sqrt(dt))/(2*a)),float((-b-sqrt(dt))/(2*a)));
		}
	}
}
main()
{
    nhap();
    ptbac2();
}
