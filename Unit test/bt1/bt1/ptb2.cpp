#include "pch.h"
#include <iostream>
#include <math.h>
#include "ptb2.hpp"

using namespace std;


KetQua giaiPhuongTrinhBacHai(float a, float b, float c) {
	KetQua result;
	float delta = b * b - 4 * a * c;

	if (delta < 0) {
		result.status = VO_NGHIEM;
	}
	else if (delta == 0) {
		result.status = NGHIEM_KEP;
		result.x1 = result.x2 = -b / (2 * a);
	}
	else {
		result.status = HAI_NGHIEM;
		result.x1 = (-b + sqrt(delta)) / (2 * a);
		result.x2 = (-b - sqrt(delta)) / (2 * a);
	}

	return result;
}