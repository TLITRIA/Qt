#include "mydragdrop.h"
#include "ui_mydragdrop.h"

#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
#include <QDebug>

MyDragDrop::MyDragDrop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyDragDrop)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

MyDragDrop::~MyDragDrop()
{
    delete ui;
}

void MyDragDrop::dragEnterEvent(QDragEnterEvent *event)
{
        qDebug() << tr("coone\n");
    if(event->mimeData()->hasUrls())    // 数据是否包含url
        event->acceptProposedAction(); // 接收动作
    else
        event->ignore();                // 放下事件
}

void MyDragDrop::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    qDebug() << tr("coone\n");
    if(mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();
        QString fileName = urlList.at(0).toLocalFile();
        qDebug() << fileName;
        if(!fileName.isEmpty())
        {
            QFile file(fileName);
            qDebug() << file.fileName();
            if(!file.open(QIODevice::ReadOnly))
                return;
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
    }
}
