
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ReadFromFile.h"
#include "writeToFile.h"
#include "MyPlane.h"
#include "MyFlight.h"
#include "MyEmployee.h"
#include "MyReservation.h"
#include "MyCustomer.h"

#define SIGH_DEVIDE ','
#define NEW_LINE '\n'

using namespace std;

/**
 *
 * @param file a specific file
 * @return the next id to the item that er choose
 */
string ReadFromFile::getNewID(string file) {

    ofstream write;
    write.open(file, ios::out | ios::app | ios::ate);
    // if a file stream wasn't successful opening a file
    if (!write.is_open()) {
        __throw_bad_exception();
    }
    write.close();

    ifstream readFile;
    readFile.open(file);
    if (!readFile.is_open()) {
        throw "can't create the file";
    }

    // read the last line of the file
    readFile.seekg(-2, ios_base::end);
    string lastLine, ID;
    int nextId;

    bool keepLooping = true;
    while (keepLooping) {
        char ch;
        // Get current byte's data
        readFile.get(ch);
        // If the data was at or before the 0th byte
        if ((int) readFile.tellg() <= 1) {
            // The first line is the last line
            readFile.seekg(0);
            // So stop there
            keepLooping = false;
            // If the data was a newline
        } else if (ch == '\n') {
            // Stop at the current position.
            keepLooping = false;
            // If the data was neither a newline nor at the 0 byte
        } else {
            // Move to the front of that data, then to the front of the data before it
            readFile.seekg(-2, ios_base::cur);
        }
    }

    string lastGivenID = "";
    getline(readFile, lastLine);

    if (lastLine == "") {
        return "1";
    }

    for (int i = 0; i < lastLine.length(); ++i) {
        if (lastLine[i] == SIGH_DEVIDE || lastLine[i] == NEW_LINE) {
            break;
        }
        lastGivenID += lastLine[i];
    }
    nextId = stoi(lastGivenID) + 1;
    ID = to_string(nextId);

    readFile.close();
    return ID;
}

/**
 *
 * @param info
 * @return a vector of all the data from the info
 */
vector<string> ReadFromFile::split(string info) {
    stringstream s(info);
    string part;
    vector<string> vec;
    while (getline(s, part, ',')) {
        vec.push_back(part);
    }
    return vec;

}

/**
 *
 * @param file
 * @param id
 * @return get a specific file and id and return the data of the item
 */
string ReadFromFile::findInfoById(string file, string id, int placeId) {
    ifstream readFile;
    readFile.open(file);
    if (!readFile.is_open()) {
        __throw_bad_exception();
    }
    //the info we wanna to find
    string line;
    while (getline(readFile, line)) {
        if (line.find(id, 0) != string::npos) {
            if (split(line)[placeId] != id)
                continue;
            break;
        }

    }
    readFile.close();
    return line;
}

/**
 *
 * @param id
 * @return a specific employee according to his id
 */
Employee *ReadFromFile::readEmployee(string id) {
    string info = findInfoById("Employees.txt", id, 0);
    vector<string> div_info;
    //when the info isn't null
    if (!info.empty()) {
        div_info = split(info);
        Jobs job;

        if (div_info[3] == "MANAGER")job = MANAGER;
        if (div_info[3] == "NAVIGATOR")job = NAVIGATOR;
        if (div_info[3] == "FLY_ATTENDANT")job = FLY_ATTENDANT;
        if (div_info[3] == "PILOT")job = PILOT;
        if (div_info[3] == "OTHER")job = OTHER;

        return new MyEmployee(div_info[0], stoi(div_info[1]), stoi(div_info[2]), div_info[4], job);
    }
    return nullptr;
}

/**
 *
 * @param id
 * @return a specific plane according to his id
 */
Plane *ReadFromFile::readPlane(string id) {
    string info = findInfoById("Planes.txt", id, 0);
    vector<string> div_info;
    //when the info isn't null
    if (!info.empty()) {
        div_info = split(info);
        map<Jobs, int> crewNeeded;

        for (int i = 0; i <= OTHER; ++i) {
            crewNeeded.insert(pair<Jobs, int>((Jobs) i, stoi(div_info[4 + i])));
        }
        return new MyPlane(div_info[0], stoi(div_info[1]), crewNeeded, stoi(div_info[2]), stoi(div_info[3]));
    }
    return nullptr;
}

/**
 *
 * @param id
 * @return a pecific flight according to his id
 */
Flight *ReadFromFile::readFlight(string id) {
    string info = findInfoById("Flights.txt", id, 0);
    vector<string> div_info;
    //when the info isn't null
    if (!info.empty()) {
        div_info = split(info);

        //write : idFlight << "," << modelNumber << "," << source << "," << destination << "," << date << "\n";
        return new MyFlight(div_info[0], stoi(div_info[1]), Date(div_info[4]), div_info[2], div_info[3]);
    }
    return nullptr;
}

/**
 *
 * @param id
 * @return a specific customer according to his id
 */
Customer *ReadFromFile::readCustomer(string id) {
    string info = findInfoById("Customers.txt", id, 0);
    vector<string> div_info;
    //when the info isn't null
    if (!info.empty()) {
        div_info = split(info);

        //id-fullName-priority
        return new MyCustomer(div_info[0], div_info[1], stoi(div_info[2]));
    }
    return nullptr;
}

/**
 *
 * @param id
 * @return a specific resevation according to his id
 */
Reservation *ReadFromFile::readReservetion(string id) {
    string info = findInfoById("Reservations.txt", id, 0);
    vector<string> div_info;
    //when the info isn't null
    if (!info.empty()) {
        div_info = split(info);

        Classes Class;
        if (div_info[4] == "FIRST_CLASS")Class = FIRST_CLASS;
        if (div_info[4] == "SECOND_CLASS")Class = SECOND_CLASS;

        //idReservetion - idCustomer - idFlight - maxBagges - class
        return new MyReservation(div_info[0], div_info[1], div_info[2], Class, stoi(div_info[3]));
    }
    return nullptr;
}

/**
 *
 * @param x what we look for
 * @param table where we search
 * @param pos what we look for in every line
 * @return all the lines fit
 */
vector<string> ReadFromFile::search(string x, vector<string> table, int pos) {
    vector<string> allOptions;
    vector<string> temp;
    for (int i = 0; i < table.size(); i++) {
        temp = split(table[i]);
        if (x == temp[pos]) {
            allOptions.push_back(temp[0]);
        }
    }
    return allOptions;
}

/**
 *
 * @param file
 * @return all the lines of the file in a vector
 */
vector<string> ReadFromFile::getTable(string file) {
    vector<string> table;

    ifstream readFile;
    readFile.open(file);
    if (!readFile.is_open()) {
        return table;
    }
    //the info we wanna to find
    string line;
    //push all the planes which have the modelNumber that we wants
    while (getline(readFile, line)) {
        table.push_back(line);
    }

    return table;
}