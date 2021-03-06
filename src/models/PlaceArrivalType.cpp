//
// Created by rienel on 14.04.18.
//

#include "PlaceArrivalType.h"

PlaceArrivalType::PlaceArrivalType(int id, QString *name) : Model(id), placeArrivalTypeName(name) {}

PlaceArrivalType::PlaceArrivalType(QString *name) : placeArrivalTypeName(name) {}

PlaceArrivalType::PlaceArrivalType(int id) : Model(id) {}

PlaceArrivalType::PlaceArrivalType() {}

PlaceArrivalType::~PlaceArrivalType() {
    if(this->placeArrivalTypeName!=nullptr){
        delete this->placeArrivalTypeName;
        this->placeArrivalTypeName=nullptr;
    }

}

QString *PlaceArrivalType::getName() const {
    return placeArrivalTypeName;
}

void PlaceArrivalType::setName(QString *name) {
    PlaceArrivalType::placeArrivalTypeName = name;
}

PlaceArrivalType::PlaceArrivalType(int id, const QString &name) : Model(id) {
    this->placeArrivalTypeName = new QString(name);
}

PlaceArrivalType::PlaceArrivalType(const QString &name) {
    this->placeArrivalTypeName = new QString(name);
}

QStringList PlaceArrivalType::columnList = {"ID_i", "Name_s"};

QStringList *PlaceArrivalType::getValueList() {
    return new QStringList({QString::number(this->id), *this->placeArrivalTypeName});
}

QStringList *PlaceArrivalType::getValForAdd() {
    return getValueList();
}

PlaceArrivalType::PlaceArrivalType(const QStringList &args) : Model(args) {
    this->placeArrivalTypeName = new QString(args[1]);
}
