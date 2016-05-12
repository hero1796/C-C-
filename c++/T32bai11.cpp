#include<iostream>
#include<cmath>
using namespace std;
int kt(int n)
{
	int x=0;
	for(int i=1; i<=n; i++)
	{
		if(n%i==0)
		x+=1;
	}
	if(x==2)
	return 1;
	return 0;
}
int kt2(int n)
{
	int s=0, k=n, m=0;
	while(n>0)
	{
		if(kt(n%10)==0)
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
	if(kt(s)==1 && kt(m)==1 && kt(k)==1)
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
		if(kt2(i)==1)
		cout<<i<<"\t";
	}
	return 0;
}
