#ifndef MYDRAWING_H
#define MYDRAWING_H

#include <QWidget>

namespace Ui {
class MyDrawing;
}

class MyDrawing : public QWidget
{
    Q_OBJECT

public:
    explicit MyDrawing(QWidget *parent = nullptr);
    ~MyDrawing();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::MyDrawing *ui;
};

#endif // MYDRAWING_H
