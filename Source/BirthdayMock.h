#ifndef BIRTHDAYMOCK_H
#define BIRTHDAYMOCK_H

#include "DateTime.h"
#include <ctime>

class BirthdayMock {
private:
    int _maxAge;
    int _currentYear;

public:
    /**
     * Constructor
     *
     * @brief BirthdayMock
     */
    BirthdayMock() {
        this->_maxAge = 120;
        this->_currentYear = DateTime::currentYear();
    }

    /**
     * @brief next
     * @return
     */
    DateTime next() {
        int year = this->_currentYear - rand() % (this->_maxAge);
        int month = rand() % (12 - 1 + 1) + 1;
        int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (DateTime::isLeapYear(year)) {
            days[2] = days[2] + 1;
        };
        int day = rand()% days[month] + 1;

        DateTime dob(year, month, day);

        return dob;
    }
};

#endif // BIRTHDAYMOCK_H
