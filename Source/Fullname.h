#ifndef FULLNAME_H
#define FULLNAME_H
#include <string>

class Fullname {
private:
    std::string _firstname;
    std::string _middlename;
    std::string _lastname;
public:
    /**
     * Default constructor
     *
     * @brief Fullname
     * @param firstname
     * @param middlename
     * @param lastname
     */
    Fullname(std::string firstname, std::string middlename, std::string lastname) {
        _firstname = firstname;
        _middlename = middlename;
        _lastname = lastname;
    }

    /**
     * @brief setFirstname
     * @param value
     */
    void setFirstname(std::string value) {
        this->_firstname = value;
    }
    std::string firstname() {
        return _firstname;
    }

    /**
     * @brief setMiddlename
     * @param value
     */
    void setMiddlename(std::string value) {
        this->_middlename = value;
    }
    std::string middlename() {
        return _middlename;
    }

    /**
     * @brief setLastname
     * @param value
     */
    void setLastname(std::string value) {
        this->_lastname = value;
    }
    std::string lastname() {
        return _lastname;
    }

    /**
     * Return the object string
     *
     * @brief toString
     * @return
     */
    std::string toString() {
        return _firstname + " " + _middlename + " " + _lastname;
    }
};

#endif // FULLNAME_H
