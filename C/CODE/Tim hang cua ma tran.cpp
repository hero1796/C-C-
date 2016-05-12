#include<stdio.h>
#include<conio.h>
main()
{
	printf("\n\n\n");
	printf("		LAP TRINH C: TIM HANG CUA MA TRAN \n\n\n\n");
	printf("				Sinh Vien: NGUYEN TRUNG HIEU - LOP: D14CN08 \n\n");
	printf("				Giang Vien: HOANG PHI DUNG\n\n\n");
	int m,n,rank,e=0;
	float a[100][100],tmp;
	printf("So hang cua ma tran la: ");
	scanf("%d",&m);
	printf("\n So cot cua ma tran la: ");
	scanf("%d",&n);
	printf("\n Nhap vao ma tran can tinh : \n\n");
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf(" nhap a[%d][%d] : ",i,j);
			scanf("%f",&a[i][j]);
		}
		printf("\n");
	}
	(m>=n)?rank=n:rank=m;
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
		{
			if(a[i][i]==0)
			{
			for(int g=1;g<=n;g++)
						    {
		 					tmp=a[i][g];
							a[i][g]=a[m][g];
							a[m][g]=tmp;
							}
						e++;
					    break;	
			}
			if(a[i][i]!=0)
			{
				float x=a[j][i]/(float)a[i][i];
				for(int k=1;k<=n;k++)
				a[j][k]=a[i][k]*x-a[j][k];
			}
				printf("\n");
	    	printf("ma tran sau bien doi la :\n");	
	    	for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				printf("%f ",a[i][j]);
				printf("\n");			
	    	}
		}
	for(int i=m;i>=1;i--)
	{   
	    int t=0;
		for(int j=1;j<=n;j++)
			if(a[i][j]==0) t++;
		if(t==n) rank--;
	}
	printf("\n\n Hang Cua Ma Tran la: %d",rank);
}
