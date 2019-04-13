#ifndef UNTITLED7_MYEMPLOYEE_H
#define UNTITLED7_MYEMPLOYEE_H

#include <map>
#include <list>
#include <string>
#include "interface.h"

using namespace std;

class MyEmployee : public Employee {
public:
    int seniority;
    int birthYear;
    string idEmployer;
    Jobs title;
    string ID;
    Employee* employer = nullptr;
    bool wasRead = false;
public:
    /**
     *
     * @param id of the employee
     * @param seniority of the employee
     * @param birthYear of the employee
     * @param idEmployer of the employy
     * @param title - a job of the employee
     * cunstructor
     */
    MyEmployee(string id,int seniority, int birthYear, string idEmployer, Jobs title);

    /**
     *
     * @return the seniority of the employee
     */
    int getSeniority();

    /**
     *
     * @return the birth year of the employee
     */
    int getBirthYear();

    /**
     *
     * @return the employer of the employee
     */
    Employee *getEmployer();

    /**
     * return the job of the employee
     * @return
     */
    Jobs getTitle();

    /**
     *
     * @return the job of the employee
     */
    string getID();

    /**
     * destructor - employee
     */
    ~MyEmployee();
};


#endif //UNTITLED7_MYEMPLOYEE_H
