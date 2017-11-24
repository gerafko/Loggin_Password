#include "login_not_found.h"
#include "ui_login_not_found.h"

Login_not_found::Login_not_found(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login_not_found)
{
    ui->setupUi(this);
}

Login_not_found::~Login_not_found()
{
    delete ui;
}

void Login_not_found::on_pushButton_clicked()
{
    this->close();
}
