//
// Created by rienel on 14.04.18.
//

#include "Client.h"

Client::Client(int id, QString *passportData, QString *surname, QString *name, QString *patronymic, QDate *dateOfBirth,
               QString *placeOfBirth, bool sex) : Model(id), passportData(passportData), surname(surname), name(name),
                                                  patronymic(patronymic), dateOfBirth(dateOfBirth),
                                                  placeOfBirth(placeOfBirth), sex(sex) {}

Client::Client(QString *passportData, QString *surname, QString *name, QString *patronymic, QDate *dateOfBirth,
               QString *placeOfBirth, bool sex) : passportData(passportData), surname(surname), name(name),
                                                  patronymic(patronymic), dateOfBirth(dateOfBirth),
                                                  placeOfBirth(placeOfBirth), sex(sex) {}

Client::Client(int id) : Model(id) {}

Client::Client() {}

Client::~Client() {
    delete this->surname;
    delete this->name;
    delete this->patronymic;
    delete this->dateOfBirth;
    delete this->placeOfBirth;
    delete this->passportData;
}

QString *Client::getPassportData() const {
    return passportData;
}

void Client::setPassportData(QString *passportData) {
    Client::passportData = passportData;
}

QString *Client::getSurname() const {
    return surname;
}

void Client::setSurname(QString *surname) {
    Client::surname = surname;
}

QString *Client::getName() const {
    return name;
}

void Client::setName(QString *name) {
    Client::name = name;
}

QString *Client::getPatronymic() const {
    return patronymic;
}

void Client::setPatronymic(QString *patronymic) {
    Client::patronymic = patronymic;
}

QDate *Client::getDateOfBirth() const {
    return dateOfBirth;
}

void Client::setDateOfBirth(QDate *dateOfBirth) {
    Client::dateOfBirth = dateOfBirth;
}

QString *Client::getPlaceOfBirth() const {
    return placeOfBirth;
}

void Client::setPlaceOfBirth(QString *placeOfBirth) {
    Client::placeOfBirth = placeOfBirth;
}

bool Client::isSex() const {
    return sex;
}

void Client::setSex(bool sex) {
    Client::sex = sex;
}