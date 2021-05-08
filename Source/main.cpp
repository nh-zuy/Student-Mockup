#include <QApplication>
#include <QStandardItemModel>
#include <QTime>
#include <iostream>
#include <random>
#include "MockStore.h"

/**
 * Create a model for App
 *
 * @brief createStudentModel
 * @param parent
 * @return
 */
QAbstractItemModel *createStudentModel(QObject *parent)
{
    QStandardItemModel *model = new QStandardItemModel(0, 7, parent);

    /* Set header */
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Student Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Citizen ID"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("HCM Address"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Birthday"));

    return model;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MockStore store;
    store.setSourceModel(createStudentModel(&store));
    store.resize(1000, 600);
    store.show();
    return app.exec();
}
