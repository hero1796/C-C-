#include<bits/stdc++.h>
using namespace std;
int id1=99,id2=99;
class BKK;
void sapXep(BKK *bkk,int n);
void tinhCong(BKK *bkk,int n);
class Nguoi{
	protected:
		string hoten,diachi;
};
class GV:public Nguoi{
	private:
		int magv;
		string trinhdo;
	public:
		friend void tinhCong(BKK *bkk,int n);
		friend void sapXep(BKK *bkk,int n);
		friend class BKK;
		GV(){
			magv=id1;
			id1++;
		}
		void nhap(int i){
			cout<<"Nhap thong tin giang vien "<<" i : "<<endl;
			cout<<"\tHO ten: ";	getline(cin,hoten);
			cout<<"\tTrinh do: ";	getline(cin,trinhdo);
			cout<<"\tDia chi: ";	getline(cin,diachi);
			cout<<"\n";
		}
		void xuat(int i){
			cout<<"Giang vien "<<i<<" :"<<endl;
			cout<<"\tHo ten: "<<hoten<<"\t\tMa giang vien: "<<magv<<endl;
			cout<<"\tTrinh do: "<<trinhdo<<endl;
			cout<<"\tDia chi: "<<diachi<<"\n\n";
		}
		void ghiFile(int i){
			ofstream fout("GV.DAT",ios::app);
			fout<<"Giang vien "<<i<<" :"<<endl;
			fout<<"\tHo ten: "<<hoten<<"\t\tMa giang vien: "<<magv<<endl;
			fout<<"\tTrinh do: "<<trinhdo<<endl;
			fout<<"\tDia chi: "<<diachi<<"\n\n";
		}
};
class MH{
	private:
		string tenmh;
		int mamh,tongsotiet,lythuyet,thuchanh;
		float kinhphi;
	public:
		friend void tinhCong(BKK *bkk,int n);
		friend void sapXep(BKK *bkk,int n);
		friend class BKK;
		MH(){
			mamh=id2;
			id2++;
		}
	void nhap(int i){
		cout<<"Nhap thong tin mon hoc "<<i<<" :"<<endl;
		cout<<"\tTen mon hoc: ";	getline(cin,tenmh);
		cout<<"\tTong so tiet: ";	cin>>tongsotiet;
		cout<<"\tSo tiet ly thuyet: ";	cin>>lythuyet;
		cout<<"\tSo tiet thuc hanh: ";	cin>>thuchanh;	
		cout<<"\tNhap kinh phi: ";	cin>>kinhphi;	cin.ignore();
		cout<<"\n";
	}
	void xuat(int i){
		cout<<"Mon hoc "<<i <<" : "<<endl;
		cout<<"\tTen mon hoc: "<<tenmh<<"\t\tMa mon hoc: "<<mamh<<endl;
		cout<<"\tTong so tiet: "<<tongsotiet<<endl;
		cout<<"\tSo tiet ly thuyet: "<<lythuyet<<endl;
		cout<<"\tSo tiet thuc hanh: "<<thuchanh<<"\n\n";
	}	
	void ghiFile(int i){
		ofstream fout("MH.DAT",ios::app);
		fout<<"--------------------Mon hoc "<<"i-----------------"<<endl;
		fout<<"\tTen mon hoc: "<<tenmh<<"\t\tMa mon hoc: "<<mamh<<endl;
		fout<<"\tTong so tiet: "<<tongsotiet<<endl;
		fout<<"\tSo tiet ly thuyet: "<<lythuyet<<endl;
		fout<<"\tSo tiet thuc hanh: "<<thuchanh<<"\n\n";
	}
};

class BKK{
	private:
		GV gv;
		int somh;
		int *solop; 
		MH *mh;
	public:
		friend void tinhCong(BKK *bkk,int n);
		friend void sapXep(BKK *bkk,int n);
		void nhap(GV *dsgv,int n,MH *dsmh,int m){
			cout<<"Nhap ma giang vien: ";	cin>>gv.magv;
			while(gv.magv<100||gv.magv>=100+n){
				cout<<"!!!. Loi. Ma giang vien khong ton tai. Hay nhap lai ma giang vien: ";	cin>>gv.magv;
			}
			for(int i=1;i<=n;i++){
				if(gv.magv==dsgv[i].magv){
					gv=dsgv[i];
					cout<<"Nhap so mon giang vien do giang day: ";	cin>>somh;
					mh=new MH[somh+1];	solop=new int [somh+1];
					for(int j=1;j<=somh;j++){
						cout<<"Nhap ma mon hoc: ";	cin>>mh[j].mamh;
						while(mh[j].mamh<100||mh[j].mamh>=100+m){
							cout<<"!!!. Loi. Ma mon hoc khong ton tai. Hay nhap lai ma mon hoc: ";	cin>>mh[j].mamh;
						}
						cout<<"Nhap so luong lop : "; cin>>solop[j];
						for(int k=1;k<=m;k++){
							if(dsmh[k].mamh==mh[j].mamh){
								mh[j]=dsmh[k];
								break;
							}
						}
					}
					/*for(int i=1;i<somh;i++){
						for(int j=1;j<=somh;j++){
							if(solop[i]<solop[j]){
								MH temp;
								temp=mh[i];	mh[i]=mh[j];	mh[j]=temp;
							}
						}
					}*/
					break;
				}
			}
		}
		void xuat(){
			cout<<"Giang vien: "<<endl;
			cout<<"\t\tHo ten: "<<gv.hoten<<"\t\tMa gv: "<<gv.magv <<endl;
			cout<<"\t\tTrinh do: "<<gv.trinhdo<<"\n"<<endl;
			cout<<"\t\tSo mon hoc giang day: "<<somh<<endl;
			for(int i=1;i<=somh;i++){
				cout<<"\t\tMon hoc: "<<mh[i].tenmh<<"\t\tMa mh: "<<mh[i].mamh<<endl;
				cout<<"\t\tTong so tiet: "<<mh[i].tongsotiet<<endl;
				cout<<"\t\tKinh phi: "<<mh[i].kinhphi<<endl;
				cout<<"\t\tSo lop day: "<<solop[i]<<"\n\n\n";
			}
		}
		void ghiFile(){
			ofstream fout("BKK",ios::app);
			fout<<"Giang vien: "<<endl;
			fout<<"\t\tHo ten: "<<gv.hoten<<"\t\tMa gv: "<<gv.magv <<endl;
			fout<<"\t\tTrinh do: "<<gv.trinhdo<<"\n"<<endl;
			fout<<"\t\tSo mon hoc giang day: "<<somh<<endl;
			for(int i=1;i<=somh;i++){
				fout<<"\t\tMon hoc: "<<mh[i].tenmh<<"\t\tMa mh: "<<mh[i].mamh;
				fout<<"\t\tTong so tiet: "<<mh[i].tongsotiet<<endl;
				fout<<"\t\tKinh phi: "<<mh[i].kinhphi<<"\n\n\n";
			}
		}
};
void nhapGV(GV *dsgv,int n){
	for(int i=1;i<=n;i++)	dsgv[i].nhap(i);
}
void xuatGV(GV *dsgv,int n){
	for(int i=1;i<=n;i++)	dsgv[i].xuat(i);
}
void ghiFileGV(GV *dsgv,int n){
	for(int i=1;i<=n;i++)	dsgv[i].ghiFile(i);
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
void nhapBKK(BKK *bkk,GV *dsgv,int n,MH *dsmh,int m){
	for(int i=1;i<=n;i++)	bkk[i].nhap(dsgv,n,dsmh,m);
}
void xuatBKK(BKK *bkk,int n){
	for(int i=1;i<=n;i++)	bkk[i].xuat();
}
void ghiFileBKK(BKK *bkk,int n){
	for(int i=1;i<=n;i++)	bkk[i].ghiFile();
}
void sapXep(BKK *bkk,int n){
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(bkk[i].gv.hoten>bkk[j].gv.hoten){
				BKK temp;
				temp=bkk[i];	bkk[i]=bkk[j];	bkk[j]=temp;
			}
		}
	}
}
void tinhCong(BKK *bkk,int n){
	float tienluong;
	for(int i=1;i<=n;i++){
		tienluong=0;
		for(int j=1;j<=bkk[i].somh;j++){
			tienluong=tienluong+bkk[i].mh[j].lythuyet*bkk[i].mh[j].kinhphi+ bkk[i].mh[j].thuchanh*bkk[i].mh[j].kinhphi*0.7;
		}
		cout<<"Giang Vien: "<<bkk[i].gv.hoten<<"\t\tMa gv: "<<bkk[i].gv.magv<<endl;
		cout<<"\tLuong : "<<tienluong<<" $"<<"\n\n";
	}
}
int main(){
	int n,m;
	GV *dsgv;
	MH *dsmh;
	BKK *bkk;
	int run=1, dachon1=0,dachon3=0,dachon5=0;
	while(run){
		cout<<"\t\tNhap 1 de nhap DS giang vien! "<<endl;
		cout<<"\t\tNhap 2 de xuat DS giang vien! "<<endl;
		cout<<"\t\tNhap 3 de nhap DS mon hoc! "<<endl;
		cout<<"\t\tNhap 4 de xuat DS mon hoc! "<<endl;
		cout<<"\t\tNhap 5 de nhap bang ke khai giang day!"<<endl;
		cout<<"\t\tNhap 6 de xuat bang ke khai gian day!"<<endl;
		cout<<"\t\tNhap 7 de in ra bang tinh tien cong cho giang vien!"<<endl;
		
		int chon;
		cout<<"Ban hay chon chuc nang: ";	cin>>chon;
		switch(chon){
			case 1:
				cout<<"--------------------Nhap Danh Sach Gang Vien----------------"<<endl;
				cout<<"Nhap sl giang vien : ";	cin>>n;	cin.ignore();
				dsgv=new GV[n+1];
				nhapGV(dsgv,n);
				dachon1=1;
				ghiFileGV(dsgv,n);
				break;
			case 2:
				if(dachon1==0){
					cout<<"Ban can nhap DS giang vien tr khi in no ra!!!!!"<<endl;
					break;
				}
				else{
					cout<<"\n---------------------Thong Tin giang Vien----------------------"<<endl;
					xuatGV(dsgv,n);
					break;	
				}
			case 3:
				cout<<"Nhap sl mon hoc : ";	cin>>m;	cin.ignore();
				dsmh=new MH[m+1];
				nhapMH(dsmh,m);
				dachon3=1;
				ghiFileMH(dsmh,m);
				break;
			case 4:
				if(dachon3==0){
					cout<<"Ban phai nhap DS mon hoc truoc khi in no ra!!!!!!"<<endl;
					break;
				}else{
					cout<<"\n------------------------Thong Tin Mon Hoc---------------------- "<<endl;
					xuatMH(dsmh,m);
					break;
				} 	
			case 5:
				if(dachon1==0&&dachon3==0){
					cout<<"Ban can nhap ds giang vien va ds mon hoc hang tr !!!!!!!!";
					break;
				}else if(dachon1==1&&dachon3==0){
					cout<<"Ban can nhap ds mon hoc tr!!!!!!!!!";
					break;
				}else if(dachon1==0&&dachon3==1){
					cout<<"Ban can nhap ds giang vien tr!!!!!!!!";
					break;
				}else{
					bkk=new BKK[n+1];
					nhapBKK(bkk,dsgv,n,dsmh,m);
					sapXep(bkk,n);
					ghiFileBKK(bkk,n);
					dachon5=1;
					break;	
				}
			case 6:
				if(dachon5==0){
					cout<<"Ban phai nhap bang ke khai tr khi in bo ra!!!!!!!!!"<<endl;
					break;
				}else{
					cout<<"\n--------------------------------Bang Ke Khai Giang Day----------------------------"<<endl;
					xuatBKK(bkk,n);
					break; 
				}
			case 7:
				cout<<"\n-----------------------------Bang Tinh Cong-------------------------------"<<endl;
				tinhCong(bkk,n);
				break;
		}
		cout<<"Nhan 1 de tiep tuc!. 0 de ket thuc chuong trinh!  ";	cin>>run;
	}
	return 0;
}
