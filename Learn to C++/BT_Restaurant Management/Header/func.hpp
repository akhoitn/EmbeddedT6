#ifndef FUNC_HPP
#define FUNC_HPP

#include <iostream>
#include <vector>
#include <string>

#include "../Header/func.hpp"
using namespace std;

class Dish
{
private:
    int ID;
    string NAME;
    int PRICE;

public:
    Dish(int id = 0, string name = "", int price = 0)
    {
        this->ID = id;
        this->NAME = name;
        this->PRICE = price;
    }
    void setName(string name)
    {
        NAME = name;
    }
    void setPrice(int price)
    {
        PRICE = price;
    }
    void setId(int id)
    {
        ID = id;
    }
    int getId()
    {
        return ID;
    }
    string getName()
    {
        return NAME;
    }
    int getPrice()
    {
        return PRICE;
    }
};

/// /////////////////////////////////////////////
class DishOnTable : public Dish
{
private:
    int NUMBERDISH;

public:
    DishOnTable(int numberDish = 0)
    {
        this->NUMBERDISH = numberDish;
    }
    void setNumberDish(int numberDish)
    {
        NUMBERDISH = numberDish;
    }
    int getNumberDish()
    {
        return NUMBERDISH;
    }
};

///////////////////////////////////////////////
class Table
{
private:
    vector<DishOnTable> databaseDishOnTable;
    int NUMBERTABLE;
    bool STATUS;

public:
    Table(int numberTable)
    {
        this->NUMBERTABLE = numberTable;
    }
    void setNumberTable(int numberTable)
    {
        NUMBERTABLE = numberTable;
    }
    void setStatus(int status)
    {
        STATUS = status;
    }
    int getNumberTable()
    {
        return NUMBERTABLE;
    }
    bool getStatus()
    {
        return STATUS;
    }
    vector<DishOnTable> &getDatabaseDishOnTable()
    {
        return databaseDishOnTable;
    }
};


void setQuantityTable(vector<Table> &databaseTable);
void prinListTable(vector<Table> &databaseTable);
void setTable(vector<Table> &databaseTable);
void addDishOnTable(vector<DishOnTable> &databaseDishOnTable, vector<Dish> &databaseDishOnMenu);
void deleteDishOnTable(vector<DishOnTable> &databaseDishOnTable, vector<Dish> &databaseDishOnMenu);
void editDishOnTable(vector<DishOnTable> &databaseDishOnTable);
void prinDishOnTable(vector<DishOnTable> &databaseDishOnTable, vector<Dish> &databaseDishOnMenu);
void Bill(vector<DishOnTable> &databaseDishOnTable, vector<Dish> &databaseDishOnMenu);
void addDishOnMenu(vector<Dish> &databaseDishOnMenu);
void prinDishOnMenu(vector<Dish> &databaseDishOnMenu);
void deleteDishOnMenu(vector<Dish> &databaseDishOnMenu);
void editDishOnMenu(vector<Dish> &databaseDishOnMenu);
void Staff(vector<Dish> &databaseDishOnMenu, vector<Table> &databaseTable, vector<DishOnTable> &databaseDishOnTable);
void Manager(vector<Dish> &databaseDishOnMenu);
#endif