#include  <stdio.h> 
#include  <conio.h> 
#include  <stdlib.h> 
#define MAX 100 
#define TRUE 1 
#define FALSE 0 
int P[MAX], B[MAX], n, count = 0;
void Init(){
 printf("\n Nhap n="); scanf("%d", &n);
 for (int i = 1; i <= n; i++)
  B[i] = TRUE;
}
void Result(){
 count++;
 printf("\n Hoan vi thu %d:", count);
 for (int i = 1; i <= n; i++)
  printf("%3d", P[i]);
 getch();
}
void Try(int i){
 for (int j = 1; j <= n; j++){
  if (B[j]) {
   P[i] = j;
   B[j] = FALSE;
   if (i == n) Result();
   else Try(i + 1);
   B[j] = TRUE;
  }
 }
}
int main(){
 Init();
 Try(1);
 return 0;
}
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int a[1000], temp, n;

// void xuat() {
// 	for(int i = 1; i <= n; ++i) {
// 		cout << a[i];
// 	}
// 	cout << endl;
// }

// void sinhHoanVi() {
// 	xuat();
// 	for(int i = n; i > 1; --i) {
// 		if(a[i] < a[i-1]) {
// 			if(i == 2) return;
// 			continue;
// 		} else  {
// 			sort(a + i, a + n + 1);
// 			auto upper = upper_bound(a + i, a + n, a[i - 1]);
// 			temp = a[i - 1];
// 			a[i -1] = *upper;
// 			*upper = temp;
// 			sort(a + i, a + n + 1);
// 			break;
// 		}
// 	}
// 	sinhHoanVi();
// }

// int main() {
// 	cin >> n;
// 	for(int i = 1; i <= n; ++i) {
// 		a[i] = i;
// 	}
// 	sinhHoanVi();
// 	return 0;
// }