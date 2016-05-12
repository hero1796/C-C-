#include<iostream>
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
int main()
{
	int n=0;
	cout<<"Nhap n : ";
	cin>>n;
	if(n<=2)
	cout<<"Khong co snt nao thoa man";
	else
	{
    	cout<<"Cac snt nho hon n la : ";
    	for(int i=2; i<=n; i++)
    	{
	    	if(ktsnt(i)==1)
	    	cout<<i<<"\t";
    	}
    }
	return 0;
}
