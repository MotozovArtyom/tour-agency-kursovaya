//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_DOCUMENTS_H
#define PSQLWORK_DOCUMENTS_H

#include "Model.h"
#include <QString>
#include <QDate>

class Documents : public Model {
private:
    QString *documentSerial;
    QDate *dateOfIssue;
    QString *issuanceDepartment;
public:
    static QStringList columnList;
    Documents(int id, QString *serial, QDate *dateOfIssue, QString *issuanceDepartment);

    Documents(int id, const QString &documentSerial, const QDate &dateOfIssue, const QString &issuanceDepartment);

    Documents(QString *serial, QDate *dateOfIssue, QString *issuanceDepartment);

    Documents(const QString &documentSerial, const QDate &dateOfIssue, const QString &issuanceDepartment);

    Documents(int id);

    Documents();

    Documents(const QStringList &args);

    virtual ~Documents();

    QString *getSerial() const;

    void setSerial(QString *serial);

    QDate *getDateOfIssue() const;

    void setDateOfIssue(QDate *dateOfIssue);

    QString *getIssuanceDepartment() const;

    void setIssuanceDepartment(QString *issuanceDepartment);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_DOCUMENTS_H
