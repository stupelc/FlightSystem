
#include <map>
#include <list>
#include <string>
#include "ReadFromFile.h"

using namespace std;

MyReservation::MyReservation(string id, const string &idCustomer, const string &idFlight, Classes Class,
                             int maxBaggage) {
    this->idFlight = idFlight;
    this->idCustomer = idCustomer;
    this->Class = Class;
    this->maxBaggage = maxBaggage;
    this->ID = id;
}

/**
 *
 * @return the customer of the resevation
 */
Customer *MyReservation::getCustomer() {
    ReadFromFile read;
    return read.readCustomer(idCustomer);
}

/**
 *
 * @return the flight of the resevation
 */
Flight *MyReservation::getFlight() {
    ReadFromFile read;
    return read.readFlight(idFlight);
}

/**
 *
 * @return the class of the resevation (first or second class)
 */
Classes MyReservation::getClass() {
    return Class;
}

/**
 *
 * @return the max baggage of the resevation
 */
int MyReservation::getMaxBaggage() {
    return maxBaggage;
}

/**
 *
 * @return the id of the resevation
 */
string MyReservation::getID() {
    return this->ID;
}

/**
 * destructor - resevation
 */
MyReservation::~MyReservation() {
}


