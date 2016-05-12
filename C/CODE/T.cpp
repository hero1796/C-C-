#include<stdio.h>
int doihang()
{
	for(int i= t+1;i<=n;i++)
		{
			if(a[i][i]!=0);
			  {
			  for(int j=1;j<=n;j++)
			  a[t][j]=a[i][j]
			  break;
			  }
	    }
	 return doihang();   
}

main()
{
	int a[100][100],n,t,det;
	printf("co cua ma tran la n= ");
	scanf("%d",&n);
	printf(" nhap ma tran \n");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			printf("nhap a[%d][%d] \n",i,j);		
	 		scanf("%.2f",&a[i][j]);
	    }
	    
	for(t=1;t<=n;t++)
		for(int j=i+1;j<=n;j++)
		{
			if a[t][t]==0 
			doihang();
			
			float x=a[j][t]/(float)(a[t][t]);
			for(int k=1;k<=n;k++)
			a[j][k]=a[t][k]*x-a[j][k];	
		}
    for(int i=1;i<=n;i++)
	  {
	    for(int j=1;j<=n;j++)
			printf("%d",a[i][j])
		printf("\n");
	  }
}
