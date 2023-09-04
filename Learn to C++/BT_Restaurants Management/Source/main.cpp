#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Dish
{
private:
    int ID;
    string NAME;
    int PRICE;

public:
    Dish(int id = 0, string name = "", int price = 0);
    void setName(string name);
    void setPrice(int price);
    void setId(int id);
    int getId();
    string getName();
    int getPrice();
};

void Dish::setName(string name)
{
    NAME = name;
}

void Dish::setPrice(int price)
{
    PRICE = price;
}

void Dish::setId(int id)
{
    ID = id;
}

string Dish::getName()
{
    return NAME;
}

int Dish::getPrice()
{
    return PRICE;
}

int Dish::getId()
{
    return ID;
}

Dish::Dish(int id, string name, int price)
{
    this->ID = id;
    this->NAME = name;
    this->PRICE = price;
}

/// /////////////////////////////////////////////
class DishOnTable : public Dish
{
private:
    int NUMBERDISH;

public:
    DishOnTable(int numberDish = 0);
    void setNumberDish(int numberDish);
    int getNumberDish();
};

DishOnTable::DishOnTable(int numberDish)
{
    this->NUMBERDISH = numberDish;
}

void DishOnTable::setNumberDish(int numberDish)
{
    NUMBERDISH = numberDish;
}

int DishOnTable::getNumberDish()
{
    return NUMBERDISH;
}

///////////////////////////////////////////////
class Table
{
private:
    vector<DishOnTable> databaseDishOnTable;
    int NUMBERTABLE;
    bool STATUS;

public:
    Table(int numberTable);
    void setNumberTable(int numberTable);
    void setStatus(int status);
    int getNumberTable();
    bool getStatus();
    vector<DishOnTable> &getDatabaseDishOnTable();
};

Table::Table(int numberTable)
{
    this->NUMBERTABLE = numberTable;
}

void Table::setNumberTable(int numberTable)
{
    NUMBERTABLE = numberTable;
}

void Table::setStatus(int status)
{
    STATUS = status;
}

int Table::getNumberTable()
{
    return NUMBERTABLE;
}

bool Table::getStatus()
{
    return STATUS;
}

vector<DishOnTable> &Table::getDatabaseDishOnTable()
{
    return databaseDishOnTable;
}
///////////////////////////////////////////////
void setQuantityTable(vector<Table> &databaseTable)
{
    cout << "--------------" << endl;
    int quantity;
    cout << "Enter the total number of table: ";
    cin >> quantity;

    for (int i = 0; i < quantity; i++)
    {
        Table table = {i};
        databaseTable.push_back(table);
    }
}

void prinListTable(vector<Table> &databaseTable)
{
    cout << "\n\nLIST Table\nTable:     ";
    for (auto tb = databaseTable.begin(); tb != databaseTable.end(); tb++)
    {
        cout << tb->getNumberTable() << "  |  ";
    }

    cout << "\nStatus: ";
    for (auto tb = databaseTable.begin(); tb != databaseTable.end(); tb++)
    {
        if (tb->getStatus() == false)
            cout << "  o  |";
        else
            cout << "  x  |";
    }
    cout << endl;
}

void setTable(vector<Table> &databaseTable)
{
    int key = 0;
back:
    cout << "\n1: Set total table\n2: Print list table\n0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        setQuantityTable(databaseTable);
        goto back;
    }
    else if (key == 2)
    {
        prinListTable(databaseTable);
        goto back;
    }
    else
        return;
}


//////////////////////////////////////////////////////
void addDishOnTable(vector<DishOnTable> &databaseDishOnTable, vector<Dish> &databaseDishOnMenu)
{

    int ID;
    cout << "Enter the IF of Dish: ";
    cin >> ID;
    int NUMBERDISH;

    for (auto i = databaseDishOnMenu.begin(); i != databaseDishOnMenu.end(); i++)
    {
        if (i->getId() == ID)
        {
            cout << "Enter number of dish: ";
            cin >> NUMBERDISH;
            DishOnTable dish(NUMBERDISH);
            dish.setName(i->getName());
            dish.setPrice(i->getPrice());
            dish.setId(i->getId());
            dish.setNumberDish(NUMBERDISH);
            databaseDishOnTable.push_back(dish);
            cout << "Add order completed" << endl;
        }
    }

    for (auto i = databaseDishOnTable.begin(); i != databaseDishOnTable.end(); i++)
    {

        cout << i->getName() << endl;
        cout << i->getNumberDish() << endl;
    }

    int key = 0;
    cout << "\n1: add dish more\n0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        addDishOnTable(databaseDishOnTable, databaseDishOnMenu);
    }
    else
        return;
}

void deleteDishOnTable(vector<DishOnTable> &databaseDishOnTable, vector<Dish> &databaseDishOnMenu)
{
    int ID;
    cout << "Enter ID dish: ";
    cin >> ID;
    for (auto dish = databaseDishOnTable.begin(); dish != databaseDishOnTable.end(); dish++)
    {
        if (dish->getId() == ID)
        {
            databaseDishOnTable.erase(dish);
            cout << "Delete order completed" << endl;
        }
    }
    int key;
    cout << "\n1: delete dish more\n0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        deleteDishOnTable(databaseDishOnTable, databaseDishOnMenu);
    }
    else
        return;
}

void editDishOnTable(vector<DishOnTable> &databaseDishOnTable)
{
    int ID;
    int NUMBERDISH;
    cout << "Enter ID the dish: ";
    cin >> ID;

    for (auto dish = databaseDishOnTable.begin(); dish != databaseDishOnTable.end(); dish++)
    {
        if (dish->getId() == ID)
        {
            int key = 0;
            dish->getNumberDish();
            cout << "\n1: edit dish\n2: edit number dish\n0: Return\nPls choice: ";
            cin >> key;
            if (key == 2)
            {
                cout << "Enter number dish: ";
                cin >> NUMBERDISH;
                dish->setNumberDish(NUMBERDISH);
                cout << "Edit completed!!" << endl;
            }
        }
    }
    int key1 = 0;
    cout << "\n1: add dish more\n0: Return\nPls choice: ";
    cin >> key1;
    if (key1 == 1)
    {
        editDishOnTable(databaseDishOnTable);
    }
    else
        return;
}

void prinDishOnTable(vector<DishOnTable> &databaseDishOnTable, vector<Dish> &databaseDishOnMenu)
{

    int count = 0;
    cout << endl;
    cout << "------------------------------Dish On Table--------------------------" << endl;
    for (auto dish = databaseDishOnTable.begin(); dish != databaseDishOnTable.end(); dish++)
    {
        count++;
        cout << "STT." << count << " ID: " << dish->getId() << " NAME: " << dish->getName() << " PRICE: " << dish->getPrice() << " QUANTITY: " << dish->getNumberDish() << endl;
    }
}
void Bill(vector<DishOnTable> &databaseDishOnTable, vector<Dish> &databaseDishOnMenu)
{
    int total = 0;
    prinDishOnTable(databaseDishOnTable, databaseDishOnMenu);

    for (auto dish = databaseDishOnTable.begin(); dish != databaseDishOnTable.end(); dish++)
    {
        total = total + (dish->getNumberDish() * dish->getPrice());
    }

    cout << "---------------------Bill----------------------" << endl;
    cout << "Total: " << total << endl;
    
    
}

////////////////////////////////////////////////////////////////////////////////////////

void addDishOnMenu(vector<Dish> &databaseDishOnMenu)
{

    cout << endl;
    string name;
    int price;

    cout << "Enter name of food: ";
    cin >> name;

    cout << "Enter price of food: ";
    cin >> price;

    static int id = 100;
    Dish dish = {id, name, price};
    id++;
    databaseDishOnMenu.push_back(dish);

    int key = 0;
    cout << "\n1: Add food more\n0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        addDishOnMenu(databaseDishOnMenu);
    }
}
void prinDishOnMenu(vector<Dish> &databaseDishOnMenu)
{
    for (auto dish = databaseDishOnMenu.begin(); dish != databaseDishOnMenu.end(); dish++)
    {
        cout << "The ID of food: " << dish->getId() << endl;
        cout << "The name of food: " << dish->getName() << endl;
        cout << "The price of food: " << dish->getPrice() << endl;
        cout << endl;
    }
}
void deleteDishOnMenu(vector<Dish> &databaseDishOnMenu)
{
    int id;
    bool flag = false;
    prinDishOnMenu(databaseDishOnMenu);

    cout << "Enter ID of food: ";
    cin >> id;

    for (auto dish = databaseDishOnMenu.begin(); dish != databaseDishOnMenu.end(); dish++)
    {
        if (dish->getId() == id)
        {
            flag = true;
            databaseDishOnMenu.erase(dish);
            cout << "\nDelete Successfully!!!" << endl;
            break;
        }
    }

    if (flag == false)
        cout << "\nNot to found!!" << endl;

    int key = 0;
    cout << "\n1: Delete food more\n0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        deleteDishOnMenu(databaseDishOnMenu);
    }
}

void editDishOnMenu(vector<Dish> &databaseDishOnMenu)
{
    int id;
    prinDishOnMenu(databaseDishOnMenu);
    cout << "Enter ID of food: ";
    cin >> id;
    string name;
    int price;

    for (auto dish = databaseDishOnMenu.begin(); dish != databaseDishOnMenu.end(); dish++)
    {
        if (dish->getId() == id)
        {
            int key = 0;
            cout << "\n1: edit name food\n2: edit price\n0: Return\nPls choice: ";
            cin >> key;
            if (key == 1)
            {
                cout << "\nEnter the new name: ";
                cin >> name;
                dish->setName(name);
                break;
            }
            else if (key == 2)
            {
                cout << "\nEnter the new price: ";
                cin >> price;
                dish->setPrice(price);
                break;
            }
            else
                return;
        }
    }
    int key = 0;
    cout << "\n1: edit food more\n0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        editDishOnMenu(databaseDishOnMenu);
    }
}
///////////////////////////////////////////////////
void Staff(vector<Dish> &databaseDishOnMenu, vector<Table> &databaseTable, vector<DishOnTable> &databaseDishOnTable)
{
    prinListTable(databaseTable);
    int numberTable;
    cout << "Enter the number table: ";
    cin >> numberTable;
back:
    int key;
    cout << "\n1: add dish on table\n2: delete dish on table\n3: edit dish on table\n4: print dish on table\n5: Bill\n0: Return\nPls choice: ";
    cin >> key;
    switch (key)
    {
    case 1:
        prinDishOnMenu(databaseDishOnMenu);
        cout << endl;
        addDishOnTable(databaseTable[numberTable].getDatabaseDishOnTable(), databaseDishOnMenu);
        databaseTable[numberTable].setStatus(1);
        goto back;
        break;
    case 2:
        prinDishOnTable(databaseTable[numberTable].getDatabaseDishOnTable(), databaseDishOnMenu);
        deleteDishOnTable(databaseTable[numberTable].getDatabaseDishOnTable(), databaseDishOnMenu);
        goto back;
        break;
    case 3:
        prinDishOnTable(databaseTable[numberTable].getDatabaseDishOnTable(), databaseDishOnMenu);
        editDishOnTable(databaseTable[numberTable].getDatabaseDishOnTable());
        goto back;
        break;
    case 4:
        prinDishOnTable(databaseTable[numberTable].getDatabaseDishOnTable(), databaseDishOnMenu);
        goto back;
        break;
    case 5:
        Bill(databaseTable[numberTable].getDatabaseDishOnTable(), databaseDishOnMenu);
        goto back;
        break;
    case 0:
        return;
    default:
        cout << "Warning. Again\n";
        break;
    }
}

void Manager(vector<Dish> &databaseDishOnMenu)
{

    int key = 0;
back:
    cout << "\n1: Add dish on menu\n2: edit dish on menu\n3: delete dish on menu\n4: Print list dish on menu\n0: Return\nPls choice: ";
    cin >> key;
    switch (key)
    {
    case 1:
        addDishOnMenu(databaseDishOnMenu);
        goto back;
        break;
    case 2:
        editDishOnMenu(databaseDishOnMenu);
        goto back;
        break;
    case 3:
        deleteDishOnMenu(databaseDishOnMenu);
        goto back;
        break;
    case 4:
        prinDishOnMenu(databaseDishOnMenu);
        goto back;
        break;
    case 0:
        return;
    default:
        cout << "Warning. Again!!" << endl;
        break;
    }
}

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