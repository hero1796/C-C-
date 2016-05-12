#include<stdio.h>
void nhapmatran(float r[100][100],int a, int b);
void inmatran(float r[100][100],int a, int b);

void nhapmatran(float r[100][100],int a, int b)
{
	
	for( int i=1;i<=a;i++)
	{
		float x;
		for(int j=1;j<=b;j++)
			{
			printf("r[%d][%d]: ",i,j);
		
			scanf("%f",&x);
			r[i][j]=x;
			}
	
	
	}
}
void inmatran(float r[100][100],int a, int b)
{ 
	for(int i=1;i<=a;i++)
	{
		for( int j=1;j<=b;j++)
		{
		printf("%f ",r[i][j]);
		}
	 printf("\n");
	}
}
main()
{
	int m,n,f,g,k;
	float a[100][100],b[100][100],c[100][100];
	printf("nhap co cua ma tran a: ");
	scanf("%d%d",&m,&n);
	printf("\n\\n");
	printf("nhap co ma tran b: ");
	scanf("%d%d",&f,&g);
	printf("\n\n");
	if(n!=f) printf("co cua 2 ma tran khong hop le");
	else
	{
		printf("nhap tran a : \n");
		nhapmatran(a,m,n);
		printf("\n\n nhap ma tran b : ");
		nhapmatran(b,f,g);
		printf("\n\n ma tran a la: \n");
		inmatran(a,m,n);
		printf("\n\n ma tran b la :\n");
		inmatran(b,f,g);
		
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			c[i][k]=0;
			for(int k=1;k<=f;k++)
			c[i][k]=c[i][k]+a[i][k]*b[k][j];
		}
		
		printf("\n\n ma tran can tim la: ");
		inmatran(c,m,g);
	}
	
	
}
