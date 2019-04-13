#include <map>
#include <list>
#include <string>
#include "MyCustomer.h"

using namespace std;

/**
 *
 * @param fullName
 * @param priority
 * @param reservations
 */
MyCustomer::MyCustomer(const string &fullName, int priority, const list<Reservation *> &reservations) :
        fullName(fullName), priority(priority), reservations(reservations) {
    this->ID = ID;
    this->reservations = reservations;
    this->priority = priority;
    this->fullName = fullName;
}

/**
 *
 * @param id of the customer
 * @param fullName of the cusdtomer
 * @param priority of thte customer
 */
MyCustomer::MyCustomer(string id,const string &fullName, int priority) :
        fullName(fullName), priority(priority) {
    this->ID = id;
    this->priority = priority;
    this->fullName = fullName;
}

/**
 *
 * @return the full name of the customer
 */
string MyCustomer::getFullName() {
    return fullName;
}

/**
 *
 * @return  the priority of the customer
 */
int MyCustomer::getPriority() {
    return priority;
}

/**
 *
 * @return a list of resevation of the customer
 */
list<Reservation *> MyCustomer::getReservations() {
    return reservations;
}

/**
 *
 * @return the id of the customer
 */
string MyCustomer::getID() {
    return this->ID;
}

MyCustomer::~MyCustomer() {

}

