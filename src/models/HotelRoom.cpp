//
// Created by rienel on 08.04.18.
//

#include "HotelRoom.h"

HotelRoom::HotelRoom(int id, QString *hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony,
                     int idHotel, int idHotelRoomType) : Model(id), hotelRoomName(hotelRoomName), places(places),
                                                         shower(shower), secondRestroom(secondRestroom),
                                                         balcony(balcony), idHotel(idHotel),
                                                         idHotelRoomType(idHotelRoomType) {}

HotelRoom::HotelRoom(QString *hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony, int idHotel,
                     int idHotelRoomType) : hotelRoomName(hotelRoomName), places(places), shower(shower),
                                            secondRestroom(secondRestroom), balcony(balcony), idHotel(idHotel),
                                            idHotelRoomType(idHotelRoomType) {}

HotelRoom::HotelRoom(int id) : Model(id) {}

HotelRoom::HotelRoom() {}

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
    delete hotelRoomName;
}