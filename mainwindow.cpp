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
    file.close();
}

void MainWindow::block_f()
{
    Block *error = new Block;
    error->show();
}

void MainWindow::loggin_not_found_f()
{
    Login_not_found *error = new Login_not_found;
    error->show();
}

void MainWindow::wrong_password_f()
{
    Wrong_password *error_pas = new Wrong_password;
    error_pas->show();
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
    int b;
    std::string user_name;
    if(ui->Loggin->text() == "") //проверяем на наличие логина в строке
    {
        qDebug()<<"Not enought information"<<endl;
        fin.close();
        file.close();
    }
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
                    fin >> b;
                    if (user_name == "admin")
                    {
                        Admin_interface *new_admin_window = new Admin_interface;
                        new_admin_window->show();
                        this->close();
                        fin.close();
                        file.close();
                        break;
                    }
                    else
                    {
                        if (b==0)
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
                            file.close();
                            break;
                        }
                        else
                        {
                            block_f();
                            fin.close();
                            file.close();
                            break;
                        }
                    }
                }
                else
                {
                    wrong_password_f();
                    break;
                }
            }
            else
            {
                fin >> a;
                fin >> a;
                fin >> a;
            }
            if (i==(LineCount(fileName)/4)-1)
                loggin_not_found_f();
        }
    }

    fin.close();
    file.close();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//    if (ui->Password->text().length() < ui->lineEdit->text().length())
//    {
//        QString a = ui->lineEdit->text();
//        int l = a.length();
//        a = a[a.length()];
//        ui->Password->text()+a;
//        ui->lineEdit->text().replace(1, l,"*");
//    }
//    else
//    {
//        int l = ui->lineEdit->text().length();
//        ui->Password->text().remove(l, 1);
//    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_editingFinished()
{
//        if (ui->Password->text().length() < ui->lineEdit->text().length())
//        {
//            QString a = ui->lineEdit->text();
//            int l = a.length();
//            a = a[a.length()];
//            ui->Password->text()+a;
//            ui->lineEdit->text().replace(1, l,"*");
//        }
//        else
//        {
//            int l = ui->lineEdit->text().length();
//            ui->Password->text().remove(l, 1);
//        }
}

void MainWindow::s1(QString i)
{
//    if (ui->lineEdit->text().length()>1)
//    {
//        QString line = ui->lineEdit->text();
//         int index = line.length();
//         line.replace(index, 1, i);
//         ui->lineEdit->insert(line);

//         QTimer *timer = new QTimer(this);
//         timer->setSingleShot(true);
//         timer->setInterval(500);

//         connect(timer, &QTimer::timeout, [this,timer,index]() {
//             QString line = ui->lineEdit->text();
//             line.replace(index, 1, '*');
//             ui->lineEdit->setText(line);
//             timer->deleteLater();
//         });

//         timer->start();
//    }
}
