#include<stdio.h>
main()
{
   int a[100],b[100],n,k,ak;
   scanf("%d %d %d",&n, &k, &ak);
   for(int i=0;i<n;i++)
   scanf("%d",&a[i]);
   for(int i=k;i<n;i++)
   b[i]=a[i];
   a[k]=ak;
   for(int i=k;i<n+1;i++)
   a[i+1]=b[i];
   for(int i=0;i<n+1;i++)
   printf("%d ",a[i]);
    
}
