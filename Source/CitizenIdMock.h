#ifndef CITIZENIDMOCK_H
#define CITIZENIDMOCK_H

#include <vector>
#include <string>
#include <sstream>
#include <ctime>

class CitizenIdMock {
private:
    std::vector<std::string> _cityCodes;

    int _maxAge;
    int _currentYear;

    /**
     * Reading data from file
     * Loading to vector
     *
     * @brief readFromFile
     * @param vt
     * @param fileName
     */
    void readFromFile(std::vector<std::string>& vt, std::string fileName) {
        std::string data;
        std::fstream dataFile(fileName, std::ios::in);

        if (!dataFile) {
            std::cout << "ERROR: open file@";
            return;
        };

        dataFile >> data;
        vt.push_back(data);
        while (!dataFile.eof()) {
            dataFile >> data;
            vt.push_back(data);
        };
        vt.pop_back();

        dataFile.close();
    }

public:
    /**
     * Constructor
     *
     * @brief CitizenIdMock
     */
    CitizenIdMock() {
        /* Max age is 120 because
         * up to now, no one can live to 120 years
         * after they've born */
        this->_maxAge = 120;

        /* Taking raw city code */
        readFromFile(_cityCodes, "Data/cityCodes.txt");

        /* Get current year */
        std::time_t t = std::time(nullptr);
        std::tm *const pTInfo = std::localtime(&t);
        this->_currentYear = 1900 + pTInfo->tm_year;
    }

    /**
     * Generating random Citizen ID
     *
     * @brief next
     * @return
     */
    std::string next() {
        int i = rand() % this->_cityCodes.size();
        std::string cityCode = this->_cityCodes[i];
        int century = this->_currentYear/100 + 1;
        int male = rand() % 2;
        int gender = (century - 20) * 2 + male;
        int birthYear = (this->_currentYear - rand() % (this->_maxAge)) % 100;

        std::stringstream writer;
        writer << cityCode << gender;
        if (birthYear < 10) {
            writer << "0";
        };

        writer << birthYear;
        for (register int i = 0; i < 6; ++i) {
            writer << rand() % 10;
        };
        std::string id = writer.str();

        return id;
    }
};

#endif // CITIZENIDMOCK_H


