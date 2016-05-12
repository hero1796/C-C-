#include<stdio.h>
main()
{
	long n,i=2,j;
	scanf("%ld",&n);
	while(i<=n)
	{
		if(n%i==0)
		{
		j=0;
		while(n>0n%i==0)
			{
			n=n/i;
			j++;
		    }
		printf("%ld %ld\n",i,j);
		}
		else
		i++;
	}
}
