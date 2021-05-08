QT += widgets
requires(qtConfig(combobox))

HEADERS     = \
    Address.h \
    BirthdayMock.h \
    CitizenIdMock.h \
    DateTime.h \
    EmailMock.h \
    Fullname.h \
    FullnameMock.h \
    HcmAddressMock.h \
    MobileNetwork.h \
    MockStore.h \
    Random.h \
    Student.h \
    StudentMock.h \
    Telephone.h \
    TelephoneMock.h
SOURCES     = main.cpp \
    MockStore.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/basicsortfiltermodel
INSTALLS += target
