#include "pch.h"
#include <gtest/gtest.h>
#include "ptb2.hpp"


TEST(giaiPhuongTrinhBacHai, VO_NGHIEM) {
	KetQua kq = giaiPhuongTrinhBacHai(1, 0, 1);
	ASSERT_EQ(0, VO_NGHIEM);
}

TEST(giaiPhuongTrinhBacHai, NGHIEM_KEP) { 
	KetQua kq = giaiPhuongTrinhBacHai(1, -2, 1);
	ASSERT_EQ(kq.status, NGHIEM_KEP);
	ASSERT_FLOAT_EQ(kq.x1, 1.0);
	ASSERT_FLOAT_EQ(kq.x2, 1.0);
}

TEST(giaiPhuongTrinhBacHai, HAI_NGHIEM) {
	KetQua kq = giaiPhuongTrinhBacHai(1, -5, 6);
	ASSERT_EQ(kq.status, HAI_NGHIEM);
	ASSERT_FLOAT_EQ(kq.x1, 3.0);
	ASSERT_FLOAT_EQ(kq.x2, 2.0);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}