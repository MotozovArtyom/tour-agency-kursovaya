//
// Created by rienel on 16.04.18.
//

#include "HotelDataBaseDAO.h"
#include <QtSql/QtSql>


//#include <QtSql/QtSql>
//#include "iostream"
//
//int main() {
//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//    db.setDatabaseName("testdb");
//    db.setUserName("rienel");
////    db.setHostName("asus");
//    db.setPassword("1957");
//    if (!db.open()) {
//        qDebug() << "Cannot open database: " << db.lastError();
//        return 0;
//    }
//    QStringList lst = db.tables();
//            foreach(QString str, lst) {
//            std::cout << "Table:" << str.toStdString();
//        }
//    return 0;
//}

std::list<Hotel *> HotelDataBaseDAO::getAll() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("");
    return std::list<Hotel *>();
}

Hotel *HotelDataBaseDAO::getById(int id) {
    return nullptr;
}

void HotelDataBaseDAO::add(Hotel *model) {

}

void HotelDataBaseDAO::update(Hotel *model) {

}

void HotelDataBaseDAO::del(Hotel *model) {

}
