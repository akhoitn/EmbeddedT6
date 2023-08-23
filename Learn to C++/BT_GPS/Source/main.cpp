#include "../Header/gps.hpp"
void addValid(list<GPSPoint> &databaseGPS);
void isValid(list<GPSPoint> &databaseGPS);
void toRadians(list<GPSPoint> &databaseGPS);
void distanceTo(list<GPSPoint> &databaseGPS);
void printCoordinate(list<GPSPoint> &databaseGPS);
void distanceTo(list<GPSPoint> &databaseGPS);
int main()
{
    list<GPSPoint> databaseGPS;

    double LATITUDE_1;
    double LONGITUDE_1;
    double LATITUDE_2;
    double LONGITUDE_2;
    double RESULT;

    addValid(databaseGPS);
    isValid(databaseGPS);
    toRadians(databaseGPS);
    printCoordinate(databaseGPS);

    distanceTo(databaseGPS);
    cout << endl;
    cout << "The distance between two A and B: ";
    for (auto gps = databaseGPS.begin(); gps != databaseGPS.end(); gps++)
    {
        printf("%.3f", gps->getResult());
    }
    return 0;
}