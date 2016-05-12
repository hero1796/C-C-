#include<iostream>
#include<cmath>
using namespace std;
void ptbac2(float a, float b, float c)
{
	float dt=(b*b)-(4*a*c);
	if(a==0)
	{
		if(b!=0)
		cout<<"PT co nghiem x= "<<(-c/b);
		else
		{
			if(c==0)
			cout<<"PT co vo so nghiem";
			else
			cout<<"PT vo nghiem";
		}
	}
	else
	{
		if(dt<0)
		cout<<"PT vo nghiem";
		else
		{
			if(dt==0)
			cout<<"PT co nghiem kep x= "<<((-b)/(2*a));
			else
			cout<<"PT co 2 nghiem phan biet :"<<endl<<"x1= "<<((-b+sqrt(dt))/(2*a))<<endl<<"x2=  "<<((-b-sqrt(dt))/(2*a));
		}
	}
}
int main()
{
	float a, b, c;
	cout<<"NHap lan luot a, b, c : ";
	cin>>a>>b>>c;
	ptbac2(a,b,c);
	return 0;
}
