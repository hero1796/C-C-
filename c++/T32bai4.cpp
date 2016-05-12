#include<iostream>
using namespace std;
int main()
{
	int n=0;
	cout<<"Nhap n : ";
	cin>>n;
	cout<<n<<"=";
	int i=2;
	while(n!=1)
	{
		if(n%i==0)
		{
			if(n!=i)
			{
		    	cout<<i<<"*";
		    	n=n/i;
		    }
		  	else
		    {
				cout<<i;
				n=n/i;
		    }
		}
		else
		i++;	
	}
	return 0;
}
