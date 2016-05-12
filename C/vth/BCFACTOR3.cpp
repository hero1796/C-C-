#include<stdio.h>
#include<math.h>
main()
{
	long n,i,j;
	scanf("%ld",&n);
	for(i=2;i<=sqrt(n);i++)
	{ 	
		if(n%i==0)
		{	
		    j=0;
		    while(n%i==0)	
	    	{
		    	n=n/i;
			    j++;
	    	}
	        printf("%ld %ld\n",i,j);
		}
    }
    if(n!=1)
	printf("%ld 1",n);
}
