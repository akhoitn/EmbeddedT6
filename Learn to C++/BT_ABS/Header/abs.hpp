#ifndef ABS_HPP
#define ABS_HPP

#include "../Header/wheel.hpp"
#include "../Header/car.hpp"

class ABS
{
private:
    Car *ABS_System;
    double time = 60; // Time speed

    double Limit = 2000; // Limited brake force

    double brakeForce;

    double calculateBrakeForce(double wheelSpeed, double totalWeight)
    {

         brakeForce = totalWeight * (wheelSpeed / time);

        return brakeForce;
    }

public:
    ABS(Car *car)
    {
        ABS_System = car;
    }

     void applyBrakes() {
        double wheelSpeed = ABS_System->getWheelSpeed();
        double totalWeight = ABS_System->getTotalWeight();

        double brakeForce = calculateBrakeForce(wheelSpeed, totalWeight);

        if (brakeForce > Limit) {
        cerr << "Warning!!!" << endl;
        } else {
            cerr << "Brakes applied normally." << endl;
        }
    }
};

#endif