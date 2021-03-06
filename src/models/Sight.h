//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_SIGHT_H
#define PSQLWORK_SIGHT_H

#include <QString>
#include <QDate>
#include "Model.h"

class Sight : public Model {
private:
    QString *sightName;
    QString *address;
    QDate *yearOfCreation;
    QString *toponym;
    int idCity;

    QString *city;
public:
    static QStringList columnList;
    Sight(int id, QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity);

    Sight(int id, const QString &name, const QString &address, const QDate &yearOfCreation, const QString &toponym,
          int idCity);

    Sight(QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity);

    Sight(const QString &name, const QString &address, const QDate &yearOfCreation, const QString &toponym, int idCity);

    Sight(int id);

    Sight();

    Sight(const QStringList &args);

    virtual ~Sight();

    QString *getName() const;

    void setName(QString *name);

    QString *getAddress() const;

    void setAddress(QString *address);

    QDate *getYearOfCreation() const;

    void setYearOfCreation(QDate *yearOfCreation);

    QString *getToponym() const;

    void setToponym(QString *toponym);

    int getIdCity() const;

    void setIdCity(int idCity);

    QString *getCity() const;

    void setCity(QString *city);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_SIGHT_H
