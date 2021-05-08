#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

class Address {
private:
    std::string _number;
    std::string _street;
    std::string _ward;
    std::string _district;
    std::string _city;

public:
    /**
     * Constructor
     *
     * @brief Address
     * @param number
     * @param street
     * @param ward
     * @param district
     * @param city
     */
    Address(std::string number, std::string street, std::string ward, std::string district, std::string city) {
        this->_number = number;
        this->_street = street;
        this->_ward = ward;
        this->_district = district;
        this->_city = city;
    }

    /**
     * @brief toString
     * @return
     */
    std::string toString() {
        return this->_number + "/" + this->_street + "/" + this->_ward + "/" + this->_district + "/" + this->_city;
    }
};

#endif // ADDRESS_H
