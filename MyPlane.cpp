#include <map>
#include <list>
#include <string>
#include "MyPlane.h"

using namespace std;

/**
 *
 * @param id the id of the plane
 * @param modelNumber of the plane
 * @param crewNeeded in the plane
 * @param maxFirstClass the num of people in the first class
 * @param maxEconomyClass the num od people in the second class
 * constructor
 */
MyPlane::MyPlane(string id, int modelNumber, const map<Jobs, int> &crewNeeded, int maxFirstClass, int maxEconomyClass) {
    this->crewNeeded = crewNeeded;
    this->maxFirstClass = maxFirstClass;
    this->maxEconomyClass = maxEconomyClass;
    this->modelNumber = modelNumber;
    this->ID = id;
}

/**
 *
 * @return the model number of the plane
 */
int MyPlane::getModelNumber() {
    return modelNumber;
}

/**
 *
 * @return a map between the jobs and the num of people we need for every job
 */
map<Jobs, int> MyPlane::getCrewNeeded() {
    return crewNeeded;
}

/**
 *
 * @return the num of people in the first class
 */
int MyPlane::getMaxFirstClass() {
    return maxFirstClass;
}

/**
 *
 * @return the num of people in the second class
 */
int MyPlane::getMaxEconomyClass() {
    return maxEconomyClass;
}

string MyPlane::getID() {
    return this->ID;
}

MyPlane::~MyPlane() {

}