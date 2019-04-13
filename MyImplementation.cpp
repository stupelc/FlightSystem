
#include "MyImplementation.h"
#include "interface.h"
#include "writeToFile.h"
#include "MyEmployee.h"
#include "MyFlight.h"
#include "MyPlane.h"
#include "MyCustomer.h"
#include "MyReservation.h"
#include "checkValid.h"

/**
 *
 * @param seniority
 * @param birth_year
 * @param employer_id
 * @param title
 * @return a new employee according to the data that we get
 */
Employee *MyImplementation::addEmployee(int seniority, int birth_year, string employer_id, Jobs title) {
    ReadFromFile r;
    string id = r.getNewID("Employees.txt");
    //check the employer is
    for (int i = 0; i < employer_id.length(); i++) {

        if (employer_id[i] - '0' >= 0 && employer_id[i] - '0' <= 9) {
            continue;
        } else {
            __throw_bad_exception();
        }
    }

    if (birth_year < 0 || seniority < 0)
        __throw_bad_exception();

    MyEmployee *emp = new MyEmployee(id, seniority, birth_year, employer_id, title);

    //write the new employee to the file
    writeToFile write;
    write.writeEmployee(emp);

    employeeList.push_back(emp);
    return emp;
}

/**
 * @param id the employee id
 * @return a specific employee according to the id
 */
Employee *MyImplementation::getEmployee(string id) {

    ReadFromFile read;
    Employee *emp = read.readEmployee(id);
    this->employeeList.push_back(emp);
    return emp;
}

/**
 *
 * @param model_number
 * @param crew_needed
 * @param max_passangers
 * @return a new plane according to the data that we get
 */
Plane *MyImplementation::addPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers) {

    ReadFromFile r;
    string id = r.getNewID("Planes.txt");

    //check if the 2 maps in plane is correct
    for (int i = 0; i <= OTHER; i++) {
        if (!crew_needed.count((Jobs) i))
            crew_needed.insert(pair<Jobs, int>((Jobs) i, 0));
    }

    for (int i = 0; i <= SECOND_CLASS; i++) {
        if (!max_passangers.count((Classes) i))
            max_passangers.insert(pair<Classes, int>((Classes) i, 0));
    }

    Plane *plane = new MyPlane(id, model_number, crew_needed, max_passangers[FIRST_CLASS],
                               max_passangers[SECOND_CLASS]);

    //write the plane to the file
    writeToFile write;
    write.writePlane(plane);

    planeList.push_back(plane);
    return plane;
}

/**
 * @param id the plane id
 * @return a specific plane according to the id
 */
Plane *MyImplementation::getPlane(string id) {
    ReadFromFile read;
    Plane *pln = read.readPlane(id);
    planeList.push_back(pln);
    return pln;
}

/**
 * @param model_number
 * @param date
 * @param source
 * @param destination
 * @return a new flight according to the data that we get
 */
Flight *MyImplementation::addFlight(int model_number, Date date, string source, string destination) {
    ReadFromFile r;
    writeToFile w;

    checkValid valid;
    //first we need to check if there are a valid plane
    //checkValid *valid = new checkValid(r, w);
    string planeId = valid.checkAvailablePlane(model_number, date, r);
    if (planeId == "") {
        __throw_bad_exception();
    }
    vector<string> crew = valid.checkAvalibleCrew(planeId, date, r, w);
    if (crew[0] == "not valid") {
        __throw_bad_exception();
    }

    string id = r.getNewID("Flights.txt");
    Flight *flight = new MyFlight(id, model_number, date, source, destination);

    //write the flight to the table
    w.writeFlight(flight);
    Plane *plane = r.readPlane(planeId);
    planeList.push_back(plane);

    //update the tables
    //update the date:plane table
    w.writeToTable(date.getDate(), planeId, "Date_Plane.txt");
    //update the maxEconomy:flights table
    w.writeToTable(to_string(plane->getMaxEconomyClass()), id, "Max2_Flight.txt");
    //update the maxFirstClass:flights table
    w.writeToTable(to_string(plane->getMaxFirstClass()), id, "Max1_Flight.txt");

    for (string idEmployee:crew) {
        //update the employee:flight table
        w.writeToTable(idEmployee, id, "Employee_Flight.txt");
        //update the date:employee table
        w.writeToTable(date.getDate(), idEmployee, "Date_Employee.txt");
    }

    flightList.push_back(flight);
    return flight;
}

/**
 * @param id the flight id
 * @return a specific flight according to the data that we get
 */
Flight *MyImplementation::getFlight(string id) {
    ReadFromFile read;
    Flight *flt = read.readFlight(id);
    this->flightList.push_back(flt);
    return flt;
}

/**
 * @param full_name
 * @param priority
 * @return a new customer accordinig to the data that we get
 */
Customer *MyImplementation::addCustomer(string full_name, int priority) {
    ReadFromFile r;
    string id = r.getNewID("Customers.txt");

    //check if the customer is good
    if (priority < 1 || priority > 5) {
        __throw_bad_exception();
    }

    Customer *customer = new MyCustomer(id, full_name, priority);
    //write the customer to the file
    writeToFile write;
    write.writeCustomer(customer);

    customeList.push_back(customer);
    return customer;
}

/**
 * @param id the customer id
 * @return a specific customer according to what we get
 */
Customer *MyImplementation::getCustomer(string id) {
    ReadFromFile read;
    Customer *cus = read.readCustomer(id);
    customeList.push_back(cus);
    return cus;
}

/**
 * @param customerId
 * @param flightId
 * @param cls
 * @param max_baggage
 * @return a new reservetion according to the data that we get
 */
Reservation *MyImplementation::addResevation(string customerId, string flightId, Classes cls, int max_baggage) {
    ReadFromFile r;
    writeToFile w;
    checkValid checkValid;

    //check if the id is exist
    vector<string> checkIdExist = r.search(customerId, r.getTable("Customers.txt"), 0);
    if (checkIdExist.empty()) {
        __throw_bad_exception();
    }

    //check if the flight is exist
    string checkFlightExist = r.findInfoById("Flights.txt", flightId, 0);
    if (checkFlightExist.empty()) {
        __throw_bad_exception();
    }

    //check if there are a free flight for the reservation
    bool fligtIDAvalible = checkValid.checkAvalibleFlight(flightId, cls, r);
    if (!fligtIDAvalible) {
        __throw_bad_exception();
    }

    string id = r.getNewID("Reservations.txt");
    Reservation *reservation = new MyReservation(id, customerId, flightId, cls, max_baggage);

    //write the reservation to the file
    w.writeReservetion(reservation);

    reservationList.push_back(reservation);
    return reservation;
}

/**
 * @param id the resevation id
 * @return a specific resevation according to what we get
 */
Reservation *MyImplementation::getReservation(string id) {
    ReadFromFile read;
    Reservation *res = read.readReservetion(id);
    reservationList.push_back(res);
    return res;
}

/**
 * exit the program
 */
void MyImplementation::exit() {
    for (list<Employee *>::const_iterator it = this->employeeList.begin(); it != this->employeeList.end(); ++it) {
        delete *it;
    }

    for (list<Plane *>::const_iterator it = this->planeList.begin(); it != this->planeList.end(); ++it) {
        delete *it;
    }

    for (list<Flight *>::const_iterator it = this->flightList.begin(); it != this->flightList.end(); ++it) {
        delete *it;
    }

    for (list<Customer *>::const_iterator it = this->customeList.begin(); it != this->customeList.end(); ++it) {
        delete *it;
    }

    for (list<Reservation *>::const_iterator it = this->reservationList.begin();
         it != this->reservationList.end(); ++it) {
        delete *it;
    }
}