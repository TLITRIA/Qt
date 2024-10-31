#include "futext.h"
#include "ui_futext.h"

#include <QTextFrame>
#include <QDebug>

FuText::FuText(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FuText)
{
    ui->setupUi(this);

    QTextDocument *document = ui->textEdit->document(); // 获取文档对象
    QTextFrame *rootFrame = document->rootFrame();      // 获取根框架
    QTextFrameFormat format;                            // 创建框架格式
    format.setBorderBrush(Qt::red);
    format.setBorder(3);
    // format.setHeight(100);                              // 固定高度
    rootFrame->setFrameFormat(format);                  // 应用框架格式

    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);
    frameFormat.setMargin(10);
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);
    QTextCursor cursor = ui->textEdit->textCursor();    // 获取光标
    cursor.insertFrame(frameFormat);                    // 在光标处插入框架

    QAction *action_textFrame = new QAction(tr("框架"), this);
    connect(action_textFrame, &QAction::triggered, this, &FuText::showTextFrame);
    ui->toolBar->addAction(action_textFrame);
}

FuText::~FuText()
{
    delete ui;
}

void FuText::showTextFrame()
{
    QTextDocument *document = ui->textEdit->document();
    QTextFrame *frame = document->rootFrame();
    QTextFrame::iterator it;
    for(it = frame->begin(); !(it.atEnd()); ++it)
    {
        QTextFrame *childFrame = it.currentFrame();
        QTextBlock childBlock = it.currentBlock();
        if(childFrame)
            qDebug() << "frame";
        else if(childBlock.isValid())
            qDebug() << "block:" << childBlock.text();
    }
}
