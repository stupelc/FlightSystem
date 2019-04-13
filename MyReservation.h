
#ifndef UNTITLED7_MYRESERVATION_H
#define UNTITLED7_MYRESERVATION_H

#include <map>
#include <list>
#include <string>
#include "interface.h"

using namespace std;

class MyReservation : public Reservation {
public:
    string idCustomer;
    string idFlight;
    Classes Class;
    int maxBaggage;
    string ID;

    /**
     *
     * @param id the id of the resevation
     * @param idCustomer of the resevation
     * @param idFlight of the resevation
     * @param Class the clss of the resevation
     * @param maxBaggage of the resevation
     * cunstructor
     */
    MyReservation(string id, const string &idCustomer, const string &idFlight, Classes Class, int maxBaggage);

    /**
     *
     * @return the customer of the resevation
     */
    Customer *getCustomer();

    /**
     *
     * @return the flight of the resevation
     */
    Flight *getFlight();

    /**
     *
     * @return the class of the resevation
     */
    Classes getClass();

    /**
     *
     * @return the max baggage of the resevation
     */
    int getMaxBaggage();

    /**
     *
     * @return the id of the resevation
     */
    string getID();

    /**
     * destructor
     */
    ~MyReservation();
};

#endif //UNTITLED7_MYRESERVATION_H
