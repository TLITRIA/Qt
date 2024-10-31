#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QActionGroup>

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


    QActionGroup *group = new QActionGroup(this);
    QAction *action_L = group->addAction(tr("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction *action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

}

MainWindow::~MainWindow()
{
    delete ui;
}
