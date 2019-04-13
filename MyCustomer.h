#ifndef UNTITLED7_MYCUSTOMER_H
#define UNTITLED7_MYCUSTOMER_H

#include <map>
#include <list>
#include <string>
#include "interface.h"

using namespace std;

class MyCustomer : public Customer {
public:
    string fullName;
    int priority;
    list<Reservation *> reservations;
    string ID;

    MyCustomer(const string &fullName, int priority, const list<Reservation *> &reservations);

    /**
     *
     * @param id of the customer
     * @param fullName of the customer
     * @param priority of the customer
     * constructor
     */
    MyCustomer(string id,const string &fullName, int priority);

    /**
     *
     * @return the full name of the customer
     */
    string getFullName();

    /**
     *
     * @return the priority of the customer
     */
    int getPriority();

    /**
     *
     * @return a list of resevation of the customer
     */
    list<Reservation *> getReservations();

    /**
     *
     * @return the id of the customer
     */
    string getID();

    /**
     * destructorof customer
     */
    ~MyCustomer();
};

#endif //UNTITLED7_MYCUSTOMER_H
