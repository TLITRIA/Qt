#ifndef MYDOUBLEBUFFERS_H
#define MYDOUBLEBUFFERS_H

#include <QWidget>

namespace Ui {
class MyDoubleBuffers;
}

class MyDoubleBuffers : public QWidget
{
    Q_OBJECT

public:
    explicit MyDoubleBuffers(QWidget *parent = nullptr);
    ~MyDoubleBuffers();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    Ui::MyDoubleBuffers *ui;

    QPixmap pix;
    QPixmap tempPix;
    QPoint startPoint;
    QPoint endPoint;
    bool isDrawing;
};

#endif // MYDOUBLEBUFFERS_H
