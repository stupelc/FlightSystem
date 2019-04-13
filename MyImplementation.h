#ifndef UNTITLED7_MYIMPLEMENTATION_H
#define UNTITLED7_MYIMPLEMENTATION_H

#include "interface.h"
#include "writeToFile.h"
#include "MyEmployee.h"
#include "MyFlight.h"
#include "MyPlane.h"
#include "MyCustomer.h"
#include "MyReservation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include "ReadFromFile.h"
#include "writeToFile.h"
#include "checkValid.h"


class MyImplementation : public Ex2 {
public:
    list<Employee *> employeeList;
    list<Plane *> planeList;
    list<Customer *> customeList;
    list<Reservation *> reservationList;
    list<Flight *> flightList;

    /**
     * @param seniority
     * @param birth_year
     * @param employer_id
     * @param title
     * @return a new employee according to the data that we get
     */
    Employee *addEmployee(int seniority, int birth_year, string employer_id, Jobs title);

    /**
     * @param id the employee id
     * @return the employee with this specific id
     */
    Employee *getEmployee(string id);

    /**
     *
     * @param model_number
     * @param crew_needed
     * @param max_passangers
     * @return a new plane according to the data that we get
     */
    Plane *addPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers);

    /**
     * @param id the plane id
     * @return the plane with this specific id
     */
    Plane *getPlane(string id);

    /**
     *
     * @param model_number
     * @param date
     * @param source
     * @param destination
     * @return a new flight according to the data that we get
     */
    Flight *addFlight(int model_number, Date date, string source, string destination);

    /**
     * @param id the flight id
     * @return the flight with this specific id
     */
    Flight *getFlight(string id);

    /**
     * @param full_name
     * @param priority
     * @return a new customer according to the data that we get
     */
    Customer *addCustomer(string full_name, int priority);

    /**
     * @param id the customer id
     * @return the customer with a specific id
     */
    Customer *getCustomer(string id);

    /**
     * @param customerId
     * @param flightId
     * @param cls
     * @param max_baggage
     * @return a new resevation according to the data that we get
     */
    Reservation *addResevation(string customerId, string flightId, Classes cls, int max_baggage);

    /**
     * @param id the resevation id
     * @return the resevation with a specific id
     */
    Reservation *getReservation(string id);

    /**
     * exit from the program
     */
    void exit();
};

#endif //UNTITLED7_MYIMPLEMENTATION_H