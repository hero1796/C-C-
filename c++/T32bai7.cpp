#include<iostream>
#include<cmath>
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
	cout<<"Nhap so chu so : ";
	cin>>n;
	for(int i=pow(10,n-1); i<pow(10,n); i++)
	{
		if(pow(10,n-1)<=tonguoc(i)<=pow(10,n) && i==tonguoc(tonguoc(i)) && i!=tonguoc(i) && i<tonguoc(i))
		cout<<i<<"va"<<tonguoc(i)<<endl<<endl;
	}
	return 0;
}
