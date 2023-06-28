/*
* File: main.c
* Author: Tran Nguyen Anh Khoi
* Date: 29/06/2023
* Description: this file: Split and print out the words in the sentence in reverse order
*/
#include <stdio.h>
#include "../Header/change.h"
#include "../Header/count.h"
#include "../Header/del.h"
int main(int argc, char const *argv[])
{
    char arr[100];
    // Enter random a string
    printf("Enter a string: ");
    fgets(arr, sizeof(arr), stdin);

    // Delete new line 
    delNewline(arr);
    
    printf("String before reverse: %s\n", arr);

    //Split out the words in the sentence in reverse order
    reverseWords(arr);

    printf("String after reverse: %s\n", arr);

    return 0;
}