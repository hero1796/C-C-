#include<iostream>
#include<cmath>
using namespace std;
int kt(int n)
{
	int s=0, k=n, m=0;
	while(n>0)
	{
		if(n%10==0)
		{
	    	return 0;
    	}
    	else
    	{
    		s+=n%10;
    		m=m*10+n%10;
    		n=n/10;
    	}
	}
	if(m==k && s%10==0)
	return 1;
}
int main()
{
	int n=0;
	cout<<"Nhap so chu so : ";
	cin>>n;
	cout<<"Cac so thoa man la : "<<endl;
	for(int  i=pow(10,n-1); i<pow(10,n); i++)
	{
		if(kt(i)==1)
		cout<<i<<"\t";
	}
	return 0;
}
