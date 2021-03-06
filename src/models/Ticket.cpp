//
// Created by rienel on 11.04.18.
//

#include "Ticket.h"

Ticket::Ticket(int id, int place, QDate *dateFlight, float price, QDate *dateOfPurchase, int idDocuments, int idFlight)
        : Model(id),
          place(place),
          dateFlight(dateFlight),
          price(price),
          idDocuments(idDocuments),
          dateOfPurchase(dateOfPurchase),
          idFlight(idFlight) {
    this->documents = nullptr;
    this->flight = nullptr;
}

Ticket::Ticket(int place, QDate *dateFlight, float price, QDate *dateOfPurchase, int idDocuments, int idFlight)
        : place(place), dateFlight(dateFlight), price(price), idDocuments(idDocuments), dateOfPurchase(dateOfPurchase),
          idFlight(idFlight) {
    this->documents = nullptr;
    this->flight = nullptr;
}

Ticket::Ticket(int id, int place, const QDate &dateFlight, float price, const QDate &dateOfPurchase, int idDocuments,
               int idFlight) : Model(id) {
    this->place = place;
    this->dateFlight = new QDate(dateFlight);
    this->price = price;
    this->idDocuments = idDocuments;
    this->dateOfPurchase = new QDate(dateOfPurchase);
    this->idFlight = idFlight;

    this->documents = nullptr;
    this->flight = nullptr;
}

Ticket::Ticket(int place, const QDate &dateFlight, float price, const QDate &dateOfPurchase, int idDocuments,
               int idFlight) {
    this->place = place;
    this->dateFlight = new QDate(dateFlight);
    this->price = price;
    this->idDocuments = idDocuments;
    this->dateOfPurchase = new QDate(dateOfPurchase);
    this->idFlight = idFlight;

    this->documents = nullptr;
    this->flight = nullptr;
}

Ticket::Ticket(int id) : Model(id) {
    this->documents = nullptr;
    this->flight = nullptr;
}

Ticket::Ticket() {
    this->documents = nullptr;
    this->flight = nullptr;
}

Ticket::~Ticket() {
    if(this->dateFlight!=nullptr){
        delete this->dateFlight;
        this->dateFlight=nullptr;
    }
    if(this->dateOfPurchase!=nullptr){
        delete this->dateOfPurchase;
        this->dateOfPurchase=nullptr;
    }

    if (this->documents != nullptr) {
        delete this->documents;
        this->documents = nullptr;
    }
    if (this->flight != nullptr) {
        delete this->flight;
        this->flight = nullptr;
    }
}

int Ticket::getPlace() const {
    return place;
}

void Ticket::setPlace(int place) {
    Ticket::place = place;
}

QDate *Ticket::getDateFlight() const {
    return dateFlight;
}

void Ticket::setDateFlight(QDate *dateFlight) {
    Ticket::dateFlight = dateFlight;
}

float Ticket::getPrice() const {
    return price;
}

void Ticket::setPrice(float price) {
    Ticket::price = price;
}

int Ticket::getIdDocuments() const {
    return idDocuments;
}

void Ticket::setIdDocuments(int idDocuments) {
    Ticket::idDocuments = idDocuments;
}

QDate *Ticket::getDateOfPurchase() const {
    return dateOfPurchase;
}

void Ticket::setDateOfPurchase(QDate *dateOfPurchase) {
    Ticket::dateOfPurchase = dateOfPurchase;
}

int Ticket::getIdFlight() const {
    return idFlight;
}

void Ticket::setIdFlight(int idFlight) {
    Ticket::idFlight = idFlight;
}

QString *Ticket::getDocuments() const {
    return documents;
}

void Ticket::setDocuments(QString *documents) {
    Ticket::documents = documents;
}

QString *Ticket::getFlight() const {
    return flight;
}

void Ticket::setFlight(QString *flight) {
    Ticket::flight = flight;
}

QStringList Ticket::columnList = {"ID_i", "Place_i", "Date_d", "Price_n", "Date of purchase_d", "Documents_f", "Flight_f"};

QStringList *Ticket::getValueList() {
    return new QStringList({QString::number(this->id), QString::number(this->place), this->dateFlight->toString("dd.MM.yyyy"),
                            QString::number(this->price), this->dateOfPurchase->toString("dd.MM.yyyy"), *this->documents,
                            *this->flight});
}

QStringList *Ticket::getValForAdd() {
    return new QStringList({QString::number(this->id), this->dateFlight->toString(), *this->flight});
}

Ticket::Ticket(const QStringList &args) : Model(args) {
    this->place = args[1].toInt();
    this->dateFlight = toDate(args[2]);
    this->price = args[3].toFloat();
    this->dateOfPurchase = toDate(args[4]);
    this->idDocuments = args[5].toInt();
    this->idFlight = args[6].toInt();

    this->documents = nullptr;
    this->flight = nullptr;
}
