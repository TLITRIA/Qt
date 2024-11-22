#include "myipc.h"
#include "ui_myipc.h"

#include <QFileDialog>
#include <QBuffer>
#include <QDebug>

MyIPC::MyIPC(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyIPC)
{
    ui->setupUi(this);
    sharedMemory.setKey("QSharedMemoryExample"); // 设置底层共享内存段的标识
}

MyIPC::~MyIPC()
{
    delete ui;
}

void MyIPC::loadFromFile()
{
    if(sharedMemory.isAttached())   // 判断是否连接到共享内存段
        detach();                   // 是就将改进程与共享内存段进行分离
    ui->label->setText(tr("选择一个 图片！"));
    QString fileName = QFileDialog::getOpenFileName(0, QString(), QString(),
                                                    tr("Images (*.png *.jpg)"));
    QImage image;
    if(!image.load(fileName))
    {
        ui->label->setPixmap(tr("选择的文件不是图片，请选择图片文件！"));
        return ;
    }

    ui->label->setPixmap(QPixmap::fromImage(image));

    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out << image;
    int size = buffer.size();
    if(!sharedMemory.create(size))
    {
        ui->label->setPixmap(tr("无法创建共享内存段！"));
        return ;
    }
    sharedMemory.lock();
    char *to = (char*)sharedMemory.data();
    const char* from = buffer.data().data();
    memcpy(to, from, qMin(sharedMemory.size(), size));
    sharedMemory.unlock();
}

void MyIPC::loadFromMemory()
{
    if(!sharedMemory.attach())
    {
        ui->label->setPixmap(tr("无法连接到共享内存段，\n"
                                "请先加载一张图片！"));
        return ;
    }

    QBuffer buffer;
    QDataStream in(&buffer);
    QImage image;
    sharedMemory.lock();
    buffer.setData((char*)sharedMemory.constData(), sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in >> image;
    sharedMemory.unlock();
    sharedMemory.detach();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MyIPC::detach()
{

}
