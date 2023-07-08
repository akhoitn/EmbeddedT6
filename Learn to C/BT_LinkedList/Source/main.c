#include <stdio.h>
#include <stdlib.h>
#include "../Header/funcList.h"

int main(int argc, char const* argv[])
{
    node *array = NULL;

    push_back(&array, 8);
    push_back(&array, 1);
    push_back(&array, 5);
    push_back(&array,60);
    push_back(&array,10);
    push_back(&array,16);
    printf("\nMembers of the list: ");
    displayList(array);

    insert(&array, 50, 4);
    printf("\nMembers of the list after insert: ");
    displayList(array);

    erase(&array, 5);
    printf("\nMembers of the list after erase: ");
    displayList(array);

    pop_Back(array);
    printf("\nMembers of the list after pop_Back: ");
    displayList(array);  

    if(isEmpty(array)) printf("\nList is empty");
    else {
        printf("\nList is not empty!");
    }
    listSize(array);
    return 0;
}