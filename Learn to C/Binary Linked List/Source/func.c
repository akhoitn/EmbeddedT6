/*
 * File: funcList.c
 * Author: Tran Nguyen Anh Khoi
 * Date: 07/07/2023
 * Description: This is file contain functions for find the number by binary linked  list
 */
#include "../Header/func.h"

/*
* Function: add_sort_node
* Description: add a new node at the last position in the linked list and sort the list from small value to big value
* Input:
*   head - pointer to pointer has datatype is node 
*   value - an integer value - value of the members
* Output:
*   new list is sorted from small to big
*/
void add_node_sort(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= value)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data < value)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

/*
* Function: buildTree
* Description: find all the middle position's value in linked list
* Input:
*   head - pointer has datatype is node 
*   start - position to start 
*   end - position to end 
* Output:
*   The list with all middle position's value
*/
CenterPoint *buildTree(Node *head, int start, int end)
{
    if (head == NULL || start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;
    for (int i = start; i < mid; i++)
    {
        if (node->next == NULL)
        {
            break;
        }
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *)malloc(sizeof(CenterPoint));
    root->value = node->data;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}

/*
* Function: centerPoint
* Description: find the length of the list and all the middle position's value
* Input:
*   head -pointer has datatype is node 
* Output:
*   Function: buildTree(head,0,size-1);
*/
CenterPoint *centerPoint(Node *head)
{
    int length = 0;
    Node *node = head;
    while (node != NULL)
    {
        node = node->next;
        length++;
    }

    return buildTree(head, 0, length - 1);
}

/*
* Function: binarySearch
* Description: Find the value you want if the linked list have the value
* Input:
*   root - pointer has datatype is centerPoint
*   value - an integer value you want to find 
* Output:
*   Null if not have the value
*   root if have the value
*/
CenterPoint *binarySearch(CenterPoint *root, int value)
{
    static int loop = 0;
    loop++;
    printf("so lan lap: %d\n", loop);
    if (root == NULL)
    {
        return NULL;
    }

    if (root->value == value)
    {
        return root;
    }

    if (value < root->value)
    {
        return binarySearch(root->left, value);
    }
    else
    {
        return binarySearch(root->right, value);
    }
}

/*
* Function: print_list
* Description: print all the value in linked list
* Input:
*   array - pointer has datatype is node
* Output:
*   print all the value in array 
*/
void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}