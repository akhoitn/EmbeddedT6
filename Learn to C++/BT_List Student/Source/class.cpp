#include "../Header/class.hpp"
#include "../Header/func.hpp"

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
    } while (inputSex != 0 && inputSex != 1);

    do
    {
        cout << "Enter math: ";
        cin >> MATH;
    } while (MATH < 0 && MATH > 10);

    do
    {
        cout << "Enter physical: ";
        cin >> PHYSICAL;
    } while (PHYSICAL < 0 && PHYSICAL > 10);

    do
    {
        cout << "Enter chemistry: ";
        cin >> CHEMISTRY;
    } while (CHEMISTRY < 0 && CHEMISTRY > 10);

    Student St(NAME, AGE, MATH, CHEMISTRY, PHYSICAL, SEX);
    database.push_back(St);

    cout << "\t\tStudent Add Successfully...." << endl;
    int key = 0;
    cout << "\n1: Add student more\n0: Return\nPls choice:";
    cin >> key;
    if (key == 1)
    {
        addSt(database);
    }
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
    int key = 0;
    cout << "\n1: Delete more\n0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        delSt(database);
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
        else
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
    int key = 0;
    cout << "Enter 0 to return: ";
    cin >> key;
    if (key == 0)
        return;
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

    int key = 0;
    cout << "Enter 0 to return: ";
    cin >> key;
    if (key == 0)
        return;
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
        back:
            int key = 0;
            system("cls");
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
            cin >> key;
            switch (key)
            {
            case 1:
                cout << "Enter name: ";
                cin >> NAME;
                st->setName(NAME);
                goto back;
                break;
            case 2:
                cout << "Enter age: ";
                cin >> AGE;
                st->setAge(AGE);
                goto back;
                break;
            case 3:
                int inputSex;
                cout << "Enter sex (0 = Female or 1 = Male): ";
                cin >> inputSex;
                SEX = (TypeSex)inputSex;
                st->setSex(SEX);
                goto back;
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
                goto back;
                break;
            case 6:
                cout << "Enter chemistry: ";
                cin >> CHEMISTRY;
                st->setChemistry(CHEMISTRY);
                goto back;
                break;
            case 7:
                display(database);
                goto back;
                break;
            case 0:
                return;
            default:
                cout << "\t\tInvalid Number ...." << endl;
            };
        }
    }
}

void sortByGPA(list<Student> &database)
{
    list<Student> temp;
    bool flag;
    for (auto st : database)
    {
        flag = false;
        for (auto st1 = temp.begin(); st1 != temp.end(); st1++)
        {
            if (st.getGPA() > st1->getGPA())
            {
                temp.insert(st1, st);
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            temp.push_back(st);
        }
    }
    for (auto st : temp)
    {
        cout << endl;
        cout << "---------Sort By GPA--------" << endl;
        cout << "Name of Student: " << st.getName() << endl;
        cout << "ID of Student: " << st.getID() << endl;
        cout << "Age of Student: " << st.getAge() << endl;
        if (st.getSex() == 0)
        {
            cout << "Sex: Female" << endl;
        }
        else
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
    }
    int key = 0;
     cout<<endl;
    cout << "Enter 0 to return: ";
    cin >> key;
    if (key == 0)
        return;
}

void sortByName(list<Student> &database)
{
    list<Student> temp;
    bool flag;
    for (auto st : database)
    {
        flag = false;
        for (auto st1 = temp.begin(); st1 != temp.end(); st1++)
        {
            if (st.getName() > st1->getName())
            {
                temp.insert(st1, st);
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            temp.push_back(st);
        }
    }
    for (auto st : temp)
    {
        cout << endl;
        cout << "---------Sort By GPA--------" << endl;
        cout << "Name of Student: " << st.getName() << endl;
        cout << "ID of Student: " << st.getID() << endl;
        cout << "Age of Student: " << st.getAge() << endl;
        if (st.getSex() == 0)
        {
            cout << "Sex: Female" << endl;
        }
        else
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
    }
    int key = 0;
     cout<<endl;
    cout << "Enter 0 to return: ";
    cin >> key;
    if (key == 0)
        return;
}