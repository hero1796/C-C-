#include<stdio.h>
main()
{
  int a[100],n,x,t=0;
  scanf("%d %d",&n, &x);
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  for(int i=0;i<n;i++)
    {
    	if(x==a[i]) 
		  printf("%d ",i);
		else t++;
    }
   if(t==n) printf(" 0 ");	    	
}
