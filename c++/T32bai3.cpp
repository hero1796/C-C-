#include<iostream>
#include<cmath>
using namespace std;
int ktsnt(int n)
{
	int x=0;
	for(int i=1; i<=n; i++)
	{
		if(n%i==0)
		x+=1;
	}
	if(x==2)
	return 1;
}
int tong(int n)
{
	int s=0;
	while(n>0)
	{
		s+=n%10;
		n=n/10;
	}
	return s;
}
int main()
{
	int n=0, s=0;
	cout<<"Nhap so chu so N : ";
	cin>>n;
	cout<<"Nhap vao so S : ";
	cin>>s;
	cout<<"Cac so thoa man la : ";
	for(int i=pow(10,n-1); i<=pow(10,n); i++)
	{
		if(ktsnt(i)==1 && tong(i)==s)
		cout<<i<<"\t";
	}
	return 0;
}
