#ifndef HCMADDRESSMOCK_H
#define HCMADDRESSMOCK_H
#include <string>
#include <vector>
#include <ctime>
#include "Address.h"

class HcmAddressMock {
private:
    std::vector<std::string> _streets;
    std::vector<std::string> _wards;
    std::vector<std::string> _districts;
    std::vector<std::string> _cities;

public:
    /**
     * Default constructor
     *
     * @brief HcmAddressMock
     */
    HcmAddressMock() {
        this->_streets = {
            "Nguyen Chi Thanh", "Au Co", "Dien Bien Phu",
            "Cong Hoa", "Tran Hung Dao", "Lac Long Quan",
            "Nguyen Thi Minh Khai", "An Nhon", "Nguyen Oanh",
            "Nguyen Thai Son", "Mai Chi Tho", "Do Xuan Hop"
        };
        this->_wards = {
            "Ward 1", "Ward 2", "Ward 3", "Ward 4", "Ward 5",
            "Ben Nghe Ward", "Co Giang Ward", "Da Kao Ward", "Pham Ngu Lao Ward",
            "Tan Dinh Ward", "An Khanh Ward"
        };
        this->_districts = {
            "District 1", "District 5", "District 10",
            "Binh Tan District", "Tan Phu District", "Binh Thanh District",
            "Phu Nhuan District", "Tan Phu District", "Go Vap District"

        };
        this->_cities = {"Ho Chi Minh"};
    }

    /**
     * Generating random address
     *
     * @brief next
     * @return
     */
    Address next() {
        std::string number = std::to_string(rand() % 100 + 1);

        int i = rand() % (this->_streets.size());
        std::string street = this->_streets[i];

        i = rand() % (this->_wards.size());
        std::string ward = this->_wards[i];

        i = rand() % (this->_districts.size());
        std::string district = this->_districts[i];

        i = rand() % (this->_cities.size());
        std::string city = this->_cities[i];

        Address address(number, street, ward, district, city);

        return address;
    }
};

#endif // HCMADDRESSMOCK_H
