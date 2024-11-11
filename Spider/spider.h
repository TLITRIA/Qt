#ifndef SPIDER_H
#define SPIDER_H

#include <QObject>
#include <QStringList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>



class Spider : public QObject
{
    Q_OBJECT
public:
    Spider();

    bool Initialize();
    void Request();
    void SaveResult();

    QString tempGetHtml();

    void getMessageWithRE(const QString& data);
    void getMessageWithXML(const QString& data);
    void getMessageWithWeb(const QString& data);
public slots:
    void readFinishedSlot();

public:
    bool taskFinished;

private:
    QString url = "https://prts.wiki/w/%E5%B9%B2%E5%91%98%E4%B8%80%E8%A7%88";
    QNetworkAccessManager* mManager;
    QString mData;
    QStringList mResult;
};

#endif // SPIDER_H
