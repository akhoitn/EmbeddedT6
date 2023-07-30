#include <iostream>
#include <string>

using namespace std;

class Obj  

{
private:
    string Name; 
    int Age;    
    string Sex; 
    int ID;
    int *ptr;

public:
    Obj(string name, int age, string sex);
    ~Obj();
    void Display();
};