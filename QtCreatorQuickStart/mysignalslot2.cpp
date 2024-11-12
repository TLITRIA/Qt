#include "mysignalslot2.h"
#include "ui_mysignalslot2.h"

#include <QPushButton>

MySignalSlot2::MySignalSlot2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MySignalSlot2)
{
    QPushButton *button = new QPushButton(this);
    button->setObjectName(tr("myButton")); // 注意是对象名称

    ui->setupUi(this); // 需要在定义部件后调用才能实现自动关联
}

MySignalSlot2::~MySignalSlot2()
{// 信号和槽的高级应用
    delete ui;
}

void MySignalSlot2::on_myButton_clicked()
{
    close();
}
