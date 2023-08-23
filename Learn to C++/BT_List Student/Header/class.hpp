#ifndef CLASS_HPP
#define CLASS_HPP

#include "../Header/class.hpp"
#include <iostream>
#include <string>
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
    void cal_GPA_Rank();

public:
    Student(string name, int age, double math, double chemistry, double physical, TypeSex sex)
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
    }

    int getID()
    {
        return ID;
    }

    void setName(string name)
    {
        NAME = name;
    }
    string getName()
    {
        return NAME;
    }

    void setAge(int age)
    {
        AGE = age;
    }
    int getAge()
    {
        return AGE;
    }

    void setMath(double math)
    {
        MATH = math;
        setRank();
    }
    double getMath()
    {
        return MATH;
        setRank();
    }

    void setPhysical(double physical)
    {
        PHYSICAL = physical;
        setRank();
    }

    double getPhysical()
    {
        return PHYSICAL;
    }

    void setChemistry(double chemistry)
    {
        CHEMISTRY = chemistry;
    }
    double getChemistry()
    {
        return CHEMISTRY;
    }

    double getGPA()
    {
        return (MATH + PHYSICAL + CHEMISTRY) / 3;
    }

    TypeSex getSex()
    {
        return SEX;
    }
    void setSex(TypeSex sex)
    {
       SEX = sex;
    }
    TypeRank getRank()
    {
        return RANK;
    }

    void setRank()
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
};


#endif