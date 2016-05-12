#include<iostream>
#include<cmath>
using namespace std;
int ktdx(int n)
{
	int s=0, k=n;
	while(n!=0)
	{
		s=s*10+(n%10);
		n=n/10;
	}
	if(s==k)
	return 1;
}
int tong(int n)
{
	int s=0;
	while(n!=0)
	{
		s+=n%10;
		n=n/10;
	}
	return s;
}
int main()
{
	int n=0, s=0;
	cout<<"Nhap N va S : ";
	cin>>n;
	cin>>s;
	cout<<"Cac so thoa man la : ";
	for(int i=pow(10,n-1); i<pow(10,n); i++)
	{
		if(tong(i)==s && ktdx(i)==1)
		cout<<i<<"\t";
	}
	return 0;
}
