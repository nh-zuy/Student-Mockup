#ifndef STUDENTMOCK_H
#define STUDENTMOCK_H

#include "TelephoneMock.h"
#include "HcmAddressMock.h"
#include "EmailMock.h"
#include "BirthdayMock.h"
#include "CitizenIdMock.h"
#include "Student.h"

class StudentMock {
private:
    FullnameMock nameStore;
    CitizenIdMock citizenIdStore;
    TelephoneMock telStore;
    EmailMock emailStore;
    HcmAddressMock addressStore;
    BirthdayMock birthdayStore;

public:
    /**
     * Generating random student
     *
     * @brief next
     * @return
     */
    Student next() {
        bool male = rand()%2 == 1;
        int studentId = rand() % (20 - 1 + 1) + 1;
        Fullname studentName = nameStore.next(male);
        std::string citizenId = citizenIdStore.next();
        std::string telephone = telStore.next().toString();
        std::string email = emailStore.next(studentName);
        std::string hcmAddress = addressStore.next().toString();
        std::string birthday = birthdayStore.next().toString();

        Student student(studentId, studentName.toString(), citizenId, telephone, email, hcmAddress, birthday);

        return student;
    }
};

#endif // STUDENTMOCK_H
