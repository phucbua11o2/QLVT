#include "ctdl.h"




void chuan_hoa(string &a);
int kiem_ta_so_cmnd(string x);
int kiem_ta_1_tu(string x);

//===============Chuan hoa chu==============

void chuan_hoa(string &a)
{
	//xu ly khoang trang dau va cuoi
	while(a[0]==' ')
	{
		a.erase(a.begin() + 0);
	}
	while(a[a.length()-1]==' ')
	{
		a.erase(a.begin() + (a.length()-1));
	}
	//xoa khoang trang giua
	for(int i=0;i<a.length();i++)
	{
		if(a[i]==' ' && a[i+1]==' ')
			{
				a.erase(a.begin()+i);
				i--;
			}
	}
	//chuan hoa ki tu
	if(a[0]>=97 && a[0]<=122)
	{
		a[0] -=32;
	}
	for(int i=1;i<a.length();i++)
	{
		if(a[i]==' ')
		{
			i++;
			if(a[i] >=97 && a[i]<=122)
			{
				a[i]-=32;
			}
		}
		else
		{
			if(a[i]>=65 && a[i]<=90)
				{
					a[i]+=32;
				}
		}
	}
	
}


int kiem_ta_1_tu(string x)  //la kiem tra tra ve 1 khi khong co bat ky khoang trang nao du o vi tri nao di nua
{
	for(int i=0;i<x.length();i++)
			{
				if(x[i]==' ')
					return 0;
			}
	return 1;
}






int kiem_ta_so_cmnd(string x)
{
	for(int i=0;i<x.length();i++)
			{
				if(x[i]>57||x[i]<48)
					return 0;
			}
	return 1;
}


void thanh_chu_thuong(string &x)
{
	for(int i=0;i<x.length();i++)
			{
				if(x[i]>=65 && x[i]<=90)
					x[i] +=32;
			}
}


