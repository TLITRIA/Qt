#ifndef MYPROPERTY_H
#define MYPROPERTY_H

#include <QWidget>

namespace Ui {
class MyProperty;
}

class MyProperty : public QWidget
{
    Q_OBJECT

public:
    explicit MyProperty(QWidget *parent = nullptr);
    ~MyProperty();
private slots:
    void userChanged(QString userName);
private:
    Ui::MyProperty *ui;
};

#endif // MYPROPERTY_H
