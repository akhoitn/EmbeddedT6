#ifndef MANAGEMENT_H
#define MANAGEMENT_H

/*
* File: Management.hpp
* Author: Anh Khoi
* Date: 07/08/2023
* Description: This is a file include function declaration of food
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;



class Management
{
private:
    string NAME_FOOD;
    int STT;
    int ID;
    int PRICE;
   

public:
    Management(string name_food, int price);
    Management();

    int getID();
    int getSTT();

    void setNameFood(string name_food);
    string getNameFood();
    void setPrice(int price);
    int getPrice();
};



#endif