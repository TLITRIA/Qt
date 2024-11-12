#ifndef MYSIGNALSLOT_H
#define MYSIGNALSLOT_H

#include <QWidget>

namespace Ui {
class MySignalSlot;
}

class MySignalSlot : public QWidget
{
    Q_OBJECT

public:
    explicit MySignalSlot(QWidget *parent = nullptr);
    ~MySignalSlot();
private slots:
    void showValue(int val);
private:
    Ui::MySignalSlot *ui;
};

#endif // MYSIGNALSLOT_H
