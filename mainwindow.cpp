#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu *editMenu = ui->menubar->addMenu(tr("编辑(&E)"));   // 添加编辑菜单
    QAction *action_Open = editMenu->addAction(         // 添加打开菜单
        QIcon(":/image/myimages/open.png"), tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));   // 添加快捷键
    ui->menubar->addAction(action_Open);
}

MainWindow::~MainWindow()
{
    delete ui;
}
