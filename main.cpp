#include "xu_ly.h"

const int so_item =11;
const int dong =11;
const int cot = 5 ;
const int Up = 72;
const int Down = 80;

char thucdon [so_item][50] = {"1. THEM NHAN VIEN",
			                  "2. DANH SACH NV VA DIEU CHINH",
			                  "3. THEM VAT TU",
			                  "4. DANH SACH VT VA DIEU CHINH",
			                  "5. LAP HOA DON",
			                  "6. IN HOA DON",
			                  "7. TRA HANG",
			                  "8. LIET KE CAC HOA DON",
			                  "9. THONG KE DOANH THU",
			                  "10. LUU DU LIEU",
			                   "11. Ket thuc chuong trinh  "};


int MenuDong(char td [so_item][50]){
  Normal();
  int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
  HidePointer();
    
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  				else
  				{
  					Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon=so_item-1;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];	
				}
				  
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  else
  				{
  					Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon=0;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];	
				}
  			  break;
  	case 13 : return chon+1;
  	
  	case 27 :	return so_item;
  		
  }  // end switch
  } while (1);
}

//=================== HAM MAIN ================

int main(int argc, char** argv) {
	
		
  int chon;  
  DS_NHAN_VIEN ds_nv;
  DS_VAT_TU ds_vt;
  docFile_Vat_Tu(ds_vt);
  docFile_Nhan_Vien(ds_nv);
  
  cout<<setprecision(1)<<fixed;
  do
  {
  	pain();
  	HidePointer();
  	//xoa_man_hinh_inside();
  	
    chon = MenuDong (thucdon);
    switch (chon ){
	    	
    case 1: 
			nhapDSNV(ds_nv,1) ;
    		break;
    		
    case 2: 
			xuat_DSNV(ds_nv.ds,ds_nv.sl);
			break;
			 
    case 3: 
		{ 
			nhap_vat_tu(ds_vt);	
			break;
			
	    };
	    
	case 4: 
		{ 
			xoa_man_hinh_inside();
			HidePointer();
			xuat_ds_vat_tu_giam(ds_vt);
			xoa_man_hinh_inside();
			break;
	    };    
	    
    case 5:
    	lap_hoa_don(ds_vt,ds_nv);
		break;
		
    case 6:	
    	in_tra_hoa_don(ds_nv,ds_vt.TREE,1);
	    break;
	    
	case 7:
		in_tra_hoa_don(ds_nv,ds_vt.TREE,2);
		break;
		
	case 8:
		
		liet_ke_hoa_don(ds_nv,ds_vt.TREE);
		break;
		
	case 9:
		thong_ke_doanh_thu_1_nam(ds_nv);
		break;
		
    case 10:
    	ghiFile_Vat_Tu(ds_vt);
		ghiFile_Nhan_Vien(ds_nv);
		BaoLoi("LUU DU LIEU THANH CONG!!");
		break;

	
    case so_item:
    	{
			/*
    		xoa_man_hinh_inside();
    		
    		gotoxy(70,32);
    		cout<<" ";
    	
	     	giai_phong(ds_vt,ds_nv);
	     	system("cls");
	     	return 0;
	     	*/
	     	
	     	int Err;
			checkExit(&Err, "Exit");
			if (Err == -1)
			{
				giai_phong(ds_vt,ds_nv);
				END();
				getch();
				return 0;
			}
			else
			{
				XoaCheckExit();
				HidePointer();
				break;
			}
 	
 	
	     	
	 	}
   }
  } while (1);
  

  return 0;	
}



