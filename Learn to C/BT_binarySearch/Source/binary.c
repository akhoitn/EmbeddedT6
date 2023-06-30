/*
 * Function: random_number
 * Description: This function: create random numbers between minN and maxN
 * Input:
 *   minN   - an integer value
 *   maxN   - an integer value
 * Output: return random number
 */
#include "../Header/binary.h"

uint16_t random_number(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}
/*
 * Function: createArray
 * Description: This function: creat an array and add random value (from 1 to 1000)
 * Input:
 *   length    - an integer value - array length
 * Output:
 *   ptr       - random array
 */
uint16_t *createArray(uint16_t length){
    uint16_t *ptr = (uint16_t*)malloc(sizeof(uint16_t)*length);
    srand((int)time(0));
    for (uint16_t i = 0; i < length; i++)
    {
        ptr[i] = random_number(1, 1000);
    }
    return ptr; 
}

/*
 * Function: sort
 * Description: This function: sort array ascending
 * Input:
 *   arr[]    -  an integer array
 *   length    - an integer value - array length
 */
void sort(uint16_t arr[], uint64_t length){
    uint16_t temp;
    for (uint16_t i = 0; i < length - 1; i++)
    {
        for (uint16_t j = i + 1; j < length ; j++)
        {
            if (arr[i] > arr[j])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        }
    }
  
}

/*
 * Function: binarySearch
 * Description: This function: find value ID in array
 * Input:
 *   arr[]   - an integer array
 *   ID      - an integer value to find
 *   left    - an integer values ​​to the left of the array from the midpoint
 *   right   - an integer values ​​to the right of the array from the midpoint
 * Output: return mid ( ID position ), return 0 (not found ID in array)
 */
uint16_t binarySearch(uint16_t arr[], uint16_t left, uint16_t right, uint16_t ID){
    uint16_t mid;
    while (left <= right)
    {
        mid = left + (right - left)/2;
        if (arr[mid] == ID)
        {
            return mid;
        } else if (ID > arr[mid])
        {
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return 0;
}