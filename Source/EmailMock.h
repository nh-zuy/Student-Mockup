#ifndef EMAILMOCK_H
#define EMAILMOCK_H

#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include "FullnameMock.h"

class EmailMock {
private:
    std::vector<std::string> _domains;
    FullnameMock _nameStore;

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
            std::cout << "ERROR: open file!";
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
     * Default constructor
     *
     * @brief EmailMock
     */
    EmailMock() {
        /* Taking raw data */
        readFromFile(_domains, "Data/emailDomains.txt");
    }

    /**
     * Generating next Email
     *
     * @brief next
     * @return
     */
    std::string next() {
        bool male = rand()%2 == 1;
        Fullname name = _nameStore.next(male);
        std::string email = this->next(name);

        return email;
    }

    /**
     * Still generating but need name first
     *
     * @brief next
     * @param name
     * @return
     */
    std::string next(Fullname name) {
        std::string first = name.firstname();
        std::transform(first.begin(), first.end(), first.begin(), ::tolower);
        std::string middle = name.middlename();
        std::transform(middle.begin(), middle.end(), middle.begin(), ::tolower);
        std::string last = name.lastname();
        std::transform(last.begin(), last.end(), last.begin(), ::tolower);

        int i = rand() % (this->_domains.size());
        std::string domain = this->_domains[i];

        std::stringstream writer;
        writer << first[0] << middle[0] << last << "@" << domain;

        std::string email = writer.str();

        return email;
    }
};

#endif // EMAILMOCK_H
