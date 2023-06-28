/*
 * Function: reverse
 * Description: This function: reverse the characters in string
 * Input:
 *   *arr    - string
 *   begin   - an integer value
 *   end     - an integer value
 */
#include "../Header/change.h"
#include "../Header/count.h"

void reverse(char *arr, int begin, int end)
{
    while (begin < end)
    {
        char temp = arr[begin];
        arr[begin] = arr[end];
        arr[end] = temp;
        begin++;
        end--;
    }
}
/*
 * Function: reverseWords
 * Description: This function: reverse the words in string
 * Input:
 *   *arr    - string
 */
void reverseWords(char *arr)
{
    int length = strLeng(arr);
    int begin = 0;
    int end = 0;

    while (end <= length)
    {
        if (arr[end] == ' ' || arr[end] == '\0')
        {
            reverse(arr, begin, end - 1);
            begin = end + 1;
        }
        end++;
    }

    reverse(arr, 0, length - 1);
}
