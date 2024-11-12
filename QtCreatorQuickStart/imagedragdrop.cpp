#include "imagedragdrop.h"
#include "ui_imagedragdrop.h"

#include <QLabel>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPaintEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>

ImageDragDrop::ImageDragDrop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageDragDrop)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    QLabel * label= new QLabel(this);
    QPixmap pix(":/image/myimages/open.png");
    label->setPixmap(pix);
    label->resize(pix.size());
    label->move(100, 100);
    label->setAttribute(Qt::WA_DeleteOnClose);  // 当窗口关闭时销毁图片

}

ImageDragDrop::~ImageDragDrop()
{
    delete ui;
}

void ImageDragDrop::mousePressEvent(QMouseEvent *event)
{
    // 1.获取图片
    QLabel *child = static_cast<QLabel*> (childAt(event->pos()));
    if(!child->inherits("QLabel"))
        return; // 部件不是QLabel直接返回
    QPixmap pixmap = child->pixmap();
    // 2.自定义
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());
    // 3.将数据放入QMimeData
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("myimage/png", itemData);
    // 4.将QMimeData数据放入QDrag
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
    // 5.给原图片添加阴影
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();
    child->setPixmap(tempPixmap);
    // 6.执行拖放操作
    if(drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction)
        == Qt::MoveAction)
        child->close();
    else
    {
        child->show();
        child->setPixmap(pixmap);
    }
}

void ImageDragDrop::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("open.png"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
        event->ignore();
}

void ImageDragDrop::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("open.png"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
        event->ignore();
}

void ImageDragDrop::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("open.png"))
    {
        QByteArray itemData = event->mimeData()->data("open.png");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;
        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->resize(pixmap.size());
        newLabel->move(event->pos() - offset); // pos() is deprecated
        newLabel->show();
        newLabel->setAttribute(Qt::WA_DeleteOnClose);
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
