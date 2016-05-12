#include<bits/stdc++.h>
using namespace std;
int id1=9999,id2=9999;
class QLBH;
void sapXep(QLBH *qlbh,int n);
void hoaDon(QLBH *qlbh,int n);
class Nguoi{
	protected:
		string hoten,diachi,sdt;
};

class KH:public Nguoi{
	private:
		int makh,loaikh;
	public:
		friend void hoaDon(QLBH *qlbh,int n);
		friend class QLBH;
		friend void sapXep(QLBH *qlbh,int n);
		KH(){
			makh=id1;
			id1++;
		}
		void nhap(int i){
			cout<<"Nhap thong tin khach hang thu "<<i<<" :"<<endl;
			cout<<"\tHo ten: ";	getline(cin,hoten);
			cout<<"\tDia chi: "; getline(cin,diachi);
			cout<<"\tSdt: ";	getline(cin,sdt);
			cout<<"\tLoai khach hang (1 neu la mua le; 2 neu la mua buon ): ";	cin>>loaikh;	cin.ignore();
			cout<<"\n\n";
		}
		void xuat(int i){
			cout<<"Khach hang "<<i<<" :"<<endl;
			cout<<"\tHo ten: "<<hoten<<"\tMa Kh: "<<makh<<endl;
			cout<<"\tDia chi: "<<diachi<<endl;
			cout<<"\tLoai Kh: ";
			switch(loaikh){
				case 1:
					cout<<"Mua le"<<"\n\n";
					break;
				case 2:
					cout<<"Mua buon"<<"\n\n";
					break;
			}
		}
		void ghiFile(int i){
			ofstream fout("KH.DAT",ios::app);
			fout<<"--------------------Khach hang "<<i<<"--------------------"<<endl;
			fout<<"Ho ten: "<<hoten<<"\tMa Kh: "<<makh<<endl;
			fout<<"Dia chi: "<<diachi<<endl;
			fout<<"Loai Kh: ";
			switch(loaikh){
				case 1:
					fout<<"Mua le"<<"\n\n";
					break;
				case 2:
					fout<<"Mua buon"<<"\n\n";
					break;
			}
		}
};

class MH{
	private:
		int mamh;
		string tenmh;
		float gia;
	public:
		MH(){
			mamh=id2;
			id2++;
		}
		friend void hoaDon(QLBH *qlbh,int n);
		friend void sapXep(QLBH *qlbh,int n);
		friend class QLBH;
		void nhap(int i){
			cout<<"Nhap thong tin mat hang thu "<<i<<" :"<<endl;
			cout<<"\tTen mh: ";	getline(cin,tenmh);
			cout<<"\tGia mat hang: ";	cin>>gia;	cin.ignore();
			cout<<"\n\n";
		}
		void xuat(int i){
			cout<<"Mat hang "<<i<<" :"<<endl;
			cout<<"\tTen mh: "<<tenmh<<"\tMa mh: "<<mamh<<endl;
			cout<<"\tGia mh: "<<gia<<"\n\n";
		}
		void ghiFile(int i){
			ofstream fout("MH.DAT",ios::app);
			fout<<"------------------------Mat hang "<<i<<"---------------------"<<endl;
			fout<<"Ten mh: "<<tenmh<<endl;
			fout<<"Gia mh: "<<gia<<"\n\n";
		}
};
class QLBH{
	private:
		KH kh;
		int soloai;
		int *sl;
		MH *mh;
	public:
		friend void hoaDon(QLBH *qlbh,int n);
		friend void sapXep(QLBH *qlbh,int n);
		void nhap(KH *dskh,int n,MH *dsmh,int m){
			cout<<"Nhap ma kh: ";	cin>>kh.makh;
			while(kh.makh<10000||kh.makh>=10000+n){
				cout<<"!!!.Loi. ma kh ko ton tai. Hay nhap lai ma kh : ";	cin>>kh.makh;
			}
			for(int i=1;i<=n;i++){
				if(dskh[i].makh==kh.makh){
					kh=dskh[i];
					cout<<"Nhap so loai mat hang kh do mua: ";	cin>>soloai;
					sl=new int [soloai+1];
					mh=new MH[soloai+1];
					for(int j=1;j<=soloai;j++){
						cout<<"Nhap ma mh thu "<<j<<" : "; cin>>mh[j].mamh;
						while(mh[j].mamh<10000||mh[j].mamh>10000+m){
							cout<<"!!!.Loi. ma mh ko ton tai. Hay nhap lai ma mh: ";	cin>>mh[j].mamh;
						}
						cout<<"Nhap sl mat hang do ma kh da mua: ";	cin>>sl[j];
						for(int k=1;k<=m;k++){
							if(dsmh[k].mamh==mh[j].mamh){
								mh[j]=dsmh[k];
								break;
							}
						}
					}
					break;	
				}
			}
		}
		void xuat(){
			cout<<"\tKhach hang : "<<kh.hoten<<endl;
			cout<<"\tMa kh : "<<kh.makh<<endl;
			cout<<"\tDs cac mat hang da mua: "<<endl;
			for(int i=1;i<=soloai;i++){
				cout<<"\t"<<i<<". Mat hang: "<<mh[i].tenmh<<"\t so luong: "<<sl[i];
				cout<<"\n";
			}
			cout<<"\n\n";
		}
		void ghiFile(){
			ofstream fout("QLBH.DAT",ios::app);
			fout<<"--------------------Khach hang------------------"<<endl;
			fout<<"\tHo ten: "<<kh.hoten<<endl;
			fout<<"\tMa kh : "<<kh.makh<<endl;
			fout<<"\tDs cac mat hang da mua: "<<endl;
			for(int i=1;i<=soloai;i++){
				fout<<"\t"<<i<<". Mat hang: "<<mh[i].tenmh<<"\t so luong : "<<sl[i];
				fout<<"\n";
			}
			fout<<"\n\n";			
		}
};
void nhapKH(KH *dskh,int n){
	for(int i=1;i<=n;i++)	dskh[i].nhap(i);
}
void xuatKH(KH *dskh,int n){
	for(int i=1;i<=n;i++)	dskh[i].xuat(i);
}
void ghiFileKH(KH *dskh,int n){
	for(int i=1;i<=n;i++)	dskh[i].ghiFile(i);
}
void nhapMH(MH *dsmh,int m){
	for(int i=1;i<=m;i++)	dsmh[i].nhap(i);
}
void xuatMH(MH *dsmh,int m){
	for(int i=1;i<=m;i++)	dsmh[i].xuat(i);
}
void ghiFileMH(MH *dsmh,int m){
	for(int i=1;i<=m;i++)	dsmh[i].ghiFile(i);
}
void nhapQLBH(QLBH *qlbh,KH *dskh,int n,MH *dsmh,int m){
	for(int i=1;i<=n;i++)	qlbh[i].nhap(dskh,n,dsmh,m);
}
void xuatQLBH(QLBH *qlbh,int m){
	for(int i=1;i<=m;i++)	qlbh[i].xuat();
}
void ghiFileQLBH(QLBH *qlbh,int m){
	for(int i=1;i<=m;i++)	qlbh[i].ghiFile();
}
void sapXep(QLBH *qlbh,int n){
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(qlbh[i].kh.hoten>qlbh[j].kh.hoten){
				QLBH temp;
				temp=qlbh[i];	qlbh[i]=qlbh[j];	qlbh[j]=temp;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<qlbh[i].soloai;j++){
			for(int k=j+1;k<=qlbh[i].soloai;k++){
				if(qlbh[i].mh[j].tenmh>qlbh[i].mh[k].tenmh){
					MH temp;
					temp=qlbh[i].mh[j];	qlbh[i].mh[j]=qlbh[i].mh[k];	qlbh[i].mh[k]=temp;
				}
			}
		}
	}
} 
void hoaDon(QLBH *qlbh,int n){
	float *sum=new float [n+1];
	for(int i=1;i<=n;i++)	sum[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=qlbh[i].soloai;j++){
			sum[i]=sum[i]+qlbh[i].mh[j].gia*qlbh[i].sl[j];
		}
	}
	
	for(int i=1;i<=n;i++){
		qlbh[i].xuat();
		cout<<"\tTong so tien kh do phai tra la: "<<sum[i]<<"\n\n\n";
	}
}
int main(){
	int n,m;
	KH *dskh;
	MH *dsmh;
	QLBH *qlbh;
	
	int run=1, dachon1=0,dachon3=0,dachon5=0;
	while(run){
		cout<<"\t\tNhap 1 de nhap DS khach hang! "<<endl;
		cout<<"\t\tNhap 2 de xuat DS khach hang! "<<endl;
		cout<<"\t\tNhap 3 de nhap DS mat hang! "<<endl;
		cout<<"\t\tNhap 4 de xuat DS mat hang! "<<endl;
		cout<<"\t\tNhap 5 de nhap bang quan ly ban hang!"<<endl;
		cout<<"\t\tNhap 6 de xuat bang quan ly ban hang!"<<endl;
		cout<<"\t\tNhap 7 de in ra hoa don cho khach hang!"<<endl;
		
		int chon;
		cout<<"Ban hay chon chuc nang: ";	cin>>chon;
		switch(chon){
			case 1:
				cout<<"Nhap sl khach hang : ";	cin>>n;	cin.ignore();
				dskh=new KH[n+1];
				nhapKH(dskh,n);
				dachon1=1;
				ghiFileKH(dskh,n);
				break;
			case 2:
				if(dachon1==0){
					cout<<"Ban can nhap DS khach hang tr khi in no ra!!!!!"<<endl;
					break;
				}
				else{
					xuatKH(dskh,n);
					break;	
				}
			case 3:
				cout<<"Nhap sl mat hang : ";	cin>>m;	cin.ignore();
				dsmh=new MH[m+1];
				nhapMH(dsmh,m);
				dachon3=1;
				ghiFileMH(dsmh,m);
				break;
			case 4:
				if(dachon3==0){
					cout<<"Ban phai nhap DS mat hang truoc khi in no ra!!!!!!"<<endl;
					break;
				}else 	xuatMH(dsmh,m);
				break;
			case 5:
				if(dachon1==0&&dachon3==0){
					cout<<"Ban can nhap ds khach hang va ds mat hang tr !!!!!!!!";
					break;
				}else if(dachon1==1&&dachon3==0){
					cout<<"Ban can nhap ds mat hang tr!!!!!!!!!";
					break;
				}else if(dachon1==0&&dachon3==1){
					cout<<"Ban can nhap ds khach hang tr!!!!!!!!";
					break;
				}else{
					qlbh=new QLBH[n+1];
					nhapQLBH(qlbh,dskh,n,dsmh,m);
					sapXep(qlbh,n);
					ghiFileQLBH(qlbh,n);
					dachon5=1;
					break;	
				}
			case 6:
				if(dachon5==0){
					cout<<"Ban phai nhap bang qlbh tr khi in bo ra!!!!!!!!!"<<endl;
					break;
				}else{
					cout<<"\t\t\tBang Quan Ly Ban Hang"<<endl;
					xuatQLBH(qlbh,n);
					break; 
				}
			case 7:
				cout<<"------------------------HOA DON-------------------------------"<<endl;
				hoaDon(qlbh,n);
				break;
		}
		cout<<"Nhan 1 de tiep tuc!. 0 de ket thuc chuong trinh!  ";	cin>>run;
	}
}
