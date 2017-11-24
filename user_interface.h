#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <QWidget>
#include <QFile>
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QString>
#include <struct.h>
#include <mainwindow.h>
#include <string>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
namespace Ui {
class user_interface;
}

class user_interface : public QWidget
{
    Q_OBJECT

public:
    QString start_user();
    int LineCount(QString fileName);
    user_interface(QWidget *parent = 0/*, std::string user_name*/);
    user_interface (const std::string user_name);
    ~user_interface();

private slots:
    void on_pushButton_clicked();

private:
    Ui::user_interface *ui;
};

#endif // USER_INTERFACE_H
