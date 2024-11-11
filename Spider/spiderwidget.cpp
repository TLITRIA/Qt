#include "spiderwidget.h"
#include "ui_spiderwidget.h"

#include <QRegularExpression>
#include <QDebug>
SpiderWidget::SpiderWidget(QWidget *parent)
    : QWidget(parent)
    , mManager(new QNetworkAccessManager(this))
    , ui(new Ui::SpiderWidget)
{
    ui->setupUi(this);

    QNetworkRequest mTestRequest(QUrl(ui->UrlLineEdit->text()));
    //进行网络请求,会返回一个回复，服务器回复结束，QnetworkReply就会释放finished信号
    QNetworkReply *networkReply = mManager->get(mTestRequest);
    //回复结束的时候QnetworkReply会释放readyRead信号
    connect(networkReply,SIGNAL(readyRead()),this,SLOT(readFinishedSlot()),Qt::UniqueConnection);

}

SpiderWidget::~SpiderWidget()
{
    delete ui;
}

void SpiderWidget::readFinishedSlot()
{
    //sender()函数作用就是得到一个指针，这个指针是：当前槽函数所对应的信号是哪个对象发送的
    QNetworkReply *reply = (QNetworkReply *) sender();
    QByteArray data1 = reply->readAll();    //读取传回来的HTML数据
    QString strData = QString(data1);
    if(strData != "")
    {
        ui->textEdit->setText("Get website page's data!");
    }
    reply->deleteLater();                   //记得释放内存
    qDebug() << strData;
    // getPictureLinkFromHTML(strData);        //解析HTML，将图片链接存储在mDownloadList中
    // downloadResource(mDownloadList);        //对这些链接进行下载

}

void SpiderWidget::getPictureLinkFromHTML(const QString &strData)
{
    qDebug()<<"-----------picture------------";
    QStringList qsList;
    qsList.clear();
    QRegularExpression re("<img src=(?<path>\\S+?) (?<junk2>.*?)>", QRegularExpression::CaseInsensitiveOption);
    //QRegularExpression globalMatch全部匹配，获取到所有符合这个规则的字符串集合
    QRegularExpressionMatchIterator itor = re.globalMatch(qsContent);
    while(itor.hasNext())
    {
        QRegularExpressionMatch match = itor.next();
        QString junk2 = match.captured("junk2");
        QString path = match.captured("path");
        qsList<<path;
    }
    //处理downloadList数据
    foreach (QString var, qsList) {
        QString str = var.replace("\"","");
        str = str.replace(">","");
        str = str.replace("'","");
        qDebug() << "_strData: " << str;
        mDownloadList << str;
    }

}
