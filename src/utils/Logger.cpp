//
// Created by rienel on 01.05.18.
//


#include <QtCore/QDate>
#include <QtCore/QTextStream>
#include "Logger.h"


//Logger *Logger::getInstance() {
//    if (instance == nullptr) {
//        instance = new Logger();
//    }
//    return instance;
//}
//
//Logger::Logger() {
//    Logger::instance = nullptr;
//}

Logger::Logger(QObject *parent, QString fileName, QPlainTextEdit *editor) {
    this->editor = editor;
    if (!fileName.isEmpty()) {
        this->file = new QFile;
        this->file->setFileName(fileName);
        this->file->open(QIODevice::Append | QIODevice::Text);
    }
}

void Logger::write(const QString &value) {
    QString text =
            QDate::currentDate().toString("dd.MM.yyyy hh:mm:ss ") + value;
    QTextStream out(this->file);
    out.setCodec("UTF-8");
    if (file != nullptr) {
        out << text;
    }
    if (this->editor != nullptr) {
        this->editor->appendPlainText(text);
    }
}

Logger::~Logger() {
    if (file != 0) {
        file->close();
    }
}


