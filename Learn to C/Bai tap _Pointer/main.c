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



int main(int agrc, char const *argv[])
{
    double d = 10.3;
    char string[] = "Hello";
  
    //((void (*)(void (*ptr)(int,int),int,int))toanhoc(6,6);
    
   
    void *array[]= {&toanhoc, &d, &string};
  
    // Gia tri tong
    printf("Gia tri tong a & b: \n");
   ((void (*)(void (*ptr)(int, int),int, int))array[0])(&tong,10,10);

    // Gia tri hieu
   printf("Gia tri hieu a & b: \n");
   ((void (*)(void (*ptr)(int, int),int, int))array[0])(&hieu,10,10);
    // Gia tri tich
   printf("Gia tri tich a & b: \n");
   ((void (*)(void (*ptr)(int, int),int, int))array[0])(&tich,2,5);

    // Gia tri thuong
   printf("Gia tri thuong a & b: %.02f\n",((double (*)(double (*ptr)(int, int),int, int))array[0])(&thuong,17,3));
   

   // GIa tri d
    printf("Gia tri: %.01f\n", *(double *)array[1]);
   // Gia tri  string
    for(int i=0; i < strlen(string); i++)
    {
        printf("%c", *((char*)array[2]+i));
    }
   
    
    return 0;
}