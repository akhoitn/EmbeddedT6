#ifndef func_hpp
#define func_hpp

#include <string>
#include <iostream>
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

#endif 