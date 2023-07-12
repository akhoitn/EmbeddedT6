#include "../Header/preson.hpp"

using namespace std;

Obj::Obj(string name, int age, string sex)
{
    static int id = 1;
    ptr = &id;
    ID = id;
    id++;

    Name = name;
    Age = age;
    Sex = sex;
}
Obj::~Obj()
{
    *ptr = 1;
    cout << "The name person: " << Name << endl;
}
void Obj::Display()
{
    cout << "ID: " << ID << endl;
    cout << "The name: " << Name << endl;
    cout << "The age: " << (int)Age << endl;
    cout << "The sex: " << Sex << endl;
    cout << "ID: " << ID << endl;
}

void test1()
{
    Obj dt("Khoi", 23, "Male");
    dt.Display();
    Obj dt1("Khoi1", 24, "Male");
    dt1.Display();
    Obj dt2("Khoi2", 26, "Male");
    dt2.Display();
}
void test2()
{
    Obj dt("Duy", 19, "Female");
    dt.Display();
}
int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}