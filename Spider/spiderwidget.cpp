#include "spiderwidget.h"
#include "ui_spiderwidget.h"

SpiderWidget::SpiderWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpiderWidget)
{
    ui->setupUi(this);
}

SpiderWidget::~SpiderWidget()
{
    delete ui;
}
