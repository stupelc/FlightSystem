#ifndef UNTITLED7_MYFLIGHT_H
#define UNTITLED7_MYFLIGHT_H

#include <map>
#include <list>
#include <string>
#include <vector>
#include "interface.h"

using namespace std;

class MyFlight : public Flight {
public:
    int modelNumber;
    Date date;
    string source;
    string destination;
    string ID;
    vector<string> crew;
    list<Employee *> employees;
    bool crewWasRead=false;

    /**
     *
     * @param id the id of the flight
     * @param modelNumber the model number
     * @param date the date of the flight
     * @param source the source of the flight
     * @param destination the destinition of the flight
     */
    MyFlight(string id, int modelNumber, const Date &date, const string &source, const string &destination);

    /**
     *
     * @return the model number
     */
    int getModelNumber();

    /**
     *
     *
     * @return the list of the reservations
     */
    list<Reservation *> getReservations();

    /**
     *
     * @return the assigned crew
     */
    list<Employee *> getAssignedCrew();

    /**
     *
     * @return the date of the flight
     */
    Date getDate();

    /**
     *
     * @return the source of the flight
     */
    string getSource();

    /**
     *
     * @return the destinition of the flight
     */
    string getDestination();

    /**
     *
     * @return the id of the flight
     */
    string getID();

    ~MyFlight();
};

#endif //UNTITLED7_MYFLIGHT_H