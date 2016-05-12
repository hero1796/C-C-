#include<stdio.h>
#include<conio.h>
#include<math.h>
void nhapmatran(float ,int ,int);
void inmatran(float ,int, int);
void nhapmatran(float x[100][100],int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        printf("nhap phan tu %d%d : ",i,j);
        scanf("%f",&x[i][j]);
    }
    
}
float inmatran(float x[100][100],int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++) 
	{
        printf("\n");
        for(j=1;j<=m;j++) 
        	printf("%f ",x[i][j]);           
    }
}
int main()
{
	printf("\n\n\n");
	printf("		LAP TRINH C: 	NHAN HAI MA TRAN \n\n\n\n");
	printf("				Sinh Vien: NGUYEN TRUNG HIEU - LOP: D14CN08 \n\n");
	printf("				Giang Vien: HOANG PHI DUNG\n\n\n");
    float a[100][100],b[100][100],c[100][100];
    int n,m,t,h,i,j,k;
    printf("Nhap so hang  A : ");
    scanf("%d",&n);
    printf("\n Nhap so cot cua A: ");
    scanf("%d",&m);
    printf("\nNhap ma tran A:\n");
    nhapmatran(a,n,m);
    printf("\n");
    printf("Nhap so hang cua B:  ");
    scanf("%d",&h);
    printf("\n nhap so cot cua B: ");
    scanf("%d",&t);
    printf("\nNhap ma tran B:\n");
    nhapmatran(b,h,t);
    printf("\nMa tran A la:\n");
    inmatran(a,n,m);
    printf("\n\nMa tran B la:\n");
    inmatran(b,h,t);
    for(i=1;i<=n;i++)
    for(j=1;j<=t;j++)
    {
        c[i][j]=0;
        for(k=1;k<=m;k++)
        c[i][j]=c[i][j]+a[i][k]*b[k][j];
    }
    printf("\n\nTich 2 ma tran A va B la:\n");
    inmatran(c,n,t);
    getch();
    return 0;
}
