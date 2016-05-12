#include<stdio.h>
#include<conio.h>

void nhapmatran(int x[100][100],int &z,int &v) {
    for(int i=1;i<=z;i++) {
    	for(int j=1;j<=v;j++) {
        	printf("nhap phan tu %d%d : ",i,j);
        	scanf("%d",&x[i][j]);
    	}
    }
}
void inmatran(int x[100][100],int &z,int &v) {
    for(int i=1;i<=z;i++) {
        for(int j=1;j<=v;j++) {
        	printf("%d  ",x[i][j]);            
        }
		printf("\n");	
    }
}
main() {
    int a[100][100],b[100][100],c[100][100];
    int n,m,t,h,i,j,k;
    
	printf("nhap so hang va so cot cua ma tran A : ");
    scanf("%d %d",&n,&m);
    printf("\nnhap ma tran A:\n");
    nhapmatran(a,n,m);
    printf("\nma tran A la:\n");
    inmatran(a,n,m);
    
    printf("nhap so hang va so cot cua ma tran B: ");
    scanf("%d %d      ",&h,&t);
    printf("\nnhap ma tran B:\n");
    nhapmatran(b,h,t);
    printf("\nma tran B la:\n");
    inmatran(b,h,t);
    
}
