#include<iostream>
using namespace std;
int main()
{
	int n=0, s=0;
	cout<<"Nhap n : ";
	cin>>n;
	while(n>0)
	{
		s+=n%10;
		n=n/10;
	}
	cout<<"Tong cac chu so cua n la : "<<s;
	return 0;
}
