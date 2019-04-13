
#ifndef UNTITLED7_READFROMFILE_H
#define UNTITLED7_READFROMFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "interface.h"
#include "writeToFile.h"
#include "MyPlane.h"
#include "MyFlight.h"
#include "MyEmployee.h"
#include "MyReservation.h"
#include "MyCustomer.h"

using namespace std;

class ReadFromFile {

public:
    /**
     *
     * @param file a specific file
     * @return the next id to the item that we choose
     */
    string getNewID(string file);

    /**
     *
     * @param info
     * @return vector of all the data from the info
     */
    vector<string> split(string info);

    /**
     *
     * @param file
     * @param id
     * @return get a specific file and id and return the data of the item
     */
    string findInfoById(string file, string id, int placeId);

    /**
     *
     * @param id
     * @return a specific employee according to his id
     */
    Employee *readEmployee(string id);

    /**
     *
     * @param id
     * @return a specific plane according to his id
     */
    Plane *readPlane(string id);

    /**
     *
     * @param id
     * @return a specific flight according to his id
     */
    Flight *readFlight(string id);

    /**
     *
     * @param id
     * @return a specific customer according to his id
     */
    Customer *readCustomer(string id);

    /**
     *
     * @param id
     * @return a specific resevation according to his id
     */
    Reservation *readReservetion(string id);

    /**
     *
     * @param x what we loook for
     * @param table where we search
     * @param pos of what we look for in the string
     * @return all the lines fit
     */
    vector<string> search(string x, vector<string> table, int pos);

    /**
     *
     * @param file
     * @return all thet lines of the file in a vector
     */
    vector<string> getTable(string file);
};


#endif //UNTITLED7_READFROMFILE_H
