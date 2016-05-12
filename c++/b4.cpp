#include<bits/stdc++.h>
using namespace std;
int id1=999,id2=999;
class DSBH;
void sapXep(DSBH *dsbh,int n);
void doanhThu(DSBH *dsbh,int n);
class Nguoi{
	protected:
		string hoten,diachi;
};
class NV:public Nguoi{
	private:
		int manv;
		string ngayhd;
	public:
		friend void doanhThu(DSBH *dsbh,int n);
		friend void sapXep(DSBH *dsbh,int n);
		friend class DSBH;
		NV(){
			manv=id1;
			id1++;
		}
		void nhap(int i){
			cout<<"Nhap thong tin Nhan vien thu "<<i<<" :"<<endl;
			cout<<"\tHo ten: ";	getline(cin,hoten);
			cout<<"\tDai chi: ";	getline(cin,diachi);
			cout<<"\tNgay hop dong: ";	getline(cin,ngayhd);
			cout<<"\n";
		}
		void xuat(int i){
			cout<<"Nhan Vien "<<i<<" :"<<endl;
			cout<<"\tHo ten: "<<hoten<<"\t Ma nhan vien: "<<manv<<endl;
			cout<<"\tNgay hop dong: "<<ngayhd<<endl;
			cout<<"\tDia chi: "<<diachi<<"\n\n";
		}
		void ghiFile(int i){
			ofstream fout("NV.DAT",ios::app);
			fout<<"------------------------Nhan Vien "<<i<<"----------------------------"<<endl;
			fout<<"\tHo ten: "<<hoten<<"\t Ma nhan vien: "<<manv<<endl;
			fout<<"\tNgay hop dong: "<<ngayhd<<endl;
			fout<<"\tDia chi: "<<diachi<<"\n\n";
		}
};
class MH{
	private:
		int mahang,nhomhang;
		string tenhang;
		float gia;
	public:
		friend void doanhThu(DSBH *dsbh,int n);
		friend void sapXep(DSBH *dsbh,int n);
		friend class DSBH;
		MH(){
			mahang=id2;
			id2++;
		}
		void nhap(int i){
			cout<<"\tTen Hang: ";	getline(cin,tenhang);
			cout<<"\tGia ban: ";	cin>>gia;
			cout<<"\tNhom hang (1 la May tinh, 2 la dien tu, 3 la dien lanh, 4 la Thiet bi van phong ): ";	cin>>nhomhang;	cin.ignore();
			cout<<"\n";
		}
		void xuat(int i){
			cout<<"\tTen hang: "<<tenhang<<"\t Ma hang: "<<mahang<<endl;
			cout<<"\tGia ban: "<<gia<<endl;
			cout<<"\tNhom hang: ";
			switch(nhomhang){
				case 1:
					cout<<"May tinh"<<"\n\n";	break;
				case 2:
					cout<<"Dien tu "<<"\n\n";	break;
				case 3:
					cout<<"Dien lanh \n\n";	break;
				case 4:
					cout<<"Thiet bi van phong\n\n";	break;
			}
		}
		void ghiFile(int i){
			ofstream fout("MH.DAT",ios::app);
			fout<<"-----------------Mat Hang "<<i<<"--------------------"<<endl;
			fout<<"\tTen hang: "<<tenhang<<"\t Ma hang: "<<mahang<<endl;
			fout<<"\tGia ban: "<<gia<<endl;
			fout<<"\tNhom hang: ";
			switch(nhomhang){
				case 1:
					fout<<"May tinh"<<"\n\n";	break;
				case 2:
					fout<<"Dien tu "<<"\n\n";	break;
				case 3:
					fout<<"Dien lanh \n\n";	break;
				case 4:
					fout<<"Thiet bi van phong\n\n";	break;
			}
		}
};
class DSBH{
	private:
		NV nv;
		int soloai;
		int *sl;
		MH *mh;
	public:
		friend void doanhThu(DSBH *dsbh,int n);
		friend void sapXep(DSBH *dsbh,int n);
		void nhap(NV *dsnv,int n,MH *dsmh,int m){
			cout<<"Nhap ma nv: ";	cin>>nv.manv;
			while(nv.manv<1000||nv.manv>=1000+n){
				cout<<"!!!.Loi. ma nv khong ton tai. Hay nhap lai ma nv: ";	cin>>nv.manv;
			}
			for(int i=1;i<=n;i++){
				if(nv.manv==dsnv[i].manv){
					nv=dsnv[i];
					cout<<"Nhap so luong loai hang nv do ban dc: ";	cin>>soloai;
					sl=new int[soloai+1];
					mh=new MH[soloai+1];
					for(int j=1;j<=soloai;j++){
						cout<<"Nhap ma mat hang thu "<<j<<" ma nv do da ban: ";	cin>>mh[j].mahang;
						while(mh[j].mahang<1000||mh[j].mahang>=1000+m){
							cout<<"!!!.Loi. Ma mat hang do khong ton tai. Hay nhap lai ma mat hang: ";	cin>>mh[j].mahang;
						}
						for(int k=1;k<=m;k++){
							if(dsmh[k].mahang==mh[j].mahang){
								mh[j]=dsmh[k];
								cout<<"Nhap so luong da ban dc cua loai hang do: ";	cin>>sl[j];
								break;
							}
						}
					}
					break;
				}
			}
	}
		void xuat(){
			cout<<"Nhan Vien: "<<nv.hoten<<"--------------Ma nhan vien: "<<nv.manv<<endl;
			cout<<"\tDAnh sach cac mat hang da ban dc la: "<<endl;
			for(int i=1;i<=soloai;i++){
				cout<<"\tMat hang: "<<mh[i].tenhang<<"\tSo luong: "<<sl[i]<<endl;
				
			}
			cout<<"\n";
		}
		void ghiFile(){
			ofstream fout("DSBH.DAT",ios::app);
			fout<<"Nhan Vien: "<<nv.hoten<<"----------------Ma nhan vien: "<<nv.manv<<endl;
			fout<<"\tDanh sach cac mat hang da ban dc la: "<<endl;
			for(int i=1;i<=soloai;i++){
				fout<<"\tMat hang: "<<mh[i].tenhang<<"\tSo luong: "<<sl[i]<<endl;
				
			}
			fout<<"\n\n";
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
void nhapMH(MH *dsmh,int m){
	for(int i=1;i<=m;i++)	dsmh[i].nhap(i);
}
void xuatMH(MH *dsmh,int m){
	for(int i=1;i<=m;i++)	dsmh[i].xuat(i);
}
void ghiFileMH(MH *dsmh,int m){
	for(int i=1;i<=m;i++)	dsmh[i].ghiFile(i);
}
void nhapDSBH(DSBH *dsbh,NV *dsnv,int n,MH *dsmh,int m){
	for(int i=1;i<=n;i++)	dsbh[i].nhap(dsnv,n,dsmh,m);
}
void xuatDSBH(DSBH *dsbh,int n){
	for(int i=1;i<=n;i++)	dsbh[i].xuat();
}
void ghiFileDSBH(DSBH *dsbh,int n){
	for(int i=1;i<=n;i++)	dsbh[i].ghiFile();
}
void sapXep(DSBH *dsbh,int n){
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			if(dsbh[i].nv.hoten>dsbh[j].nv.hoten){
				DSBH temp;
				temp=dsbh[i];	dsbh[i]=dsbh[j];	dsbh[j]=temp;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<dsbh[i].soloai;j++){
			for(int k=j+1;k<=dsbh[i].soloai;k++){
				if(dsbh[i].mh[j].nhomhang>dsbh[i].mh[k].nhomhang){
					MH temp;
					temp=dsbh[i].mh[j];	dsbh[i].mh[j]=dsbh[i].mh[k];	dsbh[i].mh[k]=temp;
				}
			}
		}
	}
}
void doanhThu(DSBH *dsbh,int n){
	int *doanhthu=new int [n];
	for(int i=1;i<=n;i++)	doanhthu[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=dsbh[i].soloai;j++){
			doanhthu[i]=doanhthu[i]+dsbh[i].mh[j].gia*dsbh[i].sl[j];
		}
		dsbh[i].xuat();
		cout<<"Doanh thu cua nhan vien do la: "<<doanhthu[i]<<"\n\n\n\n";
	}	
}
int main(){
	int n,m;
	NV *dsnv;	MH *dsmh;
	DSBH *dsbh;
	int run=1, dachon1=0,dachon3=0,dachon5=0;
	while(run){
		cout<<"\t\tNhap 1 de nhap DS nhan vien! "<<endl;
		cout<<"\t\tNhap 2 de xuat DS nhan vien! "<<endl;
		cout<<"\t\tNhap 3 de nhap DS mat hang! "<<endl;
		cout<<"\t\tNhap 4 de xuat DS mat hang! "<<endl;
		cout<<"\t\tNhap 5 de nhap bang DS ban ban hang!"<<endl;
		cout<<"\t\tNhap 6 de xuat bang DS ban hang!"<<endl;
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
				}else{
					cout<<"------------------------Thong Tin Mat Hang---------------------- "<<endl;
					xuatMH(dsmh,m);
					break;
				} 	
			case 5:
				if(dachon1==0&&dachon3==0){
					cout<<"Ban can nhap ds nhan vien va ds mat hang tr !!!!!!!!";
					break;
				}else if(dachon1==1&&dachon3==0){
					cout<<"Ban can nhap ds mat hang tr!!!!!!!!!";
					break;
				}else if(dachon1==0&&dachon3==1){
					cout<<"Ban can nhap ds nhan vien tr!!!!!!!!";
					break;
				}else{
					dsbh=new DSBH[n+1];
					nhapDSBH(dsbh,dsnv,n,dsmh,m);
					sapXep(dsbh,n);
					ghiFileDSBH(dsbh,n);
					dachon5=1;
					break;	
				}
			case 6:
				if(dachon5==0){
					cout<<"Ban phai nhap DS ban hang tr khi in bo ra!!!!!!!!!"<<endl;
					break;
				}else{
					cout<<"--------------------------------Danh Sach Ban Hang----------------------------"<<endl;
					xuatDSBH(dsbh,n);
					break; 
				}
			case 7:
				cout<<"------------------------DOANH THU-------------------------------"<<endl;
				doanhThu(dsbh,n);
				break;
		}
		cout<<"Nhan 1 de tiep tuc!. 0 de ket thuc chuong trinh!  ";	cin>>run;
	}
}
