#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>

namespace Ui {
class Block;
}

class Block : public QWidget
{
    Q_OBJECT

public:
    explicit Block(QWidget *parent = 0);
    ~Block();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Block *ui;
};

#endif // BLOCK_H
