#ifndef TELEPHONE_H
#define TELEPHONE_H

#include "MobileNetwork.h"

class Telephone {
private:
    MobileNetwork _network;
    std::string _prefix;
    std::string _numbers;
public:
    /* Default constructor */
    Telephone() {}
    Telephone(MobileNetwork mb, std::string prefix, std::string numbers) {
        _network = mb;
        _prefix = prefix;
        _numbers = numbers;
    }

    /**
     * @brief network
     * @return
     */
    MobileNetwork network() {
        return _network;
    }

    /**
     * @brief setName
     * @param value
     */
    void setName(std::string value) {
        _numbers = value;
    }
    std::string numbers() {
        return _numbers;
    }

    /**
     * @brief toString
     * @return
     */
    std::string toString() {
        return _network.name() + " " + _prefix + _numbers;
    }
};
#endif // TELEPHONE_H
