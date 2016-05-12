#include<stdio.h>
#include<conio.h>
void nhapa(int a[], int &na)
{
     for(int i=0; i<na; i++)
     {
          printf("phan tu thu %d la : ",i);
          scanf("%d",&a[i]);
     }
}
void nhapb(int b[], int &nb)
{
     for(int i=0; i<nb; i++)
     {
          printf("phan tu thu %d la : ",i);
          scanf("%d",&b[i]);
     }
}
void xuata(int a[], int na)
{
     printf("mang a la : ");
     for(int i=0; i<na; i++)
     {
             printf("%d\t",a[i]);
     }
}
void xuatb(int b[], int nb)
{
     printf("mang b la : ");
     for(int i=0; i<nb; i++)
     {
             printf("%d\t",b[i]);
     }
}
int lasnt(int n)
{
     int dem=0;
     for(int i=1; i<=n;i++)
     {
             if(n%i==0)
             dem+=1;
     }
     if(dem==2)
     return 1;
     return 0;
}
int lasonguyen(float n)
{
    if(n==int(n))
    return 1;
    return 0;
}
int chanle(int n)
{
    if(n%2==0)
    return 1;
    return 0;
}
void timkiem(int a[], int na, int x1)
{
    int dem=0;
    printf("\nnhap x1 :");
    scanf("%d",&x1);
    printf("vt cua x1 la :");
    for(int i=0; i<na; i++)
    {
            if(a[i]==x1)
            {
                   printf("%d\t",i);
                   dem+=1;
            }
    }
    if(dem==0)
    printf("-1");
}
void tachcl(int a[],int na,int c[], int &nc,int d[], int &nd)
{
     nc=0;
     nd=0;
     for(int i=0;i<na;i++)
     {
             if(chanle(a[i])==1)
             {
                    c[nc]=a[i];
                    nc++;
             }
             else
             {
                     d[nd]=a[i];
                     nd++;
             }
     }
}
void sapxeptang(int c[], int nc)
{
       for(int i=0;i<nc-1;i++)
       {
             for(int j=i+1;j<nc;j++)
             {
                     if(c[i]>c[j])
                     {
                           int m=c[i];
                           c[i]=c[j];
                           c[j]=m;
                     }      
             }
       }
}
void sapxepgiam(int d[], int nd)
{
       for(int i=0;i<nd-1;i++)
       {
             for(int j=i+1;j<nd;j++)
             {
                     if(d[i]<d[j])
                     {
                           int m=d[i];
                           d[i]=d[j];
                           d[j]=m;
                     }      
             }
       }
}
void gopmang(int a[], int &na,int c[], int nc, int d[], int nd)
{
     na=0;
     for(int i=0;i<nc;i++)
     {
            a[na]=c[i];
            na++;
     }
     for( int i=0;i<nd;i++)
     {
             a[na]=d[i];
             na++;
     }
}
void tachgt(int a[], int na, int x2, int c[], int &nc)
{
     printf("nhap x2 ");
     scanf("%d",&x2);
     nc=0;
     for(int i=0;i<na;i++)
     {
            if(a[i]==x2)
            continue;
            c[nc]=a[i];
            nc++;
     }
}   
void tachsau(int a[], int na, int vt, int c[], int &nc)
{
     printf("nhap vt ");
     scanf("%d",&vt);
     nc=0;
     if(0<vt<na)
     {
     for(int i=vt+1;i<=vt;i++)
     {
             c[nc]=a[i];
             nc++;
     }
     }
}        
main()
{
    int a[100],b[100],c[100],d[100],nd,nc,nb,na,x1,x2;float n;
    printf("so phan tu mang a la :");
    scanf("%f",&n);
    if(lasonguyen(n)==0)
    {
         printf("so phan tu mang phai nguyen");
    }
    else
    { 
         na=n;
         nhapa(a,na);
         xuata(a,na);
    }
    printf("\nso phan tu mang b la :");
    scanf("%f",&n);
    if(lasonguyen(n)==0)
    {
         printf("so phan tu mang phai nguyen");
    }
    else
    {
         nb=n;
         nhapb(b,nb);
         xuatb(b,nb);
    }
    timkiem(a,na,x1);
    tachcl(a,na,c,nc,d,nd);
    sapxeptang(c,nc);
    printf("\nmang cac so chan tang la : ");
    for(int i=0;i<nc;i++)
    {
            printf("%d\t",c[i]);
    }
    sapxepgiam(d,nd);
    printf("\nmang cac so le giam la : ");
    for(int i=0;i<nd;i++)
    {
            printf("%d\t",d[i]);
    }
    gopmang(a,na,c,nc,d,nd);
    printf("\nmang a sau khi sap xep la : ");
    for(int i=0;i<na;i++)
    {
            printf("%d\t",a[i]);
    }
    tachgt(a,na,x2,c,nc);
    printf("\nmang a sau khi tach la : ");
    for(int i=0;i<nc;i++)
    {
            printf("%d\t",c[i]);
    }
    getch();
}
