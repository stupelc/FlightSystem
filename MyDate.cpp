#include <map>
#include <list>
#include <string>
#include "interface.h"

using namespace std;

/**
 *
 * @param date a date that we get
 * check the format of the date. the format: YYYY-MM-DD
 */
Date::Date(string date) {
    //start to check the format of the date
    if (date.length() > 10) {
        throw "Illegal argument";
    }

    for (int i = 0; i < 10; i++) {
        switch (i) {
            case 0:
            case 1:
            case 2:
            case 3: //check the YEAR
                if ((date[i] - '0') < 0 || (date[i] - '0') > 9)
                    throw "Illegal argument";
                break;
            case 4:
            case 7:
                if (date[i] != '-')
                    throw "Illegal argument";
                break;
            case 5: //and case 6 . check the MONTH
                if ((date[i] - '0') == 0) {
                    if ((date[i + 1] - '0') < 1 || (date[i + 1] - '0') > 9)
                        throw "Illegal argument";
                } else if ((date[i] - '0') == 1) {
                    if ((date[i + 1] - '0') < 0 || (date[i + 1] - '0') > 2)
                        throw "Illegal argument";
                } else
                    throw "Illegal argument";
                break;
            case 8: // and case 9. check the DAY
                if ((date[i] - '0') == 0) {
                    if ((date[i + 1] - '0') < 1 || (date[i + 1] - '0') > 9)
                        throw "Illegal argument";
                } else if ((date[i] - '0') == 1) {
                    if ((date[i + 1] - '0') < 0 || (date[i + 1] - '0') > 9)
                        throw "Illegal argument";
                } else if ((date[i] - '0') == 2) {
                    if ((date[i + 1] - '0') < 0 || (date[i + 1] - '0') > 9)
                        throw "Illegal argument";
                } else if ((date[i] - '0') == 3) {
                    if ((date[i + 1] - '0') < 0 || (date[i + 1] - '0') > 1)
                        throw "Illegal argument";
                } else
                    throw "Illegal argument";
                break;
            default:
                continue;
        }

    }
    this->date=date;
}

/**
 *
 * @param d a date
 * @return 'true' if one date is smaller than the other (this<d), 'false' otherewise
 */
bool Date::operator<(const Date &d) const {
    //first we are checking if one of the dates is bigger than the other
    int year1 = (this->date[0] - '0') * 1000 + (this->date[1] - '0') * 100 + (this->date[2] - '0') * 10 +
                (this->date[3] - '0');
    int year2 = (d.date[0] - '0') * 1000 + (d.date[1] - '0') * 100 + (d.date[2] - '0') * 10 +
                (d.date[3] - '0');
    if (year1 < year2) return true;
    if (year1 > year2) return false;

    //if the 2 years were equals we check the month values
    int month1 = (this->date[5] - '0') * 10 + (this->date[6] - '0') * 1;
    int month2 = (d.date[5] - '0') * 10 + (d.date[6] - '0') * 1;
    if (month1 < month2) return true;
    if (month1 > month2) return false;

    //if the 2 month were equals we check the days values
    int day1 = (this->date[8] - '0') * 10 + (this->date[9] - '0') * 1;
    int day2 = (d.date[8] - '0') * 10 + (d.date[9] - '0') * 1;
    if (day1 < day2) return true;
    if (day1 > day2) return false;

    //if we got to here it means that both of the dates are equals
    return false;
}

/**
 *
 * @param d a date
 * @return 'true' if one date is bigger than the other (this>d), 'false' otherewise
 */
bool Date::operator>(const Date &d) const {
    if (!this->operator<(d) && !this->operator==(d))
        return true;
    return false;
}

/**
 *
 * @param d a date
 * @return 'true' if one date is equals to another (this=d), 'false' therewise
 */
bool Date::operator==(const Date &d) const {
    //first we are checking if one of the dates is bigger than the other
    int year1 = (this->date[0] - '0') * 1000 + (this->date[1] - '0') * 100 + (this->date[2] - '0') * 10 +
                (this->date[3] - '0');
    int year2 = (d.date[0] - '0') * 1000 + (d.date[1] - '0') * 100 + (d.date[2] - '0') * 10 +
                (d.date[3] - '0');
    if (year1 != year2) return false;

    //if the 2 years were equals we check the month values
    int month1 = (this->date[5] - '0') * 10 + (this->date[6] - '0') * 1;
    int month2 = (d.date[5] - '0') * 10 + (d.date[6] - '0') * 1;
    if (month1 != month2) return false;

    //if the 2 month were equals we check the days values
    int day1 = (this->date[8] - '0') * 10 + (this->date[9] - '0') * 1;
    int day2 = (d.date[8] - '0') * 10 + (d.date[9] - '0') * 1;
    if (day1 != day2) return false;

    //if we got to here it means that both of the dates are equals
    return true;
}


