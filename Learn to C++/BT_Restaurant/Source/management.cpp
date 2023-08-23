#include "../Header/management.hpp"

Dish::Dish(string name_food, int price)
{
    static int id = 100;
    ID = id;
    id++;

    static int stt = 1;
    STT = stt;
    stt++;

    NAME_FOOD = name_food;
    PRICE = price;
}

void Dish::setQuantity(int quantity)
{
    QUANTITY = quantity;
}
int Dish::getQuantity()
{
    return QUANTITY;
}

int Dish::getID()
{
    return ID;
}

void Dish::setNameFood(string name_food)
{
    NAME_FOOD = name_food;
}
string Dish::getNameFood()
{
    return NAME_FOOD;
}

int Dish::getSTT()
{
    return STT;
}

void Dish::setPrice(int price)
{
    PRICE = price;
}
int Dish::getPrice()
{
    return PRICE;
}

Table::Table(int number_table, bool status)
{
    NUMBER_TABLE = number_table;
    STATUS = status;
}

bool Table::setStatus(int status)
{
    return STATUS == status;
}
bool Table::getStatus()
{
    return STATUS;
}
int Table::getNumberTable()
{
    return NUMBER_TABLE;
}

void listMenuFood(list<Dish> &menu)
{
    for (auto &food : menu)
    {
        cout << "The ordinal number of food: " << food.getSTT() << endl;
        cout << "The ID of food: " << food.getID() << endl;
        cout << "The name of food: " << food.getNameFood() << endl;
        cout << "The price of food: " << food.getPrice() << endl;
        cout << endl;
    }
}
void listFoodTable(list<Dish> &menu)
{
    list<Dish> temp;
    cout << "-----------------" << endl;
    cout << "List Food of Table" << endl;

    for (auto &temp : menu)
    {

        cout << "The ordinal number of food: " << temp.getSTT() << endl;
        cout << "The ID of food: " << temp.getID() << endl;
        cout << "The name of food: " << temp.getNameFood() << endl;
        cout << "The price of food: " << temp.getPrice() << endl;
        cout << "The quantity of food: " << temp.getQuantity() << endl;
        cout << endl;
    }
}

void addNewFood(list<Dish> &menu)
{
    string NAME_FOOD;
    int PIRCE;

    cout << "------------------" << endl;
    do
    {
        cout << "Enter name of the food: ";
        cin >> NAME_FOOD;
    } while (NAME_FOOD == "\0");

    do
    {
        cout << "Enter the price of the food: ";
        cin >> PIRCE;
    } while (PIRCE <= 0);

    Dish food(NAME_FOOD, PIRCE);
    menu.push_front(food);

    cout << "----------------------------" << endl;
    cout << "  The Information Of Food " << endl;
    listMenuFood(menu);
    cout << "\t\t The Food Add Successfully....." << endl;

    cout << "-----------------------------" << endl;
    cout << "1. Add New Food" << endl;
    cout << "0. Back( Pls Double 0)" << endl;
    cout << "Pls Choice Number: ";
    int op;
    cin >> op;
    if (op == 1)
    {
        addNewFood(menu);
    };
}
void findFood(list<Dish> &menu)
{
    int ID;
    do
    {
        cout << "Enter ID: ";
        cin >> ID;
    } while (ID < 100);

    cout << endl;
    list<Dish> temp;
    for (auto &food : menu)
    {
        if (food.getID() == ID)
        {
            temp.push_back(food);
        }
    }
    listMenuFood(temp);
    cout << endl;
}
void updatePrice(list<Dish> &menu)
{

    cout << "----------List The Food-------------" << endl;
    listMenuFood(menu);
    cout << endl;
    int ID;
    int PRICE;

    findFood(menu);

    for (auto food = menu.begin(); food != menu.end(); food++)
    {
        int op;
        cout << "--------------------" << endl;
        cout << "1. Change The Price" << endl;
        cout << "0. Back( Double Zero)" << endl;
        cout << "Pls Choice Number: ";
        cin >> op;
        if (op == 1)
        {
            cout << "New Price: ";
            cin >> PRICE;
            food->setPrice(PRICE);
            cout << endl;
            cout << "Update Successfully!!" << endl;
            cout << "Enter Zero To Back!!" << endl;
        }
    }
}
void delMenuFood(list<Dish> &menu)
{

    listMenuFood(menu);
    cout << endl;
    int ID;
    bool flag;

    do
    {
        cout << "Enter ID: ";
        cin >> ID;
    } while (ID < 100);

    for (auto food = menu.begin(); food != menu.end(); food++)
    {
        flag = false;
        if (food->getID() == ID)
        {
            menu.erase(food);
            flag = true;
            cout << "Delete Successfully!!!" << endl;
            break;
        }
    }
    if (flag = false)
    {
        cout << "Not Found!!!" << endl;
    }
}
void setNumberTable(vector<Table> &k_table)
{
    int NUMBER_TABLE;
    int total_table = 0;
    cout << "Enter total table: ";
    cin >> total_table;

    for (NUMBER_TABLE = 1; NUMBER_TABLE <= total_table; NUMBER_TABLE++)
    {
        Table table(NUMBER_TABLE, false);
        k_table.push_back(table);
    }
}
void menu1(list<Dish> &menu, vector<Table> &k_table)
{
    int choice;
    int op;
    do
    {
        cout << "------------------------" << endl;
        cout << "1. Set Number Table" << endl;
        cout << "2. Add Food" << endl;
        cout << "3. Update The Price" << endl;
        cout << "4. Delete The Food" << endl;
        cout << "5. Display The Food" << endl;
        cout << "9. Back ( 3 times 9)" << endl;
        cout << "Pls Choice Number: ";
        cin >> op;
        switch (op)
        {
        case 1:
            setNumberTable(k_table);
            break;
        case 2:
            addNewFood(menu);
            break;
        case 3:
            updatePrice(menu);
            break;
        case 4:
            delMenuFood(menu);
            break;
        case 5:
            listMenuFood(menu);
            break;
        default:
            cout << "\t\tInvalid Number ...." << endl;
            break;
        };

        cin >> choice;
    } while (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}

void infTable(vector<Table> &k_table)
{
    for (int i = 0; i < k_table.size(); i++)
    {
        cout << k_table[i].getNumberTable() << ":";
        cout << k_table[i].getStatus() << endl;
    }
}

int checkTable(vector<Table> &k_table)
{
    int NUMBER_TABLE;
    do
    {
        cout << "Enter number table u want: ";
        cin >> NUMBER_TABLE;
        for (int i = 0; i < k_table.size(); i++)
        {
            if (k_table[i].getNumberTable() == NUMBER_TABLE && k_table[i].getStatus() == false)
            {
                k_table[i].setStatus(true);
            }
        }
    } while (NUMBER_TABLE <= 0 || NUMBER_TABLE > k_table.size());
    return NUMBER_TABLE;
}

void addFood(list<Dish> &menu)
{
    cout << "------------------" << endl;
    listMenuFood(menu);
    cout << "---------------" << endl;

    int QUANTITY;
    int ID;
    list<Dish> temp;
    do
    {
        cout << "Enter ID: ";
        cin >> ID;
    } while (ID < 100);

    do
    {
        cout << "Enter quantity of food: ";
        cin >> QUANTITY;
    } while (QUANTITY < 0);

    cout << endl;
    for (auto &food : menu)
    {
        if (food.getID() == ID)
        {
            food.setQuantity(QUANTITY);
            temp.push_back(food);
        }
    }
    listMenuFood(temp);
    cout << endl;
    listFoodTable(menu);
    int op;
    cout << "1. Add Food again" << endl;
    cout << "0.Back" << endl;
    cout << "Pls choice number: ";
    cin >> op;
    if (op == 1)
    {
        addFood(menu);
    }
}

// void delFood(list<Dish>&menu) {
//     list<Dish>temp;
//     int ID;
//     cout<<"------------------"<<endl;

//     cout<<"Enter ID of food u want delete";
//     cin >> ID;

//     for(auto &food:menu)
//     {
//         if(food.getID() == ID )
//         {
//             temp.erase(food);
//         }

//     }

// }

void bill(list<Dish> &menu, vector<Table> k_table);
void menu2(list<Dish> &menu, vector<Table> &k_table)
{
    int choice;
    int op;
    int num;

    infTable(k_table);
    num = checkTable(k_table);
    do
    {
        cout << "Number Table:" << num << endl;
        cout << "1. Add Food" << endl;
        cout << "2. Change Food" << endl;
        cout << "3. Delete Food" << endl;
        cout << "4. List Food" << endl;
        cout << "5. Bill" << endl;
        cout << "0. Back (enter 9)" << endl;
        cout << "Pls choice !! ";
        cin >> op;
        switch (op)
        {
        case 1:
            addFood(menu);
            break;
        // case 3:
        //     delFood(menu);
        //     break;
        default:
            break;
        }
        cin >> choice;
    } while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 0);
}

void Menu(list<Dish> &menu, vector<Table> &k_table)
{
    int tp;
    int choice;
    do
    {
        cout << "------------------------------------" << endl;
        cout << "1. Management" << endl;
        cout << "2. Employee" << endl;
        cout << "Pls Choice Number: ";
        cin >> tp;
        switch (tp)
        {
        case 1:
            menu1(menu, k_table);
            break;
        case 2:
            menu2(menu, k_table);
            break;
        default:
            cout << "ERROR!! Pls Choice Again" << endl;
        };

        cin >> choice;
    } while (choice == 1 || choice == 2 || choice == 0 || choice == 9);
}