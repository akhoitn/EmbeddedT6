#include"../Header/func.hpp"


int main()
{
    vector<Dish> databaseDishOnMenu;
    vector<Table> databaseTable;
    vector<DishOnTable> databaseDishOnTable;

back:
    int key = 0;
    cout << "\n1: Set table\n2: Manager\n3: Staff\n0: Exit\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        setTable(databaseTable);
        goto back;
    }
    else if (key == 2)
    {
        Manager(databaseDishOnMenu);
        goto back;
    }
    else if (key == 3)
    {
        Staff(databaseDishOnMenu, databaseTable, databaseDishOnTable);
        goto back;
    }
    else
        exit(1);

    return 0;
}