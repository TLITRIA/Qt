#include "mywebengine.h"
#include "ui_mywebengine.h"

// #include <QWebEngineView>

MyWebEngine::MyWebEngine(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWebEngine)
{
    ui->setupUi(this);
}

MyWebEngine::~MyWebEngine()
{
    delete ui;
}
