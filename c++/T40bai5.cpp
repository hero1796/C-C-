#include<iostream>
#include<cmath>
using namespace std;
typedef struct donthuc
{
	int heso=0;
	int somu=0;
};
void nhap(donthuc *a, int x)//NHap cac don thuc cua da thuc
{ 
	for(int i=1; i<=x; i++)
	{
		cout<<"Nhap he so va so mu don thuc thu "<<i<<endl;
		cin>>a[i].heso;
		cin>>a[i].somu;
	}
}
void xuat(donthuc *a, int x)//Hien thi da thuc
{
	for(int i=1; i<=x; i++)
	{
		if(a[i].heso!=0)
		{
    		cout<<a[i].heso<<"."<<"x^"<<a[i].somu;
        	if(i!=x)
			cout<<" + ";
        }
        else
        {
        	if(i==x)
        	{
				cout<<" 0 ";
        	}
        	else
        	{
             	cout<<"0";
            	cout<<" + ";
            }
        }
	}
}
void sapxep(donthuc *a, int x)//sap xep da thuc theo so mu giam dan
{
	for(int i=1; i<x; i++)
	{
		for(int j=i+1; j<=x; j++)
		{
			if(a[i].somu<a[j].somu)
			{
				int tmp1=a[i].somu;
				a[i].somu=a[j].somu;
				a[j].somu=tmp1;
				int tmp2=a[i].heso;
				a[i].heso=a[j].heso;
				a[j].heso=tmp2;
			}
		}
	}
}
void Px0(donthuc *p, int n)//tinh Pn(x0)
{
	int s=0, x0=0;
	cout<<endl<<"Nhap x0 = ";
	cin>>x0;
	for(int i=1; i<=n; i++)
	{
		s+=p[i].heso*(pow(x0,p[i].somu));
	}
	cout<<"Pn(x0) = "<<s;
}
void daoham(donthuc *p, int n, donthuc *a, int &x)//tinh dao ham Pn(x)
{
    x=0;
	for(int i=1; i<=n; i++)
	{
		a[i].heso=p[i].heso*p[i].somu;
		a[i].somu=p[i].somu-1;
		x++;
	}
	xuat(a,x);
}
void tong(donthuc *p, int n, donthuc *q, int m, donthuc *a, int &x)//tinh tong
{
	x=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(p[i].somu==q[j].somu)
			{
	    		a[x].heso=p[i].heso+q[j].heso;
	    		a[x].somu=p[i].somu;
	    		x++;
    		}
		}
	}
	for(int i=1; i<=n; i++)
	{
		int dem=0;
		for(int j=1; j<x;j++)
		{
			if(p[i].somu==a[j].somu)
			dem++;
		}
		if(dem==0)
		{
			a[x].heso=p[i].heso;
			a[x].somu=p[i].somu;
			x++;
		}
	}
	for(int i=1; i<=m; i++)
	{
		int dem=0;
		for(int j=1; j<x;j++)
		{
			if(q[i].somu==a[j].somu)
			dem++;
		}
		if(dem==0)
		{
			a[x].heso=q[i].heso;
			a[x].somu=q[i].somu;
			x++;
		}
	}
	x--;
}
void hieu(donthuc *p, int n, donthuc *q, int m, donthuc *a, int &x)//tinh hieu P(x)-Q(x)
{
	x=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(p[i].somu==q[j].somu)
			{
	    		a[x].heso=p[i].heso-q[j].heso;
	    		a[x].somu=p[i].somu;
	    		x++;
    		}
		}
	}
	for(int i=1; i<=n; i++)
	{
		int dem=0;
		for(int j=1; j<x;j++)
		{
			if(p[i].somu==a[j].somu)
			dem++;
		}
		if(dem==0)
		{
			a[x].heso=p[i].heso;
			a[x].somu=p[i].somu;
			x++;
		}
	}
	for(int i=1; i<=m; i++)
	{
		int dem=0;
		for(int j=1; j<x;j++)
		{
			if(q[i].somu==a[j].somu)
			dem++;
		}
		if(dem==0)
		{
			a[x].heso=q[i].heso;
			a[x].somu=q[i].somu;
			x++;
		}
	}
	x--;
}
void tich(donthuc *p, int n, donthuc *q, int m, donthuc *a, int &x, donthuc *b, int &y)
{
	x=1,y=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			b[y].heso=p[i].heso*q[j].heso;
			b[y].somu=p[i].somu+q[j].somu;
			y++;
		}
	}
	y--;
	sapxep(b,y);
	/*for(int i=1; i<y; i++)
	{
		if(b[i].heso!=0)
		{
			a[x].heso==b[i].heso;
			a[x].somu==b[i].somu;
	    	for(int j=i+1; j<=y; j++)
    		{
    			if(b[i].somu==b[j].somu)
    			{
    				a[x].heso+=b[j].heso;
    				a[x].somu=b[j].somu;
    				b[j].heso=0;
    			}
    		}
    		x++;
		}
	}
	x--;*/
}
int main()
{
	int n=0, m=0, x=0, y=0;
	cout<<"Nhap so don thuc cua P : ";
	cin>>n;
	cout<<"NHap so don thuc cua Q : ";
	cin>>m;
	donthuc *p, *q, *a, *b;
	p= new donthuc[n];
	q= new donthuc[m];
	b= new donthuc[y];
	a= new donthuc[x];
	cout<<"Nhap da thuc P : "<<endl;
	nhap(p,n);
	cout<<"Nhap da thuc Q : "<<endl;
	nhap(q,m);
	sapxep(p,n);
	sapxep(q,m);
	cout<<"Da thuc P la : ";
	xuat(p,n);
	cout<<endl;
	cout<<"Da thuc Q la : ";
	xuat(q,m);
	cout<<endl<<"- - - - - - - - - - - - - - - -"<<endl;
	Px0(p,n);
	cout<<endl<<"- - - - - - - - - - - - - - - -"<<endl<<endl;
	cout<<"Dao ham cap 1 cua P la : ";
	daoham(p,n,a,x);
	cout<<endl<<"- - - - - - - - - - - - - - - -"<<endl<<endl;
	tong(p,n,q,m,a,x);
	sapxep(a,x);
	cout<<"Tong 2 da thuc la : ";
	xuat(a,x);
	cout<<endl<<"- - - - - - - - - - - - - - - -"<<endl<<endl;
	hieu(p,n,q,m,a,x);
	sapxep(a,x);
	cout<<"Hieu 2 da thuc la : ";
	xuat(a,x);
	cout<<endl<<"- - - - - - - - - - - - - - - -"<<endl<<endl;
	tich(p,n,q,m,a,x,b,y);
	xuat(b,y);
	return 0;
}
