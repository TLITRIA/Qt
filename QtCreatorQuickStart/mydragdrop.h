#ifndef MYDRAGDROP_H
#define MYDRAGDROP_H

#include <QMainWindow>

namespace Ui {
class MyDragDrop;
}

class MyDragDrop : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyDragDrop(QWidget *parent = nullptr);
    ~MyDragDrop();
protected:
    void dragEnterEvent(QDragEnterEvent *event); // 拖动进入事件
    void dropEvent(QDropEvent *event);          // 放下事件

private:
    Ui::MyDragDrop *ui;
};

#endif // MYDRAGDROP_H
