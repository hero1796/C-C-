#include<bits/stdc++.h>
using namespace std;
int id1=0,id2=0;
class QLMS;
class Nguoi{
	protected:
		string hoten,sdt,diachi;
};
class BD:public Nguoi{
	private:
		int mabd;
		int loaibd;
	public:
		friend void timKiem(QLMS *qlms,int n);
		friend class QLMS;
		BD(){
			mabd=id1;
			id1++;
		}
		void nhap(int i){
			cout<<"Nhap thong tin ban doc thu "<<i<<" :"<<endl;
			cout<<"\tho ten: ";	getline(cin,hoten);
			cout<<"\tdia chi: ";	getline(cin,diachi);
			cout<<"\tSdt: ";	getline(cin,sdt);
			cout<<"\tLoai ban doc (1 la SV, 2 la CH,3 la GV ): ";	cin>>loaibd;	cin.ignore();
			cout<<"\n";
		}
		void xuat(int i){
			cout<<"Ban doc "<<i<<" :"<<endl;
			cout<<"\tho ten: "<<hoten<<"---- ma ban doc: "<<mabd<<endl;
			cout<<"\tdia chi: "<<diachi<<endl;
			cout<<"\tSdt: "<<sdt<<endl;
			cout<<"\tLoai ban doc: ";
			switch(loaibd){
				case 1:
					cout<<"Sinh vien"<<"\n\n";
					break;
				case 2: 
					cout<<"Cao hoc"<<"\n\n";
					break;
				case 3:
					cout<<"Giang Vien"<<"\n\n";
					break;
			}
		}
};

class Sach{
	private:
		int mas,namxb;
		string tens,tg;
	public:
		friend void timKiem(QLMS *qlms,int n);
		friend class QLMS;
		Sach(){
			mas=id2;
			id2++;
		}
		void nhap(int i){
			cout<<"Nhap thong tin sach thu "<<i<<" :"<<endl;
			cout<<"\tten sach: ";	getline(cin,tens);
			cout<<"\ttac gia: ";	getline(cin,tg);
			cout<<"\tnam xuat ban: ";	cin>>namxb; cin.ignore();
			cout<<"\n";
		}
		void xuat(int i){
			cout<<"Sach "<<i<<" :"<<endl;
			cout<<"\tTen sach: "<<tens<<"\t Ma Sach : "<<mas<<endl;
			cout<<"\tTen tac gia: "<<tg<<endl;
			cout<<"\tNam xuat ban: "<<namxb<<"\n\n";
		}
};
void nhapBD(BD *dsbd,int n){
	for(int i=1;i<=n;i++)	dsbd[i].nhap(i);
}
void xuatBD(BD *dsbd,int n){
	for(int i=1;i<=n;i++)	dsbd[i].xuat(i);
}
void nhapSach(Sach *dss,int m){
	for(int i=1;i<=m;i++)	dss[i].nhap(i);
}
void xuatSach(Sach *dss,int m){
	for(int i=1;i<=m;i++)	dss[i].xuat(i);
}
class QLMS{
	private:
		BD bd;
		int sl,max;
		Sach *sach;
	public:
		friend void timKiem(QLMS *qlms,int n);
		void nhap(BD *dsbd,int n,Sach *dss,int m){
			cout<<"Nhap ma bd: ";	cin>>bd.mabd;
			while(bd.mabd<=0||bd.mabd>n){
				cout<<"!!Loi. Hay nhap lai ma ban doc: ";	cin>>bd.mabd;
			}
			for(int i=1;i<=n;i++){
				if(dsbd[i].mabd==bd.mabd){
					bd=dsbd[i];
					if(bd.loaibd==1)	max=3;	else if(bd.loaibd==2)	max=5;	else if(bd.loaibd==3)	max=7;
					cout<<"Nhap sl sach ban doc do muon: ";	cin>>sl;
					sach=new Sach[sl+1];
					while(sl>max){
						cout<<"!!!. ban chi duoc muon toi da "<<max<<" sach. Hay nhap lai sl sach ban muon: ";	cin>>sl;
					}
					for(int j=1;j<=sl;j++){
						cout<<"Nhap ma sach thu "<<j<<" ban muon: ";	cin>>sach[j].mas;
						while(sach[j].mas<=0||sach[j].mas>m){
							cout<<"!!!. Ma sach ko hop le. hay nhap lai ma sach: ";	cin>>sach[j].mas;
						}
						for(int k=1;k<=m;k++){
							if(dss[k].mas==sach[j].mas){
								sach[j]=dss[k];
								break;
							}
						}
					}
					break;
				}
			}
		}
		void xuat(int i){
			cout<<"Ban doc "<<i<<" :"<<endl;
			cout<<"\tHo ten: "<<bd.hoten<<"\tma bd:"<<bd.mabd<<endl;
			cout<<"\tSl sach ban do muon la: "<<sl<<endl;
			cout<<"\tDanh sach sach ban do muon la: "<<endl;
			for(int j=1;j<=sl;j++){
				cout<<"\tsach thu "<<j<<" : "<<sach[j].tens<<endl;
			}
		}
};
void nhapQLMS(QLMS *qlms,BD *dsbd,int n,Sach *dss,int m){
	for(int i=1;i<=n;i++)	qlms[i].nhap(dsbd,n,dss,m);	
}
void xuatQLMS(QLMS *qlms,int n){
	for(int i=1;i<=n;i++)	qlms[i].xuat(i);
}
void timKiem(QLMS *qlms,int n){
	string s;
	cin.ignore();
	cout<<"Nhap ten an doc can tim kiem: ";	getline(cin,s);
	int i;
	for( i=1;i<=n;i++){
		if(qlms[i].bd.hoten==s){
			cout<<"Thong Tin Ban Doc Do La: "<<endl;
			qlms[i].xuat(i);
			break;
		}
	}
	if(i>n)	cout<<"Khong co ban doc do!!!!!!!";
}
int main(){
	int n,m;
	BD *dsbd;
	Sach *dss;
	QLMS *qlms;
	
	int	run=1;
	int dachon1=0,dachon3=0;
	while(run==1){
		cout<<"\t\tNhap 1 de nhap DS ban doc! "<<endl;
		cout<<"\t\tNhap 2 de xuat DS ban doc! "<<endl;
		cout<<"\t\tNhap 3 de nhap DS sach! "<<endl;
		cout<<"\t\tNhap 4 de xuat DS sach! "<<endl;
		cout<<"\t\tNhap 5 de nhap BQLMS!"<<endl;
		cout<<"\t\tNhap 6 de xuat BQLMS!"<<endl;
		cout<<"\t\tNhap 7 de tim kiem theo ten ban doc!"<<endl;
		int chon;
		cout<<"Ban hay chon chuc nang: ";	cin>>chon;
		switch(chon){
			case 1:
				cout<<"Nhap sl ban doc: ";	cin>>n;	cin.ignore();
				dsbd=new BD[n+1];
				nhapBD(dsbd,n);
				dachon1=1;
				break;
			case 2:
				if(dachon1==0){
					cout<<"Ban can nhap DS ban doc tr khi in no ra!!!!!"<<endl;
					break;
				}
				else{
						xuatBD(dsbd,n);	break;	
				}
			case 3:
				cout<<"Nhap sl sach: ";	cin>>m;	cin.ignore();
				dss=new Sach[m+1];
				nhapSach(dss,m);
				dachon3=1;
				break;
			case 4:
				if(dachon3==0){
					cout<<"Ban phai nhap DS sach truoc khi in no ra!!!!!!"<<endl;
					break;
				}else 	xuatSach(dss,m);
				break;
			case 5:
				if(dachon1==0&&dachon3==0){
					cout<<"Ban can nhap ds ban doc va ds sach tr !!!!!!!!";
					break;
				}else if(dachon1==1&&dachon3==0){
					cout<<"Ban can nhap ds Sach tr!!!!!!!!!";
					break;
				}else if(dachon1==0&&dachon3==1){
					cout<<"Ban can nhap ds Ban doc tr!!!!!!!!";
					break;
				}else{
					qlms=new QLMS[n+1];
					nhapQLMS(qlms,dsbd,n,dss,m);
					break;
				}	
			case 6:
				cout<<"\t\t\tBang Quan Ly Muon Sach"<<endl;
				xuatQLMS(qlms,n); 
				break;
			case 7:
				timKiem(qlms,n);
				break;
		}
		cout<<"Nhan 1 de tiep tuc!. 0 de ket thuc chuong trinh!  ";	cin>>run;
	}

}
