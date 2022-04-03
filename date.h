





int month_table[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_month_table[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//check leap year or not
#define IS_LEAP_YEAR(year) ((year%400 == 0) || (year%4 == 0 && year%100 != 0))? true : false

//public:
//Date(int d = 0, int m = 0, int y = 0): day(d), month(m), year(y)

//~Date()

void nhapDate(Date &d)
{
    cout<<"\nNhap ngay thang nam: \n";
    cout<<"\nNgay: "; cin>>d.ngay;
    cout<<"\nThang: "; cin>>d.thang;
    cout<<"\nNam: "; cin>>d.nam;
    cin.ignore();
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
if (d.nam < 1 || d.nam > 9999 ||
d.thang < 1 || d.thang > 12 ||
d.ngay < 1 || d.ngay > 31)
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

int so_sanh_date(Date d1,Date d2) //- Tra ve 0 neu date bang, 1 neu date1 lon hơn date2--- Va -1 neu nguoc lai
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
    if(so_sanh_date(d1,d2)==1)
        return 1;// Co the tra hang

    for(int i=0;i<2;i++)
    {
        nextDay(d2);
        if(so_sanh_date(d1,d2)==0)
            return 1;// Co the tra hang
    }

    return 0;// khong the tra hang
}


Date date()
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

