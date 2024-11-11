#ifndef MYWEBENGINE_H
#define MYWEBENGINE_H

#include <QWidget>

namespace Ui {
class MyWebEngine;
}


class MyWebEngine : public QWidget
{
    Q_OBJECT

public:
    explicit MyWebEngine(QWidget *parent = nullptr);
    ~MyWebEngine();

private:
    Ui::MyWebEngine *ui;
};

#endif // MYWEBENGINE_H
