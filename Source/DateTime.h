#ifndef DATETIME_H
#define DATETIME_H
#include <string>
#include <ctime>
#include <sstream>

class DateTime {
private:
    int _day;
    int _month;
    int _year;

public:
    /**
     * Constructor
     *
     * @brief DateTime
     * @param year
     * @param month
     * @param day
     */
    DateTime(int year = 0, int month = 0, int day = 0) {
        this->_day = day;
        this->_month = month;
        this->_year = year;
    }

    /**
     * @brief setDay
     * @param value
     */
    void setDay(int value) {
        this->_day = value;
    }
    int day() {
        return this->_day;
    }

    /**
     * @brief setMonth
     * @param value
     */
    void setMonth(int value) {
        this->_month = value;
    }
    int month() {
        return this->_month;
    }

    /**
     * @brief setYear
     * @param value
     */
    void setYear(int value) {
        this->_year = value;
    }
    int year() {
        return this->_year;
    }

    /**
     * Return current year
     *
     * @brief currentYear
     * @return
     */
    static int currentYear() {
        std::time_t t = std::time(nullptr);
        std::tm *const pTInfo = std::localtime(&t);

        return 1900 + pTInfo->tm_year;
    }

    /**
     * Check if year is leap
     *
     * @brief isLeapYear
     * @param year
     * @return
     */
    static bool isLeapYear(int year) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            return true;
        };

        return false;
    }

    /**
     * Return string
     *
     * @brief toString
     * @return
     */
    std::string toString() {
        std::stringstream writer;
        writer << this->day() << "/" << this->month() << "/" << this->year();
        std::string date = writer.str();

        return date;
    }
};

#endif // DATETIME_H
