#ifndef _MT_H
#define _MT_H

#include <QWidget>
#include <vector>
#include <string>
#include "StudentMock.h"

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QSortFilterProxyModel;
class QTreeView;
class QPushButton;
QT_END_NAMESPACE

class MockStore : public QWidget
{
    Q_OBJECT

public:
    /* Construtor */
    MockStore();

    /* Initial model */
    void setSourceModel(QAbstractItemModel *model);
    /* Add new student into model */
    void addStudent(QAbstractItemModel *model, const QString &studentID,
                    const QString &studentName, const QString &citizenId,
                    const QString &telephone, const QString &email,
                    const QString &hcmAddress, const QString &birthday);
    /* Get index of given value in vector */
    int getIndex(std::vector<std::string> v, int value);
    /* Read raw data from file */
    void readFromFile(std::vector<std::string>& v, std::string fileName);

private slots:
    /* Set signals for app */
    void handleCityButton();
    void handleRandomButton();
    void filterRegExpChanged();
    void filterColumnChanged();
    void handleSaveButton();
    void sortChanged();

private:
    /* Student data */
    StudentMock studentStore;
    std::vector<std::string> studentsData;

    /* Model data */
    QSortFilterProxyModel *proxyModel;
    QAbstractItemModel *sourceModel;

    /* Random number */
    QGroupBox *randomGroupBox;
    /* Random number */
    QLabel *randomLabel;
    /* Rundom number */
    QLineEdit *randomLine;
    /* Button random number */
    QPushButton *randomButton;
    /* Button random number */
    QPushButton *saveButton;

    /* Search city */
    QGroupBox *cityGroupBox;
    /* Code input label */
    QLabel *codeLabel;
    QLabel *cityLabel;
    /* Code input line */
    QLineEdit *codeLine;
    QLineEdit *cityLine;
    /* Button search city */
    QPushButton *cityButton;


    /* Source data box */
    QGroupBox *sourceGroupBox;
    QTreeView *sourceView;

    /* Filter data box */
    QGroupBox *proxyGroupBox;
    QTreeView *proxyView;

    /* Case Sensitive */
        /* Search */
    QCheckBox *filterCaseSensitivityCheckBox;
        /* Sort */
    QCheckBox *sortCaseSensitivityCheckBox;

    /* Condition search */
    QLabel *filterPatternLabel;
    /* Syntax search */
    QLabel *filterSyntaxLabel;
    /* Column search */
    QLabel *filterColumnLabel;


    /* Condition */
    QLineEdit *filterPatternLineEdit;
    /* Syntax compare */
    QComboBox *filterSyntaxComboBox;
    /* Column sort */
    QComboBox *filterColumnComboBox;
};

#endif // WINDOW_H
