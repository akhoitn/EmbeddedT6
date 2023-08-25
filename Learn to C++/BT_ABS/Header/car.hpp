#ifndef CAR_HPP
#define CAR_HPP

#include"../Header/wheel.hpp"


class Car{
    private:
    Wheel wheel;
    double Weight;
    double CustomerWeight;
    public:
    Car()
    {
        Weight = 1000;
        CustomerWeight = 0;
    }
    void setWeight(double newWeight)
    {
        Weight = newWeight;
    }
    double getWeight()
    {
        return Weight;
    }
    void addCustomer(double CustomerWeight)
    {
        CustomerWeight += CustomerWeight;
    }
    double getCustomerWeight(double CustomerWeight)
    {
        return CustomerWeight;
    }
    double getTotalWeight()
    {
        return (Weight + CustomerWeight);
    }
    double getWheelSpeed()
    {
        return this->wheel.getSpeed();
    }
};


#endif