#include "mysignalslot.h"
#include "ui_mysignalslot.h"

#include "mydialog.h"

MySignalSlot::MySignalSlot(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MySignalSlot)
{
    ui->setupUi(this);

    MyDialog *dlg = new MyDialog(this);
    connect(dlg, SIGNAL(dlgReturn(int)), this, SLOT(showValue(int)));
    dlg->show();
}

MySignalSlot::~MySignalSlot()
{
    delete ui;
}

void MySignalSlot::showValue(int val)
{
    ui->label->setText(tr("获取的值是%1").arg(val));
}
