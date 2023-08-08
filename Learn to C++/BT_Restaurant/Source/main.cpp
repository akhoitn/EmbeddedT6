#include"../Header/management.hpp"
#include"../Header/operation.hpp"


int main(int argc, char const* argv[])
{
    list<Dish> menu;
    vector<Table>k_table;

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
            menu1(menu,k_table);
            break;
        case 2:
            menu2(menu,k_table);
            break;
        default:
            cout << "ERROR!! Pls Choice Again" << endl;
        };

        cin >> choice;
    } while (choice == 1 || choice == 2 || choice == 0 || choice == 9);
    return 0;
}
