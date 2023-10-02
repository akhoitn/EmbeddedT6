#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;


enum PhuongTrinhStatus {
	VO_NGHIEM,
	NGHIEM_KEP,
	HAI_NGHIEM
};


typedef struct {
	PhuongTrinhStatus status;
	float x1;
	float x2;
}KetQua;

KetQua giaiPhuongTrinhBacHai(float a, float b, float c);