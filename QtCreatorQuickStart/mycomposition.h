#ifndef MYCOMPOSITION_H
#define MYCOMPOSITION_H

#include <QWidget>

namespace Ui {
class MyComposition;
}

class MyComposition : public QWidget
{
    Q_OBJECT

public:
    explicit MyComposition(QWidget *parent = nullptr);
    ~MyComposition();
protected:
    void paintEvent(QPaintEvent* event);
private:
    Ui::MyComposition *ui;
};

#endif // MYCOMPOSITION_H
