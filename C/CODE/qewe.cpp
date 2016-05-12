#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
int nhapmatran(int a[100][100],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        printf("nhap phan tu %d%d : ",i,j);
        scanf("%d",&a[i][j]);
    }
    return 0;
}
int inmatran(int a[100][100],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
        printf("%d  ",a[i][j]);            
    }
    return 0;
}
int main()
{
    int a[100][100],b[100][100],c[100][100];
    int n,i,j,k;
    printf("nhap so hang va so cot cua ma tran: ");scanf("%d",&n);
    printf("\nnhap ma tran A:\n");
    nhapmatran(a,n);
    printf("\nnhap ma tran B:\n");
    nhapmatran(b,n);
    printf("\nma tran A la:\n");
    inmatran(a,n);
    printf("\nma tran B la:\n");
    inmatran(b,n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        c[i][j]=0;
        for(k=1;k<=n;k++)
        c[i][j]=c[i][j]+a[i][k]*b[k][j];
    }
    printf("\ntich 2 ma tran A va B la:\n");
    inmatran(c,n);
    getch();
    return 0;
}
