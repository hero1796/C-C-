#include<stdio.h>
#include<string.h>
main()
{
	float a[100][100],det=1;
	int t,n;
	printf("co cua ma tran la: ");
	scanf("%d",&n);
	printf("hay nhap vao ma tran:\n ");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{
			printf(" nhap a[%d][%d] : ",i,j);
			scanf("%f",&a[i][j]);
		    }
	printf("ma tran can tinh dinh thuc la:\n ");
	for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=n;j++)
			printf("%.2f ",a[i][j]);
		printf("\n");				
		}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			{
				
	            float x=a[j][i]/(float)a[i][i];
	        
				for(int k=1;k<=n;k++)
					a[j][k]=a[i][k]*x-a[j][k];
			}	
	printf("\n");
	for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=n;j++)
			printf("%.2f ",a[i][j]);
		printf("\n");			
	    }
}
