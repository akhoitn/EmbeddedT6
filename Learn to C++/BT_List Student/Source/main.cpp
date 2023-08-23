#include "../Header/class.hpp"
#include "../Header/func.hpp"

int main()
{
    list<Student> database;
    int key = 0;
back:
    system("cls");
    int op;
    cout << "\t\t------------------------------" << endl;
    cout << "\t\tStudent Management System" << endl;
    cout << "\t\t------------------------------" << endl;
    cout << "\t\t 1. Add New Student" << endl;
    cout << "\t\t 2. Update Student" << endl;
    cout << "\t\t 3. Search Student" << endl;
    cout << "\t\t 4. Delete Student" << endl;
    cout << "\t\t 5. Sort By Name" << endl;
    cout << "\t\t 6. Sort By GPA" << endl;
    cout << "\t\t 7. Display Student" << endl;
    cout << "\t\t 0. Exit" << endl;
    cout << "\t\t Enter Your Choice: ";
    cin >> key;
    switch (key)
    {
    case 1:
        addSt(database);
        goto back;
        break;
    case 2:
        update(database);
        goto back;
        break;
    case 3:
        searchName(database);
        goto back;
        break;
    case 4:
        delSt(database);
        goto back;
        break;
    case 5:
        sortByName(database);
        goto back;
        break;
    case 6:
        sortByGPA(database);
        goto back;
        break;
    case 7:
        display(database);
        goto back;
        break;
    case 0:
        exit(1);
    default:
        cout << "\t\tInvalid Number ...." << endl;
    };

    return 0;
}