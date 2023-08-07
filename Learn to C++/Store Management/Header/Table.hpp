#ifndef MANAGEMENT_HPP
#define MANAGEMENT_HPP

/*
* File: Management.hpp
* Author: Anh Khoi
* Date: 07/08/2023
* Description: This is a file function table
*/

#include <iostream>
#include <list>
#include <string>
#include"../Header/Choose.hpp"

using namespace std;



typedef enum Status{
    Open,
    Close
}st;

class Table{
    private:
    st STATUS;
    int TOTAL;

    protected:
    list <Choose> order;

    public:
    void setStatus(st status);
    st getStatus();

    void addFoodToTable(Choose food);
    void backFood();
    void bill();

};


#endif