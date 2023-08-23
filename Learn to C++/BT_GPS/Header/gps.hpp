#ifndef GPS_HPP
#define GPS_HPP

#include <iostream>
#include <string>
#include <list>
#include <math.h>

using namespace std;

#define EARTH_RADIUS 6371
#define Pi 3.14

using namespace std;

class GPSPoint
{

private:
    double LATITUDE_1;
    double LONGITUDE_1;
    double LATITUDE_2;
    double LONGITUDE_2;
    double RESULT;

public:
    GPSPoint(double latitude_1, double longitude_1, double latitude_2, double longitude_2, double result)
    {
        LATITUDE_1 = latitude_1;
        LONGITUDE_1 = longitude_1;

        LATITUDE_2 = latitude_2;
        LONGITUDE_2 = longitude_2;

        RESULT = result;
    }

    double getLatitude1()
    {
        return LATITUDE_1;
    }
    void setLatitude1(double latitude_1)
    {
        LATITUDE_1 = latitude_1;
    }

    double getLongitude1()
    {
        return LONGITUDE_1;
    }
    void setLongitude1(double longitude_1)
    {
        LONGITUDE_1 = longitude_1;
    }

    double getLatitude2()
    {
        return LATITUDE_2;
    }
    void setLatitude2(double latitude_2)
    {
        LATITUDE_2 = latitude_2;
    }

    double getLongitude2()
    {
        return LONGITUDE_2;
    }
    void setLongitude2(double longitude_2)
    {
        LONGITUDE_2 = longitude_2;
    }

    double getResult()
    {
        return RESULT;
    }
    void setResult(double result)
    {
        RESULT = result;
    }
    void addValid(list<GPSPoint> &databaseGPS);
    void isValid(list<GPSPoint> &databaseGPS);
    void toRadians(list<GPSPoint> &databaseGPS);
    void distanceTo(list<GPSPoint> &databaseGPS);
};



#endif