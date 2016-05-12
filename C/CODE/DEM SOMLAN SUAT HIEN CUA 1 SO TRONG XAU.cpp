#include<stdio.h>
#include<string.h>
main()
{  
   int demcs[10]={0};
   char x[1001];
   scanf("%s",&x);
   for(int i=0;i<strlen(x);i++)
   demcs[x[i]-'0']++;
   for(int i=0;i<=9;i++)
   printf("%d xuat hien %d lan \n",i,demcs[i]);
   
}
