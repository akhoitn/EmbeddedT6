#ifndef binary_h
#define binary_h
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t random_number(int minN, int maxN);
uint16_t *createArray(uint16_t length);
void sort(uint16_t arr[], uint64_t length);
uint16_t binarySearch(uint16_t arr[], uint16_t left, uint16_t right, uint16_t ID);


#endif