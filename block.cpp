#include "block.h"
#include "ui_block.h"

Block::Block(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Block)
{
    ui->setupUi(this);
}

Block::~Block()
{
    delete ui;
}

void Block::on_pushButton_clicked()
{
    this->close();
}
