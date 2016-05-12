#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
	printf("\n\n\n");
	printf("		LAP TRINH C: TINH DINH THUC MA TRAN \n\n\n\n");
	printf("				Sinh Vien: NGUYEN TRUNG HIEU - LOP: D14CN08 \n\n");
	printf("				Giang Vien: HOANG PHI DUNG\n\n\n");
	float a[100][100],det=1,tmp;
	int t,n,e=0;
	printf("Co cua ma tran la: ");
	scanf("%d",&n);
	printf("\n\n");
	if(n<2) printf("Khong co ma tran thoa man xin hay nhap lai ma tran ");
	if(n>=2)
    {
	printf("Hay nhap vao ma tran:\n\n ");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			{
			printf("nhap a[%d][%d] : ",i,j);
			scanf("%f",&a[i][j]);
		    }
	printf("\n");	    
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
			if(a[i][i]==0)
			{
				for(int m=i+1;m<=n;m++)
					{
					int p=0;	
					if(a[m][i]!=0)
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
					}
			}
			if(a[i][i]==0)
				{
				printf("dinh thuc la : det = 0");
				break;
				}
			if(det!=0)
			{
				float x=a[j][i]/(float)a[i][i];
	            for(int k=1;k<=n;k++)
					a[j][k]=a[i][k]*x-a[j][k];
			}
			printf("\n");
	printf("ma tran sau bien doi la :\n ");	
	for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=n;j++)
			printf("%.2f ",a[i][j]);
		printf("\n");			
	    }	
		}	
	for(int i=1;i<=n;i++)
	det=(det*a[i][i]);
	det=det*pow(-1,e);
	printf("\n\n");
	printf("Dinh Thuc Cua Ma Tran La: %.2f",det);    
	}
}
