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
    double MATH;
    double CHEMISTRY;
    double PHYSICAL;
    double GPA;
    TypeRank RANK;
    TypeSex SEX;

public:
    Student(string name, int age, TypeSex sex, double math, double physical, double chemistry);
    int getID();
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    void setMath(double math);
    double getMath();
    void setPhysical(double physical);
    double getPhysical();
    void setChemistry(double chemistry);
    double getChemistry();
    void setSex(TypeSex sex);
    TypeSex getSex();
    double getGPA();
    void setRank();
    TypeRank getRank();
};

Student::Student(string name, int age, TypeSex sex, double math, double physical, double chemistry)
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
    setMath(math);
    setPhysical(physical);
    setChemistry(chemistry);
    setRank();
    assert((math >= 0 && math <= 10) && "Invalid math score");
    assert((chemistry >= 0 && chemistry <= 10) && "Invalid chemistry score");
    assert((physical >= 0 && physical <= 10) && "Invalid physical score");
}

int Student::getID()
{
    return ID;
}

void Student::setName(string name)
{
    NAME = name;
}
string Student::getName()
{
    return NAME;
}

void Student::setAge(int age)
{
    AGE = age;
}
int Student::getAge()
{
    return AGE;
}

void Student::setMath(double math)
{
    MATH = math;
    setRank();
}
double Student::getMath()
{
    return MATH;
    setRank();
}

void Student::setPhysical(double physical)
{
    PHYSICAL = physical;
    setRank();
}

double Student::getPhysical()
{
    return PHYSICAL;
}

void Student::setChemistry(double chemistry)
{
    CHEMISTRY = chemistry;
}
double Student::getChemistry()
{
    return CHEMISTRY;
}

double Student::getGPA()
{
    return (MATH + PHYSICAL + CHEMISTRY) / 3;
}

TypeSex Student::getSex()
{
    return SEX;
}

void Student::setSex(TypeSex sex)
{
    SEX = sex;
}
TypeRank Student::getRank()
{
    return RANK;
}

void Student::setRank()
{
    if (getGPA() >= 8)
    {
        RANK = EXCELLENT;
    }
    else if (getGPA() >= 6.5)
    {
        RANK = GOOD;
    }
    else if (getGPA() >= 5)
    {
        RANK = AVERAGE;
    }
    else
    {
        RANK = BELOW_AVERAGE;
    }
}

void addSt(list<Student> &database)
{
    string NAME;
    int AGE;
    TypeSex SEX;
    double MATH;
    double PHYSICAL;
    double CHEMISTRY;

    do
    {
        cout << "Enter name: ";
        cin >> NAME;
    } while (NAME == "\0");

    do
    {
        cout << "Enter age: ";
        cin >> AGE;
    } while (AGE <= 0);

    int inputSex;
    do
    {
        cout << "Enter sex (0 = Female or 1 = Male):";
        cin >> inputSex;
        SEX = (TypeSex)inputSex;
        break;
    } while (inputSex != 0 || inputSex != 1);

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

    Student St(NAME, AGE, SEX, MATH, PHYSICAL, CHEMISTRY);
    database.push_back(St);

    cout << "\t\tStudent Add Successfully...." << endl;
}

void delSt(list<Student> &database)
{
    int ID;
    int i = 0;

    do
    {
        cout << "Enter ID: ";
        cin >> ID;
    } while (ID < 100);

    for (auto up = database.begin(); up != database.end(); up++)
    {
        if (up->getID() == ID)
        {
            database.erase(up);
            i++;
            cout << "\t\tStudent Delete Successfully...." << endl;
            break;
        }
    }
    if (i == 0)
    {
        cout << "\t\tNot found" << endl;
    }
}
void display(list<Student> &database)
{

    for (auto &st : database)
    {

        cout << "---------------------------------------" << endl;
        cout << "Name of Student: " << st.getName() << endl;
        cout << "ID of Student: " << st.getID() << endl;
        cout << "Age of Student: " << st.getAge() << endl;
        if (st.getSex() == 0)
        {
            cout << "Sex: Female" << endl;
        }
        else if (st.getSex() == 1)
        {
            cout << "Sex: Male" << endl;
        }
        cout << "Score of the math: " << st.getMath() << endl;
        cout << "Score of the physical: " << st.getPhysical() << endl;
        cout << "Score of the chemistry: " << st.getChemistry() << endl;
        cout << "Score of the GPA: " << st.getGPA() << endl;
        switch (st.getRank())
        {
        case EXCELLENT:
            cout << "Rank of Student: EXCELLENT";
            break;
        case GOOD:
            cout << "Rank of Student: GOOD";
            break;
        case AVERAGE:
            cout << "Rank of Student: AVERAGE";
            break;
        case BELOW_AVERAGE:
            cout << "Rank of Student: BELOW_AVERAGE";
            break;
        default:
            cout << "Not rank";
            break;
        }
        cout << endl;
    }
}

void searchName(list<Student> &database)
{
    string NAME;
    cout << "Enter the name of student that you want to find: ";
    cin >> NAME;
    list<Student> find;
    for (auto &st : database)
    {
        if (st.getName() == NAME)
        {
            find.push_back(st);
        }
    }
    if (find.empty())
    {
        cout << "Not found: " << NAME << endl;
    }
    else
    {
        display(find);
    }
}
void sortByGPA(list<Student> &database)
{
    list<Student> sort;
    bool flag;
    for (auto &st : database)
    {
        flag = false;
        for (auto j = sort.begin(); j != sort.end(); j++)
        {
            if (st.getGPA() > j->getGPA())
            {
                sort.insert(j, st);
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            sort.push_back(st);
        }
    }
    for (auto &st : sort)
    {
        cout << "---------------------------------------" << endl;
        cout << "---------------Sort By GPA-------------" << endl;
        cout << "Name of Student: " << st.getName() << endl;
        cout << "ID of Student: " << st.getID() << endl;
        cout << "Age of Student: " << st.getAge() << endl;
        if (st.getSex() == 0)
        {
            cout << "Sex: Female" << endl;
        }
        else if (st.getSex() == 1)
        {
            cout << "Sex: Male" << endl;
        }
        cout << "Score of the math: " << st.getMath() << endl;
        cout << "Score of the physical: " << st.getPhysical() << endl;
        cout << "Score of the chemistry: " << st.getChemistry() << endl;
        cout << "Score of the GPA: " << st.getGPA() << endl;
        switch (st.getRank())
        {
        case EXCELLENT:
            cout << "Rank of Student: EXCELLENT";
            break;
        case GOOD:
            cout << "Rank of Student: GOOD";
            break;
        case AVERAGE:
            cout << "Rank of Student: AVERAGE";
            break;
        case BELOW_AVERAGE:
            cout << "Rank of Student: BELOW_AVERAGE";
            break;
        default:
            cout << "Not rank";
            break;
        }
        cout << endl;
    }
}

void sortByName(list<Student> &database)
{

    list<Student> sort;
    bool flag;
    for (auto &st : database)
    {
        flag = false;
        for (auto j = sort.begin(); j != sort.end(); j++)
        {
            if (st.getName() < j->getName())
            {
                sort.insert(j, st);
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            sort.push_back(st);
        }
    }

    for (auto &st : sort)
    {
        cout << "---------------------------------------" << endl;
        cout << "---------------Sort By Name-------------" << endl;
        cout << "Name of Student: " << st.getName() << endl;
        cout << "ID of Student: " << st.getID() << endl;
        cout << "Age of Student: " << st.getAge() << endl;
        if (st.getSex() == 0)
        {
            cout << "Sex: Female" << endl;
        }
        else if (st.getSex() == 1)
        {
            cout << "Sex: Male" << endl;
        }
        cout << "Score of the math: " << st.getMath() << endl;
        cout << "Score of the physical: " << st.getPhysical() << endl;
        cout << "Score of the chemistry: " << st.getChemistry() << endl;
        cout << "Score of the GPA: " << st.getGPA() << endl;
        switch (st.getRank())
        {
        case EXCELLENT:
            cout << "Rank of Student: EXCELLENT";
            break;
        case GOOD:
            cout << "Rank of Student: GOOD";
            break;
        case AVERAGE:
            cout << "Rank of Student: AVERAGE";
            break;
        case BELOW_AVERAGE:
            cout << "Rank of Student: BELOW_AVERAGE";
            break;
        default:
            cout << "Not rank";
            break;
        }
        cout << endl;
    }
}
void update(list<Student> &database)
{
    int ID;
    string NAME;
    int AGE;
    TypeSex SEX;
    double MATH;
    double PHYSICAL;
    double CHEMISTRY;

    do
    {
        cout << "Enter ID: ";
        cin >> ID;
    } while (ID < 100);

    for (auto st = database.begin(); st != database.end(); st++)
    {
        if (st->getID() == ID)
        {
            int choice;
            char input;
            do
            {
                system("cls");
                int op;
                cout << "\t\t------------------------------" << endl;
                cout << "\t\t 1. Name of Student" << endl;
                cout << "\t\t 2. Age of Student" << endl;
                cout << "\t\t 3. Sex of Student" << endl;
                cout << "\t\t 4. Math of Student" << endl;
                cout << "\t\t 5. Physical of Student" << endl;
                cout << "\t\t 6. Chemistry of Student" << endl;
                cout << "\t\t 7. Display of Student List" << endl;
                cout << "\t\t 8. Exit" << endl;
                cout << "\t\t Enter Your Choice: ";
                cin >> op;
                switch (op)
                {
                case 1:
                    cout << "Enter name: ";
                    cin >> NAME;
                    st->setName(NAME);
                    break;
                case 2:
                    cout << "Enter age: ";
                    cin >> AGE;
                    st->setAge(AGE);
                    break;
                case 3:
                    int inputSex;
                    cout << "Enter sex: ";
                    cin >> inputSex;
                    SEX = (TypeSex)inputSex;
                    st->setSex(SEX);
                    break;
                case 4:
                    cout << "Enter math: ";
                    cin >> MATH;
                    st->setMath(MATH);
                    break;
                case 5:
                    cout << "Enter physical: ";
                    cin >> PHYSICAL;
                    st->setPhysical(PHYSICAL);
                    break;
                case 6:
                    cout << "Enter chemistry: ";
                    cin >> CHEMISTRY;
                    st->setChemistry(CHEMISTRY);
                    break;
                case 7:
                    display(database);
                    break;
                case 8:
                    exit(1);
                default:
                    cout << "\t\tInvalid Number ...." << endl;
                };
                cout << "\t\tDo u want to Continue [Enter 9 to back] ? :";
                cin >> choice;
            } while (choice == 9 || choice == 1 ||
                     choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8);
        }
    }
    cout << "\t\tNot found" << endl;
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
            addSt(database);
            break;
        case 2:
            update(database);
            break;
        case 3:
            searchName(database);
            break;
        case 4:
            delSt(database);
            break;
        case 5:
            sortByName(database);
            break;
        case 6:
            sortByGPA(database);
            break;
        case 7:
            display(database);
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
