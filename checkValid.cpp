
#include "checkValid.h"
#include "ReadFromFile.h"
#include "MyFlight.h"
#include "MyReservation.h"
#include "interface.h"

/**
 *
 * @param modelNumber the model of the number
 * @param date a specific date
 * @return check if there is an available plane in the specific date
 */
string checkValid::checkAvailablePlane(int modelNumber, const Date &date,ReadFromFile reader) {
    //find planes by there modeNumber
    vector<string> planes = reader.search(to_string(modelNumber), reader.getTable("Planes.txt"), 1);
    //get all the planes in process
    vector<string> date_planes = reader.getTable("Date_Plane.txt");
    vector<string> temp;
    for (string id:planes) {
        //temp holds all the dates this plane reserved
        temp = reader.search(id, date_planes, 1);
        if (temp.empty()) {
            //this plane doesnt exist at the table of "Data_Plane"
            return id;
        }
        if (reader.search(date.getDate(), temp, 0).empty()) {
            //this plane doesn't work in our date
            return id;
        }
    }
    return "";
}

/**
 *
 * @param planeId the id of the plane
 * @param date the date we need crew for
 * @return num of "employees" who can work in a specific date
 */
vector<string> checkValid::checkAvalibleCrew(string planeId, Date date,ReadFromFile reader,writeToFile writer) {

    Plane *plane = reader.readPlane(planeId);
    vector<string> employees = reader.getTable("Employees.txt");
    vector<string> dates_employees = reader.getTable("Date_Employee.txt");
    map<Jobs, int> crew = plane->getCrewNeeded();

    vector<string> temp, temp2, final;
    int sum = 0;

    for (auto pair:crew) {
        temp = reader.search(writer.wordJobs(pair.first), employees, 3);
        if (temp.size() < pair.second) {
            final.clear();
            break;
        }

        int amount = pair.second;
        sum += amount;
        for (auto pair2:temp) {
            if (amount == 0) {
                //we got all the people we need for the job
                break;
            }
            //dates of this employee
            temp2 = reader.search(pair2, dates_employees, 1);
            if (temp2.empty() || (reader.search(date.getDate(), temp2, 0).empty())) {
                //this employee free for us
                amount--;
                final.push_back(pair2);
            }
        }

        if (amount>0){
            //not enough people for this job
            final.clear();
            final.push_back("not valid");
            break;
        }

    }

    if (sum>final.size()){
        final.clear();
        final.push_back("not valid");
    }
    delete plane;
    return final;
}

/**
 *
 * @param flightId the flight id
 * @param cls the class we have
 * @return
 */
bool checkValid::checkAvalibleFlight(string flightId, Classes cls,ReadFromFile reader) {
    int max;
    string m;
    if (cls == FIRST_CLASS) {
        m = reader.split(reader.findInfoById("Max1_Flight.txt", flightId,1))[0];

    } else {
        m = reader.split(reader.findInfoById("Max2_Flight.txt", flightId,1))[0];
    }
    max = stoi(m);
    Flight *f = reader.readFlight(flightId);
    list<Reservation *> res = f->getReservations();
    int passengesr = 0;
    for (Reservation *r:res) {
        if (r->getClass() == cls) {
            passengesr++;
            if (max > passengesr) {
                break;
            }
        }
    }
    return max > passengesr;
}
