#include "myproperty.h"
#include "ui_myproperty.h"

#include "myclass.h"
#include <QDebug>

MyProperty::MyProperty(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyProperty)
{
    ui->setupUi(this);

    MyClass *my = new MyClass(this);
    connect(my, &MyClass::userNameChanged, this, &MyProperty::userChanged);
    my->setUserName("yafei");
    qDebug() << "useName1:" << my->getUserName();
    my->setProperty("userName", "linux");
    qDebug() << "useName2:" << my->property("userName").toString();

    my->setProperty("myValue", 10); // 动态属性
    qDebug() << "myValue:" << my->property("myValue").toInt();


}

MyProperty::~MyProperty()
{
    delete ui;
}

void MyProperty::userChanged(QString userName)
{
    qDebug() << "User Changed:" << userName;
}
