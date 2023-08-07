#include "../Header/table.hpp"


void Table::setStatus(st status)
{
    STATUS = status;
}

st Table::getStatus()
{
    return STATUS;
}

void addFoodToTable(Choose food)
{
    order.push_back(food);
    STATUS == Close;
}

void backFood();


void bill();
