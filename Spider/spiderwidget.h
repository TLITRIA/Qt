#ifndef SPIDERWIDGET_H
#define SPIDERWIDGET_H

#include <QWidget>

namespace Ui {
class SpiderWidget;
}

class SpiderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpiderWidget(QWidget *parent = nullptr);
    ~SpiderWidget();

private:
    Ui::SpiderWidget *ui;
};

#endif // SPIDERWIDGET_H
