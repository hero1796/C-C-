#include<stdio.h>
#include<conio.h>
main()
{
	float a,b,tong,tich,hieu,thuong ;
	printf("a=") , scanf("%f",&a) ;
	printf("b=") , scanf("%f",&b) ;
	tong=a+b ;
	hieu=a-b ;
	tich=a*b ;
	thuong=a/b ;
	printf("Tong,Hieu,Tich,Thuong lan luot la :%f,%f,%f,%f",tong,hieu,tich,thuong) ;
	getch() ;
}
