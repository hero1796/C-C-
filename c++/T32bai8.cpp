#include<iostream>
using namespace std;
int main()
{
	for(char i= 'A'; i<= 'Z'; i++)
	{
		cout<<i<<"  ---  "<<int(i)<<"  ---  ";
		int a[50], n=0;
		int b = i;
		while(b>0)
    	{
    		a[n]=b%2;
    		b=b/2;
	    	n+=1;
    	}
     	for(int j=n; j>=0; j--)
    	{
	    	cout<<a[j];
    	}
    	cout<<endl;
	}
	return 0;
}
