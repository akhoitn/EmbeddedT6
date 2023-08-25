#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "../Header/dc.hpp"
#include "../Header/feed.hpp"

class DCMotorController
{

private:
    Feedback_System *Feedback;
    DCMotor *Motor;

public:
    DCMotorController(double voltage, double max_Current, DCMotor *motor, Feedback_System *feedback)
    {
        Motor = motor;
        Feedback = feedback;
    }

    void setMotorSpeed(double speed)
    {
        (*Motor).setSpeed(speed);
    }
    void setDirection_Motor(Direction direction)
    {
        (*Motor).setDirection(direction);
    }

    bool checkFeedbackSystem()
    {
        return ((*Feedback).overloadDetected())|| ((*Feedback).overheatDetected());
    }

    void checkCondition()
    {
        if(checkFeedbackSystem())
        {
            Motor_Control(false);
        }
    }
    
    void Motor_Control(bool isRunning)
    {
        if(isRunning == true)
        {
            (*Motor).start(isRunning);
            checkCondition();

        }else if(isRunning = false)
        {
            (*Motor).stop(isRunning);
        }
    }
};

#endif