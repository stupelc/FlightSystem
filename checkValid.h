#ifndef UNTITLED7_CHECKVALID_H
#define UNTITLED7_CHECKVALID_H

#include <string>
#include "ReadFromFile.h"
#include "writeToFile.h"

using namespace std;

class checkValid {
public:
    /**
     *
     * @param modelNumber the modelNumber
     * @param date a specific date
     * @param reader read from file
     * @return the id of the plane who available in a specific date
     */
    string checkAvailablePlane(int modelNumber, const Date &date, ReadFromFile reader);

    /**
     *
     * @param planeId the id of the plane
     * @param date the date
     * @param reader read from the file
     * @param writer write from the file
     * @return a vector of all the "employees" avalible in a specific date
     */
    vector<string> checkAvalibleCrew(string planeId, Date date, ReadFromFile reader, writeToFile writer);

    /**
     *
     * @param flightId the id of the plane
     * @param cls the class we use on
     * @param reader read from file
     * @return 'true' if there is an avalible place in the flight, 'false' otherwise
     */
    bool checkAvalibleFlight(string flightId, Classes cls, ReadFromFile reader);

};


#endif //UNTITLED7_CHECKVALID_H
