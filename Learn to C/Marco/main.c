#include <stdio.h>
#include "test.c"

#define BIG 15
#define SUM(a,b) a+b
#define CREATE_FUNC(name_func, cmd)\
void name_func()                    \
{                                   \
    printf("%s\n", (char *)cmd);       \
}

CREATE_FUNC(say,"Try ur best");

void display(){
    printf("Hi everyone\n");
}

int main(int argc, char const *argv[])
{
    say();
    display();
    printf("BIG: %d\n", BIG);
    printf("Sum a & b: %d\n", SUM(5,5));
    test();
    return 0;
}