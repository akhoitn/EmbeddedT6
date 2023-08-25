#ifndef WHEEL_HPP
#define WHEEL_HPP

#include <iostream>

using namespace std;

class Wheel
{
private:
    double Speed;

public:
    Wheel();
    double getSpeed() const;
    void setSpeed(double newSpeed);
};
Wheel::Wheel()
{
    Speed = 0;
}
double Wheel::getSpeed()const
{
    return Speed;
}
void Wheel::setSpeed(double newSpeed)
{
    Speed = newSpeed;
}

#endif