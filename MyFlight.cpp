#include <map>
#include <list>
#include <string>
#include "ReadFromFile.h"
#include "MyFlight.h"

using namespace std;

/**
 *
 * @param id id flight
 * @param modelNumber the model number
 * @param date the date
 * @param source
 * @param destination
 * constructor
 */
MyFlight::MyFlight(string id, int modelNumber, const Date &date, const string &source, const string &destination)
        : date(date) {
    this->ID = id;
    this->modelNumber = modelNumber;
    this->date = date;
    this->source = source;
    this->destination = destination;
}

/**
 *
 * @return the model number
 */
int MyFlight::getModelNumber() {
    return modelNumber;
}

/**
 *
 * @return the list of reservations
 */
list<Reservation *> MyFlight::getReservations() {
    ReadFromFile read;
    list<Reservation *> reservation;
    //get all the id reservation with the id of the flight
    vector<string> tempReservation = read.search(this->ID, read.getTable("Reservations.txt"), 2);
    for (string id:tempReservation) {
        reservation.push_back(read.readReservetion(id));
    }
    return reservation;
}

/**
 *
 * @return the assigned crew
 */
list<Employee *> MyFlight::getAssignedCrew() {
    ReadFromFile read;

    if (crewWasRead == false) {
        //we are gonna use in the table of "Flight_Employee" to get all the id employees of the flight
        vector<string> tempEmployees = read.search(this->ID, read.getTable("Employee_Flight.txt"), 1);
        for (string id:tempEmployees) {
            employees.push_back(read.readEmployee(id));
        }
        crewWasRead = true;
    }
    return employees;
}

/**
 *
 * @return the date
 */
Date MyFlight::getDate() {
    return date;
}

/**
 *
 * @return the source
 */
string MyFlight::getSource() {
    return source;
}

/**
 *
 * @return the destination
 */
string MyFlight::getDestination() {
    return destination;
}

/**
 *
 * @return the id of the flight
 */
string MyFlight::getID() {
    return this->ID;
}


MyFlight::~MyFlight() {
    if (employees.size() != 0) {
        //clear the data from the first time
        for (list<Employee *>::const_iterator it = this->employees.begin(); it != this->employees.end(); ++it) {
            delete *it;
        }
    }
}


