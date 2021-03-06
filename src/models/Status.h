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
    QString *statusName;
public:
    static QStringList columnList;

    Status(int id, QString *name);

    Status(int id, const QString &name);

    Status(QString *name);

    Status(const QString &name);

    Status(int id);

    Status();

    Status(const QStringList &args);

    virtual ~Status();

    QString *getName() const;

    void setName(QString *name);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_STATUS_H
