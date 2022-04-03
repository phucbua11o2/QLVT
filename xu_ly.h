//#include "ctdl.h"

#include "xu_ly_phu.h"


//========================DATE==============
int month_table[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_month_table[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//check leap year or not
#define IS_LEAP_YEAR(year) ((year%400 == 0) || (year%4 == 0 && year%100 != 0))? true : false
void nhapDate(Date &d);
void print(Date d);
void nextDay(Date &d);
bool validDate(Date d);
int so_sanh_date(Date d1,Date d2);
int tra_hang(Date d1,Date d2);
Date dateSys();
int kiem_tra_tra_hang(Date d_HD);
void Normal ();

//-========================================


//==========================DO HOA======================

void xoa_man_hinh_inside();
void HidePointer();
void ShowPointer();


void xoa_thong_bao()
{
	//82,35
	for(int i=36;i<40;i++)
	{
		gotoxy(37,i);
		SetBGColor(0);
		cout<<"                                                                                                        ";
	}
	//36,33
}

void BaoLoi (char *s)
{
  int x=wherex() , y=wherey();
  
  int a=strlen(s)/2;
  gotoxy (89-a,37);
  SetColor(4);
  SetBGColor(0);
  cout <<s;
  gotoxy(74,39);
  SetColor(6);
  //SetBGColor(3);
  cout<<"Nhan phim bat ky de tiep tuc!!";
  getch();
  //Sleep(1500);
  //gotoxy(60,39);
  xoa_thong_bao();
  //clreol();
  Normal();
  gotoxy(x,y);
}

void BaoLoiTonKho (double f,string dvt)
{
  int x=wherex() , y=wherey();
  
  gotoxy (67,37);
  SetColor(4);
  SetBGColor(0);
  cout <<"Khong du so luong. Trong kho chi con "<<setprecision(1)<<f<<" "<<dvt<<"!!";
  gotoxy(74,39);
  SetColor(6);
  //SetBGColor(3);
  cout<<"Nhan phim bat ky de tiep tuc!!";
  getch();
  xoa_thong_bao();
  Normal();
  gotoxy(x,y);
}

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}


//==========dialog thoat==========
void END();
void XoaCheckExit();
void checkExit(int *Err1, char *look);
void ChangeColor(int x);
void KhungExit();

//==========dialog xoa==========

void XoaCheckExitXXX();
void checkExitXXX(int *Err1, char *look);
void ChangeColorXXX(int x);
void KhungExitXXX();





//==============khai bao nguyen mau ham====================
//=================cau a===============
vat_tu* searchVT(tree t,string ma);
vat_tu *khoi_tao_node_vt();
int nhap_1_vat_tu(tree t,vat_tu *p);
void nhap_vat_tu(DS_VAT_TU &ds_vt);
void them_1_vat_tu(tree &t,vat_tu *p);
void xuat_1_vt(vat_tu *p);
//=============cau b===========
void xuat_ds_vat_tu(tree t);

//====================doc ghi file============
void ghiFile_Nhan_Vien(DS_NHAN_VIEN ds);
void docFile_Nhan_Vien(DS_NHAN_VIEN &ds);
void ghiFile_Vat_Tu (DS_VAT_TU ds_vt);
void docFile_Vat_Tu(DS_VAT_TU &ds_vt);

//===========

vat_tu Nhapvt();
int insertNode(tree &T, vat_tu x);
void CreateTree(DS_VAT_TU &ds_vt);

//==========

//=========Xoa vat tu========
void  removeVT (string x ,  tree &p );
void remove_case3_VT(tree &r,tree &rp);



// ===================Nhap Nhan vien========================
void nhapDSNV(DS_NHAN_VIEN &dsnv, int flag);
int nhapNV1(NHAN_VIEN &nv,DS_NHAN_VIEN ds);
int nhapNV(NHAN_VIEN &nv,DS_NHAN_VIEN ds);
//==============Xuat Nhan Vien=============================
//void xuatDSNV(DS_NHAN_VIEN dsnv);
void xuat_DSNV(NHAN_VIEN *ds[],int &sl);
// ===================Xoa Nhan vien========================
//ham tim kiem nhan vien dua vao Ma nhan vien(int)
int searchNV(DS_NHAN_VIEN ds, int x);
//ham tim kiem nhan vien dua vao CMND (string)
int searchNV_cmnd(DS_NHAN_VIEN ds, string x);
//ham hien thi 1 nhan vien
void ThongTinNV ( DS_NHAN_VIEN ds, int x);
//ham xuat thong tin nhan vien da ton tai-----i la chi so cua nhan vien do
void ThongTinNVExist  (DS_NHAN_VIEN ds, int i);
void ThongTinNVExist1  (NHAN_VIEN *p);
//ham xoa 1 nhan vien
void XoaNV(DS_NHAN_VIEN &ds, int i);

// ===================Chinh sua Nhan vien========================

//ham tra ve nhan vien dua tren chi so x --- nhan vien do da ton tai vs chi so x
NHAN_VIEN* searchNV_exist(NHAN_VIEN *ds[],int x)
{
	return ds[x];
}

void ChinhSuaNV(DS_NHAN_VIEN &ds);
//ham tim kiem nhan vien dua vao CMND(string) va chi so index x de Chinh sua nhan vien
int searchNV_cmnd_index(DS_NHAN_VIEN ds, string x,int k);

//==========cau d============
//sap xep tang dan theo ten va ho

void sapXep_NV(NHAN_VIEN *ds[],int sl,DS_NHAN_VIEN dsnv);

//==============LAP HOA DON==============

void lapHoaDon(DS_VAT_TU ds_vt,DS_NHAN_VIEN ds_nv);

//insert node trong lien ket don
void them_1_hd(HOA_DON *&phead, HOA_DON *p);

//Ham khoi tao 1 Hoa don
HOA_DON *khoi_tao_node_hd();

//Ham kiem tra So Hoa don trung,(tra ve chi so trong Dach sach NHan vien , mang con tro)
int kiem_tra_so_hd(DS_NHAN_VIEN ds_nv,string x);

//Ham kiem tra Ma Vat tu trung (Trong 1 danh sach CTHD thi khong cho Vat tu xuat hien 2 lan)---------cho cau e,Lap hoa don
//tra ve chi so index trong Danh sach chi tiet hoa don------neu tra ve -1 thì vat tu do hien chua co trong Danh sach CTHD do
int searchCTHD(DS_CHI_TIET_HD ds_cthd, string x);

//Ham lay So luong ton trong kho ( Tam thoi khong su dung)
//int lay_so_luong_ton(tree t, string x);

//Ham nhap 1 Chi tiet Hoa don

int nhap_CTHD (DS_CHI_TIET_HD &ds_cthd, CHI_TIET_HOA_DON &cthd, tree &t,int flat);

//Nhap danh sach Chi tiet hoa don
void nhap_DS_CTHD (DS_CHI_TIET_HD &ds_cthd, tree &t,int flat);  // flat la co chi day la phieu Nhap hay phieu Xuat  ---1: Nhap---2: Xuat 

void nhap_cthd(DS_CHI_TIET_HD ds_cthd, CHI_TIET_HOA_DON &cthd, tree t,int flat);
void nhap_ds_cthd (DS_CHI_TIET_HD &ds_cthd, tree t,int flat);



//================GIAI PHONG VUNG NHO=================
void giai_phong(DS_VAT_TU &ds_vt,DS_NHAN_VIEN &ds_nv);
void giai_phong_dshd_all(DS_NHAN_VIEN &ds_nv);
void giai_phong_dshd_1(DS_HOA_DON &ds_hd); // Lien ket don
void giai_phong_dsnv(DS_NHAN_VIEN &ds_nv); //Mang con tro
void giai_phong_dsvt(vat_tu *root);
void giai_phong_mct_vt(vat_tu *ds[],int &sl); //Mang con tro




















//=================cau a===============
vat_tu *khoi_tao_node_vt()
{
	vat_tu *p=new vat_tu;
	if(p==NULL)
		{
			cout<<"Khoi tao vat tu that bai\n";
			system("pause");
		}
	p->pleft=NULL;
	p->pright=NULL;
	return p;
}

// tra ve 1 neu nhap thanh cong , tra ve 0 neu muon khong nhap nua

int nhap_1_vat_tu(tree t,vat_tu *p)
{
		ShowPointer();
		xoa_man_hinh_inside();
	
		gotoxy(76,7);
		SetColor(4);
		SetBGColor(10);
		cout<<"                     ";
		gotoxy(76,8);
		cout<<"=====THEM VAT TU=====";
		gotoxy(76,9);
		cout<<"                     ";
		
		
		//in bieu mau
		{
			gotoxy(55,13);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap ma (q: Thoat!)  "; //24
			SetBGColor(15);
			gotoxy(90,13);
			cout<<"                        ";
			
			gotoxy(55,16);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap ten vat tu      ";
			SetBGColor(15);
			gotoxy(90,16);
			cout<<"                        ";
			
			gotoxy(55,19);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap don vi tinh     ";
			SetBGColor(15);
			gotoxy(90,19);
			cout<<"                        ";
			
			gotoxy(55,22);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap so luong ton    ";
			SetBGColor(15);
			gotoxy(90,22);
			cout<<"                        ";
			Normal();
			
		}
		
		
		
		while(true)
		{
			gotoxy(55,13);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap ma (q: Thoat!)  "; //24
			SetBGColor(15);
			gotoxy(90,13);
			cout<<"                        ";
			gotoxy(95,13);
			SetColor(0);
			getline(cin,p->ma_vt);
			//chuan_hoa(p->ma_vt);
	//		if(p->ma_vt=="0")
	//			return 0;//ket thuc viec nhap
		
			thanh_chu_thuong(p->ma_vt);			
			if(kiem_ta_1_tu(p->ma_vt)==0)	
				{
						cin.clear();
						_flushall();
						BaoLoi("Ma vat tu khong chua khoang trang!!");
						continue;

				}
	
			if(p->ma_vt.empty() || cin.fail() || p->ma_vt.length()>10)	
				{
						cin.clear();
						_flushall();
						BaoLoi("Ma vat tu khong hop le!!");
						continue;

				}
			else if(p->ma_vt=="q"||p->ma_vt=="Q"||p->ma_vt=="quit")
				return 0;
			else if(searchVT(t,p->ma_vt)!=NULL)
				{
					//cout<<"\nMa vat tu da ton tai! Vui long nhap ma khac.\n";
					BaoLoi("Ma vat tu da ton tai!!!");
					continue;
				}
			else 
				break;
			
		}
		
	while(true)
		{
			gotoxy(55,16);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap ten vat tu      ";
			SetBGColor(15);
			gotoxy(90,16);
			cout<<"                        ";
			gotoxy(95,16);
			SetColor(0);
			getline(cin,p->ten_vt);
			chuan_hoa(p->ten_vt);
			
			if(p->ten_vt.empty() || cin.fail() || p->ten_vt.length()>50	)
				{
						cin.clear();
						_flushall();
						
						BaoLoi("Ten vat tu khong hop le!!");
						//cout << "\nTen vat tu khong hop le!!\n";
						continue;
				}
			
			else 
				break;
			
		}
	
	while(true)
		{
			
			gotoxy(55,19);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap don vi tinh     ";
			SetBGColor(15);
			gotoxy(90,19);
			cout<<"                        ";
			gotoxy(95,19);
			SetColor(0);
			getline(cin,p->don_vi_tinh);
			chuan_hoa(p->don_vi_tinh);
			
			if(p->don_vi_tinh.empty() || cin.fail()	)
				{
						cin.clear();
						_flushall();
						BaoLoi("Don vi tinh khong hop le!!");
						//cout << "\nDon vi tinh khong hop le!!\n";
						continue;

				}
			
			else 
				break;
			
		}
	
	while(true)
		{
			gotoxy(55,22);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap so luong ton    ";
			SetBGColor(15);
			gotoxy(90,22);
			cout<<"                        ";
			gotoxy(95,22);
			SetColor(0);
			cin>>p->so_luong_ton;
			cin.ignore();
			
			if(p->so_luong_ton<=0|| cin.fail()||p->so_luong_ton>=999999)	
				{
						cin.clear();
						_flushall();
						BaoLoi("So luong ton khong hop le!!");
						//cout << "\nSo luong ton khong hop le!!\n";
						continue;
				}
			
			else 
				break;
			
		}
	
	
	
	return 1;	
}


void nhap_vat_tu(DS_VAT_TU &ds_vt)
{
	char c;
	vat_tu *p;
	while (true)
	{
	p=khoi_tao_node_vt();
	
	if(nhap_1_vat_tu(ds_vt.TREE,p)==0)
	{
			xoa_man_hinh_inside();
			return ;	
	}
	
	int kt;
	gotoxy(64,28);
	//SetBGColor(2);
	Normal();
	SetColor(9);
	cout<<"ENTER: Xac nhan them";        
	SetColor(11);
	gotoxy(90,28);
	cout<<"ESC: Huy bo va thoat";
	
	while(1)
	{
		HidePointer();
		c=getch();
		
	
    if(c==27)
    	{
    		delete p;
    		xoa_man_hinh_inside();
    		return;
		}
	else if(c==13)
		break;
	
	}
	//them vao cay	
	them_1_vat_tu(ds_vt.TREE,p);
	ds_vt.sl++;
	BaoLoi("Da them thanh cong!");
	
	gotoxy(55,28);
	SetBGColor(0);
	SetColor(15);
	cout<<"                                                                                     ";
	gotoxy(59,28);
	
	SetColor(10);
	cout<<"ESC: de thoat!\t\t";
	SetColor(12);
	cout<<"PHIM BAT KY: de nhap tiep!";
    c=getch();
    if(c==27)
    	{
    		xoa_man_hinh_inside();
    		return;
		}
	xoa_man_hinh_inside();
	}
	
}

//insert_node
void them_1_vat_tu(tree &t,vat_tu *p)
{
	if(t==NULL)
		t=p;
	else
	{
		
		if(t->ma_vt.compare(p->ma_vt)>0)
			them_1_vat_tu(t->pleft,p);
		else if(t->ma_vt.compare(p->ma_vt)<0)
			them_1_vat_tu(t->pright,p);
		}
	
}
//ham tim kiem vat tu dua tren ma_vt
vat_tu* searchVT(tree q,string ma)
{
	tree t;
	t=q;
	if(t==NULL)
		return NULL;
	while(t!=NULL && t->ma_vt.compare(ma)!=0)
		if (ma.compare(t->ma_vt)<0)
			t=t->pleft;
		else
			t=t->pright;
	return t;
}


//Ham nay tra ve ten Vat tu.... Va phai Chac chan co vt do trong Danh sach
string ten_vat_tu(tree q,string ma)
{
	tree t;
	t=q;
	if(t==NULL)
		return NULL;
	while(t!=NULL && t->ma_vt.compare(ma)!=0)
		if (ma.compare(t->ma_vt)<0)
			t=t->pleft;
		else
			t=t->pright;
	
	//phong truong hop Bi mat du lieu
	/*
	if(t==NULL)
		return "XXX";
	*/
	return t->ten_vt;
}

//===============CHINH SUA VAT TU==============
int sua_vat_tu(DS_VAT_TU &ds_vt)
{
	
	
	xoa_man_hinh_inside();
	string ma_vt;
	string don_vi_tinh;
	string ten_vt;
	gotoxy(78,8);
	SetColor(4);
	SetBGColor(10);
	cout<<"                       ";
	gotoxy(78,9);
	cout<<"   CHINH SUA VAT TU    ";
	gotoxy(78,10);
	cout<<"                       ";		
	Normal();
	tree p;
	
	while(true)
	{
		gotoxy(57,14);
		SetBGColor(13);
		SetColor(0);
		cout<<"  Nhap Ma Vat Tu ( q de Thoat)  "; //24
		SetBGColor(15);
		gotoxy(93,14);
		cout<<"                         ";
		gotoxy(102,14);
		SetColor(0);
		ShowPointer();
		getline(cin,ma_vt);
	
		if(ma_vt=="q")
			return 0;
		
		thanh_chu_thuong(ma_vt);
		if(kiem_ta_1_tu(ma_vt)==0)	
			{
					cin.clear();
					_flushall();
					BaoLoi("Ma vat tu khong chua khoang trang!!");
					continue;

			}

		if(ma_vt.empty() || cin.fail() || ma_vt.length()>10)	
			{
					cin.clear();
					_flushall();
					BaoLoi("Ma vat tu khong hop le!!");
					continue;

			}
		p=searchVT(ds_vt.TREE,ma_vt);
		if(p==NULL)
			{
				//cout<<"\nMa vat tu da ton tai! Vui long nhap ma khac.\n";
				BaoLoi("Ma vat tu khong ton tai!!!");
				continue;
			}
		else
		{
			HidePointer();
			int a=20;
			Normal();
		gotoxy(50,a-4); 
		for(int i=50;i<135;i++)	
			cout<<"-"; //  dong 16
		gotoxy(56,a-3);	
		SetColor(4);	
		cout<<"Ma Vat Tu";//
		gotoxy(77,a-3);
		cout<<"Ten Vat Tu";
		gotoxy(102,a-3);
		cout<<"Don Vi Tinh";
		gotoxy(121,a-3);
		cout<<"So Luong Ton";
		SetColor(15);
		gotoxy(50,a-3);
		cout<<"|";
		gotoxy(134,a-3);
		cout<<"|";
		
		gotoxy(70,a-3);
		cout<<"|";
		gotoxy(95,a-3);
		cout<<"|";
		gotoxy(120,a-3);
		cout<<"|"; //dong 17
		//getch();
		
		gotoxy(120,a);
		xuat_1_vt(p);
		
		//getch();
		SetBGColor(0);
		gotoxy(45,a-2); 
		for(int i=45;i<50;i++)	
			cout<<" "; //  dong
		//getch() 
		gotoxy(45,a); 
		for(int i=45;i<50;i++)	
			cout<<" ";
		
		
		{
			gotoxy(58,a+4);//hang 23
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap ten vat tu    ";
			SetBGColor(15);
			gotoxy(91,a+4);
			cout<<"                         ";
			
			gotoxy(58,a+7);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap don vi tinh   ";
			SetBGColor(15);
			gotoxy(91,a+7);
			cout<<"                         ";
		}
		
		
		
		
	ShowPointer();
	while(true)
		{
			//a=20
			gotoxy(58,a+4);//hang 23
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap ten vat tu    ";
			SetBGColor(15);
			gotoxy(91,a+4);
			cout<<"                         ";
			gotoxy(95,a+4);
			SetColor(0);
			getline(cin,ten_vt);
			chuan_hoa(ten_vt);
			
			if(ten_vt.empty() || cin.fail() || ten_vt.length()>50	)
				{
						cin.clear();
						_flushall();
						
						BaoLoi("Ten vat tu khong hop le!!");
						//cout << "\nTen vat tu khong hop le!!\n";
						continue;
				}
			
			else 
				break;
			
		}
	
	while(true)
		{
			
			gotoxy(58,a+7);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap don vi tinh   ";
			SetBGColor(15);
			gotoxy(91,a+7);
			cout<<"                         ";
			gotoxy(95,a+7);
			SetColor(0);
			getline(cin,don_vi_tinh);
			chuan_hoa(don_vi_tinh);
			
			if(don_vi_tinh.empty() || cin.fail()	)
				{
						cin.clear();
						_flushall();
						BaoLoi("Don vi tinh khong hop le!!");
						//cout << "\nDon vi tinh khong hop le!!\n";
						continue;

				}
			
			else 
				break;
			
		}
	
	
		HidePointer();
		Normal(); 
		gotoxy(64,31);
		SetColor(4);
		//SetBGColor(8);
		cout<<"ESC: Huy va Thoat!";
		
		gotoxy(88,31);
		SetColor(12);
		//SetBGColor(8);
		cout<<"ENTER: Xac nhan chinh sua!";
		SetColor(15);	  
		Normal();
			break;
		}
	}
			
		char aa;
		do
		{
		
			aa=getch();
			if(aa==13)
			{
				p->ten_vt=ten_vt;
				p->don_vi_tinh=don_vi_tinh;
				BaoLoi("Da chinh sua thanh cong!!?\n");
				return 1;
			}
		
		else if (aa==27)
			{
				//Sleep(300);
				BaoLoi("Da huy bo!");
				return 0;
			}
		}while(1);
}


//===============XOA VAT TU==============

int xoa_vt(DS_VAT_TU &ds_vt)
{
	
	xoa_man_hinh_inside();
	string ma_vt;
	
	gotoxy(78,8);
	SetColor(4);
	SetBGColor(10);
	cout<<"                     ";
	gotoxy(78,9);
	cout<<"      XOA VAT TU     ";
	gotoxy(78,10);
	cout<<"                     ";		
	Normal();
	tree p;
	
	while(true)
	{
		gotoxy(55,14);
		SetBGColor(13);
		SetColor(0);
		cout<<"  Nhap Ma Vat Tu ( q de Thoat)  "; //24
		SetBGColor(15);
		gotoxy(90,14);
		cout<<"                         ";
		gotoxy(99,14);
		SetColor(0);
		ShowPointer();
		getline(cin,ma_vt);
	
	if(ma_vt=="q")
		return 0;  // Khong co thao tac Xoa thanh cong
		thanh_chu_thuong(ma_vt);
		if(kiem_ta_1_tu(ma_vt)==0)	
			{
					cin.clear();
					_flushall();
					BaoLoi("Ma vat tu khong chua khoang trang!!");
					continue;

			}
		
		
		if(ma_vt.empty() || cin.fail() || ma_vt.length()>10)	
			{
					cin.clear();
					_flushall();
					BaoLoi("Ma vat tu khong hop le!!");
					continue;

			}
			
		p=searchVT(ds_vt.TREE,ma_vt);
		if(p==NULL)
			{
				//cout<<"\nMa vat tu da ton tai! Vui long nhap ma khac.\n";
				BaoLoi("Ma vat tu khong ton tai!!!");
				continue;
			}
		else
		{
			HidePointer();
			int a=20;
			Normal();
		gotoxy(50,a-4); 
		for(int i=50;i<135;i++)	
			cout<<"-"; //  dong 16
		gotoxy(56,a-3);	
		SetColor(4);	
		cout<<"Ma Vat Tu";//
		gotoxy(77,a-3);
		cout<<"Ten Vat Tu";
		gotoxy(102,a-3);
		cout<<"Don Vi Tinh";
		gotoxy(121,a-3);
		cout<<"So Luong Ton";
		SetColor(15);
		gotoxy(50,a-3);
		cout<<"|";
		gotoxy(134,a-3);
		cout<<"|";
		
		gotoxy(70,a-3);
		cout<<"|";
		gotoxy(95,a-3);
		cout<<"|";
		gotoxy(120,a-3);
		cout<<"|"; //dong 17
		//getch();
		
		gotoxy(120,a);
		//getch();
		xuat_1_vt(p);
		
		//getch();
		// xoa 2 khoang (-) du
		SetBGColor(0);
		gotoxy(45,a-2); 
		for(int i=45;i<50;i++)	
			cout<<" "; //  dong 
		gotoxy(45,a); 
		for(int i=45;i<50;i++)	
			cout<<" "; //  dong 
		//getch();
		
		//getch();
		
		  /*
		gotoxy(67,31);
		SetColor(13);
		cout<<"ESC: Huy va Thoat!\t\t";
		SetColor(10);
		cout<<"DEL: Xac nhan xoa";
		SetColor(15);	  
			*/
			break;
		}
	}
	
	
	
	if(p->kt==1)
		{
			BaoLoi("Khong the xoa! Do vat tu nay da duoc lap Hoa don");		
			return 0; // Xac nhan chua co thao tac Xoa
		}
			
			
			
			int Err;		
			
			
			checkExitXXX(&Err, "Delete");
			if (Err == -1) //yes
			{
				
				removeVT(ma_vt,ds_vt.TREE);
				ds_vt.sl--;
				XoaCheckExitXXX();
				HidePointer();
				BaoLoi("Da xoa thanh cong!!");
				return 1;
				
				
			}
			else
			{
				XoaCheckExitXXX();
				HidePointer();
				BaoLoi("Da huy bo xoa!!");
				return 0;
				
			}
		
		
			
			
			
			/*
			
		char a;
		do
		{
		
			a=getch();
			if(a==83)
			{
			
				removeVT(ma_vt,ds_vt.TREE);
				ds_vt.sl--;
				BaoLoi("Da xoa thanh cong!!?\n");
				return 1;
			}
		
		else if (a==27)
			{
				//Sleep(300);
				BaoLoi("Da huy bo xoa!");
				return 0;
			}
		}while(1);
			*/
}


//=============XUAT VT=================

void chuyen_cay_sang_mang(vat_tu *ds[],int &nds,tree t)
{
	
	if(t!=NULL)
	{
		
		chuyen_cay_sang_mang(ds,nds,t->pright);
		
		ds[nds]=new vat_tu;
		ds[nds]->ma_vt=t->ma_vt;
		ds[nds]->ten_vt=t->ten_vt;
		ds[nds]->don_vi_tinh=t->don_vi_tinh;
		ds[nds]->so_luong_ton=t->so_luong_ton;
		nds++;
		
		chuyen_cay_sang_mang(ds,nds,t->pleft);
		
	}
}

void xuat_1_vt(vat_tu *p)
{
	//int a=0;
	int y=wherey();
	
	
	gotoxy(45,y-1);
	for(int i=45;i<135;i++)
		cout<<"-";
	
	gotoxy(58,y);
	cout<<p->ma_vt;
	gotoxy(50,y);
	cout<<"|";
	gotoxy(134,y);
	cout<<"|";
	//a=a+25;
	gotoxy(75,y);
	cout<<p->ten_vt;
	
	//a=a+25;
	gotoxy(105,y);
	cout<<p->don_vi_tinh;
	
	gotoxy(70,y);
		cout<<"|";
		gotoxy(95,y);
		cout<<"|";
		gotoxy(120,y);
		cout<<"|";
	
	
	//a=a+25;
	gotoxy(124,y);
	cout<<p->so_luong_ton;
	//y=y+1;
	gotoxy(45,y+1);
	for(int i=45;i<135;i++)
		cout<<"-";
	
	//cout<<endl;
}

int so_trang_dsvt(int x)
{
	if(x==0)
		return 0;
	if(x<=10)
		return 1;
	
	int a=0;
	
	a=x/10+1;
	if(x%10==0)
	{
		a--;
	}
	return a;
}
void xuat_ds_vat_tu_giam(DS_VAT_TU &ds_vt)
{
	
	
	vat_tu *dsvt[ds_vt.sl];
	int nds=0;
	//system("cls");

	int a=11;
	gotoxy(55,a);
	HidePointer();
	int soTrang;
	int aa;
	int b=0;
	int c;
	int i;
	int d;
	int flat=0;// dung de gan co cho viec co nen Chuyen _cay_sang_mang hay ko?
	soTrang=so_trang_dsvt(ds_vt.sl);
		if(soTrang==0)
		{	
			BaoLoi("Danh sach vat tu rong!!");
			return;	
		}
	
	while(1)
	{
		
		
		
		
		if(flat==0)
		{
			chuyen_cay_sang_mang(dsvt,nds,ds_vt.TREE);
		}
		
		c=1;
		i=0;
		d=0;
		xoa_man_hinh_inside();
		gotoxy(84,a-6);
		SetBGColor(14);
		SetColor(1);
		HidePointer();
		cout<<"DANH SACH VAT TU"; //in dong 5
		Normal();
		gotoxy(45,a-4); 
		for(int k=45;k<135;k++)	
			cout<<"-"; //in dong 7
		gotoxy(56,a-3);	
		SetColor(4);	
		cout<<"Ma Vat Tu";//in dong 8
		gotoxy(77,a-3);
		cout<<"Ten Vat Tu";
		gotoxy(102,a-3);
		cout<<"Don Vi Tinh";
		gotoxy(121,a-3);
		cout<<"So Luong Ton";
	
		gotoxy(46,a-3);
		cout<<"STT";
		
		SetColor(15);
		
		gotoxy(45,a-3);
		cout<<"|";
		gotoxy(50,a-3);
		cout<<"|";
		gotoxy(134,a-3);
		cout<<"|";
		
		gotoxy(70,a-3);
		cout<<"|";
		gotoxy(95,a-3);
		cout<<"|";
		gotoxy(120,a-3);
		cout<<"|";
		//getch();
		
		//hang duoi the hien cac nut dat biet
		gotoxy(46,32);
		SetColor(13);
		cout<<"ESC: Thoat!\t";
		SetColor(10);
		cout<<"TAB: Chuyen trang\t";
		SetColor(11);
		cout<<"DELETE: Xoa Vat tu!\t";
		SetColor(12);
		cout<<"ENTER: Chinh Sua Vat Tu\t";
		SetColor(15);
		
		
		
		for(i=0+b;c!=11;i++,c++)
		{
			if(i>=nds)
				break;
			gotoxy(55,a+d);
			xuat_1_vt(dsvt[i]);
			
			gotoxy(45,a+d-1);
			cout<<"|";
			
			gotoxy(47,a+d-1);
			cout<<i+1;
			//getch();
			d=d+2;
			//getch();	
			
		}
		
		SetColor(2);
		gotoxy(130,wherey()+3);
		cout<<"Trang ";
		if(b<10)
			cout<<"1";
		else
			cout<<b/10+1;  // b chi bang 0 ,10 ,20 ..
			
		cout<<"/"<<soTrang;
		Normal();
		//if(i>=nds)
		//	continue;
		//int z=1;
		do
		{
		
		aa=getch();
		if(aa==27)
		{
			giai_phong_mct_vt(dsvt,nds);	
			return;
		}
		
		
		
		else if(aa==83) // 83 la delete
		{
			if(xoa_vt(ds_vt)==1) // co thao tac Xoa
			{
	
				giai_phong_mct_vt(dsvt,nds);
				//xuat_ds_vat_tu_giam(ds_vt);
				soTrang=so_trang_dsvt(ds_vt.sl);
				if(soTrang==0)
					{	
						BaoLoi("Danh sach vat tu rong!!");
						return;	
					}
				b=0; //cho quay ve trang dau tien
				flat=0;
			}
			else
				flat=1;
			break;
			//return;
		}
			
		else if(aa==13)
		{
			
			if(sua_vat_tu(ds_vt)==1) // co thao tac Sua
			{
			
				giai_phong_mct_vt(dsvt,nds);
				flat=0;
				//xuat_ds_vat_tu_giam(ds_vt);
			}
			else
				flat=1;// ko co se bi loi khi thoat ra.. vi Con du lieu nhung van chuyen cay sang mang
			break;
			//return;
		}	
				
		else if(aa==9)
			{
				if(i<nds)
				{
					b=b+10;
					flat=1;
					break;
				}
				
				else if(i>=nds)
				{
					b=0;
					flat=1;
					//z=0;
					break;
					
				}
						
			}
			
		}while (1);	
		
				
	}	
	
}








void xuat_ds_vat_tu(tree t)
{
	/*
	if(t==NULL)
	{
		cout<<"DANH SACH VAT TU RONG!!";
	}
	*/
	if(t!=NULL)
	{
		
		xuat_ds_vat_tu(t->pright);
		gotoxy(55,8);
		for(int i=0;i<61;i++)
		cout<<"=";
		gotoxy(55,9);
		cout<<"|  Ma vat tu"<<t->ma_vt;//42
		cout<<"|Ten vat tu"<<t->ten_vt;
		cout<<"|Don vi tinh"<<t->don_vi_tinh;
		cout<<"|So luong ton"<<t->so_luong_ton;
		gotoxy(55,8);
		cout<<endl<<endl;
		xuat_ds_vat_tu(t->pleft);
	}
	
}







vat_tu Nhapvt()
{
	vat_tu x;
	cout << "Nhap ma vat tu (Q De Quay Lai): ";
	cin.ignore();
	//gets(x.Masv);
	getline(cin,x.ma_vt);
	if ((x.ma_vt.compare("q"))== 0 || (x.ma_vt.compare("Q"))== 0)
	{
		return x;
	}
	cout << "Nhap ten vat tu: ";
	getline(cin,x.ten_vt);
	
	cout << "Nhap don vi tinh: ";
	getline(cin,x.don_vi_tinh);
	
	cout << "Nhap so luong ton: ";
	
	while (true)
	{
		cin >> x.so_luong_ton;
		if (cin.fail() || x.so_luong_ton>10000000||x.so_luong_ton<=0)
		{
			cin.clear();
			_flushall();
			//cin.ignore();
			cout << "So lieu nhap khong chinh xac!! Vui long nhap lai!! ";
			cout << "\nNhap so luong ton: ";

		}
		else
			break;
	}
	

	//while (getchar() != '\n');/////////////////

	return x;
}

int insertNode(tree &T, vat_tu x) // chen 1 Node vao cay
{
	if (T != NULL) {
		if (T->ma_vt.compare(x.ma_vt) == 0)
			return -1;  // Node nay da co
		if (T->ma_vt.compare(x.ma_vt) > 0)
			return insertNode(T->pleft, x); // chen vao Node trai
		else if (T->ma_vt.compare(x.ma_vt) < 0)
			return insertNode(T->pright, x);   // chen vao Node phai
	}
	T = new vat_tu;
	if (T == NULL)
		return 0;    // khong du bo nho
	*T = x;
	T->pleft = T->pright = NULL;
	return 1;   // ok
}
void CreateTree(DS_VAT_TU &ds_vt)        // nhap cay
{
	vat_tu x;
	while (1) {
		cout << "--Nhap Thong Tin Vat Tu Can Them--" << endl << endl;
		x = Nhapvt();
		if ((x.ma_vt.compare("q"))== 0 || (x.ma_vt.compare("Q"))== 0)
			break;  // thoat
		int check = insertNode(ds_vt.TREE, x);
		if (check == -1)
			cout << "---Ma vat tu da ton tai---\n" << endl;
		else if (check == 0)
			cout << "---Bo Nho Day---\n" << endl;
		else cout << "---Them Thanh Cong---\n\n";

	}
}

void ghiFile_Nhan_Vien(DS_NHAN_VIEN ds)
{
	ofstream fileout;
	HOA_DON *pHD;
	int j;// xu dung cho vong lap DS_CHI_TIET_HOA_DON
	fileout.open("dsnv.txt",ios_base::out);
	fileout <<ds.sl;
	fileout <<"\n";
	for(int i=0; i<ds.sl;i++)
	{
		fileout <<ds.ds[i]->ma_nv;
		fileout <<',';
		fileout <<ds.ds[i]->ho;
		fileout <<',';
		fileout <<ds.ds[i]->ten;
		fileout <<',';
		fileout <<ds.ds[i]->phai;
		fileout <<',';
		fileout <<ds.ds[i]->cmnd;
		fileout <<',';
		fileout <<ds.ds[i]->kt;
		fileout <<'\n';
		
		//ghi DS Hoa don
		fileout <<ds.ds[i]->danh_sach_hd.sl;
		fileout <<"\n";
		// Duyet lien ket don
		for (pHD = ds.ds[i]->danh_sach_hd.phead;  pHD  != NULL ; pHD=pHD->pnext )
	        {
	        	fileout <<pHD->so_hd;
				fileout <<',';
				fileout <<pHD->loai;
				fileout <<',';
				fileout <<pHD->ngay_lap_hd.ngay;
				fileout <<',';
				fileout <<pHD->ngay_lap_hd.thang;
				fileout <<',';
				fileout <<pHD->ngay_lap_hd.nam;
				fileout <<',';
				fileout <<pHD->kt;
				fileout <<'\n';
				fileout <<pHD->ds_CTHD.sl;
				fileout <<'\n';
				for(j=0;j<pHD->ds_CTHD.sl;j++)
					{
						fileout <<pHD->ds_CTHD.ds[j].ma_vt;
						fileout <<',';
						fileout <<pHD->ds_CTHD.ds[j].so_luong;
						fileout <<',';
						fileout <<pHD->ds_CTHD.ds[j].don_gia;
						fileout <<',';
						fileout <<pHD->ds_CTHD.ds[j].VAT;
						fileout <<',';
						fileout <<pHD->ds_CTHD.ds[j].trang_thai;
						fileout <<'\n';
					}
				
			}		
	}
	fileout.close();
	//BaoLoi("Luu file Nhan vien thanh cong!");
	
}
void docFile_Nhan_Vien(DS_NHAN_VIEN &ds)
{
	ifstream filein;
	int k,j;
	HOA_DON *pHD;
	filein.open("dsnv.txt",ios_base::in);
	filein>>ds.sl;
	filein.ignore();
	for(int i=0;i<ds.sl;i++)
	{
		ds.ds[i]=new NHAN_VIEN;
		//getline(filein,ds.ds[i]->ma_nv,',');
		filein>>ds.ds[i]->ma_nv;
		filein.ignore();
		getline(filein,ds.ds[i]->ho,',');
		getline(filein,ds.ds[i]->ten,',');
		getline(filein,ds.ds[i]->phai,',');
		getline(filein,ds.ds[i]->cmnd,',');
		filein>>ds.ds[i]->kt;
		filein.ignore();
		//doc DS_HOA_DON
		filein>>ds.ds[i]->danh_sach_hd.sl;
		filein.ignore();
		for(k=0;k<ds.ds[i]->danh_sach_hd.sl;k++)
			{
				pHD=khoi_tao_node_hd();
				
				getline(filein,pHD->so_hd,',');
				//getline(filein,pHD->loai,',');
				filein>>pHD->loai;
				filein.ignore();
				filein>>pHD->ngay_lap_hd.ngay;
				filein.ignore();
				filein>>pHD->ngay_lap_hd.thang;
				filein.ignore();
				filein>>pHD->ngay_lap_hd.nam;
				filein.ignore();
				filein>>pHD->kt;
				filein.ignore();
				//them_1_hd(ds.ds[i]->danh_sach_hd.phead,pHD);
				
				//Doc DS_CHI_TIET_HOA_DON
				filein>>pHD->ds_CTHD.sl;
				filein.ignore();
				for(j=0;j<pHD->ds_CTHD.sl;j++)
					{
						getline(filein,pHD->ds_CTHD.ds[j].ma_vt,',');
						filein>>pHD->ds_CTHD.ds[j].so_luong;
						filein.ignore();
						filein>>pHD->ds_CTHD.ds[j].don_gia;
						filein.ignore();
						filein>>pHD->ds_CTHD.ds[j].VAT;
						filein.ignore();
						filein>>pHD->ds_CTHD.ds[j].trang_thai;
						filein.ignore();
					}
				them_1_hd(ds.ds[i]->danh_sach_hd.phead,pHD);
			}
	
	}
	filein.close();
	//BaoLoi("Doc file Nhan vien thanh cong!");
	
}

//----------------------doc ghi file ds Vat Tu-----------------------

void ghiFile_Vat_Tu (DS_VAT_TU ds_vt)
{  
	ofstream fileout;
	fileout.open("dsvt.txt",ios_base::out);
	//ghi so luong vat tu
	fileout <<ds_vt.sl;
	fileout <<'\n';
	//duyet theo kieu go de quy
	const int STACKSIZE = 500;
   	tree Stack[STACKSIZE];
   	int sp=  -1;	// Khoi tao Stack rong
   	tree p=ds_vt.TREE;
   while (p!=NULL )
   {
    // "ghi p"
      		fileout <<p->ma_vt;
			fileout <<',';
			fileout <<p->ten_vt;
			fileout <<',';
			fileout <<p->don_vi_tinh;
			fileout <<',';
			fileout <<p->so_luong_ton;
			fileout <<',';
			fileout <<p->kt;	
			fileout <<'\n';
	//"ghi p"
      if (p->pright != NULL)
		Stack[++sp]= p->pright;
      if (p->pleft != NULL)
		p=p->pleft;
      else if (sp==-1)
		break;
	  else		 
	    p=Stack[sp--];
   }
   fileout.close();
   //BaoLoi("Luu file Vat tu thanh cong!");
	
}


void docFile_Vat_Tu(DS_VAT_TU &ds_vt)
{
	vat_tu *p;
	ifstream filein;
	filein.open("dsvt.txt",ios_base::in);
	filein>>ds_vt.sl;
	filein.ignore();
	for(int i=0;i<ds_vt.sl;i++)
	{
		
		
		p=khoi_tao_node_vt();//cap phat bo nho
		//nap du lieu tu file vao bien
		getline(filein,p->ma_vt,',');
		getline(filein,p->ten_vt,',');
		getline(filein,p->don_vi_tinh,',');
		filein>>p->so_luong_ton;
		filein.ignore();
		filein>>p->kt;
		filein.ignore();
		them_1_vat_tu(ds_vt.TREE,p);
	
	}
	filein.close();
	//BaoLoi("Doc file Vat tu thanh cong!");
	
}


//=================xoa vat tu======================

void remove_case3_VT(tree &r,tree &rp)
{
  if (r->pleft != NULL)
     remove_case3_VT(r->pleft,rp);
   //den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
    else 
	{
		//Chep noi dung cua r sang rp ";
		//r la nut cuc trai, rp la nut can xoa
		
	   rp->ma_vt = r->ma_vt; 
	   rp->ten_vt = r->ten_vt;
	   rp->don_vi_tinh = r->don_vi_tinh;
	   rp->so_luong_ton = r->so_luong_ton;
	   rp->kt = r->kt; 	
	   //tao lien ket xoa node 
	   rp = r;           	//de chut nua delete rp
	   r = rp->pright;
	  }
  }
void  removeVT (string x ,  tree &p )
{
	if (p == NULL )
		BaoLoi("Danh sach rong!!");
	else
	  if (x.compare(p->ma_vt) < 0)   
	  	removeVT (x, p->pleft);
	  else if (x.compare(p->ma_vt) > 0)
		  removeVT (x, p->pright);
	       else   	// p->ma_vt = x
	       {
		 		tree rp = p;
              	if (rp->pright == NULL)  
				  	p = rp->pleft;   
	// p là nút lá hoac la nut chi co cay con ben trai
		 		else if (rp->pleft == NULL)
			   		p = rp->pright;  // p là nut co cay con ben phai
				else 
					remove_case3_VT(rp->pright,rp); // Tim nut cuc trai cua cay con ben phai
		 		delete rp;
	       }
}




//===============chinh sua Vat tu======================


void Suavt(tree &P)
{
	
	string a;
	cout << "Sua ten vat tu( Nhap Q De Quay Lai): ";
	getline(cin,a);
	if (a.compare("Q")== 0 || a.compare("q") == 0)
	{
		return;
	}
	P->ten_vt=a;
	cout << "Sua don vi tinh: ";
	while (true)
	{
		getline(cin,P->don_vi_tinh);
		if (P->don_vi_tinh.empty())
		{
			cout << "\nKhong bo trong!! Nhap lai don vi tinh: ";

		}
		else
			break;
	}
	/*
	cout << "Sua so luong ton: ";
	while (true)
	{
		cin >> P->so_luong_ton;
		if (cin.fail() || P->so_luong_ton>9999|| P->so_luong_ton<=0)
		{
			cin.clear();
			_flushall();
			cin.ignore();
			cout << "Nhap lai so luong ton: ";

		}
		else
			break;
	}
	cin.ignore();
	*/
	//while (getchar() != '\n');/////////////////

	//return P;
}

// ===================Xoa Nhan vien========================
//ham tim kiem nhan vien dua vao Ma nhan vien(int)
int searchNV(DS_NHAN_VIEN ds, int x) {
  for (int i =0; i < ds.sl ; i++)
     if (ds.ds[i]->ma_nv == x) return i;
  return -1;
}

int searchNV_mct(NHAN_VIEN *ds[], int sl,int x) {
  for (int i =0; i < sl ; i++)
     if (ds[i]->ma_nv == x) return i;
  return -1;
}

//ham tim kiem nhan vien dua vao CMND(string)
int searchNV_cmnd(DS_NHAN_VIEN ds, string x) {
  for (int i =0; i < ds.sl ; i++)
     if (ds.ds[i]->cmnd.compare(x)==0) return i;
  return -1;
}
//doi so truyen vao la mang con tro tra ve chi index trong mct
int searchNV_cmnd_mct(NHAN_VIEN* ds[],int sl,string cmnd)
{
	for (int i =0; i < sl ; i++)
     if (ds[i]->cmnd.compare(cmnd)==0) return i;
  return -1;
}

//ham tim kiem nhan vien dua vao CMND(string) va chi so index x de Chinh sua nhan vien
int searchNV_cmnd_index(DS_NHAN_VIEN ds, string x,int k) {
	if(ds.ds[k]->cmnd==x)
		return -1;//giai quyet van de khi chinh sua so CMND trung voi CMND cu
  for (int i =0; i < ds.sl ; i++)
     if (ds.ds[i]->cmnd.compare(x)==0) return i;
  return -1;
}

//ham hien thi 1 nhan vien co ma nhan vien la x (Nhan vien chua dc kiem tra ton tai)
void ThongTinNV ( DS_NHAN_VIEN ds, int x) {
  int i = searchNV(ds,x) ;
  if (i==-1) 
  	cout<<"\nMa Nhan vien khong co trong danh sach!!\n";
  else 
  	{
   		cout<<"Ma nhan vien: "; //<<dsnv.ds[i]->ma_nv<<endl;
		printf("%03d\n",ds.ds[i]->ma_nv);
		cout<<"Ho: "<<ds.ds[i]->ho<<endl;
		cout<<"Ten: "<<ds.ds[i]->ten<<endl;
		cout<<"Phai: "<<ds.ds[i]->phai<<endl;
		cout<<"CMND: "<<ds.ds[i]->cmnd<<endl; 
	}
}

//ham xoa 1 nhan vien co chi so la i
void XoaNV(DS_NHAN_VIEN &ds, int i) // ko su dung
{

   if (ds.ds[i]->kt==1) 
		cout<<"\nKhong the xoa Nhan vien nay!!!!!!\n";
   else  
   { delete  ds.ds[i];
     for (int j=i+1; j <ds.sl; j++)
       ds.ds[j-1]=ds.ds[j];
       
     ds.sl--;  
     cout<<"Da xoa thanh cong!!";
	}
}

//ham xoa nhung khac tham so truyen vao ---- su dung bien mang con tro lam tham so 
void XoaNV1(NHAN_VIEN *ds[], int &sl,int i) 
{
   	 delete  ds[i];
     for (int j=i+1; j <sl; j++)
       ds[j-1]=ds[j];
       
     sl--;  
}



void xoa_nv(NHAN_VIEN *ds[],int &sl)
{
	
	int Err;
			
	
	xoa_man_hinh_inside();
	int ma_nv;
	int aa;
	gotoxy(78,8);
	SetColor(4);
	SetBGColor(10);
	cout<<"                     ";
	gotoxy(78,9);
	cout<<"     XOA NHAN VIEN   ";
	gotoxy(78,10);
	cout<<"                     ";		
	Normal();
	int index;
	ShowPointer();
	
	while(1)
		{
			
			gotoxy(63,14);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Ma(0 de thoat)  "; //24
			SetBGColor(15);
			gotoxy(95,14);
			cout<<"                 ";
			gotoxy(100,14);
			SetColor(0);
			cin>>ma_nv;
			cin.ignore();
			
			if( cin.fail())
				{
					cin.clear();
					_flushall();
					BaoLoi("Ma nhan vien khong hop le!!");
					continue;
				}
			
			if(ma_nv==0)
				return ;
				
			if(ma_nv<0 || ma_nv>9999 || cin.fail())	
				{
						cin.clear();
						_flushall();
						BaoLoi("Ma nhan vien khong hop le!!");
						continue;

				}
			index=searchNV_mct(ds,sl,ma_nv);	
			if(index==-1)
			{
				BaoLoi("Ma nhan vien nay khong ton tai!!");
				continue;
			}
			else // in thong tin nhan vien do
				{
				 	HidePointer();
					int a=20;
					Normal();
					gotoxy(50,a-4); 
					for(int i=50;i<135;i++)	
						cout<<"-"; //  dong 16
									
					gotoxy(52,a-3);	//56
					SetColor(4);	
					cout<<"Ma So";//in dong 8
					gotoxy(65,a-3); //77
					cout<<"Ho Nhan Vien";
					gotoxy(85,a-3);
					cout<<"Ten Nhan Vien";
					gotoxy(106,a-3);
					cout<<"Phai";
					gotoxy(122,a-3);
					cout<<"So CMND";
					SetColor(15);
					gotoxy(50,a-3);
					cout<<"|";
						
					gotoxy(59,a-3);
					cout<<"|";
					
					gotoxy(82,a-3);
					cout<<"|";
					
					gotoxy(100,a-3);
					cout<<"|";
					
					gotoxy(115,a-3);
					cout<<"|";
					gotoxy(134,a-3);
					cout<<"|";
				
					gotoxy(120,a);
						
					ThongTinNVExist1(searchNV_exist(ds,index));
				
					//xoa 2 khoang (-) thua
					SetBGColor(0);
					
					gotoxy(45,a-2);
					for(int i=45;i<50;i++)
					cout<<" "; 
					gotoxy(45,a);
					for(int i=45;i<50;i++)
					cout<<" ";
					
					/*
					//hang duoi the hien cac nut dat biet
					gotoxy(67,31);
					SetColor(13);
					cout<<"ESC: Huy va Thoat!\t\t";
					SetColor(10);
					cout<<"DEL: Xac nhan xoa";
					SetColor(15);
					*/				
					
				}
			
		
		
		if(ds[index]->kt==1) // Tuc la Nhan vien nay da lap Hoa don
		{
			//xoa thong bao ESC va DEL
			//SetBGColor(0);
			//gotoxy(60,31);
			//cout<<"                                                                     ";
			BaoLoi("Nhan vien nay da lap Hoa don. Nen khong the xoa!!! ");
			return;
		}
		
		
		/*			
		do
		{
		
			aa=getch();
			if(aa==83)
			{
			
				XoaNV1(ds,sl,index);
				BaoLoi("Da xoa thanh cong!!?\n");
				return;
				break;
			}
		
		else if (aa==27)
			{
				//Sleep(300);
				BaoLoi("Da huy bo xoa!");
				return;
			}
		}while(1);
			
		*/
		
		
		
			checkExitXXX(&Err, "Delete");
			if (Err == -1) //yes
			{
				XoaNV1(ds,sl,index);
				XoaCheckExitXXX();
				HidePointer();
				BaoLoi("Da xoa thanh cong!!?\n");
				return;
				
			}
			else
			{
				XoaCheckExitXXX();
				HidePointer();
				BaoLoi("Da huy bo xoa!");
				//getch();
				return;
				//HidePointer();
				//break;
			}
		
		
			
			
		}
	
	
	
	
	
}













void sua_nv(NHAN_VIEN *ds[],int sl)
{
	xoa_man_hinh_inside();
	int ma_nv;
	string ho,ten,phai,cmnd;
	int index; // dung de luu chi so cua NV do trong danh sach mct
	
	int aa;// dung de getch
	int a; // dung de ve dong
	gotoxy(78,6);
	SetColor(4);
	SetBGColor(10);
	cout<<"                         ";
	gotoxy(78,7);
	cout<<"   CHINH SUA NHAN VIEN   ";
	gotoxy(78,8);
	cout<<"                         ";		
	Normal();
	ShowPointer();
	
	while(1)
		{
			
			gotoxy(62,11);
			SetBGColor(13);
			SetColor(0);
			cout<<" Nhap Ma( 0 de thoat) "; //24
			SetBGColor(15);
			gotoxy(95,11);
			cout<<"                  ";
			gotoxy(100,11);
			SetColor(0);
			cin>>ma_nv;
			cin.ignore();
			
			if( cin.fail())
				{
					cin.clear();
					_flushall();
					BaoLoi("Ma nhan vien khong hop le!!");
					continue;
				}
			
			if(ma_nv==0)
			{
					xoa_man_hinh_inside();
					return ;
			}
				
			if(ma_nv<0 || ma_nv>9999)	
				{
						cin.clear();
						_flushall();
						BaoLoi("Ma nhan vien khong hop le!!");
						continue;

				}
			index=searchNV_mct(ds,sl,ma_nv);	
			if(index==-1)
			{
				BaoLoi("Ma nhan vien nay khong ton tai!!");
				continue;
			}
			else // in thong tin nhan vien do
				{
				 	//HidePointer();
					a=18;
					Normal();
					gotoxy(50,a-4); 
					for(int i=50;i<135;i++)	
						cout<<"-"; //  dong 16
									
					gotoxy(52,a-3);	//56
					SetColor(4);	
					cout<<"Ma So";//in dong 8
					gotoxy(65,a-3); //77
					cout<<"Ho Nhan Vien";
					gotoxy(85,a-3);
					cout<<"Ten Nhan Vien";
					gotoxy(106,a-3);
					cout<<"Phai";
					gotoxy(122,a-3);
					cout<<"So CMND";
					SetColor(15);
					gotoxy(50,a-3);
					cout<<"|";
						
					gotoxy(59,a-3);
					cout<<"|";
					
					gotoxy(82,a-3);
					cout<<"|";
					
					gotoxy(100,a-3);
					cout<<"|";
					
					gotoxy(115,a-3);
					cout<<"|";
					gotoxy(134,a-3);
					cout<<"|";
				
					gotoxy(120,a);
						
					ThongTinNVExist1(searchNV_exist(ds,index));
				
					//xoa 2 khoang (-) thua
					SetBGColor(0);
					
					gotoxy(45,a-2);
					for(int i=45;i<50;i++)
					cout<<" "; 
					gotoxy(45,a);
					for(int i=45;i<50;i++)
					cout<<" ";
					
					
					// thao tac chinh sua
					
					//form chinh sua
					{
						
						SetBGColor(13);
						SetColor(0);
						
						gotoxy(59,a+3);
						cout<<"     Nhap Ho Nhan Vien    ";
						SetBGColor(15);
						gotoxy(90,a+3);
						cout<<"                          ";
						
						SetBGColor(13);
						SetColor(0);
						gotoxy(59,a+5);
						cout<<"     Nhap Ten Nhan Vien   ";
						SetBGColor(15);
						gotoxy(90,a+5);
						cout<<"                          ";
						
						SetBGColor(13);
						SetColor(0);
						gotoxy(59,a+7);
						cout<<"     Nhap Phai( Nam/ Nu)  ";
						SetBGColor(15);
						gotoxy(90,a+7);
						cout<<"                          ";
						
						SetBGColor(13);
						SetColor(0);
						gotoxy(59,a+9);
						cout<<"     Nhap So CMND ( 9 so) ";	
						SetBGColor(15);
						gotoxy(90,a+9);
						cout<<"                          ";
	
					}
								
					while(1) 
					{
						
						SetBGColor(15);
						gotoxy(90,a+3);
						cout<<"                          ";
						gotoxy(95,a+3);
						SetColor(0);
						
						getline(cin,ho);
						chuan_hoa(ho);
						if(ho.empty() || cin.fail())	
							{
									cin.clear();
									_flushall();
									BaoLoi("Ho nhan vien khong hop le!!");
									continue;
							}
						else
							break;
					}
			
			
			
					
					
				while(true)
					{
						
						SetBGColor(15);
						gotoxy(90,a+5);
						cout<<"                          ";
						gotoxy(95,a+5);
						SetColor(0);
						getline(cin,ten);
						chuan_hoa(ten);
						
						if(kiem_ta_1_tu(ten)==0)
							{
								BaoLoi("Ten nhan vien chi chua 1 tu!!");
								continue;
							}
						
						if(ten.empty() || cin.fail())	
							{
									cin.clear();
									_flushall();
									BaoLoi("Ten nhan vien khong hop le!!");
									continue;
							}
						else
							break;			
					}
				
				while(true)
					{
						
						SetBGColor(15);
						gotoxy(90,a+7);
						cout<<"                          ";
						gotoxy(95,a+7);
						SetColor(0);
						
						getline(cin,phai);
						chuan_hoa(phai);
						
						
						if(phai.empty() || cin.fail() ||( phai.compare("Nam")!=0 && phai.compare("Nu")!=0 ))	
							{
									cin.clear();
									_flushall();
									BaoLoi("Gioi tinh chi nhan Nam/ Nu !!");
									continue;
							}
						else
							break;
			
					}
				
				while(true)
					{
						SetBGColor(15);
						gotoxy(90,a+9);
						cout<<"                          ";
						gotoxy(95,a+9);
						SetColor(0);
						getline(cin,cmnd);
						chuan_hoa(cmnd);
						if(kiem_ta_1_tu(cmnd)==0 || kiem_ta_so_cmnd(cmnd)==0 || cmnd.length()!=9)
							{
								BaoLoi("So CMND phai chua 9 chu so!!");
								continue;
							}
							
						//searchNV_cmnd(ds,int sl,cmnd);
						if(cmnd.empty() || cin.fail() )	
							{
									cin.clear();
									_flushall();
									BaoLoi("So CMND khong hop le!!");
									continue;
			
							}
						else if(cmnd!=ds[index]->cmnd)
						{
							if(searchNV_cmnd_mct(ds,sl,cmnd)!=-1)
							{
								BaoLoi("So CMND nay da ton tai!!");
								continue;
							}
						}
						
						break;	
					}			
								
					
					//hang duoi the hien cac nut dat biet
					gotoxy(61,31);
					SetColor(4);
					SetBGColor(0);
					cout<<"ESC: Huy va Thoat!\t\t";
					SetColor(10);
					cout<<"ENTER: Xac nhan chinh sua";
					SetColor(15);
									
					
				}
			
			
		do
		{
			HidePointer();		
			aa=getch();
			if(aa==13)
			{
				
				ds[index]->ho=ho;
				ds[index]->ten=ten;
				ds[index]->phai=phai;
				ds[index]->cmnd=cmnd;
				
				BaoLoi("Da chinh sua thanh cong!!?\n");
				return;
				//break;
			}
		
		else if (aa==27)
			{
				//Sleep(300);
				BaoLoi("Da huy chinh sua!");
				return;
			}
		}while(1);
			
			
			
		}
	
}
	
	
	



// ===================Chinh sua Nhan vien========================
void ChinhSuaNV(DS_NHAN_VIEN &ds)   // Khong su dung
{
	int a; //bien tam de nhap Ma nhan vien
	int i; // bien de luu chi so cua nhan vien do trong DANH SACH
		while(1) 
		{
			cout<<"\nNhap ma Nhan vien can chinh sua: ";
			cin >>a;
			cin.ignore();
			
			if(a<=0 || a>9999 || cin.fail())	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nMa nhan vien khong hop le!!\n";

				}
			i=searchNV(ds,a);
			if(i==-1)
			{
				cout<<"\nMa nhan vien nay khong ton tai!! Vui long nhap ma khac\n";
				continue;
			}
			else 
				break;
		}
		
		
		
		cout<<"\n-----Thong tin nhan vien --------"<<endl;
		ThongTinNVExist(ds,i);
		
		
		cout<<"\n==========Chinh sua========\n";
    	
		while(1) 
		{
			cout<<"Nhap Ho: ";
			getline(cin,ds.ds[i]->ho);
			chuan_hoa(ds.ds[i]->ho);
			if(ds.ds[i]->ho.empty() || cin.fail())	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nHo nhan vien khong hop le!!\n";

				}
			else
				break;
		}
		
		while(1) 
		{
			cout<<"Nhap Ten: ";
			cin>>ds.ds[i]->ten;
			chuan_hoa(ds.ds[i]->ten);
			if(ds.ds[i]->ten.empty() || cin.fail())	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nTen nhan vien khong hop le!!\n";

				}
			else
				break;
		}
		while(1) 
		{
			cout<<"Nhap gioi tinh: ";
			cin>>ds.ds[i]->phai;
			chuan_hoa(ds.ds[i]->phai);
			if(ds.ds[i]->phai.empty() || cin.fail() ||( ds.ds[i]->phai.compare("Nam")!=0 && ds.ds[i]->phai.compare("Nu")!=0 ))	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nGioi tinh khong hop le!!\n";

				}
			else
				break;
		}
	
	string tmp;//de luu tam CMND
	while(1) 
		{
			cout<<"Nhap so CMND: ";
			cin>>tmp;
			chuan_hoa(tmp);
			if(tmp.empty() || cin.fail() || tmp.length()!=9 )	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nSo CMND khong hop le!!\n";

				}
			else if(searchNV_cmnd_index(ds,tmp,i)!=-1)
			{
				cout<<"\nSo CMND nay da ton tai!! Vui long nhap so khac!!\n";
				continue;
			}
			else
			{
				ds.ds[i]->cmnd=tmp;
				break;
			}
		}
	
//	cin.ignore();
	
}


//ham hoan doi nhan vien phuc vu cho cau c..sap xep nhan vien theo ho va ten
void hoanDoi_NV(NHAN_VIEN *a,NHAN_VIEN *b)
{
	NHAN_VIEN tam;
	tam=*a;
	*a=*b;
	*b=tam;
	//delete a;
}
//sap xep tang dan theo ten va ho

void sap_xep_dsnv(NHAN_VIEN *ds[],int sl)
{
	for(int i=0;i<sl-1;i++)
	{
		for(int j=i+1;j<sl;j++)
		{
			if(ds[i]->ten > ds[j]->ten )
				hoanDoi_NV(ds[i],ds[j]);
			else if(ds[i]->ten == ds[j]->ten )
				if (ds[i]->ho > ds[j]->ho )
					hoanDoi_NV(ds[i],ds[j]);
		}
	}
		
}


void ThongTinNVExist  (DS_NHAN_VIEN ds,int i) 
{
  
   		cout<<"Ma nhan vien: ";
		printf("%03d\n",ds.ds[i]->ma_nv);
		cout<<"Ho: "<<ds.ds[i]->ho<<endl;
		cout<<"Ten: "<<ds.ds[i]->ten<<endl;
		cout<<"Phai: "<<ds.ds[i]->phai<<endl;
		cout<<"CMND: "<<ds.ds[i]->cmnd<<endl; 
		
}
//ham xuat thong tin nhan vien da ton tai-----i la chi so cua nhan vien do
void ThongTinNVExist1(NHAN_VIEN *p) // dang su dung
{
	int y=wherey();	
	gotoxy(45,y-1);
	for(int i=45;i<135;i++)
		cout<<"-";

	gotoxy(53,y);
	
	cout<<setw(3)<<setfill('0')<<p->ma_nv;
	//printf("%03d\n",p->ma_nv);

	gotoxy(64,y);
	cout<<p->ho;
		
	gotoxy(90,y);
	cout<<p->ten;
	
	gotoxy(106,y);
	cout<<p->phai;
	gotoxy(121,y);
	cout<<p->cmnd;
		
		gotoxy(50,y);
		cout<<"|";
			
		gotoxy(59,y);
		cout<<"|";
		
		gotoxy(82,y);
		cout<<"|";
		
		gotoxy(100,y);
		cout<<"|";
		
		gotoxy(115,y);
		cout<<"|";
		gotoxy(134,y);
		cout<<"|";
		
	
	gotoxy(45,y+1);
	for(int i=45;i<135;i++)
		cout<<"-";


}


void xuat_DSNV(NHAN_VIEN *ds[],int &sl)
{
	if(sl==0)
	{
		BaoLoi("Danh sach Nhan vien rong!!");
		return;
	}
	
	sap_xep_dsnv(ds,sl);
		
	int a=11;
	gotoxy(55,a);
	HidePointer();
	int soTrang;
	
	int aa;
	int b=0;
	int c;
	int i;
	int d;
	while(1)
	{
		//phong truong hop xoa nhan vien cuoi cung
				
		soTrang=so_trang_dsvt(sl);
		c=1;
		i=0;
		d=0;
		xoa_man_hinh_inside();
		gotoxy(81,a-6);
		SetBGColor(14);
		SetColor(1);
		HidePointer();
		cout<<"DANH SACH NHAN VIEN"; //in dong 5
		Normal();
		
		gotoxy(45,a-4); 
		for(int i=45;i<135;i++)	
			cout<<"-"; //in dong 7
		gotoxy(52,a-3);	//56
		SetColor(4);	
		cout<<"Ma So";//in dong 8
		gotoxy(65,a-3); //77
		cout<<"Ho Nhan Vien";
		gotoxy(85,a-3);
		cout<<"Ten Nhan Vien";
		gotoxy(106,a-3);
		cout<<"Phai";
		gotoxy(122,a-3);
		cout<<"So CMND";
	
		gotoxy(46,a-3);
		cout<<"STT";
		
		SetColor(15);
		
		gotoxy(45,a-3);
		cout<<"|";
		gotoxy(50,a-3);
		cout<<"|";
		gotoxy(59,a-3);
		cout<<"|";
		
		gotoxy(82,a-3);
		cout<<"|";
		
		gotoxy(100,a-3);
		cout<<"|";
		
		gotoxy(115,a-3);
		cout<<"|";
		gotoxy(134,a-3);
		cout<<"|";
	
		
		//hang duoi the hien cac nut dat biet
		gotoxy(44,32);
		SetColor(13);
		cout<<"ESC: Thoat!\t";
		SetColor(10);
		cout<<"  TAB: Chuyen trang\t";
		SetColor(11);
		cout<<"DELETE: Xoa Nhan Vien!\t";
		SetColor(12);
		cout<<"   ENTER: Chinh Sua Nhan Vien\t";
		SetColor(15);	
	
	//cout<<"\nDanh sach nhan vien da duoc sap xep\n";
	
	for(i=0+b;c!=11;i++,c++)
		{
			if(i>=sl)
				break;
			gotoxy(55,a+d);
			ThongTinNVExist1(ds[i]);
			
			gotoxy(45,a+d-1);
			cout<<"|";
			
			gotoxy(47,a+d-1);
			cout<<i+1;
			
			d=d+2;
		}
		
		
		
		SetColor(2);
		gotoxy(130,wherey()+3);
		cout<<"Trang ";
		if(b<10)
			cout<<"1";
		else
			cout<<b/10+1;
			
		cout<<"/"<<soTrang;
		Normal();
		//if(i>=nds)
		//	continue;
		//int z=1;
		
		
		
		do
		{
		
		aa=getch();
		if(aa==27)
		{
			xoa_man_hinh_inside();
			return;
			
		}
		
		
		else if(aa==83) // 83 la delete
		{
			xoa_nv(ds,sl);
			xoa_man_hinh_inside();
			if(sl==0)
			{		
				BaoLoi("Danh sach Nhan vien rong!!");
				return;
			}
			break;
		}
			
		else if(aa==13)
		{
			sua_nv(ds,sl);
			xoa_man_hinh_inside();
			break;
		}	
				
		else if(aa==9)
			{
				if(i<sl)
				{
					b=b+10;
					
					break;
				}
				
				else if(i>=sl)
					{
						b=0;
						
						break;
						
					}
						
			}
			
		}while (1);	

		
	
	
	
	}
}
//=======Xuat Nhan Vien==========
/*
 void xuatDSNV(DS_NHAN_VIEN dsnv)
{
	
	system("cls") ;
 printf ("                     DANH SACH NHAN VIEN \n");
 for (int i =0 ; i < dsnv.sl ; i++)
 {
  
  cout<<"\nNhan vien thu "<<i+1<<endl;
  cout<<"Ma nhan vien: "; //<<dsnv.ds[i]->ma_nv<<endl;
  printf("%03d\n",dsnv.ds[i]->ma_nv);
  cout<<"Ho: "<<dsnv.ds[i]->ho<<endl;
  cout<<"Ten: "<<dsnv.ds[i]->ten<<endl;
  cout<<"Phai: "<<dsnv.ds[i]->phai<<endl;
  cout<<"CMND: "<<dsnv.ds[i]->cmnd<<endl;
     
 }
 getch();
}

*/
//===============Them Nhan Vien============

int nhapNV(NHAN_VIEN &nv,DS_NHAN_VIEN ds)   //dang su dung
{
		ShowPointer();
		xoa_man_hinh_inside();
		
		gotoxy(75,7);
		SetColor(4);
		SetBGColor(10);
		cout<<"                      ";
		gotoxy(75,8);
		cout<<"=== THEM NHAN VIEN ===";
		gotoxy(75,9);
		cout<<"                      ";
		
		
		//in bieu mau
		{
			gotoxy(55,13);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Ma (0 de thoat) "; //24
			SetBGColor(15);
			gotoxy(90,13);
			cout<<"                          ";
			
			gotoxy(55,16);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Ho Nhan Vien    ";
			SetBGColor(15);
			gotoxy(90,16);
			cout<<"                          ";
			
			gotoxy(55,19);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Ten Nhan Vien   ";
			SetBGColor(15);
			gotoxy(90,19);
			cout<<"                          ";
			
			gotoxy(55,22);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Phai( Nam/ Nu)  ";
			SetBGColor(15);
			gotoxy(90,22);
			cout<<"                          ";
			
			gotoxy(55,25);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap So CMND         ";
			SetBGColor(15);
			gotoxy(90,25);
			cout<<"                          ";
			Normal();
			
		}
		
		
		
		
		while(1)
		{
			
			gotoxy(55,13);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Ma(0 de thoat)  "; //24
			SetBGColor(15);
			gotoxy(90,13);
			cout<<"                          ";
			gotoxy(100,13);
			SetColor(0);
			cin>>nv.ma_nv;
			cin.ignore();
			
			if( cin.fail())
				{
					cin.clear();
					_flushall();
					BaoLoi("Ma nhan vien khong hop le!!");
					continue;
				}
			
			if(nv.ma_nv==0)
				return 0;
				
			if(nv.ma_nv<0 || nv.ma_nv>9999 || cin.fail())	
				{
						cin.clear();
						_flushall();
						BaoLoi("Ma nhan vien khong hop le!!");
						continue;

				}
			else if(searchNV(ds,nv.ma_nv)!=-1)
			{
				BaoLoi("Ma nhan vien nay da ton tai!!");
				continue;
			}
			else 
				break;
			
			
		}
		
		
		
		while(1) 
		{
			gotoxy(55,16);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Ho Nhan Vien    ";
			SetBGColor(15);
			gotoxy(90,16);
			cout<<"                          ";
			gotoxy(95,16);
			SetColor(0);
			
			getline(cin,nv.ho);
			chuan_hoa(nv.ho);
			if(nv.ho.empty() || cin.fail())	
				{
						cin.clear();
						_flushall();
						BaoLoi("Ho nhan vien khong hop le!!");

				}
			else
				break;
		}



		
		
	while(true)
		{
			gotoxy(55,19);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Ten Nhan Vien   ";
			SetBGColor(15);
			gotoxy(90,19);
			cout<<"                          ";
			gotoxy(95,19);
			SetColor(0);
			getline(cin,nv.ten);
			chuan_hoa(nv.ten);
			
			if(kiem_ta_1_tu(nv.ten)==0)
				{
					BaoLoi("Ten nhan vien chi chua 1 tu!!");
					continue;
				}
			
			if(nv.ten.empty() || cin.fail())	
				{
						cin.clear();
						_flushall();
						BaoLoi("Ten nhan vien khong hop le!!");
						continue;
				}
			else
				break;			
		}
	
	while(true)
		{
			
			gotoxy(55,22);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap Phai( Nam/ Nu)  ";
			SetBGColor(15);
			gotoxy(90,22);
			cout<<"                          ";
			gotoxy(95,22);
			SetColor(0);
			
			getline(cin,nv.phai);
			chuan_hoa(nv.phai);
			
			
			if(nv.phai.empty() || cin.fail() ||( nv.phai.compare("Nam")!=0 && nv.phai.compare("Nu")!=0 ))	
				{
						cin.clear();
						_flushall();
						BaoLoi("Gioi tinh khong hop le!!");
						continue;
				}
			else
				break;

		}
	
	while(true)
		{
			gotoxy(55,25);
			SetBGColor(13);
			SetColor(0);
			cout<<"     Nhap So CMND         ";
			SetBGColor(15);
			gotoxy(90,25);
			cout<<"                          ";
			gotoxy(95,25);
			SetColor(0);
			getline(cin,nv.cmnd);
			chuan_hoa(nv.cmnd);
			if(kiem_ta_1_tu(nv.cmnd)==0 || kiem_ta_so_cmnd(nv.cmnd)==0|| nv.cmnd.length()!=9)
				{
					BaoLoi("So CMND phai chua 9 chu so!!");
					continue;
				}
				
			searchNV_cmnd(ds,nv.cmnd);
			if(nv.cmnd.empty() || cin.fail()  )	
				{
						cin.clear();
						_flushall();
						BaoLoi("So CMND khong hop le!!");

				}
			else if(searchNV_cmnd(ds,nv.cmnd)!=-1)
			{
				BaoLoi("So CMND nay da ton tai!!");
				continue;
			}
			else
				break;	
		}
		
		return 1;
}






int nhapNV1(NHAN_VIEN &nv,DS_NHAN_VIEN ds)

{
		
	//xoa_man_hinh_inside();
	while(1)
		{
			
			cout<<"\nNhap ma nhan vien( 0 de thoat!): ";
			cin >>nv.ma_nv;
			//cout<<endl<<nv.ma_nv<<endl;
			cin.ignore();
			if(nv.ma_nv<0 || nv.ma_nv>9999 || cin.fail())	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nMa nhan vien khong hop le!!\n";
						continue;

				}
			else if(searchNV(ds,nv.ma_nv)!=-1)
			{
				cout<<"\nMa nhan vien nay da ton tai!! Vui long nhap ma khac\n";
				continue;
			}
			else 
				break;
			
			
		}
	//cin.ignore();
	
	
	while(1) 
		{
			cout<<"Nhap Ho: ";
			getline(cin,nv.ho);
			chuan_hoa(nv.ho);
			if(nv.ho.empty() || cin.fail())	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nHo nhan vien khong hop le!!\n";

				}
			else
				break;
		}
		
		while(1) 
		{
			cout<<"Nhap Ten: ";
			cin>>nv.ten;
			chuan_hoa(nv.ten);
			//them ham kiem tra ten 1 tu
			
			if(nv.ten.empty() || cin.fail())	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nTen nhan vien khong hop le!!\n";

				}
			else
				break;
		}
		while(1) 
		{
			cout<<"Nhap gioi tinh: ";
			cin>>nv.phai;
			chuan_hoa(nv.phai);
			if(nv.phai.empty() || cin.fail() ||( nv.phai.compare("Nam")!=0 && nv.phai.compare("Nu")!=0 ))	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nGioi tinh khong hop le!!\n";

				}
			else
				break;
		}
	
	while(1) 
		{
			cout<<"Nhap so CMND: ";
			cin>>nv.cmnd;
			//chuan_hoa(nv.cmnd);
			searchNV_cmnd(ds,nv.cmnd);
			if(nv.cmnd.empty() || cin.fail() || nv.cmnd.length()!=9 )	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nSo CMND khong hop le!!\n";

				}
			else if(searchNV_cmnd(ds,nv.cmnd)!=-1)
			{
				cout<<"\nSo CMND nay da ton tai!! Vui long nhap so khac!!\n";
				continue;
			}
			else
				break;
		}
		
		
	
	cin.ignore();
	 return 1;
	
				

}

void nhapDSNV(DS_NHAN_VIEN &dsnv, int flag)
{

	NHAN_VIEN nv;
	if (flag==0) 
	 	while (dsnv.sl> 0)
		{
	 	   delete dsnv.ds[dsnv.sl-1];
	       dsnv.sl-- ;
	   	}
//neu flag bang 1 thi them noi duoi
	char c;
 while (dsnv.sl <MAX_NV)
 {   	
    if(nhapNV(nv,dsnv)==0)
	{
		xoa_man_hinh_inside(); 
		return;
	}
    dsnv.ds[dsnv.sl]= new NHAN_VIEN;
    *dsnv.ds[dsnv.sl]=nv;
    dsnv.sl++;
    BaoLoi("Da them thanh cong!");
    
    HidePointer();
    Normal();
    gotoxy(62,30);
    SetColor(4);
    cout<<"ESC: de thoat!!";
    gotoxy(83,30);
    SetColor(10);
    cout<<"Phim bat ky: de nhap tiep!!";
    Normal();
    
	c=getch();
    if(c==27)
    	{
    		xoa_man_hinh_inside();
    		return;
		}
		
    
 }
 if (dsnv.sl>=MAX_NV)
	BaoLoi("Danh sach Nhan vien da day!!");
}



//
//===================cau d=================
//insert node trong lien ket don
void them_1_hd(HOA_DON *&phead, HOA_DON *p)
{
	HOA_DON *plast;
	
	if (phead!=NULL ) 
    	for ( plast = phead ; plast->pnext !=NULL; plast=plast->pnext) ;
    	
	if (phead==NULL) 
		phead = p;
	else plast->pnext = p;
		plast = p;
	
	/*
	
	if (phead == NULL)
	{
		phead = p;
	}
	else
	{
		for (HOA_DON *k = phead;k != NULL;k = k->pnext)
		{
			if (k->pnext == NULL)
			{
				k->pnext = p;
				return;
			}
		}
	}
	*/
}

//Ham khoi tao 1 Hoa don
HOA_DON *khoi_tao_node_hd()
	{
		HOA_DON *p=new HOA_DON;
		p->pnext=NULL;
		return p;
	}

//Ham kiem tra So Hoa don
int kiem_tra_so_hd(DS_NHAN_VIEN ds_nv,string x)
{
	HOA_DON *p;
	
	for(int i=0;i<ds_nv.sl;i++)
	{
			for (p = ds_nv.ds[i]->danh_sach_hd.phead;  p  != NULL ; p=p->pnext )
              if ( p->so_hd == x  ) return 1;
	}
	return 0;
}

//Ham kiem tra Ma Vat tu trung cho cau e,Lap hoa don
int searchCTHD(DS_CHI_TIET_HD ds_cthd, string x)
{
	for(int i=0;i<ds_cthd.sl;i++)
		{
			if(ds_cthd.ds[i].ma_vt==x)
				return i;
		}
	return -1;
}


//Ham lay So luong ton trong kho

int lay_so_luong_ton(tree t, string x)
{
	vat_tu *p=searchVT(t,x);
	if(p==NULL)
		return -1; //vat tu khong ton tai
	return p->so_luong_ton;
}


//Ham nhap 1 Chi tiet Hoa don

int nhap_CTHD (DS_CHI_TIET_HD &ds_cthd, CHI_TIET_HOA_DON &cthd, tree &t,int flat)
{
	//int slt;
	vat_tu *vt;// De luu dia chi cua node Vat tu
	
	while(true)
		{
			cout << "\nNhap ma Vat tu (Nhap quit de Thoat) : " ; 
			cin >> cthd.ma_vt;
			if(cthd.ma_vt=="quit")
				return -1;
			if(cthd.ma_vt.empty() || cin.fail() || cthd.ma_vt.length()>10)	
				{
						cin.clear();
						_flushall();
						cout << "\nMa vat tu khong hop le!!\n";
						continue;

				}
			vt=searchVT(t,cthd.ma_vt);
			//slt=lay_so_luong_ton(t,cthd.ma_vt);		
			if(vt==NULL)
				{
					cout<<"\nMa vat tu khong ton tai trong Danh sach Vat tu! Vui long nhap ma khac!!\n";
					continue;
				}
			if(searchCTHD(ds_cthd,cthd.ma_vt)!=-1)
				{
					cout<<"\nVat tu nay da ton tai trong Hoa don!!\n";
					continue;
				}
				
			break;
			
		}
	
	while (1)
	{
	cout << "Nhap so luong: " ;
	cin>>cthd.so_luong;
	cin.ignore();
	if(cin.fail()||cthd.so_luong<=0||cthd.so_luong>999999)
		{
			cin.clear();
			_flushall();
			cout << "\nSo luong ton khong hop le!!\n";
			continue;
		}
	
	//kiem tra so luong ton
	if(flat==2)//la phieu Xuat thi kiem tra So luong ton
		{
			if(vt->so_luong_ton < cthd.so_luong)
				{
					cout<<"\nTrong kho chi con "<<vt->so_luong_ton<<" "<<vt->don_vi_tinh<<endl; 
					cout<<"------Khong du so luong de Xuat!!!--------\n";
					continue;
				}
			else //Xu ly giam so luong trong kho cho Hoa don Xuat
				{
					vt->so_luong_ton=vt->so_luong_ton - cthd.so_luong;
				}
				
		}
	else //Xu ly cho Hoa don Nhap(flat=1)
		{
			vt->so_luong_ton=vt->so_luong_ton + cthd.so_luong;
		}
	
	
	
	
	break;
	}
	
	while (1)
	{
	cout << "Nhap Don gia ( VND): " ;
	cin>>cthd.don_gia;
	cin.ignore();
	if(cin.fail()||cthd.don_gia<=0||cthd.don_gia>99999999)
		{
			cin.clear();
			_flushall();
			cout << "\nDon gia khong hop le!!\n";
			continue;
		}
	break;
	}
	
	int vat;
	while (1)
	{
	cout << "Nhap %VAT: " ;
	cin>>vat;
	cin.ignore();
	if(cin.fail()||vat<0||vat>100)
		{
			cin.clear();
			_flushall();
			cout << "\nVAT khong hop le (Nhan tu 1 ->100)!!\n";
			continue;
		}
	break;
	}
	//xu ly VAT
	cthd.VAT=vat/100.0;
	//xu ly Trang thai
	cthd.trang_thai=1; // Khach mua
	//Danh dau Vat tu nay da dc lap Hoa don -> de khong duoc Xoa
	
	vt->kt=1;
	
	//xu ly so luong ton
	//neu xuat khong du hang thi in ra so luong ton trong kho 
	// bang cach tim kiem vat tu trong Danh sach vat tu
	
	
	return 1;
}

//Nhap danh sach Chi tiet hoa don
void nhap_DS_CTHD (DS_CHI_TIET_HD &ds_cthd, tree &t,int flat)  // flat la co chi day la phieu Nhap hay phieu Xuat  ---1: Nhap---2: Xuat 
{
	CHI_TIET_HOA_DON cthd;
	int err;
	char c;
	while (ds_cthd.sl < MAX_CTHD) 
	{
		err= nhap_CTHD(ds_cthd,cthd,t,flat);// flat la co chi day la phieu Nhap hay phieu Xuat  ---1: Nhap---2: Xuat 
		if (err==-1)
		{
			cout<<"Thoat nhap thanh cong!! Nhan phim bat ky de thoat";
			getch(); 
			return ;
		}
	    ds_cthd.ds[ds_cthd.sl]= cthd;
	    ds_cthd.sl++;
	    
	    cout<<"\nDa them thanh cong!\n";
    
    cout<<"\n-------Nhan ESC de thoat--------Nhan cac phim khac de nhap tiep Vat tu!\n";
    c=getch();
    if(c==27)
    	{
    		cout<<"\nThoat thanh cong \n";
    		return;
    		getch();
		}
		
    
 	}
 if (ds_cthd.sl>=MAX_CTHD)
 	{
		cout<<"\nDanh sach da day!!\n";
	}
	
	
}




// ham chinh
void lapHoaDon(DS_VAT_TU ds_vt,DS_NHAN_VIEN ds_nv)
{
	int manv;
	int k; // dung de luu chi so cua nhan vien da tim duoc
	NHAN_VIEN *pNV;
	//----------Xac dinh Nhan vien lap Hoa don
	while(1) 
		{
			
			cout<<"\nNhap Ma so nhan vien: ";
			cin>>manv;
			
			cin.ignore();
			if(manv<0 || manv>9999 || cin.fail())	
				{
						cin.clear();
						_flushall();
						cout << "\nMa so nhan vien khong hop le!!\n";
						continue;

				}
			k=searchNV(ds_nv,manv);	//k la chi so cua nhan vien do trong Mang con tro Danh sach Nhan vien
			if(k==-1)
			{
				cout<<"\nMa nhan vien nay khong ton tai!! Vui long nhap ma khac\n";
				continue;
			}
			else 
				break;
		}
	
	pNV=ds_nv.ds[k]; //su dung bien tam de luu dia chi Nhan vien dang lap Hoa don tai chi so k cua Danh sach Mang con tro Nhan vien
	
	
	//--------------Nhap thong tin Hoa don---------
	HOA_DON *hd=khoi_tao_node_hd();
	
	string tmp_a;//dung bien tam de nhap Loai hoa don
	
	while (true)
	{
		cout<<"\nNhap loai Hoa don ( N hoac X)  :";
		cin>>tmp_a;
		if(tmp_a.length()!=1)
		{
			cin.ignore();
			cout<<"\nChi nhan 1 ki tu X hoac N\n";
            continue;
		}
		
		if(tmp_a!="N" && tmp_a!="X")
		{
			cout<<"\nLoai Hoa don khong hop le!!!\n";
			continue;
		}
		else
		{
			hd->loai=tmp_a[0];
			break;
		}
		
	}
	
	
			while(1) 
		{
			cout<<"\nNhap so Hoa don: ";
			cin>>hd->so_hd;	
			if(hd->so_hd.empty() || cin.fail()||hd->so_hd.length()>20)	
				{
						cin.clear();
						_flushall();
						//cin.ignore();
						cout << "\nSo Hoa don khong hop le!!\n";
						continue;

				}
			if(kiem_tra_so_hd(ds_nv,hd->so_hd)==1) // ham nay tra ve 0 hoac 1
			{
				cout<<"So hoa don da ton tai!!";
				continue;
			}
			
			break;
		}
	
	
	nhapDate(hd->ngay_lap_hd);
	
	
	
	
	
		
	//---------Nhap thong tin Chi tiet hoa don-----------	
		
	//Them Hoa don do vao Danh sach hoa don cua Nhan vien
	them_1_hd(pNV->danh_sach_hd.phead, hd);
	//tang so Hoa don trong danh sach cua nhan vien do
	pNV->danh_sach_hd.sl++;
	//Danh dau nhan vien nay da lap 1 Hoa don
	pNV->kt=1;
	//
	
	cout << "Lap hoa don Thanh Cong! Nhan phim bat ki de tiep tuc lap chi tiet hoa don" << endl;
	system("pause");
	cout << "\nHoa don: " << hd->loai << "  Ma Hoa don: " << hd->so_hd << "  Ngay lap hoa don: " << hd->ngay_lap_hd.ngay<<"/"<<hd->ngay_lap_hd.thang<<"/"<<hd->ngay_lap_hd.nam << endl;
	system("pause");
	cout<<"\nHOAN THANH\n=========Tiep tuc nhap Chi tiet Hoa don=========\n";
	
	int flat;
	if(hd->loai=='N')
		flat=1;
	else
		flat=2;
	
	//Nhap chi tiet hoa don
	nhap_DS_CTHD(hd->ds_CTHD,ds_vt.TREE,flat);//1: Nhap----2: Xuat
	
	
	cout<<"\nLAP HOA DON HOAN TAT\n";
	system("pause");
	
}





//=================LAP HOA DON================

// Ham xuat cac ma vat tu de giup nguoi dung nhap CTHD
void Pretrav_help_cthd (tree root,int a)
{
	//a=wherey();
	Normal();
	a;
	gotoxy(47,a-1);
	SetColor(12);
	cout<<"Cac ma Vat tu co trong Kho:";
	
	SetColor(15);
	gotoxy(47,a);
	const int STACKSIZE = 100;
	tree Stack[STACKSIZE];
	int sp=  -1;	// Khoi tao Stack rong
	tree p=root;
	while (p!=NULL )
	   {
	   	
			//	In ra cac Ma vat tu co trong kho de tro giup nguoi nhap   	
	      	
	      	if(wherex()>120)
			{
				gotoxy(47,a+1);			
				
			}
			cout <<p->ma_vt << ", ";   // "xu ly p"
			
			
			//
					
	    	if (p->pright != NULL)
				Stack[++sp]= p->pright;
	      	if (p->pleft != NULL)
				p=p->pleft;
	      	else  if (sp==-1)
				break;
		    else
				p=Stack[sp--];
	   }
	   
	   //co kha nang se ko xoa duoc
	   /*
	   gotoxy(wherex()-4,wherey());
	   SetBGColor(0);
	   cout<<"  ";
	   Normal();
	   */  
}



void nhap_cthd(DS_CHI_TIET_HD ds_cthd, CHI_TIET_HOA_DON &cthd, tree t,int flat)
{

	vat_tu *vt;// De luu dia chi cua node Vat tu
	ShowPointer();
	//form nhap cthd
	
	Pretrav_help_cthd(t,26);
	
	{
				
		SetBGColor(11);
		SetColor(0);
		gotoxy(92,22);
		cout<<"   Nhap %VAT( 0->100)     "; //22
		
		SetBGColor(15);
		gotoxy(119,22);
		cout<<"               "; //15
		
		SetBGColor(11);
		SetColor(0);
		gotoxy(47,22);
		cout<<"    Nhap Don Gia      "; //22
		SetBGColor(15);
		gotoxy(72,22);
		cout<<"               "; //15
		
		
		
			
		SetBGColor(11);
		SetColor(0);
		gotoxy(92,20);
		cout<<"   So Luong               "; //22
		SetBGColor(15);
		gotoxy(119,20);
		cout<<"               "; //15
		
		
				
		SetBGColor(11);
		SetColor(0);
		gotoxy(47,20);
		cout<<"    Nhap Ma Vat Tu    "; //22
		SetBGColor(15);
		gotoxy(72,20);
		cout<<"               "; //15
	}
	while(1) 
	{
				
		
		SetBGColor(15);
		gotoxy(72,20);
		cout<<"               "; //15
		gotoxy(77,20);
		SetColor(0);
		//cin.ignore();
		getline(cin,cthd.ma_vt);
				
		if(cthd.ma_vt.empty() || cin.fail())	
			{
					cin.clear();
					_flushall();
					BaoLoi("Ma so Vat tu khong hop le!!");
					continue;
			}
			
		thanh_chu_thuong(cthd.ma_vt);
		if(cthd.ma_vt.length()>10)
			{
				BaoLoi("Ma Vat tu chi chua toi da 10 ki tu!!");
				continue;
			}
		if(kiem_ta_1_tu(cthd.ma_vt)==0)  // ma vat tu ko chua bat ky khoang trang o bat cu vi tri nao
			{
				BaoLoi("Ma Vat tu khong chua khoang trang!!");
				continue;
			}
		
		
		vt=searchVT(t,cthd.ma_vt);
		if(vt==NULL)
			{
				BaoLoi("Ma vat tu khong ton tai trong Danh sach Vat tu! Vui long nhap ma khac!!");
				continue;
			}
		if(searchCTHD(ds_cthd,cthd.ma_vt)!=-1)  //kiem tra vat nu nay da ton tai trong danh sach Dang duoc lap hay chua
			{
				BaoLoi("Vat tu nay da ton tai trong Hoa don!!");
				continue;
			}
	
		break;
	}
	SetBGColor(11);
	SetColor(0);
	gotoxy(104,20);
	cout<<"( "<<vt->don_vi_tinh<<")";
	
	while (1)
	{
	
		SetBGColor(15);
		gotoxy(119,20);
		cout<<"               "; //15
		gotoxy(123,20);
		SetColor(0);
		
		cin>>cthd.so_luong;
		cin.ignore();
		if(cin.fail()||cthd.so_luong<=0||cthd.so_luong>999999)
			{
				cin.clear();
				_flushall();
				BaoLoi("So luong khong hop le!!");
				continue;
			}
		
		//kiem tra so luong ton
		
		
		if(flat==2)//la phieu Xuat thi kiem tra So luong ton co du hay khong?
			{
				if(vt->so_luong_ton < cthd.so_luong)
					{
						BaoLoiTonKho(vt->so_luong_ton,vt->don_vi_tinh);
						continue;
					}
				
					
			}	
		break;
	}
	
	
	
	while (1)
	{

		SetBGColor(15);
		gotoxy(72,22);
		cout<<"               "; //15
		gotoxy(77,22);
		SetColor(0);
	
		cin>>cthd.don_gia;
		cin.ignore();
		if(cin.fail()||cthd.don_gia<=0||cthd.don_gia>99999999)
			{
				cin.clear();
				_flushall();
				BaoLoi("Don gia khong hop le!!");
				continue;
			}
		break;
	}
	
	
	int vat;
	while (1)
	{

		SetBGColor(15);
		gotoxy(119,22);
		cout<<"               "; //15
		gotoxy(123,22);
		SetColor(0);
		
		cin>>vat;
		
		cin.ignore();
		if(cin.fail()||vat<0||vat>100)
			{
				cin.clear();
				_flushall();
				BaoLoi("VAT khong hop le( Nhan tu 1 ->100)!!");
				continue;
			}
		break;
	}
	//xu ly VAT
	cthd.VAT=vat/100.0;



	
}
//2 cach diem so luong phan tu trong cay
int dem_cay(tree root)
{
	if(root==NULL)
		return 0;
	else
		return (dem_cay(root->pright)+dem_cay(root->pleft))+1;
}

void diem_NLR(tree root,int &count)
{
	if(root)
	{
		count++;
		diem_NLR(root->pleft,count);
		diem_NLR(root->pright,count);
	}
}


//Nhap danh sach Chi tiet hoa don
void nhap_ds_cthd (DS_CHI_TIET_HD &ds_cthd, tree t,int flat)  // flat la co chi day la phieu Nhap hay phieu Xuat  ---1: Nhap---2: Xuat 
{
	CHI_TIET_HOA_DON cthd;
	int gech; // bien nhan ham getch()
	
	int dem=dem_cay(t);
	
	while (ds_cthd.sl < MAX_CTHD) 
	{
		nhap_cthd(ds_cthd,cthd,t,flat);// flat la co chi day la phieu Nhap hay phieu Xuat  ---1: Nhap---2: Xuat 
		
	    ds_cthd.ds[ds_cthd.sl]= cthd;
	    ds_cthd.sl++;
	    
	    // Phong truong hop so luong cac loai Vat tu nho hon hoac bang 20 
	    if(ds_cthd.sl==dem)
	    {
	    	BaoLoi("Khong du so loai Vat tu de them!!");
	    	return;
		}
	    
		
		HidePointer();
		
	    BaoLoi("Them thanh cong vao Danh sach Chi Tiet Hoa Don!!");
		gotoxy(51,32);
		SetColor(6);
		SetBGColor(0);
		cout<<"ESC: Ghi hoac Chinh sua Hoa don!\t";
		SetColor(10);
		cout<<"PHIM BAT KY: De nhap tiep Vat tu vao Hoa don!";
		SetColor(15);
		
		do
		{
		
			gech=getch();
			if(gech==27)
			{	
				//BaoLoi("Chinh sua hoac Ghi Hoa don!!");
				return;
			}
		
		else 
			{
				//Xoa thong bao Enter , phim bat ky
				gotoxy(50,32);
				SetBGColor(0);
				cout<<"                                                                         			";
				break;
				
			}
		}while(1);
		
		
		
    
 	}
 if (ds_cthd.sl>=MAX_CTHD)
 	{
		cout<<"\nDanh sach Chi tiet Hoa don da day!!\n";
	}
	
	
}



// ham lien quan den viec Xoa Vat tu khoi Hoa don dang lap


void ThongTinCTHD(CHI_TIET_HOA_DON cthd,tree t) 
{

	vat_tu *vt;
	vt=searchVT(t,cthd.ma_vt);
	
	int y=wherey();	
	gotoxy(45,y-1);
	for(int i=45;i<135;i++)
		cout<<"-";

	gotoxy(53,y);
	
	cout<<cthd.ma_vt;
													
	gotoxy(67,y);
	cout<<vt->ten_vt;
		
	gotoxy(94,y);
	cout<<cthd.so_luong;
	
	gotoxy(109,y);
	cout<<cthd.don_gia;
	gotoxy(125,y);
	double vat=cthd.VAT*100.0;
	cout<<vat<<"%";
		
		gotoxy(50,y);
		cout<<"|";
			
		gotoxy(63,y);
		cout<<"|";
		
		gotoxy(90,y);					
		cout<<"|";
		
		gotoxy(106,y);
		cout<<"|";
		
		gotoxy(121,y);
		cout<<"|";
		gotoxy(134,y);
		cout<<"|";
		
	
	gotoxy(45,y+1);
	for(int i=45;i<135;i++)
		cout<<"-";


}

void xoa_vt_from_cthd(DS_CHI_TIET_HD &ds_cthd,int index)
{
	 for (int j=index+1; j <ds_cthd.sl; j++)
       ds_cthd.ds[j-1]=ds_cthd.ds[j];
       
     ds_cthd.sl--;
}



void xoa_cthd(DS_CHI_TIET_HD &ds_cthd,tree t)
{
	xoa_man_hinh_inside();
	string ma_vt;
	vat_tu *vt;
	int gech;
	int a;//  xac dinh dong 
	int index; // luu chi so cua vat tu trong ds cthd
	gotoxy(72,8);
	SetColor(4);
	SetBGColor(10);
	cout<<"                               ";
	gotoxy(72,9);
	cout<<"     XOA VAT TU KHOI HOA DON   ";
	gotoxy(72,10);
	cout<<"                               ";		
	Normal();
	
	while(1)
		{
			ShowPointer();
			gotoxy(63,14);
			SetBGColor(13);
			SetColor(0);
			cout<<"   Nhap Ma Vat Tu( q de thoat)  "; //24
			SetBGColor(15);
			gotoxy(100,14);
			cout<<"                   ";
			gotoxy(105,14);
			SetColor(0);
			getline(cin,ma_vt);
			
			if(ma_vt=="q"||ma_vt=="Q")
				return;
			
			if(ma_vt.empty() || cin.fail() || ma_vt.length()>10)	
			{
					cin.clear();
					_flushall();
					BaoLoi("Ma vat tu khong hop le!!");
					continue;
			}	
					
			if(kiem_ta_1_tu(ma_vt)==0)	// phai ko co bat ky khoang trang nao
			{
					cin.clear();
					_flushall();
					BaoLoi("Ma vat tu khong chua khoang trang!!");
					continue;
			}

			
			index=searchCTHD(ds_cthd,ma_vt);
			
			if(index==-1)  //kiem tra vat nu nay da ton tai trong danh sach Dang duoc lap hay chua
			{
				BaoLoi("Vat tu nay khong ton tai trong Danh sach CTHD!!");
				continue;
			}
			
			break;
		}
			 // in thong tin nhan vien do
				
					vt=searchVT(t,ma_vt); // Muc dich la Lay ten cua vat tu co ma do
				 	HidePointer();
					a=20;
					Normal();
					gotoxy(50,a-4); 
					for(int i=50;i<135;i++)	
						cout<<"-"; //  dong 16
									
					gotoxy(52,a-3);	//56
					SetColor(4);	
					cout<<"Ma VT";//in dong 8
					gotoxy(67,a-3); //77
					cout<<"Ten Vat Tu";
					gotoxy(93,a-3);
					cout<<"So luong";
					gotoxy(109,a-3);                   
					cout<<"Don Gia";
					gotoxy(126,a-3);
					cout<<"%VAT";
					SetColor(15);
					gotoxy(50,a-3);
					cout<<"|";
						
					gotoxy(63,a-3);
					cout<<"|";
					
					gotoxy(90,a-3);
					cout<<"|";
					
					gotoxy(106,a-3);
					cout<<"|";
					
					gotoxy(121,a-3);
					cout<<"|";
					gotoxy(134,a-3);
					cout<<"|";
				
					gotoxy(120,a);
						
					ThongTinCTHD(ds_cthd.ds[index],t);
				
					//xoa 2 khoang (-) thua
					SetBGColor(0);
					
					gotoxy(45,a-2);
					for(int i=45;i<50;i++)
					cout<<" "; 
					gotoxy(45,a);
					for(int i=45;i<50;i++)
					cout<<" ";
					
					
					/*
					//hang duoi the hien cac nut dat biet
					gotoxy(67,31);
					SetColor(13);
					cout<<"ESC: Huy va Thoat!\t\t";
					SetColor(10);
					cout<<"DEL: Xac nhan xoa";
					SetColor(15);
									
					
				
			
			
				do
				{
				
					gech=getch();
					if(gech==83)
					{
						xoa_vt_from_cthd(ds_cthd,index);
						
						BaoLoi("Da xoa thanh cong!!?\n");
						return;
					}
				
				else if (gech==27)
					{
						BaoLoi("Da huy bo xoa!");
						return;
					}
				}while(1);
				*/
				
				int Err;		
				
				
				checkExitXXX(&Err, "Delete");
				if (Err == -1) //yes
				{
					
					XoaCheckExitXXX();
					HidePointer();
					xoa_vt_from_cthd(ds_cthd,index);
							
					BaoLoi("Da xoa thanh cong!!?\n");
					return;
					
					
				}
				else
				{
					XoaCheckExitXXX();
					HidePointer();
					BaoLoi("Da huy bo xoa!");
					return;
					
				}			
			
}





int show_ds_cthd(DS_CHI_TIET_HD &ds_cthd,tree t)
				
{
	
	
		
	int a=11;
	gotoxy(55,a);
	HidePointer();
	int soTrang;
	//int Err;		
			
	
	int gech;
	int b=0;
	int c;
	int i;
	int d;
	while(1)
	{
				
		soTrang=so_trang_dsvt(ds_cthd.sl); // su dung cong thuc tinh so trang
		c=1;
		i=0;
		d=0;
		xoa_man_hinh_inside();
		gotoxy(78,a-6);
		SetBGColor(14);
		SetColor(1);
		HidePointer();
		cout<<"DANH SACH CHI TIET HOA DON"; //in dong 5
	
		Normal();
		
		gotoxy(45,a-4); 
		for(int i=45;i<135;i++)	
			cout<<"-"; //in dong 7
			
		SetColor(4);
		gotoxy(46,a-3);
		cout<<"STT";
		gotoxy(54,a-3);	//56	
		
		cout<<"Ma VT";//in dong 8
		gotoxy(71,a-3); //77
		cout<<"Ten Vat Tu";
		gotoxy(94,a-3);										
		cout<<"So Luong";
		gotoxy(110,a-3);
		cout<<"Don Gia";
		gotoxy(126,a-3);
		cout<<"%VAT";
	
		SetColor(15);
		
		gotoxy(45,a-3);
		cout<<"|";
		gotoxy(50,a-3);
		cout<<"|";
			
		gotoxy(63,a-3);
		cout<<"|";
		
		gotoxy(90,a-3);
		cout<<"|";
		
		gotoxy(106,a-3);
		cout<<"|";
		
		gotoxy(121,a-3);
		cout<<"|";
		gotoxy(134,a-3);
		cout<<"|";
	
		
		//hang duoi the hien cac nut dat biet
		gotoxy(44,32);
		SetColor(4);
		cout<<"ESC: Huy bo Hoa don!\t";
		SetColor(10);
		cout<<"  TAB: Chuyen trang\t";
		SetColor(11);
		cout<<"DELETE: Xoa bo Vat tu!\t";
		SetColor(12);
		cout<<"   ENTER: Ghi Hoa don";
		SetColor(15);	
	
	
	for(i=0+b;c!=11;i++,c++)
		{
			if(i>=ds_cthd.sl)
				break;
			gotoxy(55,a+d);
			ThongTinCTHD(ds_cthd.ds[i],t);
			
			gotoxy(45,a+d-1);
			cout<<"|";
			
			gotoxy(47,a+d-1);
			cout<<i+1;
			
			d=d+2;
		}
		
		
		
		SetColor(2);
		gotoxy(130,wherey()+3);
		cout<<"Trang ";
		if(b<10)
			cout<<"1";
		else
			cout<<b/10+1;
			
		cout<<"/"<<soTrang;
		Normal();
		
		
		
		do
		{
		
			gech=getch();
			if(gech==27) // Huy bo Hoa don dang lap
			{
				
				//xoa thong bao cu, thay thong bao moi	
				gotoxy(40,32);
				SetBGColor(0);
				cout<<"                                                                                                          ";
				
				gotoxy(51,32);
				SetColor(4);
				cout<<"ENTER: Xac Nhan Huy Bo Hoa Don Nay!\t\t";
				SetColor(10);
				cout<<"CAC PHIM KHAC: Quay Lai!!";
				
			
				gech=getch();
				if(gech==13) //phim Enter
					{
						BaoLoi("Huy bo Hoa don thanh cong!!");
						xoa_man_hinh_inside();
						return 0; //Sau do thiet lap viec Xoa pHD
					}
				else
					break;
					
						
						/*		
						checkExitXXX(&Err, "Delete");
						if (Err == -1) //yes
						{
							
							removeVT(ma_vt,ds_vt.TREE);
							ds_vt.sl--;
							XoaCheckExitXXX();
							HidePointer();
							BaoLoi("Da xoa thanh cong!!?\n");
							return 1;
							
							
						}
						else
						{
							XoaCheckExitXXX();
							HidePointer();
							BaoLoi("Da huy bo xoa!");
							return 0;
							
						}
								
					*/
					
					
					
					
			}
			
			
			else if(gech==83) // Xoa bo Vat tu khoi Hoa don
			{
				xoa_cthd(ds_cthd,t);
				xoa_man_hinh_inside();
				if(ds_cthd.sl==0)
				{		
					BaoLoi("Huy bo thao tac Lap Hoa don, do Danh sach CTHD rong!!");
					return 0; //Khi xoa het tat ca Vat tu trong DS_CTHD thi Hoa don do se bi huy
				}
				break;
			}
				
			else if(gech==13) //Phim Enter
			{
				BaoLoi("Lap Hoa don thanh cong!!");
				xoa_man_hinh_inside();
				return 1; // Xac nhan Hoa don duoc lap Thanh cong
			}	
					
			else if(gech==9)
				{
					if(i<ds_cthd.sl)
					{
						b=b+10;
						
						break;
					}
					
					else if(i>=ds_cthd.sl)
						{
							b=0;
							
							break;
							
						}
							
				}
			
		}while (1);	
	}
}


// ket thuc cac ham lien quan den Xoa vat tu khoi hoa don dang lap











void lap_hoa_don(DS_VAT_TU &ds_vt, DS_NHAN_VIEN &ds_nv)
{

	xoa_man_hinh_inside();
	
	
	int ma_nv;
	int k; // dung de luu chi so cua nhan vien da tim duoc
	NHAN_VIEN *pNV;
	HOA_DON *pHD;
	int index; // dung de luu chi so cua NV do trong danh sach mct
	bool whilee=true;// dung de thoat vong lap while
	int gech; // bien dung de nhan ham getch()
	gotoxy(78,4);
	SetColor(4);
	SetBGColor(10);
	cout<<"                          ";
	gotoxy(78,5);
	cout<<"        LAP HOA DON       ";
	gotoxy(78,6);
	cout<<"                          ";		
	Normal();
	
	while(whilee)
		{
			ShowPointer();
			gotoxy(62,9);
			SetBGColor(13);
			SetColor(0);
			cout<<"  Nhap Ma So Nhan Vien( 0: thoat)  "; //24
			SetBGColor(15);
			gotoxy(103,9);
			cout<<"              ";
			gotoxy(108,9);
			SetColor(0);
			cin>>ma_nv;
			cin.ignore();
			
			if( cin.fail())
				{
					cin.clear();
					_flushall();
					BaoLoi("Ma nhan vien khong hop le!!");
					continue;
				}
			
			if(ma_nv==0)
			{
					xoa_man_hinh_inside();
					return ;
			}
				
			if(ma_nv<0 || ma_nv>9999)	
				{
						cin.clear();
						_flushall();
						BaoLoi("Ma nhan vien khong hop le!!");
						continue;

				}
			index=searchNV_mct(ds_nv.ds,ds_nv.sl,ma_nv);	
			if(index==-1)
			{
				BaoLoi("Ma nhan vien nay khong ton tai!!");
				continue;
			}
			else
			{
				pNV=ds_nv.ds[index];
				gotoxy(72,11);
				SetBGColor(0);
				SetColor(15);
				cout<<"Ho va ten Nhan vien: ";
				SetColor(1);
				cout<<pNV->ho<<" "<<pNV->ten;
				
				//Hoi nguoi dung tiep tuc nhap hay
				
				
				//menu cac dieu ng dung can chon
					gotoxy(57,31);
					SetColor(4);
					SetBGColor(0);
					cout<<"ESC: Huy bo va Thoat!\t";
					SetColor(10);
					cout<<"ENTER: Tiep tuc\t";
					SetColor(6);
					cout<<"  BACKSPACE: Thay doi Nhan vien";
					
					Normal();
				
				
				
				while(1)
				{
					HidePointer(); 
					gech=getch();
					
					if(gech==27) // phim ESC
					{
						xoa_man_hinh_inside();
						return;
					}
					else if(gech==13) // phim ENTER
					{
						gotoxy(50,31);
						SetBGColor(0);
						cout<<"                                                                                            ";
						whilee=false;
						break;
					}
					else if(gech==8) // phim BACKSPACE
					{
						//Xoa dong thong tin Nhan vien cu
						gotoxy(65,11);
						SetBGColor(0);
						//for(int i=0;i<145;i++)
						cout<<"                                                                      ";
						//Xoa dong thong bao lua chon
						gotoxy(50,31);
						SetBGColor(0);
						cout<<"                                                                                            ";
						
						
						break;
					}
				}
				
			}
		}
			
			
		
		
			

				ShowPointer();
					// thao tac Nhap thong tin Hoa don
						pHD=khoi_tao_node_hd();
						string loai; // bien tam de nhap Loai hoa don
					//form chinh sua
					{
						
						SetBGColor(13);
						SetColor(0);
						
						gotoxy(62,13);
						cout<<"    Nhap Ma So Hoa Don    ";
						SetBGColor(15);
						gotoxy(91,13);
						cout<<"                          ";
						
						SetBGColor(13);
						SetColor(0);
						gotoxy(62,15);
						cout<<"    Nhap Loai( N hoac X)  ";
						SetBGColor(15);
						gotoxy(91,15);
						cout<<"                          ";
						
						SetBGColor(13);
						SetColor(0);
						gotoxy(62,17);
						cout<<"    Nhap Ngay Lap Hoa Don ";
						SetBGColor(15);
						gotoxy(91,17);
						cout<<"                          ";
						gotoxy(101,17);
						cout<<"/";
						gotoxy(106,17);
						cout<<"/";
						 //2 /3 /2017
						
					}
								
					while(1) 
					{
						
						SetBGColor(15);
						gotoxy(91,13);
						cout<<"                          ";
						gotoxy(95,13);
						SetColor(0);
						
						getline(cin,pHD->so_hd);
						
						if(pHD->so_hd.empty() || cin.fail())	
							{
									cin.clear();
									_flushall();
									BaoLoi("Ma so Hoa don khong hop le!!");
									continue;
							}
						if(pHD->so_hd.length()>20)
							{
								BaoLoi("Ma so Hoa don chi chua toi da 20 ki tu!!");
								continue;
							
							}
						if(kiem_ta_1_tu(pHD->so_hd)==0)
							{
								BaoLoi("Ma so Hoa don khong chua khoang trang!!");
								continue;
							}
						if(kiem_tra_so_hd(ds_nv,pHD->so_hd)==1) // ham nay tra ve 0 hoac 1
							{
								BaoLoi("Ma so Hoa don da ton tai!!");
								continue;
							}
										
						break;
					}
			
			
			
					
					
				while(true)
					{
						
						SetBGColor(15);
						gotoxy(91,15);
						cout<<"                          ";
						gotoxy(95,15);
						SetColor(0);
						getline(cin,loai);
						//chuan_hoa(ten);
						chuan_hoa(loai);
						
						if(loai.empty() || cin.fail())	
							{
									cin.clear();
									_flushall();
									BaoLoi("Loai khong hop le!!");
									continue;
							}
						
						if(loai.length()!=1)
							{
								BaoLoi("Loai chi nhan 1 ki tu duy nhat!!");
								continue;
							}
						if(loai!="N" && loai!="X")
							{
								BaoLoi("Loai chi nhan 1 ki tu X hoac N!!");
								continue;
							}
						
						pHD->loai=loai[0];
						break;			
					}
				
				Date date;
				
				Date date_system;
				date_system=dateSys();
				//int ngay,thang,nam;// bien tam de nhap
				
				//Nhap ngay thang nam
				while(true)
					{	
					
						SetColor(0);
						SetBGColor(15);
						gotoxy(91,17);
						cout<<"                          ";
						gotoxy(101,17);
						cout<<"/";
						gotoxy(106,17);
						cout<<"/";
						 //      2  / 3  / 2017
						
						//nhap
						gotoxy(98,17);
						cin>>date.ngay;
						cin.ignore();
						if(cin.fail()||date.ngay<=0||date.ngay>31)	
							{
									cin.clear();
									_flushall();
									BaoLoi("Ngay khong hop le ( 1->31 )!!");
									continue;
							}
						
						
						gotoxy(103,17);
						cin>>date.thang;
						cin.ignore();
						if(cin.fail()||date.thang<1||date.thang>12)	
							{
									cin.clear();
									_flushall();
									BaoLoi("Thang khong hop le!!( 1->12 )");
									continue;
							}
						
						gotoxy(108,17);
						cin>>date.nam;
						cin.ignore();
						if(cin.fail()||date.nam<1980||date.nam>date_system.nam)	
							{
									cin.clear();
									_flushall();
									BaoLoi("Nam khong hop le( Nam chi tu 1980 -> nam hien tai)!!");
									continue;
							}
						
						if(so_sanh_date(date,date_system)==1)
							{
								BaoLoi("Ngay lap Hoa don dang o Tuong Lai. Hay nhap lai!!");
								continue;
							}
						
						if(!validDate(date))
							{
								BaoLoi("Ngay thang nam khong hop le!!");
								continue;
							}
						
						pHD->ngay_lap_hd=date;
						break;
			
					}
				
				BaoLoi("Tao thong tin Hoa don thanh cong, Tiep tuc nhap Chi tiet Hoa don!!");
				//in danh sach ma vat tu
				
				//tiep tuc nhap DS_CTHD
				
				int flat_loai;
				if(pHD->loai=='N')
					flat_loai=1;   // Phieu nhap la 1
				else
					flat_loai=2;	  // Phieu xuat la 2
				
				nhap_ds_cthd(pHD->ds_CTHD,ds_vt.TREE,flat_loai);
				
				
				if(show_ds_cthd(pHD->ds_CTHD,ds_vt.TREE)==0)
				{
					// co nghia la da HUY BO HOA DON
					delete pHD;
				}
				else 
				{
					//Ghi Hoa don
					
					//Danh dau trang thai cac vat tu de khong the Xoa cac vat tu nay
					vat_tu *vt;
					for(int i=0;i<pHD->ds_CTHD.sl;i++)
					{
						vt=searchVT(ds_vt.TREE,pHD->ds_CTHD.ds[i].ma_vt);
						vt->kt=1;
						
						if(flat_loai==1) // La phieu Nhap
						{
							vt->so_luong_ton +=pHD->ds_CTHD.ds[i].so_luong;
							
						}
						else
						{
							vt->so_luong_ton -=pHD->ds_CTHD.ds[i].so_luong;
							
						}
						
					}
					
					
					//Danh dau nhan vien nay da lap Hoa don de ko the Xoa Nhan vien nay
					pNV->kt=1;
					
					//Them Hoa don nay vao Danh sach Hoa don cua pNV
					them_1_hd(pNV->danh_sach_hd.phead,pHD);
					// tang so luong Hoa don cua Nhan vien nay
					pNV->danh_sach_hd.sl++;
					
				}
				
											
			
		//BaoLoi("Da roi Ham Lap Hoa Don!!!!!!");
}









//[==============In va tra hang------- cau f va cau g ================]



int so_trang_cthd(int sl)
{
	if(sl%5==0)
		return sl/5;
	else
		return (sl/5 +1);
}




//Ham kiem tra So Hoa don trung from Tat ca hoa don cua tat ca nhan vien ( tra ve con tro HOA_DON do va ho ten NV do)
	HOA_DON* ptr_kiem_tra_so_hd(DS_NHAN_VIEN ds_nv,string x, string &sHo,string &sTen)
	{
		HOA_DON *p;
		
		for(int i=0;i<ds_nv.sl;i++)
		{
				for (p = ds_nv.ds[i]->danh_sach_hd.phead;  p  != NULL ; p=p->pnext )
	              if ( p->so_hd == x  ) 
	              {
	              	
	              	sHo=ds_nv.ds[i]->ho;
	              	sTen=ds_nv.ds[i]->ten;
				  	return p;
				  	
				  }
		}
		return NULL;
	}



void tra_hang_hd(HOA_DON *p,tree t)
{
	
	vat_tu *vt;
	int flat;
	
	if(p->loai=='N')
		flat=1;
	else flat =2;
	
	p->kt=0;//danh dau Hoa don nay da bi tra hang 
	for(int i=0;i<p->ds_CTHD.sl;i++)
		{
			p->ds_CTHD.ds[i].trang_thai=0;//khach tra cho tung CTHD
		}
		
		
	//xu ly so luong ton
	
	if(flat==1)
	{
		for(int i=0;i<p->ds_CTHD.sl;i++)
		{
			vt=searchVT(t,p->ds_CTHD.ds[i].ma_vt);
			vt->so_luong_ton -= p->ds_CTHD.ds[i].so_luong;
		}
	}
	else
	{
		for(int i=0;i<p->ds_CTHD.sl;i++)
		{
			vt=searchVT(t,p->ds_CTHD.ds[i].ma_vt);
			vt->so_luong_ton += p->ds_CTHD.ds[i].so_luong;
		}
	}
}


void in_tra_hoa_don (DS_NHAN_VIEN ds_nv,tree t,int flat)  // flat=1 la In hoa don ---flat=2 la Tra hang
				
{
	xoa_man_hinh_inside();
	ShowPointer();
	
	string sHo,sTen;
	string so_hd;
	HOA_DON *p;
	
	
	
	if(flat==1)
	{
	
		gotoxy(73,4);
		SetColor(4);
		SetBGColor(10);
		cout<<"                               ";
		gotoxy(73,5);
		cout<<"           IN HOA DON          ";
		gotoxy(73,6);
		cout<<"                               ";		
		Normal();
	
	
	}
	else
	{
		gotoxy(76,4);
		SetColor(4);
		SetBGColor(10);
		cout<<"                           ";
		gotoxy(76,5);
		cout<<"         TRA HANG          ";
		gotoxy(76,6);
		cout<<"                           ";		
		Normal();
	}
	
	

	while(1) 
	{
		SetBGColor(13);
		SetColor(0);
		
		gotoxy(55,15);
		cout<<" Nhap Ma So Hoa Don( q de thoat!)  ";
		
		SetBGColor(15);
		gotoxy(97,15);
		cout<<"                      ";
		gotoxy(101,15);
		SetColor(0);
		
		getline(cin,so_hd);
		
		if(so_hd.empty() || cin.fail())	
			{
					cin.clear();
					_flushall();
					BaoLoi("Ma so Hoa don khong hop le!!");
					continue;
			}
		if(so_hd=="q"||so_hd=="Q"||so_hd=="quit")
		{
			xoa_man_hinh_inside();
			return;
		
		}
			
		if(so_hd.length()>20)
			{
				BaoLoi("Ma so Hoa don chi chua toi da 20 ki tu!!");
				continue;
			
			}
		if(kiem_ta_1_tu(so_hd)==0)
			{
				BaoLoi("Ma so Hoa don khong chua khoang trang!!");
				continue;
			}
		
	
		p=ptr_kiem_tra_so_hd(ds_nv,so_hd,sHo,sTen);
		
		if(p==NULL)
			{
				BaoLoi("Ma so Hoa don khong ton tai!!");
				continue;
			}
						
		break;
	}
	
	
	//Kiem tra xem Hoa don nay da tra hang chu va thuoc Loai chuong trinh In hay tra hang
	
	if(flat==2) // Dang la Chuong trinh Tra Hang
	{
		if(p->kt==0) // Tuc la Hoa don nay da tra hang  -> thi thoat ra
		{
			BaoLoi("DA TRA HANG HOA DON NAY ROI!!");
			xoa_man_hinh_inside();
			return;
		}
	}
	
	
	//
	
	
	xoa_man_hinh_inside();
	
	int a=19;
	gotoxy(55,a);
	HidePointer();
	int soTrang;
	
	int gech;
	int b=0;
	int c;
	int i;
	int d;
	
	
	soTrang=so_trang_cthd(p->ds_CTHD.sl); // su dung cong thuc tinh so trang (1 trang co toi da 5 phan tu)
		
	
	while(1)
	{
				
		c=1;
		i=0;
		d=0;
		xoa_man_hinh_inside();
		//HidePointer();
		
		
		if(flat==1)
	{
	
		gotoxy(73,4);
		SetColor(4);
		SetBGColor(10);
		cout<<"                               ";
		gotoxy(73,5);
		cout<<"           IN HOA DON          ";
		gotoxy(73,6);
		cout<<"                               ";		
		Normal();
	
	
	}
	else
	{
		gotoxy(76,4);
		SetColor(4);
		SetBGColor(10);
		cout<<"                           ";
		gotoxy(76,5);
		cout<<"         TRA HANG          ";
		gotoxy(76,6);
		cout<<"                           ";		
		Normal();
	}
		
		
		//
		gotoxy(55,a-10);
		SetColor(12);
		cout<<"MA SO HOA DON: ";
		SetColor(15);
		cout<<p->so_hd<<"\t\t";
		
		
		// Kiem tra xem don hang nay da tra hang chua
		if(p->kt==0) //tinh trang da tra hang
		{
			SetColor(15);
			SetBGColor(4);
			cout<<" TINH TRANG: ";
			
			//SetBGColor(15);
			cout<<"DA TRA HANG ";
			
		}
		
		gotoxy(55,a-9);
		SetColor(12);
		SetBGColor(0);
		cout<<"LOAI HOA DON: ";
		SetColor(15);
		if(p->loai=='N')
			cout<<"Nhap";
		else
			cout<<"Xuat";
			
		gotoxy(55,a-8);
		SetColor(12);
		cout<<"NGAY LAP: ";
		SetColor(15);
		cout<<setw(2)<<setfill('0')<<p->ngay_lap_hd.ngay<<" / "<<setw(2)<<setfill('0')<<p->ngay_lap_hd.thang<<" / "<<setw(4)<<setfill('0')<<p->ngay_lap_hd.nam;
		
		gotoxy(55,a-7);
		SetColor(12);
		cout<<"NGUOI LAP HOA DON: ";
		SetColor(15);
		cout<<sHo<<" "<<sTen;
		
		//
		gotoxy(55,a-5);
		SetBGColor(14);
		SetColor(1);
		
		cout<<" DANH SACH CHI TIET HOA DON "; //in dong 5
	
	
		Normal();
		
		// In tu hang 14 ->
		gotoxy(45,a-4); 
		for(int i=45;i<135;i++)	
			cout<<"-"; //in dong 7
			
		SetColor(4);
		gotoxy(46,a-3);
		cout<<"STT";
		gotoxy(54,a-3);	//56	
		
		cout<<"Ma VT";//in dong 8
		gotoxy(71,a-3); //77
		cout<<"Ten Vat Tu";
		gotoxy(94,a-3);										
		cout<<"So Luong";
		gotoxy(110,a-3);
		cout<<"Don Gia";
		gotoxy(126,a-3);
		cout<<"%VAT";
	
		SetColor(15);
		
		gotoxy(45,a-3);
		cout<<"|";
		gotoxy(50,a-3);
		cout<<"|";
			
		gotoxy(63,a-3);
		cout<<"|";
		
		gotoxy(90,a-3);
		cout<<"|";
		
		gotoxy(106,a-3);
		cout<<"|";
		
		gotoxy(121,a-3);
		cout<<"|";
		gotoxy(134,a-3);
		cout<<"|";
	
		
		
		//hang duoi the hien cac nut dat biet
		if(flat==1) //in hoa don nen chi Co 2 Thong bao
		{
			gotoxy(75,32);
		}
		else //se Co 3 thong bao ben duoi de getch()
		{
			gotoxy(63,32);
		}	
		
		SetColor(13);
		cout<<"ESC: Thoat!!\t";
		SetColor(6);
		cout<<"TAB: Chuyen trang\t";
		
		
		if(flat==2) // day la thao tac Tra hang
		{
			SetColor(4);
			cout<<"DELETE: Tra hang!";
		
		}
		
		Normal();
	
	
	
	for(i=0+b;c!=6;i++,c++)
		{
			if(i>=p->ds_CTHD.sl)
				break;
			gotoxy(55,a+d);
			ThongTinCTHD(p->ds_CTHD.ds[i],t);
			
			gotoxy(45,a+d-1);
			cout<<"|";
			
			gotoxy(47,a+d-1);
			cout<<i+1;
			
			d=d+2;
		}
		
		
		
		SetColor(2);
		gotoxy(130,wherey()+3);
		cout<<"Trang ";
		if(b==0)
			cout<<1;	
		else 
			cout<<b/5+1;
			
		cout<<"/"<<soTrang;
		Normal();
		
		
		
		do
		{
		
			gech=getch();
			
			
			if(flat==2)  // day la chuong trinh Tra hang
			{
			
			
				if(gech==83) // Tra hang
				{
					//Neu ko the Tra hang do qua 3 ngay thi
					if(kiem_tra_tra_hang(p->ngay_lap_hd)==0)
					{
						BaoLoi("KHONG THE TRA HANG DO DA QUA 3 NGAY KE TU NGAY MUA!!");
						xoa_man_hinh_inside();
						return;
					}
					
					
					
					//Neu co the Tra hang thi dua ra thong bao ben duoi
					//xoa thong bao cu, thay thong bao moi	
					gotoxy(40,32);
					SetBGColor(0);
					cout<<"                                                                                                          ";
					
					gotoxy(59,32);
					SetColor(13);
					cout<<"CAC PHIM KHAC: Quay Lai!!\t\t";
					
					SetColor(4);
					cout<<"ENTER: Xac Nhan Tra Hang!";
					
					
					gech=getch();
					if(gech==13) //phim Enter
						{
							BaoLoi("Tra hang thanh cong!!");
							
							//thao tac tra hang
							tra_hang_hd(p,t);
							xoa_man_hinh_inside();
							return; //
						}
					else
						break;
				}
					
			}
			
		
			if(gech==27) // Thoat 
				{
					
					xoa_man_hinh_inside();
					return;
				}
			
			else if(gech==9)
				{
					if(i<p->ds_CTHD.sl)
					{
						b=b+5;
						
						break;
					}
					
					else if(i>=p->ds_CTHD.sl)
						{
							b=0;
							break;
							
						}
							
				}
			
			
			
			
			
			
		}while (1);	
	}
}
















//------==============IN HOA DON===========--------

//

//Xuat danh sach chi tiet hoa don
	void xuat_danh_sach_cthd(DS_CHI_TIET_HD ds_cthd,tree t)
	{
		vat_tu *p;
		for(int i=0;i<ds_cthd.sl;i++)
			{
				
				cout<<"\n\nVat tu thu "<<i+1;
				p=searchVT(t,ds_cthd.ds[i].ma_vt);
				cout<<"\nTen Vat tu: "<<p->ten_vt;
				cout<<"\nMa Vat tu: "<<ds_cthd.ds[i].ma_vt;
				cout<<"\nSo luong: "<<ds_cthd.ds[i].so_luong;
				cout<<"\nDon gia: "<<ds_cthd.ds[i].don_gia;
				cout<<"\n%VAT: "<<ds_cthd.ds[i].VAT*100<<"%";
			}
	}


	// cau g------IN HOA DON
	
	void in_hoa_don(DS_NHAN_VIEN ds_nv,DS_VAT_TU ds_vt)
	{
		string sHo,sTen; // bien luu ho va ten cua Nhan vien
		
		cout<<"\n=============In Hoa don===========\n";
		string so_hd;
		HOA_DON *p;
		
		while(1) 
			{
				cout<<"\nNhap so Hoa don ( Nhap 0 de thoat): ";
				cin>>so_hd;
				if(so_hd=="0")
					return;	
				if(so_hd.empty() || cin.fail()||so_hd.length()>20)	
					{
							cin.clear();
							_flushall();
							cout << "\nSo Hoa don khong hop le!!\n";
							continue;
	
					}
					
				
				p=ptr_kiem_tra_so_hd(ds_nv,so_hd,sHo,sTen);
				if(p==NULL)
				{
					cout<<"\nSo Hoa don khong ton tai!!\n";
					continue;
				}
				
				break;
			}
			
			cout<<"\nTHONG TIN HOA DON "<<so_hd<<endl;
			
			cout<<"\nNguoi lap: "<<sHo<<" "<<sTen;
			cout<<"\nLoai hoa don: ";
			if(p->loai=='N')
				cout<<"Nhap";
			else
				cout<<"Xuat";
			cout<<"\nNgay lap: "<<p->ngay_lap_hd.ngay<<"/"<<p->ngay_lap_hd.thang<<"/"<<p->ngay_lap_hd.nam;
			if(p->kt==1) //neu bang 1 co nghia la Hoa don nay da bi tra hang
				{
					cout<<"\nTrang thai: Da tra hang\n";		
				}
			
			
			cout<<"\nTHONG TIN CHI TIET HOA DON \n";
			
			xuat_danh_sach_cthd(p->ds_CTHD,ds_vt.TREE);
	}


// =========== cau f-----tra hang================
/*
void tra_hang(HOA_DON *p)
{
	p->kt=0;//danh dau Hoa don nay da bi tra hang 
	for(int i=0;i<p->ds_CTHD.sl;i++)
		{
			p->ds_CTHD.ds[i].trang_thai=0;//khach tra cho tung CTHD
		}
}
*/








// cau h: liet ke cac Hoa don do 1 nhan vien da lap trong khoang thoi gian

double tri_gia(CHI_TIET_HOA_DON cthd)
{
	double triGia=0.0;
	triGia=cthd.don_gia*cthd.so_luong*(1.0+cthd.VAT);
	return triGia;
}

void liet_ke_hd_time(HOA_DON *phead, Date startDate,Date endDate)
{
	int i;
	double triGia;
	for(HOA_DON *p=phead;p!=NULL;p=p->pnext )
	{
		//xu ly
		//if((so_sanh_date(startDate,p->ngay_lap_hd)==-1 || so_sanh_date(startDate,p->ngay_lap_hd)==0) && (so_sanh_date(endDate,p->ngay_lap_hd)==1 || so_sanh_date(endDate,p->ngay_lap_hd)==0))
		if(so_sanh_date(startDate,p->ngay_lap_hd) <=0  && so_sanh_date(endDate,p->ngay_lap_hd)>=0)
			{
			cout<<"\nHoa don XXX \n";
			for(i=0;i<p->ds_CTHD.sl;i++)
				{
					cout<<"\nMa vat tu: "<<p->ds_CTHD.ds[i].ma_vt;	
					cout<<"\nTri gia: "<<tri_gia(p->ds_CTHD.ds[i]);
					cout<<endl<<endl;
				
				}
			}
	}
}

// Tham so truyen vao ma DS,, khac voi truyen vao la mang con tro

NHAN_VIEN* searchNV_ptr(DS_NHAN_VIEN ds, int x) {
  for (int i =0; i < ds.sl ; i++)
     if (ds.ds[i]->ma_nv == x) return ds.ds[i];
  return NULL;
}




void cauH(DS_NHAN_VIEN ds_nv, DS_VAT_TU ds_vt)
{
	NHAN_VIEN *nv;
	Date startDate,endDate;
	cout<<endl;
	int ma_nv;
	while(1)
	{
		
		cout<<"\nNhap ma nhan vien:(0 de thoat!) ";
		cin >>ma_nv;
		if(ma_nv==0)
			return;
		//cout<<endl<<nv.ma_nv<<endl;
		cin.ignore();
		if(ma_nv<0 || ma_nv>9999 || cin.fail())	
			{
					cin.clear();
					_flushall();
					//cin.ignore();
					cout << "\nMa nhan vien khong hop le!!\n";
					continue;

			}
		nv=searchNV_ptr(ds_nv,ma_nv);
		if(nv==NULL)
		{
			cout<<"\nMa nhan vien nay khong ton tai!! Vui long nhap ma khac\n";
			continue;
		}
		else 
			break;
	}
	
	
	nhapDate(startDate);
	nhapDate(endDate);
	if(so_sanh_date(startDate,endDate)==1)
	{
		cout<<"\n2 ngay khong hop le!!\n";
		return;
	}
	
	
	liet_ke_hd_time(nv->danh_sach_hd.phead,startDate,endDate);
	
	
}
	


//=================Cau h ----------LIET KE HOA DON TRONG KHOAN THOI GIAN==============






void chi_tiet_hd_dscthd(HOA_DON *p,CHI_TIET_HOA_DON cthd,tree t)
{

	int y=wherey();
	
	gotoxy(40,y-1);
	for(int i=40;i<146;i++)
		{
			//SetBGColor();
			cout<<"-";
		}
		
	gotoxy(42,y);
	cout<<p->so_hd;
	gotoxy(53,y);
	cout<<setw(2)<<setfill('0')<<p->ngay_lap_hd.ngay<<"/"<<setw(2)<<setfill('0')<<p->ngay_lap_hd.thang<<"/"<<setw(4)<<setfill('0')<<p->ngay_lap_hd.nam;
	gotoxy(66,y);
	if(p->loai=='N')
		cout<<"Nhap";
	else
		cout<<"Xuat";
	gotoxy(73,y);
	cout<<cthd.ma_vt;
	gotoxy(84,y);
	cout<<ten_vat_tu(t,cthd.ma_vt);
	gotoxy(106,y);
	cout<<cthd.so_luong;
	gotoxy(115,y);
	cout<<cthd.don_gia;
	gotoxy(126,y);
	cout<<cthd.VAT*100.0<<"%";
	gotoxy(134,y);
	cout<<tri_gia(cthd);
	
	gotoxy(40,y);
	cout<<"|";
	gotoxy(52,y);
	cout<<"|";
	gotoxy(63,y);
	cout<<"|";
	gotoxy(71,y);
	cout<<"|";
	gotoxy(82,y);
	cout<<"|";
	gotoxy(104,y);
	cout<<"|";
	gotoxy(113,y);
	cout<<"|";
	gotoxy(125,y);
	cout<<"|";
	gotoxy(132,y);
	cout<<"|";
	gotoxy(145,y);
	cout<<"|";

	gotoxy(40,y+1);	
	for(int i=40;i<146;i++)
		{
			//SetBGColor();
			cout<<"-";
		}
}

void in_full_tt(string sHo,string sTen,Date startDate,Date endDate)
{
		xoa_man_hinh_inside();
		int a=19;
		
		gotoxy(69,6);
		SetColor(4);
		SetBGColor(10);
		cout<<"                                                      ";
		gotoxy(69,7);
		cout<<"   BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN    ";
		gotoxy(69,8);
		cout<<"                                                      ";		
		Normal();     
		
		
		
		
		
		
		gotoxy(70,10);
		cout<<"Tu ngay: ";
		SetColor(4);
		cout<<setw(2)<<setfill('0')<<startDate.ngay<<" / "<<setw(2)<<setfill('0')<<startDate.thang<<" / "<<setw(4)<<setfill('0')<<startDate.nam;
		SetColor(15);
		cout<<" \t ";
		//gotoxy(70,10);
		cout<<"Den ngay: ";
		SetColor(4);
		cout<<setw(2)<<setfill('0')<<endDate.ngay<<" / "<<setw(2)<<setfill('0')<<endDate.thang<<" / "<<setw(4)<<setfill('0')<<endDate.nam;
		
		gotoxy(70,12);
		SetColor(15);
		cout<<"Nhan vien: ";
		SetColor(4);
		cout<<sHo<<" "<<sTen;
		Normal();
		
		//====In bang=====
		
		
		gotoxy(40,a-4);
		for(int i=40;i<146;i++)
			{
				cout<<"-";
			}
		
		SetColor(4);
		gotoxy(43,a-3);
		cout<<"So HD";
		gotoxy(54,a-3);
		cout<<"Ngay Lap";
		gotoxy(64,a-3);
		cout<<"Loai HD";
		gotoxy(74,a-3);
		cout<<"Ma VT";
		gotoxy(88,a-3);
		cout<<"Ten Vat Tu";
		gotoxy(105,a-3);
		cout<<"So Luong";
		gotoxy(116,a-3);
		cout<<"Don Gia";
		gotoxy(127,a-3);
		cout<<"VAT";
		gotoxy(135,a-3);
		cout<<"Tri Gia";
		
		
		Normal();
		gotoxy(40,a-3);
		cout<<"|";
		gotoxy(52,a-3);
		cout<<"|";
		gotoxy(63,a-3);
		cout<<"|";
		gotoxy(71,a-3);
		cout<<"|";
		gotoxy(82,a-3);
		cout<<"|";
		gotoxy(104,a-3);
		cout<<"|";
		gotoxy(113,a-3);
		cout<<"|";
		gotoxy(125,a-3);
		cout<<"|";
		gotoxy(132,a-3);
		cout<<"|";
		gotoxy(145,a-3);
		cout<<"|";
		
		
		gotoxy(72,32);
		SetColor(13);
		cout<<"ESC: Thoat!!\t";
		SetColor(6);
		cout<<"\tTAB: Chuyen trang\t";
		
		Normal();
		
		
}















void liet_ke_hoa_don(DS_NHAN_VIEN ds_nv,tree t)

{
	xoa_man_hinh_inside();
	
	int ma_nv;	
	NHAN_VIEN *pNV;
	Date startDate,endDate;
	Date date_system=dateSys();
	HOA_DON *pHD;
	
	int gech; // bien dung de nhan ham getch()
	
	string sHo,sTen;
	
	
	
	
	
	
	//=====================BUOC NHAP DU LIEU=========================
	gotoxy(61,7);
	SetColor(4);
	SetBGColor(10);
	cout<<"                                                         ";
	gotoxy(61,8);
	cout<<"     LIET KE DANH SACH HOA DON TRONG KHOANG THOI GIAN    ";
	gotoxy(61,9);
	cout<<"                                                         ";		
	Normal();
	
	
	//Form nhap lieu
	{
		gotoxy(62,14);
		SetBGColor(13);
		SetColor(0);
		cout<<"  Nhap Ma So Nhan Vien( 0: thoat)  "; //24
		SetBGColor(15);
		gotoxy(103,14);
		cout<<"              ";
		
		SetBGColor(13);
		SetColor(0);
		gotoxy(62,18);
		cout<<"     Nhap Ngay Bat Dau    ";
		SetBGColor(15);
		gotoxy(91,18);
		cout<<"                          ";
		gotoxy(101,18);
		cout<<"/";
		gotoxy(106,18);
		cout<<"/";
		
		SetBGColor(13);
		SetColor(0);
		gotoxy(62,21);
		cout<<"     Nhap Ngay Ket Thuc   ";
		SetBGColor(15);
		gotoxy(91,21);
		cout<<"                          ";
		gotoxy(101,21);
		cout<<"/";
		gotoxy(106,21);
		cout<<"/";
		
		
	}
	
		
	
	while(1)
		{
			ShowPointer();
			gotoxy(62,14);
			SetBGColor(13);
			SetColor(0);
			cout<<"  Nhap Ma So Nhan Vien( 0: thoat)  "; //24
			SetBGColor(15);
			gotoxy(103,14);
			cout<<"              ";
			gotoxy(109,14);
			SetColor(0);
			cin>>ma_nv;
			cin.ignore();
			
			if( cin.fail())
				{
					cin.clear();
					_flushall();
					HidePointer();
					BaoLoi("Ma nhan vien khong hop le!!");
					continue;
				}
			
			if(ma_nv==0)
			{
					xoa_man_hinh_inside();
					return ;
			}
				
			if(ma_nv<0 || ma_nv>9999)	
				{
						cin.clear();
						_flushall();
						HidePointer();
						BaoLoi("Ma nhan vien khong hop le!!");
						continue;

				}
				
			pNV=searchNV_ptr(ds_nv,ma_nv);
			//p=ptr_kiem_tra_so_hd(ds_nv,so_hd,sHo,sTen);
		
			if(pNV==NULL)
			{
				HidePointer();
				BaoLoi("Ma nhan vien nay khong ton tai!!");
				continue;
			}
			
			else
			{
				
				
				gotoxy(72,16);
				SetBGColor(0);
				SetColor(15);
				cout<<"Ho va ten Nhan vien: ";
				SetColor(1);
				cout<<pNV->ho<<" "<<pNV->ten;
				
				sHo=pNV->ho;
				sTen=pNV->ten;
				
				
				if(pNV->danh_sach_hd.phead==NULL) // Co the dung pNV->kt==0 cung dc
					{
						BaoLoi("Nhan vien nay chua lap Hoa don!!");	
						//xoa thong bao ho ten nhan vien do
						gotoxy(70,16);
						Normal();
						cout<<"                                         ";
						continue;
						
					}
					
				
			}
			
			break;
		}
		
				
			
			//Nhap ngay bat dau ngay ket thuc
			
			while(1)
			{
				ShowPointer();
				SetBGColor(13);
				SetColor(0);
				gotoxy(62,18);
				cout<<"     Nhap Ngay Bat Dau    ";
				SetBGColor(15);
				gotoxy(91,18);
				cout<<"                          ";
				gotoxy(101,18);
				cout<<"/";
				gotoxy(106,18);
				cout<<"/";
				gotoxy(98,18);
				cin>>startDate.ngay;
				cin.ignore();
				if(cin.fail()||startDate.ngay<=0||startDate.ngay>31)	
					{
							cin.clear();
							_flushall();
							HidePointer();
							BaoLoi("Ngay khong hop le ( 1->31 )!!");
							continue;
					}
				
				
				gotoxy(103,18);
				cin>>startDate.thang;
				cin.ignore();
				if(cin.fail()||startDate.thang<1||startDate.thang>12)	
					{
							cin.clear();
							_flushall();
							HidePointer();
							BaoLoi("Thang khong hop le!!( 1->12 )");
							continue;
					}
				
				gotoxy(108,18);
				cin>>startDate.nam;
				cin.ignore();
				if(cin.fail()||startDate.nam<1980||startDate.nam>date_system.nam)	
					{
							cin.clear();
							_flushall();
							HidePointer();
							BaoLoi("Nam khong hop le( Nam chi tu 1980 -> nam hien tai)!!");
							continue;
					}
				
				if(so_sanh_date(startDate,date_system)==1)
					{
						HidePointer();
						BaoLoi("Ngay Bat dau dang o Tuong Lai. Hay nhap lai!!");
						continue;
					}
				if(so_sanh_date(startDate,date_system)==0)
					{
						HidePointer();
						BaoLoi("Ngay Bat dau khong duoc trung ngay Hien tai. Hay nhap lai!!");
						continue;
					}
				
				if(!validDate(startDate))
					{
						HidePointer();
						BaoLoi("Ngay thang nam khong hop le theo Lich!!");
						continue;
					}
				
				break;
			}
			
		while(1)
			{
				ShowPointer();
				SetBGColor(13);
				SetColor(0);
				gotoxy(62,21);
				cout<<"     Nhap Ngay Ket Thuc   ";
				SetBGColor(15);
				gotoxy(91,21);
				cout<<"                          ";
				gotoxy(101,21);
				cout<<"/";
				gotoxy(106,21);
				cout<<"/";
				gotoxy(98,21);
				cin>>endDate.ngay;
				cin.ignore();
				if(cin.fail()||endDate.ngay<=0||endDate.ngay>31)	
					{
							cin.clear();
							_flushall();
							HidePointer();
							BaoLoi("Ngay khong hop le ( 1->31 )!!");
							continue;
					}
				
				
				gotoxy(103,21);
				cin>>endDate.thang;
				cin.ignore();
				if(cin.fail()||endDate.thang<1||endDate.thang>12)	
					{
							cin.clear();
							_flushall();
							HidePointer();
							BaoLoi("Thang khong hop le!!( 1->12 )");
							continue;
					}
				
				gotoxy(108,21);
				cin>>endDate.nam;
				cin.ignore();
				if(cin.fail()||endDate.nam<1980||endDate.nam>date_system.nam)	
					{
							cin.clear();
							_flushall();
							HidePointer();
							BaoLoi("Nam khong hop le( Nam chi tu 1980 -> nam hien tai)!!");
							continue;
					}
				
				if(so_sanh_date(endDate,date_system)==1)
					{
						HidePointer();
						BaoLoi("Ngay Ket thuc dang o Tuong Lai. Hay nhap lai!!");
						continue;
					}
				if(so_sanh_date(startDate,endDate)==0)
					{
						HidePointer();
						BaoLoi("Ngay Ket thuc khong duoc trung ngay Bat dau. Hay nhap lai!!");
						continue;
					}	
				if(so_sanh_date(startDate,endDate)==1)  // Ngay bat dau ma lon hon ngay ket thuc thi Thong bao loi
					{
						HidePointer();
						BaoLoi("Ngay Ket thuc phai sau ngay Bat dau. Hay nhap lai!!");
						continue;
					}
				
				if(!validDate(endDate))
					{
						HidePointer();
						BaoLoi("Ngay thang nam khong hop le theo Lich!!");
						continue;
					}
				
				break;
			}	
	
	//==============HOAN THANH BUOC NHAP SO LIEU===============

	
	
	int dem=0,dem_cthd=0;
	
		for(HOA_DON *hd1=pNV->danh_sach_hd.phead;hd1!=NULL;hd1=hd1->pnext )
		{
			if(hd1->kt==1 && so_sanh_date(startDate,hd1->ngay_lap_hd) <=0  && so_sanh_date(endDate,hd1->ngay_lap_hd)>=0)
			{
				for(int k=0;k<hd1->ds_CTHD.sl;k++)
				{
					dem_cthd++;
				}
			}
		}
			
		
	
	//===================TOI BUOC XUAT DU LIEU=================	
	
	
	
	
	
	if(dem_cthd==0)
	{
		HidePointer();
		BaoLoi("Khong co Hoa don duoc lap trong khoang thoi gian tren!!");
		xoa_man_hinh_inside();
		return;
	}
	
		
		int a=19;
		gotoxy(55,a);
		HidePointer();
		int soTrang;
		
		//int gech;
		int b=0;
		int c;
		int i;
		int d;
		int while2=1;
		
		soTrang=so_trang_cthd(dem_cthd); // su dung cong thuc tinh so trang (1 trang co toi da 5 phan tu)
			
		c=1;
		i=0;
		d=0;
	
		//xoa_man_hinh_inside();
		HidePointer();

		xoa_man_hinh_inside();

		gotoxy(69,6);
		SetColor(4);
		SetBGColor(10);
		cout<<"                                                      ";
		gotoxy(69,7);
		cout<<"   BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN    ";
		gotoxy(69,8);
		cout<<"                                                      ";		
		Normal();     
		
		
		
		
		
		
		gotoxy(70,10);
		cout<<"Tu ngay: ";
		SetColor(4);
		cout<<setw(2)<<setfill('0')<<startDate.ngay<<" / "<<setw(2)<<setfill('0')<<startDate.thang<<" / "<<setw(4)<<setfill('0')<<startDate.nam;
		SetColor(15);
		cout<<" \t ";
		//gotoxy(70,10);
		cout<<"Den ngay: ";
		SetColor(4);
		cout<<setw(2)<<setfill('0')<<endDate.ngay<<" / "<<setw(2)<<setfill('0')<<endDate.thang<<" / "<<setw(4)<<setfill('0')<<endDate.nam;
		
		gotoxy(70,12);
		SetColor(15);
		cout<<"Nhan vien: ";
		SetColor(4);
		cout<<sHo<<" "<<sTen;
		Normal();
		
		//====In bang=====
		
		
		gotoxy(40,a-4);
		for(int i=40;i<146;i++)
			{
				cout<<"-";
			}
		
		SetColor(4);
		gotoxy(43,a-3);
		cout<<"So HD";
		gotoxy(54,a-3);
		cout<<"Ngay Lap";
		gotoxy(64,a-3);
		cout<<"Loai HD";
		gotoxy(74,a-3);
		cout<<"Ma VT";
		gotoxy(88,a-3);
		cout<<"Ten Vat Tu";
		gotoxy(105,a-3);
		cout<<"So Luong";
		gotoxy(116,a-3);
		cout<<"Don Gia";
		gotoxy(127,a-3);
		cout<<"VAT";
		gotoxy(135,a-3);
		cout<<"Tri Gia";
		
		
		Normal();
		gotoxy(40,a-3);
		cout<<"|";
		gotoxy(52,a-3);
		cout<<"|";
		gotoxy(63,a-3);
		cout<<"|";
		gotoxy(71,a-3);
		cout<<"|";
		gotoxy(82,a-3);
		cout<<"|";
		gotoxy(104,a-3);
		cout<<"|";
		gotoxy(113,a-3);
		cout<<"|";
		gotoxy(125,a-3);
		cout<<"|";
		gotoxy(132,a-3);
		cout<<"|";
		gotoxy(145,a-3);
		cout<<"|";
		
		
		gotoxy(72,32);
		SetColor(13);
		cout<<"ESC: Thoat!!\t";
		SetColor(6);
		cout<<"\tTAB: Chuyen trang\t";
		
		Normal();
		
		
		pHD=pNV->danh_sach_hd.phead;		
		
		//for(pHD=pNV->danh_sach_hd.phead;pHD!=NULL;pHD=pHD->pnext )
		
		while(pHD)
		{
			//xu ly
			
			if(pHD->kt==1&&so_sanh_date(startDate,pHD->ngay_lap_hd) <=0  && so_sanh_date(endDate,pHD->ngay_lap_hd)>=0)
				{
					b=0;				
					while2=1;
					while(while2==1)
					{
					for(i=0+b;c!=6;i++,c++)
						{
							
							if(i==pHD->ds_CTHD.sl)
								{
									//pHD=pHD->pnext;
									while2=0;
									break;
								}
							gotoxy(55,a+d);
							chi_tiet_hd_dscthd(pHD,pHD->ds_CTHD.ds[i],t);
							dem++;
							//Xoa cac dong lap lai cua Hoa don
							if(i!=0)
							{
								//SetBGColor(0);
								gotoxy(41,a+d-1);
								cout<<"           ";
								gotoxy(53,a+d-1);
								cout<<"          ";
								gotoxy(64,a+d-1);
								cout<<"       ";
								
							}
							
							d=d+2; // de xac dinh dong;
							
						}
						
					
					if(c==6||dem_cthd==dem)
					{
						
						SetColor(2);
						gotoxy(130,wherey()+3);
						cout<<"Trang ";
						
						
						if(dem%5==0)
							cout<<dem/5;	
						else 
							cout<<dem/5+1;
							
						cout<<"/"<<soTrang;
						Normal();
		

						
						
						
						while(1)
						
						{
						// se co 2 truong hop la
						//- van con phan tu trong vong for
						//-het phan tu
						gech=getch();
						if(gech==27)
							{
								xoa_man_hinh_inside();
								return;
							}
						else if(gech==9)
							{
								if(dem_cthd==dem)
								{
									//da toi trang cuoi
									xoa_man_hinh_inside();
									in_full_tt(sHo,sTen,startDate,endDate);
									d=0;
									c=1;
									b=0;
									//dem=0;
									//pHD=pNV->danh_sach_hd.phead;
									while2=0;
									break;
								}
								
								else if(i<pHD->ds_CTHD.sl)
								{
									xoa_man_hinh_inside();
									b=i;
									d=0;
									c=1;
									in_full_tt(sHo,sTen,startDate,endDate);
									
									break;
								}
								else
								{
									xoa_man_hinh_inside();
									//b=0;
									d=0;
									c=1;
									in_full_tt(sHo,sTen,startDate,endDate);
									while2=0;
									break;
								}
								
							}
						
						}
					}
	
					
					}	
						
					
				}
				
				
			pHD=pHD->pnext;
				
			if(dem==dem_cthd)
			{
				pHD=pNV->danh_sach_hd.phead;
				dem=0;
			}
				
				
		}
									
}		



// ===========THONG KE DOANH THU TRONG 1 NAM==============

//Phai la Hoa don Xuat va trong 1 nam da duoc kiem tra dieu kien.
double doanh_thu(HOA_DON *p)
{
	double dt=0;
	for(int i=0;i<p->ds_CTHD.sl;i++)
	{
		dt +=tri_gia(p->ds_CTHD.ds[i]);
	}
	return dt;
}



void thong_ke_doanh_thu_1_nam(DS_NHAN_VIEN ds_nv)
{
	xoa_man_hinh_inside();
	ShowPointer();
	
	int dt_nam;
	Date date_system=dateSys();
	
	double doanh_thu_thang[12];
	int gech;
	
	for(int i=0;i<12;i++)
	{
		doanh_thu_thang[i]=0;
	}
	
	
	
	SetColor(15);
	SetBGColor(2);
	gotoxy(78,10);
	cout<<"                                ";
	gotoxy(78,11);
	
	cout<<" THONG KE DOANH THU TRONG 1 NAM ";
	gotoxy(78,12);
	
	cout<<"                                ";
	
	
	
	while(1)
	{
	
				
		gotoxy(75,16);
		SetBGColor(13);
		SetColor(0);
		cout<<"  Nhap Nam( 0: thoat)  "; //24
		SetBGColor(15);
		gotoxy(101,16);
		cout<<"            ";
			
		gotoxy(104,16);
		cin>>dt_nam;
		if(cin.fail())
		{
			cin.clear();
			_flushall();
			BaoLoi("Nam khong hop le( Nam phai la Chu So)!!");
			continue;
		}	
		
		cin.ignore();
		if(dt_nam==0)
			{
				xoa_man_hinh_inside();
				return;
			}
			
				
		if(dt_nam<1980||dt_nam>date_system.nam)	
			{
					cin.clear();
					_flushall();
					BaoLoi("Nam khong hop le( Nam chi tu 1980 -> nam hien tai)!!");
					continue;
			}
	
		break;
	}
	
	
	
	
	
	//Tinh doanh thu cac thang
	HOA_DON *p;
	
	for(int i=0;i<ds_nv.sl;i++)
	{
		if(ds_nv.ds[i]->kt==1) // Tuc la Nhan vien da lap Hoa don
		{
			for(p=ds_nv.ds[i]->danh_sach_hd.phead;p!=NULL;p=p->pnext)
			{
				if(p->loai=='X' && p->kt==1 && p->ngay_lap_hd.nam==dt_nam)
				{
					doanh_thu_thang[p->ngay_lap_hd.thang-1] +=doanh_thu(p);
				}
			}
		}
	}
	
	
	
	int check=1; // Bien kiem tra xem trong Nam do co Doanh thu hay khong
	
	
	for(int i=0;i<12;i++)
	{
		if(doanh_thu_thang[i]>0)
			check=0;
			
	}
	
	if(check==1)
	{
		BaoLoi("Khong co Doanh thu trong nam do");
		xoa_man_hinh_inside();
		return;
		
	}
	
	
	
	
	//========Toi buoc xuat Du lieu
	
	HidePointer();
	xoa_man_hinh_inside();
	
	SetColor(15);
	SetBGColor(2);
	gotoxy(76,4);
	cout<<"                                  ";
	gotoxy(76,5);
	
	cout<<" BANG THONG KE DOANH THU NAM "<<dt_nam<<" ";
	gotoxy(76,6);
	
	cout<<"                                  ";
	
	
	Normal();
	SetColor(10);
	gotoxy(86,33);
	cout<<"ESC: Thoat!!";
	
	
	
	SetColor(13);
	gotoxy(79,8);
	cout<<"THANG";
	gotoxy(97,8);
	cout<<"DOANH THU";
	
	SetColor(15);
	for(int i=0;i<12;i++)
		{
			gotoxy(81,9+(i*2));
			cout<<i+1;
		}
	
	cout<<setprecision(0)<<fixed;
	for(int i=0;i<12;i++)
		{
			gotoxy(99,9+(i*2));
			cout<<doanh_thu_thang[i];
			if(doanh_thu_thang[i]>0)
				cout<<" vnd";
		}
	cout<<setprecision(1)<<fixed;
	
	
	do
	{
		gech=getch();
		
		if(gech==27)
			{
				xoa_man_hinh_inside();
				return;
			}
	}while(true);
	
	

}















//================GIAI PHONG VUNG NHO=================
void giai_phong(DS_VAT_TU &ds_vt,DS_NHAN_VIEN &ds_nv)
{
	//Giai phong DS Hoa Don
	giai_phong_dshd_all(ds_nv);
	//Giai phong DS Nhan Vien
	giai_phong_dsnv(ds_nv);
	//Giai phong DS Vat Tu
	giai_phong_dsvt(ds_vt.TREE);
	ds_vt.sl=0;
	
}

void giai_phong_dshd_all(DS_NHAN_VIEN &ds_nv)
{
	for(int i=ds_nv.sl-1;i>=0;i--)
	{
		giai_phong_dshd_1(ds_nv.ds[i]->danh_sach_hd);
	}
	
}

void giai_phong_dshd_1(DS_HOA_DON &ds_hd) // Lien ket don
{
	ds_hd.sl=0;
	
	HOA_DON *p;
	while(ds_hd.phead!=NULL)
	{
		p=ds_hd.phead;
		ds_hd.phead=ds_hd.phead->pnext;
		delete p; 
	}
}	

void giai_phong_dsnv(DS_NHAN_VIEN &ds_nv) //Mang con tro
{
	for(int i=ds_nv.sl-1;i>=0;i--)
	{
		delete ds_nv.ds[i];
	}
	ds_nv.sl=0;
}

void giai_phong_mct_vt(vat_tu *ds[],int &sl) //Mang con tro
{
	for(int i=sl-1;i>=0;i--)
	{
		delete ds[i];
	}
	sl=0;
}

void giai_phong_dsvt(vat_tu *root)
{
	//vat_tu *p=;
    if ( root == NULL )
        return;
 
    giai_phong_dsvt( root->pleft );
    giai_phong_dsvt( root->pright );
    delete root;

}




















//========================DATE==============



void nhapDate(Date &d)
{
    cout<<"\nNhap ngay thang nam: \n";
    cout<<"\nNgay: "; cin>>d.ngay;
    cout<<"\nThang: "; cin>>d.thang;
    cout<<"\nNam: "; cin>>d.nam;
}


void print(Date d)
{
	cout << setfill ('0') << setw(2) << d.ngay << "/"
	<< setfill ('0') << setw(2) <<d.thang << "/"
	<< setfill ('0') << setw(4) << d.nam << endl;
}
void nextDay(Date &d)
{
	d.ngay++;
	if (IS_LEAP_YEAR(d.nam))
	{
	    if (d.ngay > leap_month_table[d.thang-1])
		{
			d.ngay = 1;
			d.thang++;
		if (d.thang > 12)
		{
			d.thang = 1;
			d.nam++;
		}
		}
	}
	else
	{
		if (d.ngay > month_table[d.thang-1])
		{
			d.ngay = 1;
			d.thang++;
			if (d.thang > 12)
			{
				d.thang = 1;
				d.nam++;
			}
		}
	}
}
bool validDate(Date d)
{
	// validate dd/mm/yyyy
	if (d.nam < 1 || d.nam > 9999 ||	d.thang < 1 || d.thang > 12 || d.ngay < 1 || d.ngay > 31)
	{
		return false;
	}
	
	if (IS_LEAP_YEAR(d.nam))
	{
		if (d.ngay > leap_month_table[d.thang-1])
		{
			return false;
		}
	}
	else
	{
		if (d.ngay > month_table[d.thang-1])
		{
			return false;
		}
	}
	
	return true;
}

int so_sanh_date(Date d1,Date d2) //- Tra ve 0 neu date bang, 1 neu date1 lon hon date2--- Va -1 neu nguoc lai
{
    if(d1.nam==d2.nam)
    {
        if(d1.thang==d2.thang)
        {
            if(d1.ngay==d2.ngay)
                return 0;
            else if(d1.ngay>d2.ngay)
                return 1;
            else
                return -1;
        }
        else if(d1.thang>d2.thang)
            return 1;
        else
            return -1;


    }
    else if(d1.nam>d2.nam)
        return 1;
    else
        return -1;

    return 0;
}

int tra_hang(Date d1,Date d2) //d1 la moc ngay User tra hang------d2 la ngay lap Hoa don
{
    if(so_sanh_date(d1,d2)==0)
        return 1;// Co the tra hang

    for(int i=0;i<2;i++)
    {
        nextDay(d2);
        if(so_sanh_date(d1,d2)==0)
            return 1;// Co the tra hang
    }

    return 0;// khong the tra hang
}

int kiem_tra_tra_hang(Date d_HD) //d1 la moc ngay User tra hang------d2 la ngay lap Hoa don
{
	
	Date d_sys=dateSys();
	
    if(so_sanh_date(d_sys,d_HD)==0)
        return 1;// Co the tra hang

    for(int i=0;i<2;i++)
    {
        nextDay(d_HD);
        if(so_sanh_date(d_sys,d_HD)==0)
            return 1;// Co the tra hang
    }

    return 0;// khong the tra hang
}




Date dateSys()
{
    Date d;

    // current date/time based on current system
 time_t now = time(0);
 //cout << "Number of sec since January 1,1970:" << now << endl;
 tm *ltm = localtime(&now);

 // print various components of tm structure.
 //cout << "Year: "<< 1900 + ltm->tm_year << endl;
 //cout << "Month: "<< 1 + ltm->tm_mon<< endl;
 //cout << "Day: "<< ltm->tm_mday << endl;
 //cout << "Time: "<< 1 + ltm->tm_hour << ":";
 //cout << 1 + ltm->tm_min << ":";
 //cout << 1 + ltm->tm_sec << endl;
  d.ngay= ltm->tm_mday;
  d.thang= 1 + ltm->tm_mon;
  d.nam=1900 + ltm->tm_year;

    return d;
}

















//==========================DO HOA======================

void xoa_man_hinh_inside()
{
	for (int i = 3; i < 34; i++)
	{
		gotoxy(36, i);
		SetBGColor(0);
		printf("                                                                                                                  ");
		textcolor(7);
	}

}

void pain()  // t?o khung chuong trình
{
	//gotoxy(7,7);
	SetColor(4);
	SetBGColor(15);
	//cout<<"                      ";
	gotoxy(7,8);
	cout<<"         MENU         ";
	//gotoxy(7,9);
	//cout<<"                      ";
	//textcolor(7);
	SetColor(3);
	SetBGColor(3);
	char unsigned c = 205;  //?ng Ngang
	char unsigned d = 186;  // ?ng d?c
	char unsigned c1 = 201; // góc trái trên
	char unsigned c2 = 200; // góc trái du?i
	char unsigned c3 = 187; // góc ph?i trên 
	char unsigned c4 = 188; // góc ph?i du?i
	char unsigned c5 = 202; // ?ng cam lên
	char unsigned c6 = 203; // ?ng c?m xu?ng
	char unsigned c7 = 206; // ?ng D?u c?ng
	gotoxy(0, 0);
	int i;
	//?ng Bên Chi?u Dài Trên 
	for (i = 2; i < Console_Dai; i++)
	{
		gotoxy(i, 2);
		printf("%c", c);
	}
	gotoxy(1, 2); 
	printf("%c", c1);
	gotoxy(Console_Dai, 2); 
	printf("%c", c3);
	gotoxy(35, 2); 
	printf("%c", c6);
	textcolor(4);
	SetBGColor(7);
	gotoxy(62, 1);	
	printf("CHUONG TRINH QUAN LY NHAP XUAT VAT TU");
	textcolor(7);
	//?ng bên Chieu dài duoi

	textcolor(7);
	SetColor(3);
	for (i = 2; i <= Console_Dai; i++)
	{
		gotoxy(i, Console_Rong-6);
		printf("%c", c);
		if (i == 35)
		{
			gotoxy(i, Console_Rong);
			printf("%c", c5);
		}
		else if (i == Console_Dai)
		{
			gotoxy(1, Console_Rong);
			printf("%c", c2);
			//break;
		}
		if (i == Console_Dai)
		{
			gotoxy(i, Console_Rong);
			printf("%c", c4);
			break;
		}
	}
	// hang Bên Chieu rong
	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(1, i);
		printf("%c", 178);
	}
	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(Console_Dai, i);
		printf("%c", 178);
	}
	// hanng Giua
	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(35, i);
		printf("%c", d);
	}
	
	//hang cuoi
	SetColor(3);
	SetBGColor(3);
	for (i = 1; i < Console_Dai+1; i++)
	{
		gotoxy(i, Console_Rong+1);
		printf("%c", c);
	}
	
	//thong bao
	gotoxy (82,35);
	SetBGColor(15);
	SetColor(4);
	cout<<"===THONG BAO===";
	Normal();
	
	SetColor(5);
	gotoxy(6,36);
	cout<<"UP ARROW: ";
	SetColor(12);
	cout<<"LEN";
	gotoxy(6,37);
	SetColor(5);
	cout<<"DOWN ARROW: ";
	SetColor(12);
	cout<<"XUONG";
	gotoxy(6,38);
	SetColor(5);
	cout<<"ENTER: ";
	SetColor(12);
	cout<<"CHON";
	gotoxy(6,39);
	SetColor(5);
	cout<<"ESC: ";
	SetColor(12);
	cout<<"THOAT CHUONG TRINH";

	//gotoxy(1, 1);
	Normal();
}














void HidePointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
// Hien Con Tro
void ShowPointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}



//===========THOAT  CHUONG  TRINH======

void END()
{
	system("cls");
	gotoxy(77, 13);
	char s1[] = "END";
	SetColor(4);
	for (int i = 0; i < 3; i++)
	{
		Sleep(200);
		printf("%c", s1[i]);
	}
	Normal();
	gotoxy(69, 15);
	char s2[] = "----THANKS YOU----";
	for (int i = 0; i < 18; i++)
	{
		Sleep(150);
		printf("%c", s2[i]);
	}

}

void KhungExit()
{
	char unsigned c = 205;  //?ng Ngang
	char unsigned d = 186;  // ?ng d?c
	char unsigned c1 = 201; // góc trái trên
	char unsigned c2 = 200; // góc trái du?i
	char unsigned c3 = 187; // góc ph?i trên 
	char unsigned c4 = 188; // góc ph?i du?i
	char unsigned c5 = 202; // ?ng cam lên
	char unsigned c6 = 203; // ?ng c?m xu?ng

	gotoxy(0, 0);
	int i;
	textcolor(240);
	//?ng Bên Chi?u Dài Trên t
	for (i = 75; i < 110; i++)
	{
		gotoxy(i, 15);
		printf("%c", c);

	}
	gotoxy(75, 15); printf("%c", c1);
	gotoxy(110, 15); printf("%c", c3);
	//?ng Bên Chi?u Dài Du?i 
	for (i = 75; i < 110; i++)
	{
		gotoxy(i, 21);
		printf("%c", c);

	}
	gotoxy(75, 15); printf("%c", c1);
	gotoxy(110, 15); printf("%c", c3);
	/// ?ng Bên Chi?u r?ng
	for (i = 16; i < 21; i++)
	{
		gotoxy(75, i);
		printf("%c", d);

	}
	for (i = 16; i < 21; i++)
	{
		gotoxy(110, i);
		printf("%c", d);
	}
	gotoxy(75, 21); printf("%c", c2);
	gotoxy(110, 21); printf("%c", c4);

	for (int i = 76; i < 110; i++)
	{
		textcolor(255);
		gotoxy(i, 16);
		printf(" ");
		gotoxy(i, 18);
		printf(" ");
		gotoxy(i, 20);
		printf(" ");
	}
	gotoxy(76, 17); printf("        ");
	gotoxy(105, 17); printf("     ");
	gotoxy(76, 19); printf("             ");
	gotoxy(95, 19); printf("               ");
	gotoxy(94, 19); printf(" ");
	gotoxy(92, 19); printf(" ");
}


void ChangeColor(int x)
{
	switch (x)
	{
	case 89:
		textcolor(286);
		gotoxy(89, 19);
		printf("yes");
		textcolor(244);
		gotoxy(95, 19);
		printf("No");
		break;
	case 95:
		textcolor(286);
		gotoxy(95, 19);
		printf("No");
		textcolor(244);
		gotoxy(89, 19);
		printf("yes");
		break;
	}
}

void checkExit(int *Err1, char *look)
{
	KhungExit();
	textcolor(244);
	HidePointer();
	gotoxy(84, 17);
	printf("Do You Want To %s ?", look);
	gotoxy(89, 19);
	printf("yes");
	gotoxy(93, 19); printf("|");
	textcolor(286);
	gotoxy(95, 19);
	printf("No");


	int x = 95;
	int Nhap = 0;

	while (1)
	{
		fflush(stdin);
		Nhap = getch();
		switch (Nhap)
		{
		case 77:
			x -= 6;
			break;
		case 75:
			x += 6;
			break;
		}
		if (Nhap == 13)
		{
			switch (x)
			{
			case 95:
				*Err1 = 1; //no
				break;
			case 89:
				*Err1 = -1;  //yes
				break;
			}
		}
		if ((x > 95)) x = 89;
		if ((x < 89)) x = 95;
		// Chuy?n màu
		ChangeColor(x);
		if (Nhap == 13) break;
	}
	textcolor(15);
}
void XoaCheckExit()
{

	HidePointer();
	for (int i = 15; i < 23; i++)
	{
		gotoxy(40, i);
		textcolor(256);
		printf("                                                                         ");
		textcolor(7);
	}
	ShowPointer();

}










// dialog xoa nv, vt


void KhungExitXXX()
{
	char unsigned c = 205;  //?ng Ngang
	char unsigned d = 186;  // ?ng d?c
	char unsigned c1 = 201; // góc trái trên
	char unsigned c2 = 200; // góc trái du?i
	char unsigned c3 = 187; // góc ph?i trên 
	char unsigned c4 = 188; // góc ph?i du?i
	char unsigned c5 = 202; // ?ng cam lên
	char unsigned c6 = 203; // ?ng c?m xu?ng

	gotoxy(0, 0);
	int i;
	textcolor(240);
	//Canh Tren
	for (i = 75; i < 110; i++)
	{
		gotoxy(i, 22);
		printf("%c", c);

	}
	gotoxy(75, 22); printf("%c", c1);
	gotoxy(110, 22); printf("%c", c3);
	
	//?ng Bên Chi?u Dài Du?i 
	for (i = 75; i < 110; i++)
	{
		gotoxy(i, 28);
		printf("%c", c);

	}
	gotoxy(75, 22); printf("%c", c1);
	gotoxy(110, 22); printf("%c", c3);
	/// ?ng Bên Chi?u r?ng
	for (i = 23; i < 28; i++)
	{
		gotoxy(75, i);
		printf("%c", d);

	}
	for (i = 23; i < 28; i++)
	{
		gotoxy(110, i);
		printf("%c", d);
	}
	gotoxy(75, 28); printf("%c", c2);
	gotoxy(110, 28); printf("%c", c4);

	for (int i = 76; i < 110; i++)
	{
		textcolor(255);
		gotoxy(i, 23);
		printf(" ");
		gotoxy(i, 25);
		printf(" ");
		gotoxy(i, 27);
		printf(" ");
	}
	gotoxy(76, 24); printf("        ");
	gotoxy(105, 24); printf("     ");
	gotoxy(76, 26); printf("             ");
	gotoxy(95, 26); printf("               ");
	gotoxy(94, 26); printf(" ");
	gotoxy(92, 26); printf(" ");
}


void ChangeColorXXX(int x)
{
	switch (x)
	{
	case 89:
		textcolor(286);
		gotoxy(89, 26);
		printf("yes");
		textcolor(244);
		gotoxy(95, 26);
		printf("No");
		break;
	case 95:
		textcolor(286);
		gotoxy(95, 26);
		printf("No");
		textcolor(244);
		gotoxy(89, 26);
		printf("yes");
		break;
	}
}
void checkExitXXX(int *Err1, char *look)
{
	KhungExitXXX();
	textcolor(244);
	HidePointer();
	gotoxy(84, 24);
	printf("Do You Want To %s ?", look);
	gotoxy(89, 26);
	printf("yes");
	gotoxy(93, 26); printf("|");
	textcolor(286);
	gotoxy(95, 26);
	printf("No");


	int x = 95;
	int Nhap = 0;

	while (1)
	{
		fflush(stdin);
		Nhap = getch();
		switch (Nhap)
		{
		case 77:
			x -= 6;
			break;
		case 75:
			x += 6;
			break;
		}
		if (Nhap == 13)
		{
			switch (x)
			{
			case 95:
				*Err1 = 1; //no
				break;
			case 89:
				*Err1 = -1;  //yes
				break;
			}
		}
		if ((x > 95)) x = 89;
		if ((x < 89)) x = 95;
		// Chuy?n màu
		ChangeColorXXX(x);
		if (Nhap == 13) break;
	}
	textcolor(15);
}
void XoaCheckExitXXX()
{

	HidePointer();
	for (int i = 22; i < 30; i++)
	{
		gotoxy(40, i);
		textcolor(256);
		printf("                                                                         ");
		textcolor(7);
	}
	ShowPointer();

}





