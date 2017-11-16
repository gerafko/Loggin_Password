#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//QString MainWindow::QBeteArrayTOQString(QByteArray a)
//{
//    QString backToString = a;
//}

void MainWindow::Start(QString fileName)
{
    QFile file(fileName);
    if(QFileInfo::exists(fileName))
    {
        qDebug () << "file exists" << endl;
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QString data =  file.readAll();
        qDebug () << "data in file:" << data << endl;
        qDebug () <<"file already created"<<endl;
        file.close();
    }
    else
    {
        qDebug () << "file does not exists" << endl;
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        file.write("admin\n");
        file.write("5\n");
        file.write("admin\n");
        file.write("0\n");
        qDebug()<<"file created"<<endl;
        file.close();
    }
}

int MainWindow::LineCount(QString fileName)
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
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName("massive.txt");
    Start(fileName);
//    qDebug()<<"start"<<endl;
    QFile file(fileName);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    std::ifstream fin ("massive.txt");
    //в функцию (определение количества строк в файле)


    //сравниваем данные для входа
    std::string a;
    std::string user_name;
    if(ui->Loggin->text() == "") //проверяем на наличие логина в строке
        qDebug()<<"Not enought information"<<endl;
    else
    {
        Struct user;
        for(int i=0; i<LineCount(fileName)/4; i++) //начинаем перебирать логины в базе, далее пароли
        {
            fin >> a;
            if (ui->Loggin->text().toStdString() == a)
            {
                user_name = a;
                fin >> a;
                fin >> a;
                if (ui->Password->text().toStdString() == a)
                {
                    fin >> a;
                    if (user_name == "admin")
                    {
                        Admin_interface *new_admin_window = new Admin_interface;
                        new_admin_window->show();
                        this->close();
                    }
                    else
                    {
                            //открывает доп.файл
                        QFile file_add("realtimesession.txt");
                        file_add.open(QIODevice::ReadOnly | QIODevice::Text);
                        std::ofstream fout("realtimesession.txt");
                        fout << user_name;

                        user_interface *new_window = new user_interface;
                        new_window->show();
                        this->close();

                        fout.close();
                        file_add.close();
                    }
                }
            }
            else
            {
                fin >> a;
                fin >> a;
                fin >> a;
            }
        }
    }

    fin.close();
    file.close();
}
