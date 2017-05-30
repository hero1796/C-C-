#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
typedef float item;
struct Node {
	item heso;
	item somu;
	struct Node *next;
};
typedef struct Node* DaThuc;
// Khoi tao da thuc
void init(DaThuc &D) {
	D = NULL;
}
// Tao mot don thuc
Node *createNode(item heso, item somu) {
	struct Node *tmp = new Node;
	if (tmp == NULL) return 0;
	tmp->heso = heso;
	tmp->somu = somu;
	tmp->next = NULL;
	return tmp;
}
// Chen mot don thuc vao da thuc
void insert(item heso, item somu, DaThuc &D) {
	struct Node *tmp = createNode(heso, somu);
	if(D == NULL) D = tmp;
	else {
		if(tmp->somu > D->somu) { 
			tmp->next = D; D = tmp; // Neu don thuc tmp co so mu > so mu don thuc dau tien cua da thuc thi chen vao dau da thuc
		}
		else if(tmp->somu == D->somu) {
			D->heso += tmp->heso; // Neu don thuc tmp co so mu = so mu don thuc dau tien cua da thuc thi chen cong 2 he so lai
		}
		else if(tmp->somu < D->somu) { // . . . < . . .
			struct Node *p = D, *q = D;
			while(p != NULL) { // Duyet lan luot cac don thuc cua da thuc den khi break
				q = p; p = p->next;
				if (p == NULL || p->somu < tmp->somu) { // Gap don thuc cua da thuc co so mu < so mu cua don thuc tmp hoac khong co do thuc nao thoa man
					q->next = tmp; tmp->next = p; // Chen don thuc tmp vao giua hai don thuc q va p
					break;
				} else if (p->somu == tmp->somu) { // Gap don thuc cua da thuc co so mu = so mu cua don thuc tmp
					p->heso += tmp->heso; // Cong 2 he so cua 2 don thuc do lai
					break;
				}
			}
		}
	}
}

void NhapDaThuc(DaThuc &D1, DaThuc &D2) {
	item heso, somu;
	ifstream f;
	f.open("input.txt");
	string s;
	int check = 1; // Neu check = 1 thi nhap D1 , check = 2 thi nhap D2
	if (f.is_open()) {
   		while (!f.eof()) { // Khi chua gap ki tu cuoi cung cua file
  		  	if(check == 1) {
  		  		f>>heso>>somu;
    			insert(heso, somu, D1);
			} else if(check == 2) { 
				f>>heso>>somu;
    			insert(heso, somu, D2);
			}
    		getline(f, s);
  		  	if(f.peek() == '\n' && s.empty()) { // Phan tu dau tien cua dong la "\n" va dong do khong co ki tu nao
				check = 2;
				cout<<endl;
			}
  		}
  		f.close();
 	} else cout << "Khong the mo file !"<<endl; 
}

void Result(DaThuc D) {
	ofstream f;
  	f.open ("output.txt",ios::app); // Viet tiep vao file, khong bi ghi de file
	for(struct Node*p = D; p != NULL; p = p->next) {
		if(p->next == NULL) {
			cout << p->heso << "x^" << p->somu << endl;
			f << p->heso << "x^" << p->somu << endl;
			break;
		}
		cout << p->heso << "x^" << p->somu << " + ";
		f << p->heso << "x^" << p->somu << " + ";
	}
	f.close();
}
// Insert lan luot cac don thuc cua D1 va D2 vao Da thuc Tong
DaThuc Cong(DaThuc D1, DaThuc D2) {
	DaThuc Tong = NULL;
	while(D1 != NULL) {
		insert(D1->heso, D1->somu, Tong);
		D1 = D1->next;
	}
	while(D2 != NULL) {
		insert(D2->heso, D2->somu, Tong);
		D2 = D2->next;
	}
	return Tong;
}
//  Insert lan luot cac don thuc cua D1 va D2 vao Da thuc Hieu nhung phai doi dau he so cua D2
DaThuc Tru(DaThuc D1, DaThuc D2) {
	DaThuc Hieu = NULL;
	while(D1 != NULL) {
		insert(D1->heso, D1->somu, Hieu);
		D1 = D1->next;
	}
	while(D2 != NULL) {
		insert(-D2->heso, D2->somu, Hieu);
		D2 = D2->next;
	}
	return Hieu;
}
// Nhan lan luot tung don thuc cua D2 voi cac don thuc cua D1 roi Insert vao Da thuc Tich
DaThuc Nhan(DaThuc D1, DaThuc D2) {
	DaThuc Tich = NULL;
	for(Node *p = D1; p != NULL; p = p->next) {
		for(Node *q = D2; q != NULL; q = q->next) {
			insert(p->heso * q->heso, p->somu + q->somu, Tich);
		}
	}
	return Tich;
}
// Xoa don thuc dau tien cua Da thuc
void Del_Front(DaThuc &D) {
	if(D == NULL) return;
	struct Node *p = D;
	D = D->next; 
	delete(p);
}

void ChiaDaThuc(DaThuc D1, DaThuc D2) {
	if(D1->somu < D2->somu) { // So mu lon nhat cua D1 nho hon so mu lon nhat cua D2
		cout << "P(x) / Q(x) = 0"<<endl;
		cout <<"Phan du : "; Result(D1); // Phan du = Da thuc D1
	} else {
		DaThuc Thuong = NULL, Du = D1; // Phan du ban dau cho = D1
		while (Du->somu >= D2->somu) { // Khi con co the chia duoc
			insert(Du->heso / D2->heso, Du->somu - D2->somu, Thuong);// insert don thuc = don thuc dau tien cua Du / don thuc dau tien cua D2 vao Da thuc Thuong
			struct Node *p = Thuong;
			while (p->next != NULL) p = p->next; // Tim don thuc p la don thuc cuoi cung cua Da thuc Thuong de nhan voi Da thuc D2
			Du = Tru(Du, Nhan(p, D2)); // Xet lai Da thuc Du = cach tru Da thuc Du cho Da thuc (p*D2)
			Del_Front(Du); // Xoa 0X^0 la don thuc dau tien cua Da thuc Du vua nhan duoc
			if(Du == NULL) { // Khi D1 chia het cho D2 thi Du = NULL nen phai thoat vong lap ngay !
				insert(0, 0, Du);
				break;
			}
		}
		cout << "P(x) / Q(x) = "; Result(Thuong); cout<<endl;
		cout <<"Phan du : "; Result(Du);
	}
}

int main(){
	DaThuc D1;
	DaThuc D2;
	init(D1);
	init(D2);
	NhapDaThuc(D1,D2);
	cout<<"Da thuc D1 la : "; Result(D1); cout<<endl;
	cout<<"Da thuc D2 la : "; Result(D2); cout<<endl;
	cout<<"Da thuc tong la : "; Result(Cong(D1,D2)); cout<<endl;
	cout<<"Da thuc hieu la : "; Result(Tru(D1,D2)); cout<<endl;
	cout<<"Da thuc tich la : "; Result(Nhan(D1,D2)); cout<<endl;
	ChiaDaThuc(D1,D2);
	return 0;
}
