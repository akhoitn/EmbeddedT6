#ifndef CHOOSE_HPP
#define CHOOSE_HPP

/*
* File: Management.hpp
* Author: Anh Khoi
* Date: 07/08/2023
* Description: This is a file choose food
*/

#include <iostream>
#include <string>
#include <list>
#include"../Header/management.hpp"

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