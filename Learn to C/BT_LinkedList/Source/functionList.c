/*
* File: funcList.c
* Author: Tran Nguyen Anh Khoi
* Date: 07/07/2023
* Description: This is a header file contain functions for single linked  list
*/
#include "../Header/funcList.h"
#include <stdint.h>

/*
* Function: createNode
* Description: This function is used create a Node
* Input:
*   int value : an integer value
* Output:
*   returns a created node with input value
*/
node*  createNode(int value)
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr -> value = value;
    ptr -> next  = NULL; 
    return ptr;
}

/*
* Function: get
* Description: This function to get a node from a linked list at the position you want
* Input:
*   node **array : linked list want to find a node
*   int index: index want to get a node from linked list
* Output:
*   value of that node
*/
int get (node *array, int index)
{
    int i =0;
    while (array -> next !=NULL && index != i)
    {
        array = array -> next;
        i++;
    }
    return array -> value;
}

/*
* Function: push_back
* Description: This function to push a node to linked list
* Input:
*   node **array : a new node to push into a linked list
*   int value: value of that new a node to be pushed into a linked list 
*/
void push_back(node **array, int value)
{
    node *temp, *p;
    temp = createNode(value);
    if (*array == NULL)
    {
        *array = temp;
    }
    else {
        p = *array;
        while (p ->next != NULL)
        {
            p = p->next;
        }
        p -> next = temp;
        
    }
    
}

/*
* Function: insert
* Description: This function to get a node from a linked list at the position you want
* Input:
*   node **array : linked list want to insert a node
*   int value: value of node want to push into linked list
*   int pos: postion want to push into linked list
*   
*/
void insert (node **array, int value, int pos)
{
    node *temp, *p;

    p = *array;
    temp = createNode(value);
    int i =0;
    if (pos == 0)
    {
        temp -> next = *array;
        *array = temp;
    } else {

        while (p -> next !=NULL && pos != i)
        {
            p = p -> next;
            i++;
        }

        temp->next = p->next;
        p->next = temp;
        
    }
    
}

/*
* Function: erase
* Description: This function will delete a node in linked list
* Input:
*   node *array : linked list
*   int pos: position of node want to be deleted from linked list
*/
void erase (node **array, int pos)
{
    node *current = *array;
    node *previous = *array;
    if(*array == NULL)
    {
        printf("List is already empty!");
    }else if (pos == 1)
    {
        *array = current->next;
        free(current);
        current = NULL;
    }else {
        while (pos != 1)
        {
            previous = current;
            current = current -> next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;      
    }
}

/*
* Function: pop_Back
* Description: Function to remove a last node from a linked list
* Input:
*   node *array : linked list 
*/
void pop_Back (node *array)
{
    if(array->next == NULL)
    {
        free(array);
        array = NULL;
    }
    else{
    node *current = array;
    node *previous = array;
    
    while (current->next != NULL)
    {
        previous = current;
        current  = current->next;
    }
    previous->next = NULL;
    free(current);
    current = NULL;
    }
}

/*
* Function: displayList
* Description: Function to print a list of the linked list
* Input:
*   node *array : linked list
*/
void displayList(node *array)
{
    node* current = array;
    while (current != NULL) {
        printf("%d  ", current->value);
        current = current->next;
    }
}

/*
* Function: listSize
* Description: Function to calculate the size of a linked list
* Input:
*   node *head : linked list  
*/
void listSize(node *array)
{
    int count = 0;
    node *temp;
    temp = array;
    while (temp != 0)
    {
        count ++;
        temp = temp -> next;
    }
    printf("\nLength of the list: %d", count);
    
}

/*
* Function: isEmpty
* Description: Function to check linked list is empty or not empty
* Input:
* node *array : linked list
*/
bool isEmpty(node *array){
    if (array->next == array) return true;
    else return false;
}