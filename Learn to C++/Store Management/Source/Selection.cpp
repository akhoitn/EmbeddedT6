#include "../Header/Choose.hpp"
#include"../Header/Management.hpp"
#include"../Header/Table.hpp"


void menu(list<Management> &database)
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
            int total_table;
            cout<<"Enter Total Available: ";
            cin>>total_table;
            cout<<"Enter Zero To Back: ";
            break;
        case 2:
            addNewFood(database);
            break;
        case 3:
            updatePrice(database);
            break;
        case 4:
            delMenuFood(database);
            break;
        case 5:
            listMenuFood(database);
            break;
        default:
            cout << "\t\tInvalid Number ...." << endl;
            break;
        };

        cin >> choice;
    } while (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}

