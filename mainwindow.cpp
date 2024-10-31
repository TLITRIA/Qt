#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QActionGroup>
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QLabel>
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


    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolBar->addWidget(toolBtn);
    QSpinBox *spinBox = new QSpinBox(this);
    ui->toolBar->addWidget(spinBox);


    ui->statusbar->showMessage(tr("欢迎使用多文档编辑器"), 3000);
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("https://tlitria.github.io/");
    ui->statusbar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    QTextEdit *edit = new QTextEdit(this);
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
}



void MainWindow::on_action_Dock_triggered()
{
    ui->dockWidget->show();
}

