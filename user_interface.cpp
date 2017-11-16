#include "user_interface.h"
#include "ui_user_interface.h"

void user_interface::start_user()
{
//    QFile file_add("realtimesession.txt");
//    file_add.open(QIODevice::ReadWrite | QIODevice::Text);
//    std::ifstream fin("realtimesession.txt");
//    std::ofstream fout("realtimesession.txt");
//    std::string user_name_str;
//    fin >> user_name_str;
//    fout << user_name_str;
//    QString q = QString::fromStdString(user_name_str.c_str());
//    ui->User_name_label->setText(q);

//    file_add.close();
//    fin.close();
//    fout.close();
    QFile("realtimesession.txt").remove();
}

user_interface::user_interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_interface)
{
    ui->setupUi(this);
    start_user();
}

user_interface::~user_interface()
{
    delete ui;
}
