#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <QWidget>
#include <QFile>
#include <string>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QString>

namespace Ui {
class user_interface;
}

class user_interface : public QWidget
{
    Q_OBJECT

public:
    void start_user();
    explicit user_interface(QWidget *parent = 0);
    ~user_interface();

private:
    Ui::user_interface *ui;
};

#endif // USER_INTERFACE_H
