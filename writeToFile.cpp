#include "writeToFile.h"
#include "MyPlane.h"
#include "MyFlight.h"
#include "MyEmployee.h"
#include "MyReservation.h"
#include "MyCustomer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

/**
 *
 * @param newEmployee
 * get a new employee and write it into the "Employee" file
 */
void writeToFile::writeEmployee(Employee *newEmployee) {
    ofstream fileEmployee;
    fileEmployee.open("Employees.txt", ios::out | ios::app | ios::ate);
    if (!fileEmployee.is_open()) {
        __throw_bad_exception();
    }
    string idEmployer;
    if (newEmployee->getEmployer() == nullptr) {
        idEmployer = "0";
    } else {
        idEmployer = newEmployee->getEmployer()->getID();
    }

    string job;
    switch (newEmployee->getTitle()) {
        case MANAGER:
            job = "MANAGER";
            break;
        case NAVIGATOR:
            job = "NAVIGATOR";
            break;
        case FLY_ATTENDANT:
            job = "FLY_ATTENDANT";
            break;
        case PILOT:
            job = "PILOT";
            break;
        case OTHER:
            job = "OTHER";
            break;
        default:
            break;
    }
    string id = newEmployee->getID();
    int birthYear = newEmployee->getBirthYear();
    int seniority = newEmployee->getSeniority();

    fileEmployee << id << "," << birthYear << "," << seniority << "," << job << "," << idEmployer << "\n";
    fileEmployee.close();
}

/**
 *
 * @param newPlane
 * get a new plane and write it into the "Plane" file
 */
void writeToFile::writePlane(Plane *newPlane) {
    ofstream filePlane;
    filePlane.open("Planes.txt", ios::out | ios::app | ios::ate);
    if (!filePlane.is_open()) {
        __throw_bad_exception();
    }
    string idPlane = newPlane->getID();
    int modeNumber = newPlane->getModelNumber();
    int maxFirstClass = newPlane->getMaxFirstClass();
    int maxEconomyClass = newPlane->getMaxEconomyClass();
    map<Jobs, int> crewNeeded = newPlane->getCrewNeeded();


    filePlane << idPlane << "," << modeNumber << "," << maxFirstClass << "," << maxEconomyClass;
    //now we are wanna to write the map of the crew needed
    for (auto const &crew : crewNeeded) {
        filePlane << "," << crew.second;
    }

    filePlane << "\n";
    filePlane.close();
}

/**
 *
 * @param newCustomer
 * get a new customer and write it into the "Customers" file
 */
void writeToFile::writeCustomer(Customer *newCustomer) {

    ofstream fileCustomer;
    fileCustomer.open("Customers.txt", ios::out | ios::app | ios::ate);
    if (!fileCustomer.is_open()) {
        __throw_bad_exception();
    }
    string idCustomer = newCustomer->getID();
    string fullName = newCustomer->getFullName();
    int priority = newCustomer->getPriority();

    fileCustomer << idCustomer << "," << fullName << "," << priority << "\n";

    fileCustomer.close();
}

/**
 *
 * @param newReservetion
 * get a new resevation and write it into the "Resevation" file
 */
void writeToFile::writeReservetion(Reservation *newReservetion) {

    ofstream fileReservetion;
    fileReservetion.open("Reservations.txt", ios::out | ios::app | ios::ate);
    if (!fileReservetion.is_open()) {
        __throw_bad_exception();
    }

    string idReservetion = newReservetion->getID();
    int maxBaggage = newReservetion->getMaxBaggage();

    string calsss;
    switch (newReservetion->getClass()) {
        case FIRST_CLASS:
            calsss = "FIRST_CLASS";
            break;
        case SECOND_CLASS:
            calsss = "SECOND_CLASS";
            break;
        default:
            break;
    }

    string id_customer = newReservetion->getCustomer()->getID();
    string id_flight = newReservetion->getFlight()->getID();


    fileReservetion << idReservetion << "," << id_customer << "," << id_flight << "," << maxBaggage << "," << calsss
                    << "\n";

    fileReservetion.close();
}

/**
 *
 * @param newFlight
 * get a new flight and write it into the "Flight" file
 */
void writeToFile::writeFlight(Flight *newFlight) {

    ofstream fileFlight;
    fileFlight.open("Flights.txt", ios::out | ios::app | ios::ate);
    if (!fileFlight.is_open()) {
        __throw_bad_exception();
    }

    string idFlight = newFlight->getID();
    int modelNumber = newFlight->getModelNumber();
    string source = newFlight->getSource();
    string destination = newFlight->getDestination();
    string date = newFlight->getDate().getDate();

    fileFlight << idFlight << "," << modelNumber << "," << source << "," << destination << "," << date << "\n";

    fileFlight.close();
}

/**
 *
 * @param a the first item we wanna to write
 * @param b the second item we wanna to write
 * @param table the table we wanna to write
 */
void writeToFile::writeToTable(string a, string b, string table) {
    ofstream file;
    file.open(table, ios::out | ios::app | ios::ate);
    if (!file.is_open()) {
        __throw_bad_exception();
    }
    file << a << "," << b << "\n";
    file.close();
}

string writeToFile::wordJobs (int j){
    switch (j){
        case 0:
            return "MANAGER";
        case 1:
            return "NAVIGATOR";
        case 2:
            return "FLY_ATTENDANT";
        case 3:
            return "PILOT";
        default:
            return "OTHER";

    }
}