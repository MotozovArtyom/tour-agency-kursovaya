//
// Created by rienel on 14.04.18.
//

#include <QtWidgets/QMessageBox>
#include <iostream>
#include "Client.h"

Client::Client(int id, QString *passportData, QString *surname, QString *name, QString *patronymic, QDate *dateOfBirth,
               QString *placeOfBirth, bool sex) : Model(id), passportData(passportData), surname(surname),
                                                  clientName(name),
                                                  patronymic(patronymic), dateOfBirth(dateOfBirth),
                                                  placeOfBirth(placeOfBirth), sex(sex) {}

Client::Client(QString *passportData, QString *surname, QString *name, QString *patronymic, QDate *dateOfBirth,
               QString *placeOfBirth, bool sex) : passportData(passportData), surname(surname), clientName(name),
                                                  patronymic(patronymic), dateOfBirth(dateOfBirth),
                                                  placeOfBirth(placeOfBirth), sex(sex) {}

Client::Client(int id) : Model(id) {}

Client::Client() {}

Client::~Client() {
    if (this->surname != nullptr) {
        delete this->surname;
        this->surname = nullptr;
    }
    if (this->clientName != nullptr) {
        delete this->clientName;
        this->clientName = nullptr;
    }
    if (this->patronymic != nullptr) {
        delete this->patronymic;
        this->patronymic = nullptr;
    }
    if (this->dateOfBirth != nullptr) {
        delete this->dateOfBirth;
        this->dateOfBirth = nullptr;
    }
    if (this->placeOfBirth != nullptr) {
        delete this->placeOfBirth;
        this->placeOfBirth = nullptr;
    }
    if (this->passportData != nullptr) {
        delete this->passportData;
        this->passportData = nullptr;
    }
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
    return clientName;
}

void Client::setName(QString *name) {
    Client::clientName = name;
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

Client::Client(int id, const QString &passportData, const QString &surname, const QString &name,
               const QString &patronymic, const QDate &dateOfBirth, const QString &placeOfBirth, bool sex) : Model(
        id) {
    this->passportData = new QString(passportData);
    this->surname = new QString(surname);
    this->clientName = new QString(name);
    this->patronymic = new QString(patronymic);
    this->dateOfBirth = new QDate(dateOfBirth);
    this->placeOfBirth = new QString(placeOfBirth);
    this->sex = sex;
}

Client::Client(const QString &passportData, const QString &surname, const QString &name,
               const QString &patronymic, const QDate &dateOfBirth, const QString &placeOfBirth, bool sex) : Model() {
    this->passportData = new QString(passportData);
    this->surname = new QString(surname);
    this->clientName = new QString(name);
    this->patronymic = new QString(patronymic);
    this->dateOfBirth = new QDate(dateOfBirth);
    this->placeOfBirth = new QString(placeOfBirth);
    this->sex = sex;
}

QStringList Client::columnList = {"ID_i", "Passport Data_s", "Surname_s", "Name_s", "Patronymic_s", "Date of birth_d",
                                  "Place of birth_s", "Sex_b"};

QStringList *Client::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->passportData, *this->surname, *this->clientName, *this->patronymic,
             this->dateOfBirth->toString("dd.MM.yyyy"), *this->placeOfBirth, (this->sex ? "+" : "-")});
}

QStringList *Client::getValForAdd() {
    return new QStringList(
            {QString::number(this->id), *this->surname, *this->clientName, *this->patronymic,
             this->dateOfBirth->toString("dd.MM.yyyy")});
}

Client::Client(const QStringList &args) : Model(args) {
    this->passportData = new QString(args[1]);
    this->surname = new QString(args[2]);
    this->clientName = new QString(args[3]);
    this->patronymic = new QString(args[4]);
    this->dateOfBirth = toDate(args[5]);
    this->placeOfBirth = new QString(args[6]);
    this->sex = toBool(args[7]);
}
