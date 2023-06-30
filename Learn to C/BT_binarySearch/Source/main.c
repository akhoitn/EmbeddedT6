/*
* File: main.c
* Author: Tran Nguyen Anh Khoi
* Date: 30/06/2023
* Description: this file: find position of ID in random array
*/

#include"../header/binary.h"

int main(int argc, char const *argv[])
{
    uint16_t *array = createArray(1000);
    uint16_t position_t;
    uint16_t ID;
     
    sort(array,1000);
    for (uint16_t i = 0; i < 1000; i++)
    {
    printf("[%d] %d\n ",i, array[i]);
    }

    ID = 767;

    position_t = binarySearch(array, 0, 999, ID);
    
    if (position_t != 0)
    {
    printf("\n Position of ID : %d \n", position_t);
    } else {
    printf("ID not found");
    }
   
    return 0;
}