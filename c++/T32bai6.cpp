#include<iostream>
using namespace std;
int tonguoc(int n)
{
	int s=0;
	for(int i=1; i<n; i++)
	{
		if(n%i==0)
		{
			s+=i;
		}
	}
	return s;
}
int main()
{
	int n=0;
	cout<<"Nhap n : ";
	cin>>n;
	cout<<"Cac so hoan hao nho hon n la : ";
	for(int i=1; i<=n; i++)
	{
		if(tonguoc(i)==i)
		{
			cout<<i<<"\t";
		}
	}
	return 0;
}
