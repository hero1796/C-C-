#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
int nhapmatran(int ,int ,int);
int inmatran(int ,int, int);
int nhapmatran(int a[100][100],int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        printf("nhap phan tu %d%d : ",i,j);
        scanf("%d",&a[i][j]);
    }
    return 0;
}
int inmatran(int a[100][100],int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=m;j++)
        printf("%d  ",a[i][j]);            
    }
    return 0;
}
int main()
{
    int a[100][100],b[100][100],c[100][100];
    int n,m,t,h,i,j,k;
    printf("nhap so hang va so cot cua ma tran A : ");
    scanf("%d %d",&n,&m);
    printf("\nnhap ma tran A:\n");
    nhapmatran(a,n,m);
  
    printf("\nma tran A la:\n");
    inmatran(a,n,m);
 
    getch();
    return 0;
}
