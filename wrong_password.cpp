#include "wrong_password.h"
#include "ui_wrong_password.h"

Wrong_password::Wrong_password(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wrong_password)
{
    ui->setupUi(this);
}

Wrong_password::~Wrong_password()
{
    delete ui;
}

void Wrong_password::on_pushButton_clicked()
{
    this->close();
}
