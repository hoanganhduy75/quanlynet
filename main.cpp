#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
string random_string()
{
    char alpha_num[35] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z' ,
                          '1', '2', '3', '4', '5','6','7','8','9'};
    string random = "";
    for (int i = 0; i < 8; i++)
    {
        random = random + alpha_num[rand() % 33];
    }
    return random;
}
struct maytinh
{
    int ma_may;
    bool tinh_trang;
};
struct using_com
{
    string ma_kh;
    int ma_may;
    time_t start;
    time_t end;
};
struct used_com
{
    string ma_kh;
    int ma_may;
    time_t start;
    time_t end;
    int tien;
    float hours;
};
vector <used_com> used_computer;
vector <using_com> using_computer;
class quanlynet
{
private:
    int m;
    int n;
public:
    void set_m();
    void set_n();
    int get_m();
    int get_n();
    quanlynet();
    ~quanlynet();
};
void quanlynet::set_m()
{
    cout << "Nhap m:";
    cin >> m;
}
void quanlynet::set_n()
{
    cout << "Nhap n:";
    cin >> n;
}
int quanlynet::get_m()
{
    return m;
}
int quanlynet::get_n()
{
    return n;
}
quanlynet::quanlynet()
{
}
quanlynet::~quanlynet()
{
}

void option1(int m, int n, maytinh **may, fstream &wFile)
{
    using_com a;
    a.ma_kh = random_string();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (may[i][j].tinh_trang == true)
            {
                a.ma_may = may[i][j].ma_may;
                may[i][j].tinh_trang = false;
                a.start = time(0);
                a.end = 0;
                cout << a.ma_kh << "\n" << a.ma_may << "\n" << a.start << "\n" << a.end << endl;
                using_computer.push_back(a);
                return;
            }
        }
    }
}
void option2(int m, int n, maytinh **may, fstream &wFile)
{
    time_t hour;
    int ma_may;
    cout << "Nhap ma may can tinh tien: ";
    cin >> ma_may;
    
    for (int i = 0; i < using_computer.size(); i++)
    {
        if (using_computer[i].ma_may == ma_may)
        {
            used_com a;
            using_computer[i].end = time(0);
            hour = using_computer[i].end - using_computer[i].start;
            a.start = using_computer[i].start;
            a.end = using_computer[i].end;
            cout << "Ma KH:" << using_computer[i].ma_kh << endl;
            a.ma_kh = using_computer[i].ma_kh;
            cout << "Ma may:" << using_computer[i].ma_may << endl;
            a.ma_may = using_computer[i].ma_may;
            float h = (hour / 3600) % 24;
            cout << "Thoi gian:" << h << endl;
            int tien = 0;
            if (h > 1)
            {
                a.hours = abs(h);
                tien = (h-1)*3+6;
            }
            if (h < -1)
            {
                h = 24 - h;
                tien = (h-1)*3+6;
                a.hours = abs(h);
            }
                          
            if (h > 0 && h <2 )
            {
                tien = h*6;
                a.hours = abs(h);
            }
            if (h < 0 && h >-2 )
            {
                h = 24 - h;
                tien = h*6;
                a.hours = abs(h);
            }
            a.tien = tien;
            cout << "Thanh tien:" << tien << endl;
            using_computer.erase(using_computer.begin()+i);
            used_computer.push_back(a);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (may[i][j].ma_may == ma_may)
                    {
                        may[i][j].tinh_trang = true;
                    }
                }
            }
        }
        for (int i = 0; i < used_computer.size(); i++)
        {
            wFile << "Ma khach hang:";
            wFile << used_computer[i].ma_kh;
            wFile << endl;
            wFile << "Ma may:";
            wFile << used_computer[i].ma_kh;
            wFile << endl;
            wFile << "So gio:";
            wFile << used_computer[i].hours;
            wFile << endl;
            wFile << "Tien:";
            wFile << used_computer[i].tien;
            wFile << endl;
        }
    }
}
void option3(int m, int n, maytinh **may, fstream &wFile)
{
    cout << "Cac may da dung xong:" << used_computer.size() << endl;
    int tongtien = 0;
    for (int i = 0; i < used_computer.size(); i++)
    {
        tongtien += used_computer[i].tien;
    }
    cout << "Tong tien:" << tongtien << "\n" << endl;
    for (int i = 0; i < used_computer.size(); i++)
    {
        cout << "Ma khach hang: " << used_computer[i].ma_kh << endl;
        cout << "Ma ma may: " << used_computer[i].ma_may << endl;
        cout << "Ma thanh tien: " << used_computer[i].tien << endl;
        cout << endl;
    }
}
void option4(int m, int n, maytinh **may, fstream &wFile)
{
    cout << "So do cac may:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (may[i][j].tinh_trang ==  true)
                cout << "O ";
            else cout << "X ";
        }
        cout << endl;
    }
}
bool menu(int m, int n, maytinh **may, fstream &wFile)
{
    int option;
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "3. Option 3" << endl;
    cout << "4. Option 4" << endl;
    cout << "5. Exit" << endl;
    cout << "Chon 1 option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        option1(m, n, may,wFile);
    return true;
        break;
    case 2:
        option2(m, n, may,wFile);
    return true;
        break;
    case 3:
         option3(m, n, may,wFile);
    return true;
        break;
    case 4:
         option4(m, n, may,wFile);
    return true;
        break;
    default:
        return false;
        break;
    }
}

int main()
{
    srand(time_t(0));
    quanlynet quanly;
    quanly.set_m();
    quanly.set_n();
    int m = quanly.get_m();
    int n = quanly.get_n();
    maytinh **may = new maytinh *[m];
    for (int i = 0; i < m; i++)
    {
        may[i] = new maytinh [n];
    }
    int count = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            may[i][j].ma_may = count;
            may[i][j].tinh_trang = true;
            count++;
        }
    }

    fstream wFile("/Users/yudhna_/file.txt", ios::out);
    while (menu(m,n,may,wFile))
    {
    }

    for (int i = 0; i < m; i++)
    {
        delete [] may[i];
    }
    delete []may;
    may = nullptr;
    wFile.close();
}
