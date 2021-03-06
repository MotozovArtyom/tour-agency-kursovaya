//
// Created by rienel on 11.04.18.
//

#include "Flight.h"

Flight::Flight(int id, QDate *dateOfPurchase, QDate *dateOfDeparture, QTime *departureTime, QTime *arrivalTime,
               QDate *arrivalDate) : Model(id), dateOfPurchase(dateOfPurchase), dateOfDeparture(dateOfDeparture),
                                     departureTime(departureTime), arrivalTime(arrivalTime), arrivalDate(arrivalDate) {}

Flight::Flight(QDate *dateOfPurchase, QDate *dateOfDeparture, QTime *departureTime, QTime *arrivalTime,
               QDate *arrivalDate) : dateOfPurchase(dateOfPurchase), dateOfDeparture(dateOfDeparture),
                                     departureTime(departureTime), arrivalTime(arrivalTime), arrivalDate(arrivalDate) {}

Flight::Flight(int id) : Model(id) {}

Flight::Flight() {}

Flight::~Flight() {
    if(this->dateOfPurchase!=nullptr){
        delete this->dateOfPurchase;
        this->dateOfPurchase=nullptr;
    }
    if(this->arrivalDate!=nullptr){
        delete this->arrivalDate;
        this->arrivalDate=nullptr;
    }
    if(this->arrivalTime!=nullptr){
        delete this->arrivalTime;
        this->arrivalTime=nullptr;
    }
    if(this->dateOfDeparture!=nullptr){
        delete this->dateOfDeparture;
        this->dateOfDeparture=nullptr;
    }
    if(this->departureTime!=nullptr){
        delete this->departureTime;
        this->departureTime=nullptr;
    }
}

QDate *Flight::getDateOfPurchase() const {
    return dateOfPurchase;
}

void Flight::setDateOfPurchase(QDate *dateOfPurchase) {
    Flight::dateOfPurchase = dateOfPurchase;
}

QDate *Flight::getDateOfDeparture() const {
    return dateOfDeparture;
}

void Flight::setDateOfDeparture(QDate *dateOfDeparture) {
    Flight::dateOfDeparture = dateOfDeparture;
}

QTime *Flight::getDepartureTime() const {
    return departureTime;
}

void Flight::setDepartureTime(QTime *departureTime) {
    Flight::departureTime = departureTime;
}

QTime *Flight::getArrivalTime() const {
    return arrivalTime;
}

void Flight::setArrivalTime(QTime *arrivalTime) {
    Flight::arrivalTime = arrivalTime;
}

QDate *Flight::getArrivalDate() const {
    return arrivalDate;
}

void Flight::setArrivalDate(QDate *arrivalDate) {
    Flight::arrivalDate = arrivalDate;
}

Flight::Flight(int id, const QDate &dateOfPurchase, const QDate &dateOfDeparture, const QTime &departureTime,
               const QTime &arrivalTime, const QDate &arrivalDate) : Model(id) {
    this->dateOfPurchase = new QDate(dateOfPurchase);
    this->dateOfDeparture = new QDate(dateOfDeparture);
    this->departureTime = new QTime(departureTime);
    this->arrivalTime = new QTime(arrivalTime);
    this->arrivalDate = new QDate(arrivalDate);
}

Flight::Flight(const QDate &dateOfPurchase, const QDate &dateOfDeparture, const QTime &departureTime,
               const QTime &arrivalTime, const QDate &arrivalDate) : Model() {
    this->dateOfPurchase = new QDate(dateOfPurchase);
    this->dateOfDeparture = new QDate(dateOfDeparture);
    this->departureTime = new QTime(departureTime);
    this->arrivalTime = new QTime(arrivalTime);
    this->arrivalDate = new QDate(arrivalDate);
}

QStringList Flight::columnList = {"ID_i", "Date of Purchase_d", "Date of Departure_d", "Departure time_t", "Arrival time_t",
                                  "Arrival date_d"};

QStringList *Flight::getValueList() {
    return new QStringList(
            {QString::number(this->id), this->dateOfPurchase->toString("dd.MM.yyyy"), this->dateOfDeparture->toString("dd.MM.yyyy"),
             this->departureTime->toString("HH:mm"), this->arrivalTime->toString("HH:mm"), this->arrivalDate->toString("dd.MM.yyyy")});
}

QStringList *Flight::getValForAdd() {
    return new QStringList({QString::number(this->id)});
}

Flight::Flight(const QStringList &args) : Model(args) {
    this->dateOfPurchase = toDate(args[1]);
    this->dateOfDeparture=toDate(args[2]);
    this->departureTime=toTime(args[3]);
    this->arrivalTime=toTime(args[4]);
    this->arrivalDate=toDate(args[5]);
}
