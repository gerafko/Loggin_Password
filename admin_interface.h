#ifndef ADMIN_INTERFACE_H
#define ADMIN_INTERFACE_H

#include <QWidget>

namespace Ui {
class Admin_interface;
}

class Admin_interface : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_interface(QWidget *parent = 0);
    ~Admin_interface();

private:
    Ui::Admin_interface *ui;
};

#endif // ADMIN_INTERFACE_H
