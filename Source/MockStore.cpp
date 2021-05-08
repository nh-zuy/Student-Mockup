#include <QtWidgets>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "MockStore.h"
/**
 * @brief MockStore::MockStore
 *
 * Constructor
 * @access public
 *
 */
MockStore::MockStore()
{
    /* Seeding */
    srand(time(NULL));

    /* Model handle data in form */
    proxyModel = new QSortFilterProxyModel;

    /* Random number view */
    randomGroupBox = new QGroupBox(tr("Generating number students"));
    randomLine = new QLineEdit;
    randomLine->setReadOnly(true);
    randomLabel = new QLabel(tr("&Random number"));
    randomLabel->setBuddy(randomLine);
    randomButton = new QPushButton("&Generate");
    QGridLayout *randomLayout = new QGridLayout;
    randomLayout->addWidget(randomLabel, 0, 0, 1, 1);
    randomLayout->addWidget(randomLine, 0, 1, 1, 1);
    randomLayout->addWidget(randomButton, 0, 2, 1, 1);
    randomGroupBox->setLayout(randomLayout);

    /* Search city by codes */
    cityGroupBox = new QGroupBox(tr("City codes"));
    codeLine = new QLineEdit;
    codeLabel = new QLabel(tr("City &code"));
    codeLabel->setBuddy(codeLine);
    cityLine = new QLineEdit;
    cityLine->setReadOnly(true);
    cityButton = new QPushButton("&Search");

    QGridLayout *cityLayout = new QGridLayout;
    cityLayout->addWidget(codeLabel, 0, 0, 2, 1);
    cityLayout->addWidget(codeLine, 0, 2, 1, 1);
    cityLayout->addWidget(cityLine, 0, 3, 1, 1);
    cityLayout->addWidget(cityButton, 0, 4);
    cityGroupBox->setLayout(cityLayout);

    /* Orginal view */
    sourceView = new QTreeView;
    sourceView->setRootIsDecorated(false);
    sourceView->setAlternatingRowColors(true);

    /* Filter view */
    proxyView = new QTreeView;
    proxyView->setRootIsDecorated(false);
    proxyView->setAlternatingRowColors(true);
    proxyView->setModel(proxyModel);

    /* Two checkbox */
    sortCaseSensitivityCheckBox = new QCheckBox(tr("Case-sensitive sorting"));
    filterCaseSensitivityCheckBox = new QCheckBox(tr("Case-sensitive filter"));

    /* Condition search */
    filterPatternLineEdit = new QLineEdit;
    filterPatternLabel = new QLabel(tr("&Keyword:"));
    filterPatternLabel->setBuddy(filterPatternLineEdit);

    /* Syntax search */
    filterSyntaxComboBox = new QComboBox;
    filterSyntaxComboBox->addItem(tr("Fixed string"), QRegExp::FixedString);
    filterSyntaxComboBox->addItem(tr("Wildcard"), QRegExp::Wildcard);
    filterSyntaxComboBox->addItem(tr("Regex"), QRegExp::RegExp);
    filterSyntaxLabel = new QLabel(tr("Filter &syntax:"));
    filterSyntaxLabel->setBuddy(filterSyntaxComboBox);

    /* Column search */
    filterColumnComboBox = new QComboBox;
    filterColumnComboBox->addItem(tr("ID"));
    filterColumnComboBox->addItem(tr("Student Name"));
    filterColumnComboBox->addItem(tr("Citizen ID"));
    filterColumnComboBox->addItem(tr("Telephone"));
    filterColumnComboBox->addItem(tr("Email"));
    filterColumnComboBox->addItem(tr("HCM Address"));
    filterColumnComboBox->addItem(tr("Birthday"));

    filterColumnLabel = new QLabel(tr("Filter &column:"));
    filterColumnLabel->setBuddy(filterColumnComboBox);

    /* Saving button */
    saveButton = new QPushButton("Save");

    /* Set signals for app */
    connect(randomButton, &QPushButton::released, this, &MockStore::handleRandomButton);
    connect(filterPatternLineEdit, &QLineEdit::textChanged,
            this, &MockStore::filterRegExpChanged);
    connect(filterSyntaxComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MockStore::filterRegExpChanged);
    connect(filterColumnComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MockStore::filterColumnChanged);
    connect(filterCaseSensitivityCheckBox, &QAbstractButton::toggled,
            this, &MockStore::filterRegExpChanged);
    connect(sortCaseSensitivityCheckBox, &QAbstractButton::toggled,
            this, &MockStore::sortChanged);
    connect(saveButton, &QPushButton::released, this, &MockStore::handleSaveButton);
    connect(cityButton, &QPushButton::released, this, &MockStore::handleCityButton);

    /* Orginal data box */
    sourceGroupBox = new QGroupBox(tr("Student Mockup"));
    /* Filter data box */
    proxyGroupBox = new QGroupBox(tr("Finding student"));

    /* Make orginal data view */
    QHBoxLayout *sourceLayout = new QHBoxLayout;
    sourceLayout->addWidget(sourceView);
    sourceGroupBox->setLayout(sourceLayout);

    /* Make filter data view */
    QGridLayout *proxyLayout = new QGridLayout;
    proxyLayout->addWidget(proxyView, 0, 0, 1, 3);
    proxyLayout->addWidget(filterPatternLabel, 1, 0);
    proxyLayout->addWidget(filterPatternLineEdit, 1, 1, 1, 2);
    proxyLayout->addWidget(filterSyntaxLabel, 2, 0);
    proxyLayout->addWidget(filterSyntaxComboBox, 2, 1, 1, 2);
    proxyLayout->addWidget(filterColumnLabel, 3, 0);
    proxyLayout->addWidget(filterColumnComboBox, 3, 1, 1, 2);
    proxyLayout->addWidget(filterCaseSensitivityCheckBox, 4, 0, 1, 2);
    proxyLayout->addWidget(sortCaseSensitivityCheckBox, 4, 2);
    proxyLayout->addWidget(saveButton, 5, 1);
    proxyGroupBox->setLayout(proxyLayout);

    /* Add all widget into Main frame */
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(randomGroupBox);
    mainLayout->addWidget(cityGroupBox);
    mainLayout->addWidget(sourceGroupBox);
    mainLayout->addWidget(proxyGroupBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Student Mockup Store"));

    proxyView->sortByColumn(1, Qt::AscendingOrder);
    filterColumnComboBox->setCurrentIndex(1);

    filterPatternLineEdit->setText("Nguyen Nhat Duy");
    filterCaseSensitivityCheckBox->setChecked(true);
    sortCaseSensitivityCheckBox->setChecked(true);

    /* Row in TreeView can't be edited */
    sourceView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    proxyView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

/**
 * Initial model
 *
 * @brief MockStore::setSourceModel
 * @param model
 */
void MockStore::setSourceModel(QAbstractItemModel *model)
{
    sourceModel = model;
    proxyModel->setSourceModel(sourceModel);
    sourceView->setModel(sourceModel);
}

/**
 *  Signal random number when click
 *
 *  @brief MockStore::handleRandomButton
 */
void MockStore::handleRandomButton() {
    /* Romve all data */
    sourceModel->removeRows(0, sourceModel->rowCount());
    studentsData.clear();

    /* Mocking n new student */
    int n = rand()% (20 - 1 + 1) + 1;
    randomLine->setText(QString::number(n));
    for (register int i = 0; i < n; ++i) {
        /* Mockup data */
        auto student = studentStore.next();

        QString id = QString::number(i + 1);
        student.setStudentID(i + 1);
        QString name = QString::fromStdString(student.StudentName());
        QString citizenId = QString::fromStdString(student.CitizenId());
        QString telephone = QString::fromStdString(student.Telephone());
        QString email = QString::fromStdString(student.Email());
        QString address = QString::fromStdString(student.HcmAddress());
        QString birthday = QString::fromStdString(student.Birthday());

        addStudent(sourceModel, id, name, citizenId, telephone, email, address, birthday);
        studentsData.push_back(student.toString());
    };

    sourceView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    sourceView->header()->setStretchLastSection(false);
    proxyView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    proxyView->header()->setStretchLastSection(false);
}
/* Add student data into current model */
void MockStore::addStudent(QAbstractItemModel *model, const QString &studentID,
                           const QString &studentName, const QString &citizenId,
                           const QString &telephone, const QString &email,
                           const QString &hcmAddress, const QString &birthday)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), studentID);
    model->setData(model->index(0, 1), studentName);
    model->setData(model->index(0, 2), citizenId);
    model->setData(model->index(0, 3), telephone);
    model->setData(model->index(0, 4), email);
    model->setData(model->index(0, 5), hcmAddress);
    model->setData(model->index(0, 6), birthday);
}

/**
 *  Signal for Search button
 *
 * @brief MockStore::handleCityButton
 */
void MockStore::handleCityButton() {
    CitizenIdMock idStore;

    if (codeLine->text() == "") {
        cityLine->setText("Please enter code beside !");
        return;
    };

    int code = codeLine->text().trimmed().toInt();
    std::vector<std::string> cityCodes;
    std::vector<std::string> cities;

    readFromFile(cityCodes, "Data/cityCodes.txt");

    std::string data;
    std::fstream dataFile("Data/cities.txt", std::ios::in);
    if (!dataFile) {
        std::cout << "ERROR: open file@";
        return;
    };
    std::getline(dataFile, data);
    cities.push_back(data);
    while (!dataFile.eof()) {
        std::getline(dataFile, data);
        cities.push_back(data);
    };
    cities.pop_back();
    dataFile.close();

    int x = getIndex(cityCodes, code);
    std::string city = (x == -1) ? "404 Not found !" : cities[x];

    cityLine->setText(QString::fromStdString(city));
}

/**
 * Signal change syntax search
 *
 * @brief MockStore::filterRegExpChanged
 */
void MockStore::filterRegExpChanged()
{
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(
        filterSyntaxComboBox->itemData(
            filterSyntaxComboBox->currentIndex()
        ).toInt()
    );

    Qt::CaseSensitivity caseSensitivity =
            filterCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive
                                                       : Qt::CaseInsensitive;

    QRegExp regExp(filterPatternLineEdit->text(), caseSensitivity, syntax);
    proxyModel->setFilterRegExp(regExp);
}

/**
 * Signal change column search
 *
 * @brief MockStore::filterColumnChanged
 */
void MockStore::filterColumnChanged()
{
    proxyModel->setFilterKeyColumn(filterColumnComboBox->currentIndex());
}

/**
 * Saving students data to file
 *
 * @brief MockStore::handleSaveButton
 */
void MockStore::handleSaveButton() {
    std::fstream dataFile("Data/students.txt", std::ios::out);

    if (!dataFile) {
        std::cout << "ERROR: open file@";
        return;
    };

    for(register int i = 0; i < (int)studentsData.size(); ++i) {
        dataFile << studentsData[i] << std::endl;
    };

    dataFile.close();
}

/**
 * Get index of given value from vector
 *
 * @brief MockStore::getIndex
 * @param v
 * @param value
 * @return
 */
int MockStore::getIndex(std::vector<std::string> v, int value) {
    std::stringstream writer;
    if (value < 10) {
        writer << "00";
    } else {
        writer << "0";
    };
    writer << value;
    std::string word = writer.str();

    auto it = std::find(v.begin(), v.end(), word);
    if (it != v.end()) {
        return (it - v.begin());
    };

    return -1;
}

/**
 *  Check case sensitive
 *
 * @brief MockStore::sortChanged
 */
void MockStore::sortChanged()
{
    proxyModel->setSortCaseSensitivity(sortCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);
}

/**
 * Reading data from file
 * Loading to vector
 *
 * @brief readFromFile
 * @param vt
 * @param fileName
 */
void MockStore::readFromFile(std::vector<std::string>& vt, std::string fileName) {
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
