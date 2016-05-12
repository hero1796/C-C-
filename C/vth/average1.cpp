#include<stdio.h>
#include<conio.h>
main()
{
	float x,y,z,a,b,c ;
	printf("diem toan-he so:  ") , scanf("%f    %f",&x,&a) ;
	printf("diem li-he so:    ") , scanf("%f    %f",&y,&b) ;
	printf("diem hoa-he so:   ") , scanf("%f    %f",&z,&c) ;
	printf("average= %f",(x*a+y*b+z*c)/(a+b+c)) ;
	getch() ;
}
