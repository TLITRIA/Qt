#ifndef MYOWNERSHIP_H
#define MYOWNERSHIP_H

#include <QWidget>

namespace Ui {
class MyOwnership;
}

class MyOwnership : public QWidget
{
    Q_OBJECT

public:
    explicit MyOwnership(QWidget *parent = nullptr);
    ~MyOwnership();

private:
    Ui::MyOwnership *ui;
};

#endif // MYOWNERSHIP_H
