#include "pch.h"
#include <string>
#include <vector>
using namespace std;

enum class LoaiPhong {
    LOAI_THUONG,
    LOAI_TRUNG,
    LOAI_VIP
};

class Phim {
public:
    Phim(string ten, LoaiPhong loai);
    string getTen();
    LoaiPhong getLoaiPhong();
    int getSoVeDaDat();
    int getSoVeConLai();
    bool datVe(int soLuong);
    int getMaxSoVe();
private:
    string ten;
    LoaiPhong loai;
    int soVeDaDat;
};

Phim::Phim(string ten, LoaiPhong loai) : ten(ten), loai(loai), soVeDaDat(0) {}

string Phim::getTen() {
    return ten;
}

LoaiPhong Phim::getLoaiPhong() {
    return loai;
}

int Phim::getSoVeDaDat() {
    return soVeDaDat;
}

int Phim::getSoVeConLai() {
    return getMaxSoVe() - getSoVeDaDat();
}

bool Phim::datVe(int soLuong) {
    if (soLuong <= 0 || soLuong > getSoVeConLai()) {
        return false;
    }

    soVeDaDat += soLuong;
    return true;
}

int Phim::getMaxSoVe() {
    switch (loai)
    {
    case LoaiPhong::LOAI_THUONG:
        return 50;
        break;
    case LoaiPhong::LOAI_TRUNG:
        return 100;
        break;
    case LoaiPhong::LOAI_VIP:
        return 150;
        break;
    default:
        return 0;
        break;
    }
}

class RapChieuPhim
{
public:
    void themPhim(Phim phim);
    vector <Phim> getDanhSachPhim();
    bool xoaPhim(Phim phim);
    bool datVePhim(Phim phim, int soLuong);
    int getSucChuaRapPhim();

private:
    vector <Phim> DanhSachPhim;
};

void RapChieuPhim::themPhim(Phim phim)
{
    DanhSachPhim.push_back(phim);
}

vector <Phim> RapChieuPhim::getDanhSachPhim()
{
    return DanhSachPhim;
}

bool RapChieuPhim::xoaPhim(Phim phim)
{
    vector <Phim> ::iterator it, ptr;
    bool checkPhim = false;
    for (it = DanhSachPhim.begin(); it != DanhSachPhim.end(); ++it)
    {
        if ((*it).getTen() == phim.getTen() && (*it).getLoaiPhong() == phim.getLoaiPhong())
        {
            ptr = it;
            checkPhim = true;
        }
    }

    if (checkPhim == true)
    {
        DanhSachPhim.erase(ptr);
        return true;
    }

    return false;

}

bool RapChieuPhim::datVePhim(Phim phim, int soLuong)
{
    vector <Phim> ::iterator it, ptr;
    bool checkDatVe = false;
    for (it = DanhSachPhim.begin(); it != DanhSachPhim.end(); ++it)
    {
        if ((*it).getTen() == phim.getTen() && (*it).getLoaiPhong() == phim.getLoaiPhong())
        {

            if ((*it).datVe(soLuong))
            {
                checkDatVe = true;
            }
        }
    }

    return checkDatVe;
}

int RapChieuPhim::getSucChuaRapPhim()
{
    int sucChua = 0;
    for (auto it : DanhSachPhim)
    {
        sucChua += it.getMaxSoVe();
    }
    return sucChua;
}