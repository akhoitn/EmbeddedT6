#ifndef func_h
#define func_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void add_node_sort(Node **head, int value);

typedef struct CenterPoint
{
    int value;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

CenterPoint *buildTree(Node *head, int start, int end);

CenterPoint *centerPoint(Node *head);

CenterPoint *binarySearch(CenterPoint *root, int value);

void print_list(Node *head);

#endif