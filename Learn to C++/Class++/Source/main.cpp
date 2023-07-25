#include <iostream>
#include <string>

using namespace std;

class DoiTuong
{
protected:
    string TEN;
    int NAM_SINH;
    int TUOI;
    string DIA_CHI;
    int tinhTuoi(int namSinh);

public:
    void hienThi();
    void ThemThongTin(string ten, int namSinh, string dia_chi);
};
int DoiTuong::tinhTuoi(int namSinh)
{
    return 2023 - namSinh;
}
void DoiTuong::ThemThongTin(string ten, int namSinh, string dia_chi)
{
    TEN = ten;
    NAM_SINH = namSinh;
    DIA_CHI = dia_chi;
}

void DoiTuong::hienThi()
{
    cout << "Ten: " << TEN << endl;
    cout << "Nam sinh: " << NAM_SINH << endl;
    cout << "Dia chi: " << DIA_CHI << endl;
    cout << "Tuoi: " << tinhTuoi(NAM_SINH) << endl;
}
class SinhVien : public DoiTuong
{
private:
    int MSSV;

public:
    SinhVien();
    int getMSSV();
    void ThemThongTin(string ten, int namSinh, string dia_chi);
    void hienThi();
};
SinhVien::SinhVien()
{
    static int mssv = 100;
    MSSV = mssv;
    mssv++;
}
int SinhVien::getMSSV()
{
    return MSSV;
}
void SinhVien::ThemThongTin(string ten, int namSinh, string dia_chi)
{
    TEN = ten;
    NAM_SINH = namSinh;
    DIA_CHI = dia_chi;
}
void SinhVien::hienThi()
{
    cout << "Ten: " << TEN << endl;
    cout << "Nam sinh: " << NAM_SINH << endl;
    cout << "Dia chi: " << DIA_CHI << endl;
    cout << "Tuoi: " << tinhTuoi(NAM_SINH) << endl;
}

int main(int argc, char const *argv[])
{
    DoiTuong dt;
    SinhVien sv;
    dt.ThemThongTin("Phuong", 2002, "Bien Hoa");
    dt.hienThi();
    sv.ThemThongTin("Khoi", 2000, "quan 10");
    sv.hienThi();
    return 0;
}