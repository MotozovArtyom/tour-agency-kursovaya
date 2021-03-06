//
// Created by rienel on 28.05.18.
//

#ifndef PSQLWORK_ADDWINDOW_H
#define PSQLWORK_ADDWINDOW_H

#include <QtWidgets>
#include <utils/Tables.h>

class AddWindow : public QDialog {
    Q_OBJECT
protected:
    QList<QWidget *> editList;
    QList<QLabel *> labelList;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QFormLayout *formLayout;
    Tables currentTable;

public:
    AddWindow(QWidget *parent, const Qt::WindowFlags &f, Tables table);

    virtual ~AddWindow();

    const QList<QWidget *> &getEditList() const;

    void setEditList(const QList<QWidget *> &editList);

    const QList<QLabel *> &getLabelList() const;

    void setLabelList(const QList<QLabel *> &labelList);

    QPushButton *getOkButton() const;

    void setOkButton(QPushButton *okButton);

    QPushButton *getCancelButton() const;

    void setCancelButton(QPushButton *cancelButton);

    QFormLayout *getFormLayout() const;

    void setFormLayout(QFormLayout *formLayout);

    void initDialogForm();

    QComboBox *initForeignEditLine(const QString columnName);

    template<class modelClass, class modelDaoClass>
    QComboBox *_initForeignEditLine(const QString columnName){
        QList<modelClass *> modelList = modelDaoClass().getAllFilled();
        auto comboBox = new QComboBox();
        foreach(modelClass *model, modelList){
            comboBox->addItem(model->getValForAdd()->join(" "));
        }
        return comboBox;
    };

    template<class modelClass>
    void _initDialogForm(){
        QStringList labelList = modelClass::columnList;
        QLabel *formLabel= nullptr;
        QLineEdit *lineEdit = nullptr;
        QComboBox *comboBox = nullptr;
        QDateEdit *dateEdit = nullptr;
        QTimeEdit *timeEdit = nullptr;
        QCheckBox *checkBox = nullptr;
        QSpinBox *numberEdit = nullptr;
        QDoubleSpinBox *doubleNumberEdit = nullptr;
        foreach(QString label, labelList){
            QStringList labelSplited = label.split("_");
            QString labelName = labelSplited[0];
            QString labelType = labelSplited[1];
            formLabel= new QLabel(labelName);
            if(labelName=="ID"){
                continue;
            }
            if(labelType == "i"){
                numberEdit = new QSpinBox();
                if(labelName=="Stars"){
                    numberEdit->setMaximum(5);
                    numberEdit->setMinimum(1);
                }else if(labelName=="Places"){
                    numberEdit->setMinimum(1);
                    numberEdit->setMaximum(7);
                }else{
                    numberEdit->setMaximum(10000000);
                }
                this->editList << numberEdit;
                this->formLayout->addRow(formLabel, numberEdit);
            }else if (labelType == "n"){
                doubleNumberEdit = new QDoubleSpinBox();
                doubleNumberEdit->setMaximum(10000000);
                doubleNumberEdit->setSingleStep(1);
                doubleNumberEdit->setDecimals(0);
                this->editList << doubleNumberEdit;
                this->formLayout->addRow(formLabel, doubleNumberEdit);
            }else if (labelType=="d"){
                dateEdit = new QDateEdit();
                dateEdit->setCalendarPopup(true);
                dateEdit->setMinimumDate(QDate(500,1,1));
                dateEdit->setMaximumDate(QDate(2100,1,1));
                dateEdit->setDisplayFormat(QString("dd.MM.yyyy"));
                dateEdit->setDate(QDate::currentDate());
                this->editList << dateEdit;
                this->formLayout->addRow(formLabel, dateEdit);
            }else if (labelType=="t") {
                timeEdit = new QTimeEdit();
                this->editList << timeEdit;
                this->formLayout->addRow(formLabel, timeEdit);
            }else if (labelType=="s") {
                lineEdit = new QLineEdit();
                this->editList << lineEdit;
                this->formLayout->addRow(formLabel, lineEdit);
            }else if (labelType=="b") {
                checkBox = new QCheckBox();
                this->editList << checkBox;
                this->formLayout->addRow(formLabel, checkBox);
            }else{
                comboBox = initForeignEditLine(labelName);
                this->editList << comboBox;
                this->formLayout->addRow(formLabel, comboBox);
            }
            this->labelList << formLabel;
        }
    };

public slots:

    void acceptForReservation();
};


#endif //PSQLWORK_ADDWINDOW_H
