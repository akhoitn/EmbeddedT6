#include<stdio.h>
#include<string.h>

void tong(int a, int b)
{
    printf("Tong %d và %d = %d\n", a, b, a+b);
}
void hieu(int a, int b)
{
    printf("Tong %d và %d = %d\n", a, b, a-b);
}
void tich(int a, int b)
{
    printf("Tong %d và %d = %d\n", a, b, a*b);
}
double thuong(int a, int b)
{
    return (double)a/b;
}
void toanhoc(void(*ptr)(int,int), int a, int b){
    printf("Chuong trinh tinh toan\n");
    ptr(a,b);
    
}
/*void (*afptr[])(int,int) = {
    &tong,
    &hieu,
    &tich,
    &thuong,
}*/



int main(int agrc, char const *argv[])
{
    double d = 10.3;
    char string[] = "Hello";
    
    //void *ptr1 =&tong;
    //((void (*)(int,int))ptr1)(6,6);
    //toanhoc(&ptr1,6,6);
   
    void *array[]= {&toanhoc, &d, &string};
    // Gia tri toanhoc
    //printf("%d\n", (*array[0])(&hieu,6,6));
  
 
   
   // GIa tri d
    printf("Gia tri: %.01f\n", *(double *)array[1]);
   // Gia tri  string
    for(int i=0; i < strlen(string); i++)
    {
        printf("%c", *((char*)array[2]+i));
    }
   
    
    return 0;
}