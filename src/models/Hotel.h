//
// Created by rienel on 08.04.18.
//

#ifndef PSQLWORK_HOTEL_H
#define PSQLWORK_HOTEL_H

#include "Model.h"
#include <QtCore>

class Hotel: public Model {
private:
    QString* hotelName;
    QString* address;
    int stars;
    QDate* yearOfFoundation;
    int idCity;
public:
    Hotel(int id, QString *hotelName, QString *address, int stars, QDate *yearOfFoundation, int idCity);

    Hotel(int id, const QString &hotelName, const QString &address, int stars, const QDate &yearOfFoundation, int idCity);

    Hotel(QString *hotelName, QString *address, int stars, QDate *yearOfFoundation, int idCity);

    Hotel(int id);

    Hotel();

    virtual ~Hotel();

    QString *getHotelName() const;

    void setHotelName(QString *hotelName);

    QString *getAddress() const;

    void setAddress(QString *address);

    int getStars() const;

    void setStars(int stars);

    QDate *getYearOfFoundation() const;

    void setYearOfFoundation(QDate *yearOfFoundation);

    int getIdCity() const;

    void setIdCity(int idCity);
};


#endif //PSQLWORK_HOTEL_H
