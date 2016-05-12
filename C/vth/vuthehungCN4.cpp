#include<stdio.h>
#include<conio.h>
void nhapmanga (int a[], int &na)
{
     printf("nhap so luong phan tu mang a : ");
     scanf("%d",&na);
     for(int i=0;i<na;i++)
     {
          printf("nhap phan tu thu %d cua mang a : ",i);
          scanf("%d",&a[i]);
     }
}
void nhapmangb(int b[], int &nb)
{
     printf("\nnhap so luong phan tu mang b : ");
     scanf("%d",&nb);
     for(int i=0;i<nb;i++)
     {
          printf("nhap phan tu thu %d cua mang b : ",i);
          scanf("%d",&b[i]);
     }
}
void xuatmanga(int a[], int na)
{
     printf("cac phan tu cua mang a la : ");
     for(int i=0;i<na;i++)
     {
          printf("%d\t",a[i]);
     }
}
void xuatmangb(int b[], int nb)
{
     printf("\ncac phan tu cua mang b la : ");
     for(int i=0;i<nb;i++)
     {
          printf("%d\t",b[i]);
     }
}
int timkiem(int a[], int na, int x1)
{
int vt = -1;
while (vt < na && a[vt] != x1)
vt++;
if (vt < na)
return vt;
return -1;
}
int LaSNT(int n)
{
   int dem = 0;
   for (int i = 1; i <= n; i++)
   if (n % i == 0)
   dem++;
   if (dem == 2)
   return 1;
   else
   return 0;
}
int kiemtra(int a[], int na)
{
for (int i = 0; i < na; i++)
if (!LaSNT(a[i]))
return 0;
return 1;
}
void tachSNT(int a[], int na, int c[], int &nc)
{
     nc=0;
     for(int i=0;i<na;i++)
     {
         if(LaSNT(a[i]))
         {
              c[nc]=a[i];
              nc++;
         }
     }
}
void tachSNT2(int a[], int na, int d[], int &nd)
{
     nd=0;
     for(int i=0;i<na;i++)
     {
          if(!LaSNT(a[i]))
          {
               d[nd]=a[i];
               nd++;
          }
     }
}
void gopmang(int a[], int na, int b[], int nb, int c[], int &nc)
{
     nc=0;
     for(int i=0;i<na;i++)
     {
          c[nc]=a[i];
          nc++;            
     }
     for(int i=0;i<nb;i++)
     {
          c[nc]=b[i];
          nc++;            
     }
}
int max(int a[], int na)
{
      int max = a[0];
      for(int i=1;i<na;i++)
      {
            if(a[i]>max)
            max=a[i];           
      }
      return max;
}
int min(int a[], int na)
{
      int min = a[0];
      for(int i=1;i<na;i++)
      {
              if(min>a[i])
              min=a[i];
      }
      return min;
}
void sapxeptang(int a[], int na)
{
      for(int i=0;i<na-1;i++)
      {
             for(int j=i+1;j<na;j++)
             {
                    if(a[i]>a[j])
                    {
                          int tmp=a[i];
                          a[i]=a[j];
                          a[j]=tmp;       
                    } 
             }         
      }
}
void sapxepgiam(int a[], int na)
{
      for(int i=0;i<na-1;i++)
      {
             for(int j=i+1;j<na;j++)
             {
                    if(a[i]<a[j])
                    {
                          int tmp=a[i];
                          a[i]=a[j];
                          a[j]=tmp;       
                    } 
             }         
      }
}
void them(int a[], int &na, int vt, int x2)
{
     if(0<=vt&&vt<=na)
     {
           for(int i=na;i>vt;i--)
           {
                 a[i]=a[i-1];            
           }
           a[vt]=x2;
     }
}
void sua(int a[], int na, int vt, int x2)
{
     if(0<=vt&&vt<na)
     a[vt]=x2;
}
void xoa(int a[], int &na, int vt)
{
     if(0<=vt&&vt<na)
     {
           for(int i=vt;i<na-1;i++)
           {
                 a[i]=a[i+1];            
           }
           na--;           
     }
}
main()
{
      int a[100],b[100],c[100],d[100];
      int na,nb,nc,nd,x1,x2,vt;
      nhapmanga(a,na);
      nhapmangb(b,nb);
      xuatmanga(a,na);
      xuatmangb(b,nb);
      printf("\n\n");
      printf("x1 = ");
      scanf("%d",&x1);
      printf("vi tri cua x1 la : %d \n\n",timkiem(a,na,x1));
      if(kiemtra(a,na)==1)
      {
           printf("mang toan so nguyen to\n\n");
           tachSNT(a,na,c,nc);
           printf("cac snt trong mang a la : ");
           for(int i=0;i<nc;i++)
           {
               printf("%d\t",c[i]);
           }
          
      }
      else
      {
      printf("mang co phan tu k la so nguyen to\n\n");
       tachSNT(a,na,c,nc);
           printf("cac snt trong mang a la : ");
           for(int i=0;i<nc;i++)
           {
               printf("%d\t",c[i]);
           }
      printf("\n");
           tachSNT2(a,na,d,nd);
           printf("cac so k phai snt trong mang a la :");
           for(int i=0;i<nd;i++)
           {
               printf("%d\t",d[i]);
           }
      }
      gopmang(a,na,b,nb,c,nc);
      printf("\n\nmang sau khi gop 2 mang a va b la :");
      for(int i=0;i<nc;i++)
           {
               printf("%d\t",c[i]);
           }
      printf("\n\n max mang a la : %d\n",max(a,na));
      printf("\n\n min mang a la : %d\n\n",min(a,na));
      sapxeptang(a,na);
      printf("mang a sap xep tang la : ");
       for(int i=0;i<na;i++)
           {
               printf("%d\t",a[i]);
           }
       sapxepgiam(a,na);
       printf("\n\n mang a sap xep giam la :");
       for(int i=0;i<na;i++)
           {
               printf("%d\t",a[i]);
           }
           
           
            printf("\n\n x2=");
       scanf("%d",&x2);
       printf("vt=");
       scanf("%d",&vt);
       printf("\n");
       
       
       
      nhapmanga(a,na);
      xuatmanga(a,na);
       them(a,na,vt,x2);
       printf("\n\n mang a sap sau khi them la :");
       for(int i=0;i<=na;i++)
           {
               printf("%d",a[i]);
           }
        printf("\n");
        
        
      nhapmanga(a,na);
      xuatmanga(a,na);
       xoa(a,na,vt);
        printf("\n\n mang a sap sau khi xoa la :");
         for(int i=0;i<na;i++)
           {
               printf("%d\t",a[i]);
           }
            printf("\n");
            
            
      nhapmanga(a,na);
      xuatmanga(a,na);
           sua(a,na,vt,x2);
          printf("\n\n mang a sap sau khi sua la :"); 
           for(int i=0;i<na;i++)
           {
               printf("%d\t",a[i]);
           }
           getch();
}



