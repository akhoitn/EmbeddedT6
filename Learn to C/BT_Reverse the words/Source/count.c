/*
 * Function: strLeng
 * Description: This function calculates string length
 * Input:
 *   arr - string
 * Output:
 *   returns length string of arr = i
 */

#include "../Header/count.h"

int strLeng(char arr[])
{
    int i = 0;
    while (1)
    {
        if (arr[i] == '\0')
        {
            return i;
        }
        i++;
    }
}
