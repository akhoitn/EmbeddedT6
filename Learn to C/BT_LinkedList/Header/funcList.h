#ifndef funcList_h
#define funcList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node {
    int value;
    struct node *next;
}node;

node* createNode(int value);

int get (node *array, int index);

void push_back(node **array, int value);

void insert (node **array, int value, int pos);

void erase (node **array, int pos);

void pop_Back (node *array);

void displayList(node *array);

void listSize(node *array);

bool isEmpty(node *array);

#endif