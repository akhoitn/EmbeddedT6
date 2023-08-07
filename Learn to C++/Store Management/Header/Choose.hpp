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
#include "../Header/Management.hpp"

using namespace std;



class Choose
{
    private:
        int NUMBER_FOOD;
        Management FOOD_ORDER;
        
    public:
        Choose(int number_food, Management food_order);

        void setNumberFood(int number_food);
        int getNumberFood();
        

        Management getFood();
};



#endif