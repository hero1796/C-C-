#include "stdio.h"
#include"conio.h"
int main()
{
    double  dt=1,x,A[100][100];
    int n, i, j, k,trunggian;
    char t;
    printf("\t\t\t\t DINH THUC MA TRAN\n");
    printf("\t\t\tCode by Nguyen Duc Thanh D14ATTT1 PTIT");
	printf("\n Moi ban nhap vao cap cua ma tran \t");
	scanf("%d",&n);

	for (  i=0;i<n;i++)
	for ( j=0;j<n;j++){
		printf("A[%d][%d]=\t",i+1,j+1);
	scanf("%lf",&A[i][j]);}
	printf("Ma tran\n");
	for ( i=0;i<n;i++){
for ( j=0;j<n;j++)
printf(" \t%lf  ",A[i][j]);
printf("\n");
}
for (i=0;i<(n-1);i++)
    {
    if(A[i][i]==0)
        {
        	k=i+1;
            while ((k<n)&&(A[k][i]==0))
                k++;
            if (k>(n-1))
            {
                dt=0;
                break;
            }
            else 
            {
                dt=-dt;
                for (j=i;j<n;j++)
                {
                    trunggian=A[i][j];
                    A[i][j]=A[k][j];
                    A[k][j]=trunggian;
                }
            }
        }
        for (k=i+1;k<n;k++)
        {
            	 x=-A[k][i]/A[i][i];
            for (j=i;j<n;j++)
                A[k][j]=A[k][j]+x*A[i][j];
        }
    }
    for (i=0;i<n;i++)
        dt=dt*A[i][i];
    printf("Co dinh thuc cua ma tran la %lf",dt);
    printf("\n^_^ Nhan phim bat ky de ket thuc chuong trinh ");
	getch();
    return 0;
}
