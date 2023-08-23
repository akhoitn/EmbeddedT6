#include "../Header/gps.hpp"
#include <math.h>
void addValid(list<GPSPoint> &databaseGPS);
void isValid(list<GPSPoint> &databaseGPS);
void toRadians(list<GPSPoint> &databaseGPS);
void distanceTo(list<GPSPoint> &databaseGPS);

void addValid(list<GPSPoint> &databaseGPS)
{

    double LATITUDE_1;
    double LONGITUDE_1;
    double LATITUDE_2;
    double LONGITUDE_2;
    double RESULT;

    do
    {
        cout << "Enter the latitude: ";
        cin >> LATITUDE_1;
    } while (LATITUDE_1 < -90 || LATITUDE_1 > 90);

    do
    {
        cout << "Enter the longitude: ";
        cin >> LONGITUDE_1;
    } while (LONGITUDE_1 < -180 || LONGITUDE_1 > 180);

    do
    {
        cout << "Enter the latitude: ";
        cin >> LATITUDE_2;
    } while (LATITUDE_2 < -90 || LATITUDE_2 > 90);

    do
    {
        cout << "Enter the longitude: ";
        cin >> LONGITUDE_2;
    } while (LONGITUDE_2 < -180 || LONGITUDE_2 > 180);

    GPSPoint gps(LATITUDE_1, LONGITUDE_1, LATITUDE_2, LONGITUDE_2, RESULT);
    databaseGPS.push_back(gps);

    cout << "Add Valid Successfully" << endl;
}

void isValid(list<GPSPoint> &databaseGPS)
{

    for (auto gps : databaseGPS)
    {
        if (gps.getLatitude1() > -90 && gps.getLatitude1() < 90)
        {
            cerr << "The value of latitude 1 is ok" << endl;
        }
        else
            cerr << "The value of latitude 1 is wrong" << endl;
    }

    for (auto gps : databaseGPS)
    {
        if (gps.getLongitude1() > -180 && gps.getLongitude1() < 180)
        {
            cerr << "The value of longitude 1 is ok" << endl;
        }
        else
            cerr << "The value of longitude 1 is wrong" << endl;
    }

    for (auto gps : databaseGPS)
    {
        if (gps.getLatitude2() > -90 && gps.getLatitude2() < 90)
        {
            cerr << "The value of latitude 2 is ok" << endl;
        }
        else
            cerr << "The value of latitude 2 is wrong" << endl;
    }

    for (auto gps : databaseGPS)
    {
        if (gps.getLongitude2() > -180 && gps.getLongitude2() < 180)
        {
            cerr << "The value of longitude 2 is ok" << endl;
        }
        else
            cerr << "The value of longitude 2 is wrong" << endl;
    }
}

void toRadians(list<GPSPoint> &databaseGPS)
{
    double LATITUDE_1;
    double LONGITUDE_1;
    double LATITUDE_2;
    double LONGITUDE_2;

    for (auto gps = databaseGPS.begin(); gps != databaseGPS.end(); gps++)
    {
        LATITUDE_1 = (gps->getLatitude1() * Pi) / 180;
        gps->setLatitude1(LATITUDE_1);
    }

    for (auto gps = databaseGPS.begin(); gps != databaseGPS.end(); gps++)
    {
        LONGITUDE_1 = (gps->getLongitude1() * Pi) / 180;
        gps->setLongitude1(LONGITUDE_1);
    }

    for (auto gps = databaseGPS.begin(); gps != databaseGPS.end(); gps++)
    {
        LATITUDE_2 = (gps->getLatitude2() * Pi) / 180;
        gps->setLatitude2(LATITUDE_2);
    }

    for (auto gps = databaseGPS.begin(); gps != databaseGPS.end(); gps++)
    {
        LONGITUDE_2 = (gps->getLongitude2() * Pi) / 180;
        gps->setLongitude2(LONGITUDE_2);
    }
};

void distanceTo(list<GPSPoint> &databaseGPS)
{
    double RESULT = 0;
    // toRadians(databaseGPS);
    for (auto gps = databaseGPS.begin(); gps != databaseGPS.end(); gps++)
    {
        RESULT = 0.5 - cos(gps->getLatitude2() - gps->getLatitude1()) / 2 + cos(gps->getLatitude2())
         * (1 - cos(gps->getLongitude2() - gps->getLongitude1()) / 2);
        RESULT = 2 * EARTH_RADIUS * asin(sqrt(RESULT));

        gps->setResult(RESULT);
        
    }
    
    
}
void printCoordinate(list<GPSPoint> &databaseGPS)
{
    cout << "A: ";
    for (auto gps : databaseGPS)
    {
        printf("%.3f, %.3f", gps.getLatitude1(), gps.getLongitude1());
    }

    cout << endl;
    cout << "B: ";
    for (auto gps : databaseGPS)
    {
        printf("%.3f, %.3f", gps.getLatitude2(), gps.getLongitude2());
    }
}
