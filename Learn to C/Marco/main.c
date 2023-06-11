#include <stdio.h>
#include "test.c"

#define BIG 15
#define SUM(a,b) a+b

void display(){
    printf("Hi everyone\n");
}

int main(int argc, char const *argv[])
{

    display();
    printf("BIG: %d\n", BIG);
    printf("Sum a & b: %d\n", SUM(5,5));
    test();
    return 0;
}