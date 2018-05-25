//
// Created by rienel on 04.05.18.
//

#ifndef PSQLWORK_MAINWINDOW_H
#define PSQLWORK_MAINWINDOW_H

#include <QtCore>
#include <QtWidgets>
#include <models/interfaces/ModelDAO.h>

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    QTableWidget *pTable;
    QPushButton *pButton;
    QTabWidget *tabWidget;
    QMenuBar *menu;
public:
    MainWindow(QMainWindow *pwgt = 0);

    virtual ~MainWindow();

    QTableWidget *getPTable() const;

    void setPTable(QTableWidget *pTable);

    QPushButton *getPButton() const;

    void setPButton(QPushButton *pButton);

    QTabWidget *getTabWidget() const;

    void setTabWidget(QTabWidget *tabWidget);

    template<class modelClass, class daoClass>void renderTable();
};


#endif //PSQLWORK_MAINWINDOW_H
