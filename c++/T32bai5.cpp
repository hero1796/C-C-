#include<iostream>
using namespace std;
int ucln(int a, int b)
{
	while(a!=b)
	{
		if(a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
	}
    return a; 
}
int main()
{
	int a=0, b=0;
	cout<<"Nhap a : ";
	cin>>a;
	cout<<"Nhap b : ";
	cin>>b;
	if(a*b==0)
	{
		if(a==0 && b==0)
		{
			cout<<"Khong co ucln";
		}
		else
		{
			if(a!=0)
			{
				cout<<"ucln la : ";
				cout<<a;
			}
			else
			{
				cout<<"ucln la : ";
				cout<<b;
			}
		}
	}
	else
	{
		cout<<"ucln la : ";
		cout<<ucln(a,b);
	}
	return 0;
}
