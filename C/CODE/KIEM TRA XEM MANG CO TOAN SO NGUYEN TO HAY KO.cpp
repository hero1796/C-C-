#include<stdio.h>
main()
{
  int a[100],n,b=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  for(int i=0;i<n;i++)
    {  
      int t=1; 
      for(int j=2;j<a[i];j++)
	    {
	    	if(a[i]%j==0) 
			 {	
			  t=2;
	    	  printf ("no");
			  break;
		     }
		}
	   if(t==2) break;
	   else b++;		
	}
   if(b==n) printf("yes");	 	    	
}
