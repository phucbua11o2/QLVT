#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <fstream>
#include <iomanip>
#include<ctime>
#include "mylib.h"
using namespace std;
#define MAX_CTHD 20 
#define MAX_NV 500

//==========Dinh nghia cau truc ngay/thang/nam=====================================================================

typedef struct Date {
	int ngay;
	int thang;
	int nam;
};


//==========Danh sach CHI TIET HOA DON ----- Mang tuyen tinh (cap phat tinh, toi da 20 phan tu)=====================

struct chi_tiet_hoa_don {
	string ma_vt;
	double so_luong;
	double don_gia;
	double VAT;
	int trang_thai=1; // 1 Mac dinh la khach mua      0. khach tra
};
typedef struct chi_tiet_hoa_don CHI_TIET_HOA_DON;


struct ds_chi_tiet_hd {
	CHI_TIET_HOA_DON ds[MAX_CTHD];
	int sl=0;
};
typedef struct ds_chi_tiet_hd DS_CHI_TIET_HD;



//==========Danh sach HOA DON ----- Lien ket don====================================================================

struct hoa_don {
	string so_hd;
	Date ngay_lap_hd;
	char loai;//X: xuat ----- N:nhap
	int kt=1; // 1: Trang thai Hoa don binh thuong--- 0: Khach da tra hang Hoa don nay
	DS_CHI_TIET_HD ds_CTHD;
	hoa_don *pnext;
};
typedef struct hoa_don HOA_DON;


struct ds_hoa_don {
	HOA_DON *phead=NULL;
	int sl=0;
	};
typedef struct ds_hoa_don DS_HOA_DON;

//==========Danh sach VAT TU - Cay nhi phan====================================================================

 struct vat_tu {
	string ma_vt;
	string ten_vt;
	string don_vi_tinh;
	double so_luong_ton;
	int kt=0;//0--mac dinh la co the xoa duoc//khi tao hoa don se =1
	vat_tu* pleft;
	vat_tu* pright;
};
typedef struct vat_tu* tree;
 
struct ds_vat_tu {
	tree TREE=NULL;
	int sl=0;
};
typedef struct ds_vat_tu DS_VAT_TU;

//==========Danh sach NHAN VIEN ----- Mang con tro==================================================================

struct nhan_vien {
	int ma_nv;
	string ho;
	string ten;
	string phai;
	string cmnd;
	int kt=0;//----O mac dinh la Nhan vien chua lap Hoa don-----1 la Nhan vien do da lap Hoa don
	DS_HOA_DON danh_sach_hd;
};
typedef struct nhan_vien NHAN_VIEN;

struct ds_nhan_vien {
	
	NHAN_VIEN *ds[MAX_NV];
	int sl=0;

};
typedef struct ds_nhan_vien DS_NHAN_VIEN;
