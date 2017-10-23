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

QString MainWindow::QBeteArrayTOQString(QByteArray a)
{
    QString backToString = a;
}

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
    QTextStream in(&file);
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
    //в функцию (определение количества строк в файле)

    if(ui->Loggin->text() == "")
        qDebug()<<"Not enought information"<<endl;
    else
    {
        Struct user;
        for(int i=0; i<LineCount(fileName)/4; i++)
        {

        }
    }


    file.close();
}
