#ifndef MYTRANSFORMATION_H
#define MYTRANSFORMATION_H

#include <QWidget>

namespace Ui {
class MyTransformation;
}

class QTimer;
class MyTransformation : public QWidget
{
    Q_OBJECT

public:
    explicit MyTransformation(QWidget *parent = nullptr);
    ~MyTransformation();
protected:
    void paintEvent(QPaintEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
private:
    Ui::MyTransformation *ui;
    QTimer* timer;
    int angle;
};

#endif // MYTRANSFORMATION_H
