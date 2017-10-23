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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString QBeteArrayTOQString(QByteArray a);
    void Start(QString fileName);
    int LineCount(QString fileName);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
