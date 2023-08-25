#ifndef FEED_HPP
#define FEED_HPP

#include<iostream>

#define LOAD_LIMIT 100
#define HEAT_LIMIT 100

using namespace std;

class Feedback_System{

    private:
    double *Load;
    double *Heat;

    public:
    Feedback_System (double *load, double *heat)
    {
        Load = load;
        Heat = heat;
    }
    bool overloadDetected()
    {
        ((*Load) > LOAD_LIMIT);
    }

    bool overheatDetected()
    {
         return ((*Heat) > HEAT_LIMIT);
    }
};


#endif