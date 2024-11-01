#ifndef IMAGEDRAGDROP_H
#define IMAGEDRAGDROP_H

#include <QMainWindow>

namespace Ui {
class ImageDragDrop;
}

class ImageDragDrop : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageDragDrop(QWidget *parent = nullptr);
    ~ImageDragDrop();

protected:
    void mousePressEvent(QMouseEvent *event);       // 鼠标按下
    void dragEnterEvent(QDragEnterEvent *event);    // 拖动进入
    void dragMoveEvent(QDragMoveEvent *event);      // 拖动
    void dropEvent(QDropEvent *event);              // 放下
private:
    Ui::ImageDragDrop *ui;
};

#endif // IMAGEDRAGDROP_H
