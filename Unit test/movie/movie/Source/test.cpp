#include "pch.h"
#include "movie.hpp"
#include "gtest/gtest.h"
// Quan ly dat ve xem phim
// Them phim moi
// Danh sach phim
// Dat ve cho mot phim
// Kiem tra suc chua rap phim




TEST(PhimTest, ThemPhimVaXoaPhim)
{
    Phim phim1("Phim A", LoaiPhong::LOAI_THUONG);
    Phim phim2("Phim B", LoaiPhong::LOAI_TRUNG);
    Phim phim3("Phim C", LoaiPhong::LOAI_VIP);

    RapChieuPhim CGV;
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 0);

    CGV.themPhim(phim1);
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 1);

    CGV.themPhim(phim2);
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 2);

    ASSERT_EQ(CGV.xoaPhim(phim1), true);
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 1);

    ASSERT_EQ(CGV.xoaPhim(phim3), false);
    ASSERT_EQ(CGV.getDanhSachPhim().size(), 1);

}

TEST(PhimTest, DatVe)
{
    Phim phim1("Phim A", LoaiPhong::LOAI_THUONG);
    Phim phim2("Phim B", LoaiPhong::LOAI_TRUNG);
    Phim phim3("Phim C", LoaiPhong::LOAI_VIP);
    Phim phim4("Empty", LoaiPhong::LOAI_VIP);

    RapChieuPhim CGV;
    CGV.themPhim(phim1);
    CGV.themPhim(phim2);
    CGV.themPhim(phim3);

    ASSERT_EQ(CGV.getDanhSachPhim().at(0).getMaxSoVe(), 50);
    ASSERT_EQ(CGV.getDanhSachPhim().at(1).getMaxSoVe(), 100);
    ASSERT_EQ(CGV.getDanhSachPhim().at(2).getMaxSoVe(), 150);

    ASSERT_EQ(CGV.datVePhim(phim1, 10), true);
    ASSERT_EQ(CGV.getDanhSachPhim().at(0).getSoVeConLai(), 40);

    ASSERT_EQ(CGV.datVePhim(phim2, 30), true);
    ASSERT_EQ(CGV.getDanhSachPhim().at(1).getSoVeConLai(), 70);

    ASSERT_EQ(CGV.datVePhim(phim3, 25), true);
    ASSERT_EQ(CGV.getDanhSachPhim().at(2).getSoVeConLai(), 125);

    ASSERT_EQ(CGV.datVePhim(phim4, 2), false);
}

TEST(PhimTest, SucChua)
{
    Phim phim1("Phim A", LoaiPhong::LOAI_THUONG);
    Phim phim2("Phim B", LoaiPhong::LOAI_TRUNG);
    Phim phim3("Phim C", LoaiPhong::LOAI_VIP);

    RapChieuPhim Galaxy;

    Galaxy.themPhim(phim1);
    ASSERT_EQ(Galaxy.getSucChuaRapPhim(), 50);

    Galaxy.themPhim(phim2);
    ASSERT_EQ(Galaxy.getSucChuaRapPhim(), 150);

    Galaxy.themPhim(phim3);
    ASSERT_EQ(Galaxy.getSucChuaRapPhim(), 300);

    ASSERT_EQ(Galaxy.xoaPhim(phim2), true);
    ASSERT_EQ(Galaxy.getSucChuaRapPhim(), 200);


}


