#include "futext.h"
#include "ui_futext.h"

#include <QTextFrame>
#include <QDebug>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

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

    QAction *action_textFind = new QAction(tr("查找"), this);
    connect(action_textFind, &QAction::triggered, this, &FuText::textFind);
    ui->toolBar->addAction(action_textFind);

    findDialog = new QDialog(this);
    lineEdit = new QLineEdit(findDialog);
    QPushButton *btn = new QPushButton(findDialog);
    btn->setText(tr("查找下一个"));
    connect(btn, &QPushButton::clicked, this, &FuText::findNext);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    findDialog->setLayout(layout);

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

void FuText::textFind()
{
    findDialog->show();
}

void FuText::findNext()
{
    QString string = lineEdit->text();
    bool isfind = ui->textEdit->find(string);
    if(isfind)
    {
        qDebug() << tr("行号：%1 列号：%2")
                        .arg(ui->textEdit->textCursor().blockNumber())
                        .arg(ui->textEdit->textCursor().columnNumber());
    }

    /* 文本
By Bryan Lynn
31 October, 2024
Researchers say a large fish that was thought to have disappeared from Asia's Mekong River has been seen in the waterway in recent years.

The fish is called a giant salmon carp. A recent study detailed the most recent sightings of the fish. The lead writer of that study said the fish was seen at least three times between 2020 and 2023.

The predatory fish can grow to more than one meter in length and has an identifiable yellow spot surrounding its large eyes.

This undated photo provided by Chhut Chheana shows a researcher holding a giant salmon carp Aaptosyax grypus rediscovered in Cambodia. (Chhut Chheana/Wonders of the Mekong via AP)
This undated photo provided by Chhut Chheana shows a researcher holding a giant salmon carp Aaptosyax grypus rediscovered in Cambodia. (Chhut Chheana/Wonders of the Mekong via AP)
The Mekong River is Southeast Asia's longest river. It passes through China, Laos, Thailand, Myanmar, Cambodia and Vietnam. About 60 million people depend on the river for food and survival. It is also an important environment for numerous river creatures.

The leader of the research was Chheana Chhut. He is with the Inland Fisheries Research and Development Institute in Phnom Penh, Cambodia. “The giant salmon carp is like a symbol of the Mekong region,” Chheana recently told The Associated Press.

He was the co-writer with other researchers of a study announcing the findings in the publication Biological Conservation. Chheana said researchers had believed that the last confirmed sighting of the fish in the Mekong was in 2005.

But since 2017, biologists following the movements of migratory fish in Cambodia developed relationships with local fishing communities. They asked people in the communities to inform them of any unusual sightings.

That process led to the finding that three giant salmon carp were identified in the Mekong River and a neighboring waterway in Cambodia between 2020 and 2023.

Bunyeth Chan is a researcher at Cambodia's Svay Rieng University. He helped lead the research. Bunyeth told the AP, “I was really surprised and excited to see the real fish for the first time.”

Researchers say the sightings give them new hope for the future of the species. Another name used for the species is “ghost fish.”

“This rediscovery is very exciting, positive news,” said Zeb Hogan. He is a fish biologist at the University of Nevada, Reno, who was part of the research team.

But the problems the fish experienced also demonstrate the dangers facing all migratory species in the Mekong. The huge river faces industrial pollution and overfishing, among other problems.

Brian Eyler is director of the Southeast Asia Program at the Stimson Center in Washington, D.C. He was was not involved in the research. Eyler said one issue is that more than 700 dams are built along the river and neighboring waterways. In addition, there are very few workable “fish passages” that help species avoid obstructions.

The Greater Mekong area includes Vietnam, Cambodia, Laos, Thailand and Myanmar.

The researchers said they hope that cooperation with local communities in Thailand and Laos will permit them to confirm whether the fish also still swims in other parts of the Mekong.

I'm Bryan Lynn.

The Associated Press reported this story. Bryan Lynn adapted the report for VOA Learning English.
*/
}
