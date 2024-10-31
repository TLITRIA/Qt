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

    QAction *action_textBlock = new QAction(tr("文本块"), this);
    connect(action_textBlock, &QAction::triggered, this, &FuText::showTextBlock);
    ui->toolBar->addAction(action_textBlock);

    QAction *action_font = new QAction(tr("字体"), this);
    action_font->setCheckable(true);
    connect(action_font, &QAction::toggled, this, &FuText::setTextFont);
    ui->toolBar->addAction(action_font);

    QAction *action_textTable = new QAction(tr("表格"), this);
    QAction *action_textList = new QAction(tr("列表"), this);
    QAction *action_textImage = new QAction(tr("图片"), this);
    connect(action_textTable, &QAction::triggered, this, &FuText::insertTable);
    connect(action_textList, &QAction::triggered, this, &FuText::insertList);
    connect(action_textImage, &QAction::triggered, this, &FuText::insertImage);
    ui->toolBar->addAction(action_textTable);
    ui->toolBar->addAction(action_textList);
    ui->toolBar->addAction(action_textImage);

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

void FuText::showTextBlock()
{
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();
    for(int i = 0; i < document->blockCount(); i++)
    {
        qDebug() << tr("文本块%1，文本块首行行号：%2，长度：%3，内容为：")
                        .arg(i).arg(block.firstLineNumber()).arg(block.length())
                 << block.text();
        block = block.next();
    }
}

void FuText::setTextFont(bool checked)
{
    if(checked)
    {
        QTextCursor cursor = ui->textEdit->textCursor();

        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);

        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        charFormat.setFont(QFont(tr("宋体"), 12, QFont::Bold, true));
        charFormat.setFontUnderline(true);
        cursor.setCharFormat(charFormat);

        cursor.insertText(tr("测试字体"));
    }
    else
    {
        // 如何恢复？
    }
}

void FuText::insertTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellSpacing(2);
    format.setCellPadding(10);
    cursor.insertTable(2, 2, format);
}

void FuText::insertList()
{
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);
    ui->textEdit->textCursor().insertList(format);
}

void FuText::insertImage()
{
    QTextImageFormat format;
    format.setName(":/image/myimages/new.png");
    ui->textEdit->textCursor().insertImage(format);
}
