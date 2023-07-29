#include <iostream>
#include <string>
#include <cassert>
#include <list>

using namespace std;

typedef enum
{
    FEMALE,
    MALE
} TypeSex;

typedef enum
{
    EXCELLENT,
    GOOD,
    AVERAGE,
    BELOW_AVERAGE
} TypeRank;

class Student
{
private:
    int ID;
    string NAME;
    int AGE;
    string SEX;
    TypeRank RANK;
    double MATH;
    double CHEMISTRY;
    double PHYSICAL;
    double GPA;

public:
    Student(string name, int age, string sex, double math, double physical, double chemistry);
    void editInf(string name, int age, string sex, double math, double physical, double chemistry);
    void display();
    int displayID();
    string displayName();
    double displayTB();
};

Student::Student(string name, int age, string sex, double math, double physical, double chemistry)
{
    static int id = 100;
    ID = id;
    id++;
    NAME = name;
    AGE = age;
    SEX = sex;
    MATH = math;
    CHEMISTRY = chemistry;
    PHYSICAL = physical;

    GPA = (MATH + CHEMISTRY + PHYSICAL) / 3;
    if (GPA >= 8)
    {
        RANK = EXCELLENT;
    }
    else if (GPA >= 6.5)
    {
        RANK = GOOD;
    }
    else if (GPA >= 5)
    {
        RANK = AVERAGE;
    }
    else
    {
        RANK = BELOW_AVERAGE;
    }
}

void Student::display()
{
    string tp;
    switch (RANK)
    {
    case 0:
        tp = "EXCELLENT";
        break;
    case 1:
        tp = "GOOD";
        break;
    case 2:
        tp = "AVERAGE";
        break;
    default:
        tp = "BELOW AVERAGE";
        break;
    }

    cout << "---------------------------------------" << endl;
    cout << "------------           ----------------" << endl;
    cout << "The name of student: " << NAME << endl;
    cout << "ID of student: " << ID << endl;
    cout << "Age of student: " << AGE << endl;
    cout << "Sex of student: " << SEX << endl;
    cout << "The math: " << MATH << endl;
    cout << "The physical: " << PHYSICAL << endl;
    cout << "The chemistry: " << CHEMISTRY << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Rank: " << tp << endl;
}
int Student::displayID()
{
    return ID;
}

string Student::displayName()
{
    return NAME;
}

double Student::displayTB()
{
    return GPA;
}

void Student::editInf(string name, int age, string sex, double math, double physical, double chemistry)
{
    NAME = name;
    AGE = age;
    SEX = sex;
    MATH = math;
    CHEMISTRY = chemistry;
    PHYSICAL = physical;
    GPA = (MATH + PHYSICAL + CHEMISTRY) / 3;
    if (GPA >= 8)
    {
        RANK = EXCELLENT;
    }
    else if (GPA >= 6.5)
    {
        RANK = GOOD;
    }
    else if (GPA >= 5)
    {
        RANK = AVERAGE;
    }
    else
    {
        RANK = BELOW_AVERAGE;
    }
}

void addNewSv(list<Student> &database)
{
    string NAME;
    int AGE;
    string SEX;
    double MATH;
    double PHYSICAL;
    double CHEMISTRY;

    do
    {
        cout << "Enter name: ";
        fflush(stdin);
        getline(cin, NAME);
    } while (NAME == "\0");

    do
    {
        cout << "Enter age: ";
        cin >> AGE;
    } while (AGE <= 0);

    do
    {
        cout << "Enter sex(Male or Femail):";
        cin >> SEX;
    } while (SEX != "Male" && SEX != "male" && SEX != "Female" && SEX != "female");

    do
    {
        cout << "Enter math: ";
        cin >> MATH;
    } while (MATH < 0 || MATH > 10);

    do
    {
        cout << "Enter physical: ";
        cin >> PHYSICAL;
    } while (PHYSICAL < 0 || PHYSICAL > 10);

    do
    {
        cout << "Enter chemistry: ";
        cin >> CHEMISTRY;
    } while (CHEMISTRY < 0 || CHEMISTRY > 10);

    Student st(NAME, AGE, SEX, MATH, PHYSICAL, CHEMISTRY);
    database.push_back(st);

    cout << "\t\tStudent Add Successfully...." << endl;
}

void update(list<Student> &database)
{
    int id;
    string NAME;
    int AGE;
    string SEX;
    double MATH;
    double PHYSICAL;
    double CHEMISTRY;

    do
    {
        cout << "Enter id: ";
        cin >> id;
    } while (id < 100);

    for (auto up = database.begin(); up != database.end(); up++)
    {
        if (up->displayID() == id)
        {
            do
            {
                cout << "Enter name: ";
                fflush(stdin);
                getline(cin, NAME);
            } while (NAME == "\0");

            do
            {
                cout << "Enter age: ";
                cin >> AGE;
            } while (AGE <= 0);

            do
            {
                cout << "Enter sex(Male or Femail): ";
                cin >> SEX;
            } while (SEX != "Male" && SEX != "male" && SEX != "Female" && SEX != "female");

            do
            {
                cout << "Enter math: ";
                cin >> MATH;
            } while (MATH < 0 || MATH > 10);

            do
            {
                cout << "Enter physical: ";
                cin >> PHYSICAL;
            } while (PHYSICAL < 0 || PHYSICAL > 10);

            do
            {
                cout << "Enter chemistry: ";
                cin >> CHEMISTRY;
            } while (CHEMISTRY < 0 || CHEMISTRY > 10);
            up->editInf(NAME, AGE, SEX, MATH, PHYSICAL, CHEMISTRY);
            break;
        }
    }

    cout << "\t\tNot found" << endl;
}

void delSv(list<Student> &database)
{
    int id;
    int i = 0;

    do
    {
        cout << "Nhap id: ";
        cin >> id;
    } while (id < 1000);

    for (auto up = database.begin(); up != database.end(); up++)
    {
        if (up->displayID() == id)
        {
            database.erase(up);
            i++;
        }
    }
    if (i == 0)
    {
        cout << "\t\tNot found" << endl;
    }
}

void searchName(list<Student> &database)
{
    string name;
    int i = 0;
    do
    {
        cout << "Enter the name you want to find: ";
        fflush(stdin);
        getline(cin, name);
    } while (name == "\0");

    for (auto up = database.begin(); up != database.end(); up++)
    {
        if (up->displayName() == name)
        {
            up->display();
            i++;
        }
    }
    if (i == 0)
    {
        cout << "\t\tNot found: " << name << endl;
    }
}
void sortByName();
void sortByGPA();
void displayList(list<Student> &database)
{
    for (Student stu : database)
    {
        stu.display();
    }
}

int main(int argc, char const *argv[])
{
    list<Student> database;
    char choice;
    do
    {
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
        cout << "\t\t 8. Exit" << endl;
        cout << "\t\t Enter Your Choice: ";
        cin >> op;
        switch (op)
        {
        case 1:
            addNewSv(database);
            break;
        case 2:
            update(database);
            break;
        case 3:
            searchName(database);
            break;
        case 4:
            delSv(database);
            break;
            //        case 5:
            //       sortByName();
            //        break;
            //        case 6:
            //        sortByGPA();
            break;
        case 7:
            displayList(database);
            break;
        case 8:
            exit(1);
        default:
            cout << "\t\tInvalid Number ...." << endl;
        };
        cout << "\t\tDo u want to Continue [Y/N] ? :";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}