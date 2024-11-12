#ifndef MYSIGNALSLOT2_H
#define MYSIGNALSLOT2_H

#include <QWidget>

namespace Ui {
class MySignalSlot2;
}

class MySignalSlot2 : public QWidget
{
    Q_OBJECT

public:
    explicit MySignalSlot2(QWidget *parent = nullptr);
    ~MySignalSlot2();
private slots:
    void on_myButton_clicked();
private:
    Ui::MySignalSlot2 *ui;
};

#endif // MYSIGNALSLOT2_H
