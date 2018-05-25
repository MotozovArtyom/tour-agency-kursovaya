//
// Created by rienel on 25.05.18.
//

#ifndef PSQLWORK_STATUS_H
#define PSQLWORK_STATUS_H

#include "models/Model.h"
#include <QString>
#include <QStringList>

class Status : public Model {
private:
    QString *name;
public:
    static QStringList columnList;

    Status(int id, QString *name);

    Status(int id, QString &name);

    Status(QString *name);

    Status(QString &name);

    Status(int id);

    Status();

    virtual ~Status();

    QString *getName() const;

    void setName(QString *name);
};


#endif //PSQLWORK_STATUS_H
