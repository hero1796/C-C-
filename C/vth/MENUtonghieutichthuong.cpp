#include<stdio.h>
#include<stdlib.h>
float a,b;
void nhap()
{
	printf("a =");
	scanf("%f",&a);
	printf("b =");
	scanf("%f",&b);
}
void tong()
{
	printf("Tong = %.2f\n\n",a+b);
}
void hieu()
{
	printf("Hieu = %.2f\n\n",a+b);
}
void thuong()
{
	if(b==0)
	printf("Khong chia duoc vi mau bang 0\n\n");
	else
	printf("Thuong = %.2f\n\n",a/b);
}
void tich()
{
	printf("Tich = %.2f\n\n",a*b);
}
void thoat()
{
	printf("Thanks!!! Good bye");
	exit(0);
}
main()
{
	int x,y;
	printf("Ho va ten : Vu The Hung\n");
	printf("D14CN04\n");
	printf("------------------------\n");
	printf("\t\tBAI TAP : Nhap 2 so a,b in ra tong hieu tich thuong\n");
	printf("1.Nhap\n");
	printf("2.Tong\n");
	printf("3.Hieu\n");
	printf("4.Tich\n");
	printf("5.Thuong\n");
	printf("6.Thoat\n");
	printf("------------------------\n");
	printf("Moi chon :");
	nhap1 :;
	scanf("%d",&x);
	switch(x)
	{
		case 1 : nhap();
		{
			nhap3 :;
		   printf("Moi chon tiep:");
		   nhap2: ;
		   scanf("%d",&y);	
		   switch(y)
	       {
	       	    case 1 : nhap();goto nhap3;
		    	case 2 : tong();goto nhap3;
		    	case 3 : hieu();goto nhap3;
		    	case 4 : tich();goto nhap3;
			    case 5 : thuong();goto nhap3;
			    case 6 : thoat();
			    default :
			    	{
			    		printf("Hay chon lai : ");
			    		goto nhap2;
					}
		   }
		}
		case 6 : thoat();
		default : 
		{	printf("Hay chon 1 de nhap a,b truoc : ");
		    goto nhap1;
		}  
	}
}
