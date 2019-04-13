
#ifndef UNTITLED7_MYPLANE_H
#define UNTITLED7_MYPLANE_H

#include "interface.h"

using namespace std;

class MyPlane : public Plane {
public:
    int modelNumber;
    map<Jobs, int> crewNeeded;
    int maxFirstClass;
    int maxEconomyClass;
    string ID;

public:
    /**
     *
     * @param id the id of the plane
     * @param modelNumber of the plane
     * @param crewNeeded to the plane
     * @param maxFirstClass the num of people in the first class
     * @param maxEconomyClass the num of people in the second class
     */
    MyPlane(string id, int modelNumber, const map<Jobs, int> &crewNeeded, int maxFirstClass, int maxEconomyClass);

    /**
     *
     * @return the midel number of the plane
     */
    int getModelNumber();

    /**
     *
     * @return a map between the jobs and the num of people we need for every job
     */
    map<Jobs, int> getCrewNeeded();

    /**
     *
     * @return the num of people in the first class
     */
    int getMaxFirstClass();

    /**
     *
     * @return the num of people in the second class
     */
    int getMaxEconomyClass();

    /**
     *
     * @return the id of the plane
     */
    string getID();

    /**
     * destructor - plane
     */
    ~MyPlane();
};


#endif //UNTITLED7_MYPLANE_H