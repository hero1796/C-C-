#include<stdio.h>
void duongchay(int a[],int n)
{
    int dem[100], vt[100],i,j;
    for(i=1;i<=100;i++)
        dem[i]=0;
    int m=1,k;
    for(i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
           dem[m]++;

        else
        {
            m++;
            vt[m]=i+1;
        }
    }
    int max=dem[1];
    for(i=1;i<=m;i++)
        if(dem[i]>max)
        {
            max=dem[i];
            k=i;
        }
    printf("%d\n",max);
    for(i=vt[k];i<=vt[k]+max;i++)
    printf("%d ",a[i]);
}
main()
{
    int n,a[100],i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    duongchay(a,n);
}
