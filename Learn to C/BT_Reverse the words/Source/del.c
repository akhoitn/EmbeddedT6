/*
* Function: delNewline
* Description: This function delete new line
* Input:
*   arr - string
*/
#include "../Header/del.h"
#include "../Header/count.h"
void delNewline(char arr[])
{
	int len = strLeng(arr);
	if(arr[len-1] == '\n'){
		arr[len-1] = '\0';
}
}