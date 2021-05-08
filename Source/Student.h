#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <sstream>

class Student {
private:
    int _StudentID;
    std::string _StudentName;
    std::string _CitizenId;
    std::string _Telephone;
    std::string _Email;
    std::string _HcmAddress;
    std::string _Birthday;

public:
    /* Default Constructor */
    Student() {}
    /* Constructor */
    Student(int studentID, std::string studentName,
            std::string citizenId, std::string telephone,
            std::string email, std::string hcmAddress,
            std::string birthday) {
        _StudentID = studentID;
        _StudentName = studentName;
        _CitizenId = citizenId;
        _Telephone = telephone;
        _Email = email;
        _HcmAddress = hcmAddress;
        _Birthday = birthday;
    }
    /* Copy constructor */
    Student(const Student& student) {
        _StudentID = student._StudentID;
        _StudentName = student._StudentName;
        _CitizenId = student._CitizenId;
        _Telephone = student._Telephone;
        _Email = student._Email;
        _HcmAddress = student._HcmAddress;
        _Birthday = student._Birthday;
    }

    /* Overloading = */
    const Student& operator =(const Student& student) {
        _StudentID = student._StudentID;
        _StudentName = student._StudentName;
        _CitizenId = student._CitizenId;
        _Telephone = student._Telephone;
        _Email = student._Email;
        _HcmAddress = student._HcmAddress;
        _Birthday = student._Birthday;

        return *this;
    }
    /* Destructor */
    ~Student() {}

    /**
     * @brief Student::StudentID
     * @return
     */
    int StudentID()
    {
        return _StudentID;
    }
    void setStudentID(int StudentID)
    {
        _StudentID = StudentID;
    }

    /**
     * @brief Student::StudentName
     * @return
     */
    std::string StudentName()
    {
        return _StudentName;
    }
    void setStudentName(const std::string &StudentName)
    {
        _StudentName = StudentName;
    }

    /**
     * @brief Student::CitizenId
     * @return
     */
    std::string CitizenId()
    {
        return _CitizenId;
    }
    void setCitizenId(const std::string &CitizenId)
    {
        _CitizenId = CitizenId;
    }

    /**
     * @brief Student::Telephone
     * @return
     */
    std::string Telephone()
    {
        return _Telephone;
    }
    void setTelephone(const std::string &Telephone)
    {
        _Telephone = Telephone;
    }

    /**
     * @brief Student::Email
     * @return
     */
    std::string Email()
    {
        return _Email;
    }
    void setEmail(const std::string &Email)
    {
        _Email = Email;
    }

    /**
     * @brief Student::HcmAddress
     * @return
     */
    std::string HcmAddress()
    {
        return _HcmAddress;
    }
    void setHcmAddress(const std::string &HcmAddress)
    {
        _HcmAddress = HcmAddress;
    }

    /**
     * @brief Student::Birthday
     * @return
     */
    std::string Birthday()
    {
        return _Birthday;
    }
    void setBirthday(const std::string &Birthday)
    {
        _Birthday = Birthday;
    }

    /**
     * @brief toString
     * @return string like "a, b, c, d, ..."
     */
    std::string toString() {
        std::stringstream writer;
        writer << _StudentID;
        std::string studentId = writer.str();

        return studentId + ", " + _StudentName + ", " + _CitizenId + ", " + _Telephone + ", " + _Email + ", " + _HcmAddress + ", " + _Birthday;
    }

};

#endif


