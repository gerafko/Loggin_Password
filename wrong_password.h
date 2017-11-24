#ifndef WRONG_PASSWORD_H
#define WRONG_PASSWORD_H

#include <QWidget>

namespace Ui {
class Wrong_password;
}

class Wrong_password : public QWidget
{
    Q_OBJECT

public:
    explicit Wrong_password(QWidget *parent = 0);
    ~Wrong_password();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Wrong_password *ui;
};

#endif // WRONG_PASSWORD_H
