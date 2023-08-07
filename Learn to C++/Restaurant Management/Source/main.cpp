#include"../Header/management.hpp"
#include"../Header/selection.hpp"

int main(int argc, char const* argv[])
{
    list<Management> database;

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
            menu(database);
            break;
        // case 2:
        //     menu2(set);
        //     break;
        default:
            cout << "ERROR!! Pls Choice Again" << endl;
        };

        cin >> choice;
    } while (choice == 1 || choice == 2 || choice == 0 || choice == 9);
    return 0;
}