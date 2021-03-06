//
// Created by rienel on 08.04.18.
//

#include <iostream>
#include "HotelRoom.h"

HotelRoom::HotelRoom(int id, QString *hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony,
                     int idHotel, int idHotelRoomType) : Model(id), hotelRoomName(hotelRoomName), places(places),
                                                         shower(shower), secondRestroom(secondRestroom),
                                                         balcony(balcony), idHotel(idHotel),
                                                         idHotelRoomType(idHotelRoomType) {
    this->hotel = nullptr;
    this->hotelRoomType = nullptr;
}

HotelRoom::HotelRoom(QString *hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony, int idHotel,
                     int idHotelRoomType) : hotelRoomName(hotelRoomName), places(places), shower(shower),
                                            secondRestroom(secondRestroom), balcony(balcony), idHotel(idHotel),
                                            idHotelRoomType(idHotelRoomType) {
    this->hotel = nullptr;
    this->hotelRoomType = nullptr;
}

HotelRoom::HotelRoom(int id) : Model(id) {
    this->hotel = nullptr;
    this->hotelRoomType = nullptr;
}

HotelRoom::HotelRoom() {
    this->hotel = nullptr;
    this->hotelRoomType = nullptr;
}

QString *HotelRoom::getHotelRoomName() const {
    return hotelRoomName;
}

void HotelRoom::setHotelRoomName(QString *hotelRoomName) {
    HotelRoom::hotelRoomName = hotelRoomName;
}

int HotelRoom::getPlaces() const {
    return places;
}

void HotelRoom::setPlaces(int places) {
    HotelRoom::places = places;
}

bool HotelRoom::isShower() const {
    return shower;
}

void HotelRoom::setShower(bool shower) {
    HotelRoom::shower = shower;
}

bool HotelRoom::isSecondRestroom() const {
    return secondRestroom;
}

void HotelRoom::setSecondRestroom(bool secondRestroom) {
    HotelRoom::secondRestroom = secondRestroom;
}

bool HotelRoom::isBalcony() const {
    return balcony;
}

void HotelRoom::setBalcony(bool balcony) {
    HotelRoom::balcony = balcony;
}

int HotelRoom::getIdHotel() const {
    return idHotel;
}

void HotelRoom::setIdHotel(int idHotel) {
    HotelRoom::idHotel = idHotel;
}

int HotelRoom::getIdHotelRoomType() const {
    return idHotelRoomType;
}

void HotelRoom::setIdHotelRoomType(int idHotelRoomType) {
    HotelRoom::idHotelRoomType = idHotelRoomType;
}

HotelRoom::~HotelRoom() {

    if(this->hotelRoomName!=nullptr){
        delete this->hotelRoomName;
        this->hotelRoomName=nullptr;
    }

    if (this->hotelRoomType != nullptr) {
        delete this->hotelRoomType;
        this->hotelRoomType = nullptr;
    }
    if (this->hotel != nullptr) {
        delete this->hotel;
        this->hotel = nullptr;
    }
}

HotelRoom::HotelRoom(const QString &hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony,
                     int idHotel, int idHotelRoomType) : Model() {
    this->hotelRoomName = new QString(hotelRoomName);
    this->places = places;
    this->shower = shower;
    this->secondRestroom = secondRestroom;
    this->balcony = balcony;
    this->idHotel = idHotel;
    this->idHotelRoomType = idHotelRoomType;

    this->hotel = nullptr;
    this->hotelRoomType = nullptr;
}

HotelRoom::HotelRoom(int id, const QString &hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony,
                     int idHotel, int idHotelRoomType) : Model(id) {
    this->hotelRoomName = new QString(hotelRoomName);
    this->places = places;
    this->shower = shower;
    this->secondRestroom = secondRestroom;
    this->balcony = balcony;
    this->idHotel = idHotel;
    this->idHotelRoomType = idHotelRoomType;

    this->hotel = nullptr;
    this->hotelRoomType = nullptr;
}

QString *HotelRoom::getHotel() const {
    return hotel;
}

void HotelRoom::setHotel(QString *hotel) {
    HotelRoom::hotel = hotel;
}

QString *HotelRoom::getHotelRoomType() const {
    return hotelRoomType;
}

void HotelRoom::setHotelRoomType(QString *hotelRoomType) {
    HotelRoom::hotelRoomType = hotelRoomType;
}

QStringList HotelRoom::columnList = {"ID_i", "Hotel room name_s", "Places_i", "Shower_b", "Second restroom_b",
                                     "Balcony_b",
                                     "Hotel_f", "Hotel Room Type_f"};

QStringList *HotelRoom::getValueList() {
    return new QStringList({QString::number(this->id),
                            *this->hotelRoomName,
                            QString::number(this->places),
                            (this->shower ? "Yes" : "No"),
                            (this->secondRestroom ? "Yes" : "No"),
                            (this->balcony ? "Yes" : "No"),
                            *this->hotel,
                            *this->hotelRoomType});
}

QStringList *HotelRoom::getValForAdd() {
    return new QStringList({QString::number(this->id), *this->hotelRoomName});
}

HotelRoom::HotelRoom(const QStringList &args) : Model(args) {
    this->hotelRoomName = new QString(args[1]);
    this->places = args[2].toInt();
    std::cout << args[3].toStdString();
    this->shower = toBool(args[3]);
    this->secondRestroom = toBool(args[4]);
    this->balcony = toBool(args[5]);
    this->idHotel = args[6].toInt();
    this->idHotelRoomType = args[7].toInt();


    this->hotel = nullptr;
    this->hotelRoomType = nullptr;
}
