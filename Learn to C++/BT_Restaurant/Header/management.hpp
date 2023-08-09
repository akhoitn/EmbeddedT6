#ifndef MANAGEMENT_HPP
#define MANAGEMENT_HPP

/*
 * File: dish.hpp
 * Author: Anh Khoi
 * Date: 07/08/2023
 * Description: This is a file include function declaration of food
 */

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Header/management.hpp"

using namespace std;

class Dish
{
private:
    string NAME_FOOD;
    int STT;
    int ID;
    int PRICE;
    int QUANTITY;

public:
    Dish(string name_food, int price);

    void setQuantity(int quantity);
    int getQuantity();

    int getID();
    int getSTT();

    void setNameFood(string name_food);
    string getNameFood();

    void setPrice(int price);
    int getPrice();
};
class Table
{
private:
    int NUMBER_TABLE;
    bool STATUS = false;

public:
    Table(int number_table, bool status);

    int getNumberTable();

    bool setStatus(int status);
    bool getStatus();
};

#endif