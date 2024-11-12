#include "spider.h"


#include <qdebug.h>
#include <QRegularExpression>
#include <QTextDocument>
// #include <qtwEB>
#include <QFile>
Spider::Spider()
: taskFinished(false)
, mManager(new QNetworkAccessManager(this))
{

}

bool Spider::Initialize()
{

    return true;
}

void Spider::Request()
{
    taskFinished = true;

    QNetworkRequest mTestRequest(url);
    //进行网络请求,会返回一个回复，服务器回复结束，QnetworkReply就会释放finished信号
    QNetworkReply *networkReply = mManager->get(mTestRequest);
    //回复结束的时候QnetworkReply会释放readyRead信号
    connect(networkReply,SIGNAL(readyRead()),this,SLOT(readFinishedSlot()),Qt::UniqueConnection);
}

void Spider::SaveResult()
{


    // save data to file or sql
}

QString Spider::tempGetHtml()
{
    QString fileName = R"(D:\Documents\QtCreatorQuick\干员一览 - PRTS - 玩家共同构筑的明日方舟中文Wiki.html)";
    QFile file(fileName);
    qDebug() << file.exists();
    file.open(QIODevice::ReadOnly);
    QString ret = file.readAll();
    file.close();
    return ret;
}

void Spider::readFinishedSlot()
{
    QNetworkReply *reply = (QNetworkReply *) sender(); // 取到发送信号的对象的指针
    QByteArray data1 = reply->readAll();    //读取传回来的HTML数据
    mData = QString(data1);
    if(mData != "")
        qDebug() << QString("Get website page's data!");
    reply->deleteLater();                   //记得释放内存

    qDebug() << "data as below:\n";
    qDebug() << mData;

    getMessageWithRE(mData);        //解析HTML

    SaveResult();
}

void Spider::getMessageWithRE(const QString &data)
{
    QStringList qsList;
    qsList.clear();

    QRegularExpression re(R"()");
    QRegularExpressionMatch match = re.match(data);

    qDebug() << "match result as below:\n";
    if(match.hasMatch())
    {
        int length = match.capturedLength();
        for (int i = 0; i < length; i++)
        {
            qDebug() << match.captured(i);
        }
    }
}

void Spider::getMessageWithXML(const QString &data)
{

}

void Spider::getMessageWithWeb(const QString &data)
{

}
