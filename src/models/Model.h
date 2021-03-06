//
// Created by rienel on 02.03.18.
//

#ifndef PSQLWORK_MODEL_H
#define PSQLWORK_MODEL_H

#include <QtCore/QObject>

class Model {
protected:
    int id;

public:
    Model(int id);

    Model();

    Model(QStringList args);

    virtual ~Model();

    int getId() const;

    void setId(int id);

    virtual QStringList *getValueList()=0;

    virtual QStringList *getValForAdd()=0;

    QDate *toDate(const QString dateString);

    QTime *toTime(const QString timeString);

    bool toBool(const QString boolString);

};


#endif //PSQLWORK_MODEL_H
