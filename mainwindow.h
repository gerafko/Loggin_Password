#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include "struct.h"
#include <QFileInfo>
#include <QDebug>
#include <QByteArray>
#include <QTextCodec>
#include <fstream>
#include <iostream>
#include <user_interface.h>
#include <admin_interface.h>
#include <block.h>
#include <login_not_found.h>
#include <wrong_password.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    virtual void keyPressEvent(QKeyEvent *event);
    QString QBeteArrayTOQString(QByteArray a);
    void Start(QString fileName);
    int LineCount(QString fileName);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void wrong_password_f();
    void block_f();
    void loggin_not_found_f();
    void s1(const QString i);

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
