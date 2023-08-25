#include"../Header/abs.hpp"
#include"../Header/car.hpp"
#include"../Header/wheel.hpp"

int main()
{
    Car car;
    Wheel wheel;
    ABS ABS_system(&car);

    double speed;
    cout<<"Enter the speed : "; cin >> speed;
    wheel.setSpeed(speed);

    double weight;
    cout<<"Enter the weight: "; cin >> weight;
    car.setWeight(weight);

    double customer;
    cout<<"Enter the weight of customer: "; cin >> customer;
    car.addCustomer(customer);

    cout<<"Status: "<< endl;
    ABS_system.applyBrakes();

    return 0;

}