#include "../Header/control.hpp"
#include "../Header/dc.hpp"
#include "../Header/feed.hpp"

int main()
{
    double voltage, max_Current;
    cout << "Enter voltage: ";
    cin >> voltage;
    cout << "Enter max current: ";
    cin >> max_Current;
    DCMotor motor(voltage, max_Current);

    double overload = max_Current;
    double overheat= voltage * voltage* max_Current;

    Feedback_System feedback(&overload, &overheat);
  
    DCMotorController motor_controller(voltage, max_Current, &motor, &feedback);


    while (1)
    {
        motor_controller.checkCondition();
    }



    return 0;
}