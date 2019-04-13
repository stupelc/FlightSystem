#include <map>
#include <list>
#include <string>
#include "MyEmployee.h"
#include "ReadFromFile.h"

using namespace std;

/**
 *
 * @param id of the employee
 * @param seniority of the employee
 * @param birthYear of the employee
 * @param idEmployer of the employee
 * @param title the job of the employee
 */
MyEmployee::MyEmployee(string id, int seniority, int birthYear, string idEmployer, Jobs title) {
    this->ID = id;
    this->title = title;
    this->birthYear = birthYear;
    this->idEmployer = idEmployer;
    this->seniority = seniority;
}

/**
 *
 * @return the seniority of the employee
 */
int MyEmployee::getSeniority() {
    return seniority;
}

/**
 *
 * @return the birth year of the employee
 */
int MyEmployee::getBirthYear() {
    return birthYear;
}

/**
 *
 * @return the employer of the employee
 */
Employee *MyEmployee::getEmployer() {
    if (wasRead == false) {
        ReadFromFile read;
        this->employer = read.readEmployee(this->idEmployer);
        wasRead = true;
    }
    return this->employer;
}

/**
 *
 * @return the job of the employee
 */
Jobs MyEmployee::getTitle() {
    return title;
}

/**
 *
 * @return the id of the employee
 */
string MyEmployee::getID() {
    return this->ID;
}

/**
 * destructor - employee
 */
MyEmployee::~MyEmployee() {
    delete this->employer;
}
