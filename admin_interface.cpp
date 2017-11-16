#include "admin_interface.h"
#include "ui_admin_interface.h"

Admin_interface::Admin_interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_interface)
{
    ui->setupUi(this);
}

Admin_interface::~Admin_interface()
{
    delete ui;
}
