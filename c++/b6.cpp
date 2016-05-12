#include<bits/stdc++.h>
using namespace std;
int id1=999,id2=999;
class BPC;
class DA;
void sapXep(BPC *bpc,int n);
void timKiem(BPC *bpc,int n);
//void swap(DA &da1,DA &da2);

class Nguoi{
	protected:
		string hoten,diachi;
};
class NV:public Nguoi{
	private:
		int manv,bacluong;
	public:
		friend void timKiem(BPC *bpc,int n);
		friend void sapXep(BPC *bpc,int n);
		friend class BPC;
		NV(){
			manv=id1;
			id1++;
		}
		void nhap(int i){
			cout<<"Nhap thong tin Nhan vien thu "<<i<<" :"<<endl;
			cout<<"\tHo ten: ";	getline(cin,hoten);
			cout<<"\tDia chi: ";	getline(cin,diachi);
			cout<<"\tBac luong: ";	cin>>bacluong;	cin.ignore();
			cout<<"\n";
		}
		void xuat(int i){
			cout<<"Nhan Vien "<<i<<" :"<<endl;
			cout<<"\tHo ten: "<<hoten<<"\t Ma nhan vien: "<<manv<<endl;
			cout<<"\tBac Luong: "<<bacluong<<endl;
			cout<<"\tDia chi: "<<diachi<<"\n\n";
		}
		void ghiFile(int i){
			ofstream fout("NV.DAT",ios::app);
			fout<<"------------------------Nhan Vien "<<i<<"----------------------------"<<endl;
			fout<<"\tHo ten: "<<hoten<<"\t Ma nhan vien: "<<manv<<endl;
			fout<<"\tBac luong: "<<bacluong<<endl;
			fout<<"\tDia chi: "<<diachi<<"\n\n";
		}
};
class DA{
	private:
		int mada;
		string tenda,kieuda;
		float kinhphi;
	public:
		friend void timKiem(BPC *bpc,int n);
		friend void sapXep(BPC *bpc,int n);
		friend class BPC;
		DA(){
			mada=id2;
			id2++;
		}
		void nhap(int i){
			cout<<"Nhap thong tin du an "<<i<<" : "<<endl;
			cout<<"\tTen du an: ";	getline(cin,tenda);
			cout<<"\tKieu du an: ";	getline(cin,kieuda);
			cout<<"\tKinh phi: ";	cin>>kinhphi;	cin.ignore();
		}
		void xuat(int i){
			cout<<"Du an "<<i<<" : "<<endl;
			cout<<"\tTen du an: "<<tenda<<"\t\tMa du an: "<<mada<<endl;
			cout<<"\tKieu du an: "<<kieuda<<endl;
			cout<<"\tKinh phi: "<<kinhphi<<"\n\n";
		}
		void ghiFile(int i){
			ofstream fout("DA.DAT",ios::app);
			fout<<"Du an "<<i<<" : "<<endl;
			fout<<"\tTen du an: "<<tenda<<"\t\tMa du an: "<<mada<<endl;
			fout<<"\tKieu du an: "<<kieuda<<endl;
			fout<<"\tKinh phi: "<<kinhphi<<"\n\n";
		}
};
class BPC{
	private:
		NV nv;
		int soda;
		int *songay;
		DA *da;
	public:
		friend void timKiem(BPC *bpc,int n);
		friend void sapXep(BPC *bpc,int n);
		void nhap(NV *dsnv,int n,DA *dsda,int m){
			cout<<"Nhap ma nhan vien: ";	cin>>nv.manv;
			while(nv.manv<1000||nv.manv>=1000+n){
				cout<<"!!!.Loi. Ma nhan vien khong ton tai. Hay nhap lai ma nhan vien: ";	cin>>nv.manv;
			}
			for(int i=1;i<=n;i++){
				if(nv.manv==dsnv[i].manv){
					nv=dsnv[i];
					cout<<"Nhap so du an nhan vien do tham gia: ";	cin>>soda;
					songay=new int [soda+1];
					da=new DA[soda+1];
					for(int j=1;j<=soda;j++){
						cout<<"Nhap ma da: ";	cin>>da[j].mada;
						while(da[j].mada<1000||da[j].mada>=1000+m){
							cout<<"!!!.Loi. ma du an khong ton tai. Hay nhap lai ma du an: ";	cin>>da[j].mada;
						}
						for(int k=1;k<=m;k++){
							if(da[j].mada==dsda[k].mada){
								da[j]=dsda[k];;
								break;	
							}	
						}
						cout<<"Nhap ngay ngay lam du an do: ";	cin>>songay[j];
					}
					break;
				}
			}
			for(int j=1;j<soda;j++){
				for(int k=j+1;k<=soda;k++){
					if(songay[j]<songay[k]){
						//swap(da[j],da[k]);
						DA temp;
						temp=da[j];	da[j]=da[k];	da[k]=temp;
					}		
				}
			}
		}
		void xuat(){
			cout<<"Nhan Vien: "<<nv.hoten<<"\t\tMa nhan vien: "<<nv.manv<<endl;
			cout<<"\tSo du an: "<<soda<<endl;
			cout<<"\tDS cac du an: "<<endl;
			for(int i=1;i<=soda;i++){
				cout<<"\t\tTen du an: "<<da[i].tenda<<endl;
				cout<<"\t\tKieu du an: "<<da[i].kieuda<<endl;
				cout<<"\t\tSo ngay tham gia da: "<<songay[i]<<endl;
				cout<<"\t\tKinh phi: "<<da[i].kinhphi<<"\n\n";
			}
		}
		void ghiFile(){
			ofstream fout("BPC.DAT",ios::app);
			fout<<"Nhan Vien: "<<nv.hoten<<"\t\tMa nhan vien: "<<nv.manv<<endl;
			fout<<"\tSo du an: "<<soda<<endl;
			fout<<"\tDS cac du an: "<<endl;
			for(int i=1;i<=soda;i++){
				fout<<"\t\tTen du an: "<<da[i].tenda<<endl;
				fout<<"\t\tKieu du an: "<<da[i].kieuda<<endl;
				fout<<"\t\tSo ngay tham gia da: "<<songay[i]<<endl;
				fout<<"\t\tKinh phi: "<<da[i].kinhphi<<"\n\n";
			}
		}
};
void nhapNV(NV *dsnv,int n){
	for(int i=1;i<=n;i++)	dsnv[i].nhap(i);
}
void xuatNV(NV *dsnv,int n){
	for(int i=1;i<=n;i++)	dsnv[i].xuat(i);
}
void ghiFileNV(NV *dsnv,int n){
	for(int i=1;i<=n;i++)	dsnv[i].ghiFile(i);
}
void nhapDA(DA *dsda,int m){
	for(int i=1;i<=m;i++)	dsda[i].nhap(i);
}
void xuatDA(DA *dsda,int m){
	for(int i=1;i<=m;i++)	dsda[i].xuat(i);
}
void ghiFileDA(DA *dsda,int m){
	for(int i=1;i<=m;i++)	dsda[i].ghiFile(i);
}
void nhapBPC(BPC *bpc,NV *dsnv,int n,DA *dsda,int m){
	for(int i=1;i<=n;i++)	bpc[i].nhap(dsnv,n,dsda,m);
}
void xuatBPC(BPC *bpc,int n){
	for(int i=1;i<=n;i++)	bpc[i].xuat();
}
void ghiFileBPC(BPC *bpc,int n){
	for(int i=1;i<=n;i++)	bpc[i].ghiFile();
}

void sapXep(BPC *bpc,int n){
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(bpc[i].nv.hoten>bpc[j].nv.hoten){
				BPC temp=bpc[i];
				bpc[i]=bpc[j];	bpc[j]=temp;
			}
		}
	};	
}
//void swap(DA &da1,DA &da2){
//	DA temp;
//	temp=da1;	da1=da2;	da2=temp;
//}
void timKiem(BPC *bpc,int n){
	string s;
	cin.ignore();
	cout<<"Nhap ho ten nhan vien can tim: ";	getline(cin,s);
	for(int i=1;i<=n;i++){
		if(bpc[i].nv.hoten==s){
			bpc[i].xuat();
			break;
		}
	}
}

int main(){
	int n,m;
	NV *dsnv;
	DA *dsda;
	BPC *bpc;
	int run=1, dachon1=0,dachon3=0,dachon5=0;
	while(run){
		cout<<"\t\tNhap 1 de nhap DS nhan vien! "<<endl;
		cout<<"\t\tNhap 2 de xuat DS nhan vien! "<<endl;
		cout<<"\t\tNhap 3 de nhap DS du an! "<<endl;
		cout<<"\t\tNhap 4 de xuat DS du an! "<<endl;
		cout<<"\t\tNhap 5 de nhap bang phan cong!"<<endl;
		cout<<"\t\tNhap 6 de xuat bang phan cong!"<<endl;
		cout<<"\t\tNhap 7 de in ra doanh thu cho  moi nhan vien!"<<endl;
		
		int chon;
		cout<<"Ban hay chon chuc nang: ";	cin>>chon;
		switch(chon){
			case 1:
				cout<<"Nhap sl nhan vien : ";	cin>>n;	cin.ignore();
				dsnv=new NV[n+1];
				nhapNV(dsnv,n);
				dachon1=1;
				ghiFileNV(dsnv,n);
				break;
			case 2:
				if(dachon1==0){
					cout<<"Ban can nhap DS nhan vien tr khi in no ra!!!!!"<<endl;
					break;
				}
				else{
					cout<<"---------------------Thong Tin Nhan Vien----------------------"<<endl;
					xuatNV(dsnv,n);
					break;	
				}
			case 3:
				cout<<"Nhap sl du an : ";	cin>>m;	cin.ignore();
				dsda=new DA[m+1];
				nhapDA(dsda,m);
				dachon3=1;
				ghiFileDA(dsda,m);
				break;
			case 4:
				if(dachon3==0){
					cout<<"Ban phai nhap DS du an truoc khi in no ra!!!!!!"<<endl;
					break;
				}else{
					cout<<"------------------------Thong Tin Du An---------------------- "<<endl;
					xuatDA(dsda,m);
					break;
				} 	
			case 5:
				if(dachon1==0&&dachon3==0){
					cout<<"Ban can nhap ds nhan vien va ds du an tr !!!!!!!!";
					break;
				}else if(dachon1==1&&dachon3==0){
					cout<<"Ban can nhap ds du an tr!!!!!!!!!";
					break;
				}else if(dachon1==0&&dachon3==1){
					cout<<"Ban can nhap ds nhan vien tr!!!!!!!!";
					break;
				}else{
					bpc=new BPC[n+1];
					nhapBPC(bpc,dsnv,n,dsda,m);
					sapXep(bpc,n);
					ghiFileBPC(bpc,n);
					dachon5=1;
					break;	
				}
			case 6:
				if(dachon5==0){
					cout<<"Ban phai nhap Bang phan cong tr khi in bo ra!!!!!!!!!"<<endl;
					break;
				}else{
					cout<<"--------------------------------Bang Phan Cong----------------------------"<<endl;
					xuatBPC(bpc,n);
					break; 
				}
			case 7:
				cout<<"-----------------------Tim Kiem-------------------------------"<<endl;
				timKiem(bpc,n);
				break;
		}
		cout<<"Nhan 1 de tiep tuc!. 0 de ket thuc chuong trinh!  ";	cin>>run;
	}
	return 0;
}
