#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "../Header/management.hpp"

void setNumberTable(vector<Table> &k_table);
void addNewFood(list<Dish> &menu);
void findFood(list<Dish> &menu);
void updatePrice(list<Dish> &menu);
void delMenuFood(list<Dish> &menu);
void listMenuFood(list<Dish> &menu);
void menu1(list<Dish> &menu, vector<Table> &k_table);

int infTable(vector<Table> &k_table);
void checkTable(vector<Table> &k_table);
void addFood(list<Dish> &menu, vector<Table> &k_table);
// void changeFood(list<Dish> &menu, vector<Table> k_table);
// void delFood(list<Dish> &menu, vector<Table> k_table);
void listFoodTable(list<Dish> &menu);
// void bill(list<Dish> &menu, vector<Table> k_table);
void menu2(list<Dish> &menu, vector<Table> &k_table);
void Menu(list<Dish> &menu, vector<Table> &k_table);

#endif