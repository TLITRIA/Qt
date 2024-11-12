#ifndef MYDRAWING3_H
#define MYDRAWING3_H

#include <QWidget>

namespace Ui {
class MyDrawing3;
}

class MyDrawing3 : public QWidget
{
    Q_OBJECT

public:
    explicit MyDrawing3(QWidget *parent = nullptr);
    ~MyDrawing3();
protected:
    void paintEvent(QPaintEvent* event);
private:
    Ui::MyDrawing3 *ui;
};

#endif // MYDRAWING3_H
