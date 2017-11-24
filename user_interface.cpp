#include "user_interface.h"
#include "ui_user_interface.h"

int user_interface::LineCount(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //в функцию (определение количества строк в файле)
    QTextStream fin(&file);
    int i=0;
    while(!file.atEnd())
    {
        file.readLine();
        i++;
//        qDebug()<<i<<endl;
    }
    return i;
    file.close();
}

QString user_interface::start_user()
{
    QFile file_add("realtimesession.txt");
    file_add.open(QIODevice::ReadWrite | QIODevice::Text);
    std::ifstream fin("realtimesession.txt");
    std::ofstream fout("realtimesession.txt");
    std::string user_name_str;
    fin >> user_name_str;
    fout << user_name_str;
    QString q = QString::fromStdString(user_name_str.c_str());
    file_add.close();
    fin.close();
    fout.close();
    QFile("realtimesession.txt").remove();
    return q;
}

user_interface::user_interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_interface)
{    
    ui->setupUi(this);
}



user_interface::~user_interface()
{
    delete ui;
}

void user_interface::on_pushButton_clicked()
{
    QString fileName("test.txt");
    QFile file(fileName);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    std::string a = "2";

    QTextStream in(&file);
//    QString line = in.readLine();
//    if (line.contains("1")){  //провер€ю нужно ли править строку
//        file.seek(file.pos() - line.length()); // ещЄ единичка дл€ перевода строки
//        in << line.append("   <-- changed string\n");

//}

    in.seek(0);

    // spisok loginov
    QString loginsString = in.readAll();

    QString LoginToDelete = "1";

    int indexLoginStrToDelete = loginsString.indexOf(LoginToDelete);
    loginsString.remove(indexLoginStrToDelete, 1);
    in.
    file.close();
}

