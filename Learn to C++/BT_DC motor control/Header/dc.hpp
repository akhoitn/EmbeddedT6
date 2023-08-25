#ifndef DC_HPP
#define DC_HPP

#include <iostream>
#include <string>
#include <list>

using namespace std;
typedef enum
{
    CLOCKWISE,
    COUNTERCLOCKWISE
} Direction;

class DCMotor
{

private:
    double VOLTAGE;
    double MAX_CURRENT;
    double SPEED;
    bool isRunning = false;
    Direction DIRECTION;

public:
    DCMotor(double voltage, double max_Current);
    double getVoltage();
    void setVoltage(double voltage);
    double getMax_Current();
    void setMax_Current(double max_Current);
    void setSpeed(double speed);
    void setDirection(Direction direction);
    bool IsRunning();
    void start(bool isRunning);
    void stop(bool isRunning);
};

DCMotor::DCMotor(double voltage, double max_Current)
{
    VOLTAGE = voltage;
    MAX_CURRENT = max_Current;
    SPEED = 0;
}
double DCMotor::getVoltage()
{
    return VOLTAGE;
}
void DCMotor::setVoltage(double voltage)
{
    VOLTAGE = voltage;
}
double DCMotor::getMax_Current()
{
    return MAX_CURRENT;
}
void DCMotor::setMax_Current(double max_Current)
{
    MAX_CURRENT = max_Current;
}

void DCMotor::setSpeed(double speed)
{
    SPEED = speed;
}
void DCMotor::setDirection(Direction direction)
{
    DIRECTION = direction;
}
bool DCMotor::IsRunning()
{
    return isRunning;
}

void DCMotor ::start(bool isRunning)
{
    isRunning = true;
    cerr << "Start motor" << endl;
}

void DCMotor::stop(bool isRunning)
{
    isRunning = false;
    cerr <<"Stop motor" << endl;
}


#endif