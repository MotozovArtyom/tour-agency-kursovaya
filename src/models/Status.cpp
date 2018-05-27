//
// Created by rienel on 25.05.18.
//

#include "Status.h"

Status::Status(int id, QString *name) : Model(id), statusName(name) {}

Status::Status(QString *name) : statusName(name) {}

Status::Status(int id, const QString &name) : Model(id) {
    this->statusName = new QString(name);
}

Status::Status(const QString &name) : Model() {
    this->statusName = new QString(name);
}

Status::Status(int id) : Model(id) {}

Status::Status() {}

Status::~Status() {
    delete this->statusName;
}

QString *Status::getName() const {
    return statusName;
}

void Status::setName(QString *name) {
    Status::statusName = name;
}

QStringList Status::columnList = {"ID", "Name"};

QStringList *Status::getValueList() {
    QStringList *list = new QStringList({QString::number(this->id), *this->statusName});
    return list;
}
