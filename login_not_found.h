#ifndef LOGIN_NOT_FOUND_H
#define LOGIN_NOT_FOUND_H

#include <QWidget>

namespace Ui {
class Login_not_found;
}

class Login_not_found : public QWidget
{
    Q_OBJECT

public:
    explicit Login_not_found(QWidget *parent = 0);
    ~Login_not_found();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login_not_found *ui;
};

#endif // LOGIN_NOT_FOUND_H
