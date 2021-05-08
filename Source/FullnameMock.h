#ifndef FULLNAMEMOCK_H
#define FULLNAMEMOCK_H
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include "Fullname.h"

class FullnameMock {
private:
    std::vector<int> _distribution;

    std::vector<std::string> _femaleMiddleNames;
    std::vector<std::string> _maleMiddleNames;
    std::vector<std::string> _femaleLastNames;
    std::vector<std::string> _maleLastNames;
    std::vector<std::string> _firstNames;
    std::default_random_engine _rng;


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
     * @brief FullnameMock
     */
    FullnameMock() {
        /* Taking raw data */
        readFromFile(_firstNames, "Data/firstNames.txt");
        readFromFile(_femaleLastNames, "Data/femaleLastNames.txt");
        readFromFile(_femaleMiddleNames, "Data/femaleMiddleNames.txt");
        readFromFile(_maleLastNames, "Data/maleLastNames.txt");
        readFromFile(_maleMiddleNames, "Data/maleMiddleNames.txt");

        /* Set distribution for First Name */
        _distribution.resize(992); /* 0 1 -> 991 xap xi 100% */
        _distribution[0] = -1;
        /* 38,4% Nguyen */
        for (register int i = 1; i <= 384; ++i) {
            _distribution[i] = 0; // This is Nguyen's index in vector _firstName;
        };
        /* 12,1% ho Tran */
        for (register int i = 385; i <= 505; ++i) {
            _distribution[i] = 1; // This is Tran's index in vector _firstName;
        };
        /* 9,5% ho Le */
        for (register int i = 506; i <= 600; ++i) {
            _distribution[i] = 2; // This is Le's index in vector _firstName;
        }
        /* 7% ho Pham */
        for (register int i = 601; i <= 670; ++i) {
            _distribution[i] = 3; // This is Pham's index in vector _firstName;
        }
        /* 5,1% ho Hoang/Huynh */
        for (register int i = 671; i <= 721; ++i) {
            _distribution[i] = 4; // This is Hoang's index in vector _firstName;
        }
        for (register int i = 722; i <= 772; ++i) {
            _distribution[i] = 5; // This is Huynh's index in vector _firstName;
        }
        /* 4,5% ho Phan */
        for (register int i = 773; i <= 817; ++i) {
            _distribution[i] = 6; // This is Phan's index in vector _firstName;
        }
        /* 3,9% ho Vu/Vo */
        for (register int i = 818; i <= 856; ++i) {
            _distribution[i] = 7; // This is Vu's index in vector _firstName;
        }
        for (register int i = 857; i <= 895; ++i) {
            _distribution[i] = 8; // This is Vo's index in vector _firstName;
        }
        /* 2.1% ho Dang */
        for (register int i = 896; i <= 916; ++i) {
            _distribution[i] = 9; // This is Dang's index in vector _firstName;
        }
        /* 2% ho Bui */
        for (register int i = 917; i <= 936; ++i) {
            _distribution[i] = 10; // This is Bui's index in vector _firstName;
        }
        /* 1,4% ho Do */
        for (register int i = 937; i <= 950; ++i) {
            _distribution[i] = 11; // This is Do's index in vector _firstName;
        }
        /* 1,3% ho Ho */
        for (register int i = 951; i <= 963; ++i) {
            _distribution[i] = 12; // This is Ho's index in vector _firstName;
        }
        /* 1,3% ho Ngo */
        for (register int i = 964; i <= 976; ++i) {
            _distribution[i] = 13; // This is Ngo's index in vector _firstName;
        }
        /* 1% ho Duong */
        for (register int i = 977; i <= 986; ++i) {
            _distribution[i] = 14; // This is Duong's index in vector _firstName;
        }
        /* 0,5% ho Ly */
        for (register int i = 987; i <= 991; ++i) {
            _distribution[i] = 15; // This is Ly's index in vector _firstName;
        }
    }

    /**
     * Generating a random name
     *
     * @brief next
     * @param male
     * @return
     */
    Fullname next(bool male) {
        std::uniform_int_distribution<int> unformiDistribution(1, 991);
        int i = unformiDistribution(_rng);
        std::string first = _firstNames[_distribution[i]];
        std::string middle = "";
        std::string last = "";
        if (male) {
            i = rand() % (_maleMiddleNames.size());
            middle = _maleMiddleNames[i];

            i = rand() % (_maleLastNames.size());
            last = _maleLastNames[i];
        } else {
            i = rand() % (_femaleMiddleNames.size());
            middle = _femaleMiddleNames[i];

            i = rand() % (_femaleLastNames.size());
            last = _femaleLastNames[i];
        };
        Fullname result(first, middle, last);

        return result;
    }
};

#endif // FULLNAMEMOCK_H
