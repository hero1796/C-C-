#include<stdio.h>
#include<math.h>
main()
{
	long n,i,j;
	scanf("%ld",&n);
	for(i=2;i<=n;i++)
	{
		if(n%i==0)
		{
		j=0;
		while(n>0&&n%i==0)
		
		  { 
		  n=n/i;
		  j++;   
		  }
		printf("%ld %ld\n",i,j);
		}
	}
}
