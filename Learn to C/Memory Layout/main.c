#include <stdio.h>
#include <stdint.h>
#include  <stdlib.h>

const pi = 3.14; // text segment
int a = 20; // data segment
static int b = 5 ; // data segment
int i ; // bss segment
static int c ; // bss segment


int hieu(int a, int b){ // các input parameter
    int x; // stack segment
    static int y; // bss segment
    x = a-b;
    return x;
}

int main(int argc, char const * argv[]){
   
    uint8_t array_St[] = {23, 25, 40, 2}; // Static Array
    int *ptr = array_St;
    printf ("Dia chi arr: %p\n",array_St);
    for(int i=0; i < 4; i++)
    {
        printf("Dia chi array[%d] = %p\n",i,&array_St[i]);
    }
    
    printf("Gia tri ban dau: ");
    int *array_Dy = (int*)malloc(sizeof(int)*5);  // Dynamic array

    for(int i = 0; i <5; i++){

        array_Dy[i] = i;
    }
    for(int i = 0; i < 5; i++){

        printf("%d  ", array_Dy[i]);
    }

    printf("\nGia tri sau thay doi kich thuoc: ");
    array_Dy = (int*)realloc(array_Dy, sizeof(int)*8); // Realloc tăng memory lên cho array
    
    for(int i = 0; i < 8; i++){

        array_Dy[i] = i*2;
    }
    for(int i = 0; i < 8; i++){

        printf("%d ", array_Dy[i]);
    }

    free(array_Dy); // Giai phong bo nho sau khi sử dụng để tránh tràn bộ nhớ.
    return 0;
}