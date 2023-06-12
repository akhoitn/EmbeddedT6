#include<stdio.h>
#include<stdint.h>

typedef struct
{
    uint32_t ID;
    uint8_t Date;   

}Visa;

typedef enum{
        January =1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,

}Month;

void Display (Visa visa, Month month){
    printf("ID: %d, Date: %d\n", visa.ID, visa.Date);

    switch (month)
    {
    case January:
        printf("Thang 1\n");
        break;
    case February:
        printf("Thang 2\n");
        break;    
    case March:
        printf("Thang 3\n");
        break;
    case April:
        printf("Thang 4\n");
        break;
    case May:
        printf("Thang 5\n");
        break;
    case June:
        printf("Thang 6\n");
        break;
    case July:
        printf("Thang 7\n");
        break;
    case August:
        printf("Thang 8\n");
        break;
    case September:
        printf("Thang 9\n");
        break;
    case October:
        printf("Thang 10\n");
        break;
    case November:
        printf("Thang 11\n");
        break;
    case December:
        printf("Thang 12\n");
        break;                                                                                   
    default:
    printf("Have Troubles\n");
        break;
    }
}

int main(int argc, char const *agrv)
{
    Visa visa;
    Month month = June;
    visa.ID = 58729429;
    visa.Date = 24;
    Display(visa, month);
    return 0;
}