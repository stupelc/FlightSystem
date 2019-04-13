#ifndef UNTITLED7_WRITETOFILE_H
#define UNTITLED7_WRITETOFILE_H

#include "MyEmployee.h"
#include "MyPlane.h"
#include "MyFlight.h"
#include "MyReservation.h"

class writeToFile {

public:
    /**
     *
     * @param newEmployee
     * get a new employee and write it into thte "Employee" file
     */
    void writeEmployee(Employee *newEmployee);

    /**
     *
     * @param newPlane
     * get a new plane and write it into the "Plane" file
     */
    void writePlane(Plane *newPlane);

    /**
     *
     * @param newCustomer
     * get a new customer and write it into the "Customer" file
     */
    void writeCustomer(Customer *newCustomer);

    /**
     *
     * @param newFlight
     * get a new flight and write it into the "Flight" file
     */
    void writeFlight(Flight *newFlight);

    /**
     *
     * @param newReservetion
     * get a new resevation and write it into the "Resevation" file
     */
    void writeReservetion(Reservation *newReservetion);

    /**
     *
     * @param a the first item we write
     * @param b the secind item we write
     * @param table the table we write to
     */
    void writeToTable (string a,string b,string table);

    string wordJobs (int j);


};

#endif //UNTITLED7_WRITETOFILE_H
