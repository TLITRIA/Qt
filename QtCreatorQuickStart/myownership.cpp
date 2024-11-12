#include "myownership.h"
#include "ui_myownership.h"

#include "mybutton.h"
#include <QDebug>
#include <QHBoxLayout>

MyOwnership::MyOwnership(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyOwnership)
{
    ui->setupUi(this);

    MyButton *btn = new MyButton(this);
    btn->setText(tr("button"));

    MyButton *btn1 = new MyButton;
    MyButton *btn2 = new MyButton;
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(btn1);
    layout->addWidget(btn2);
    setLayout(layout);

    qDebug() << children(); // 子部件
}

MyOwnership::~MyOwnership()
{
    delete ui;
    qDebug() << "delete MyOwnership";
}
