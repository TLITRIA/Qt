#ifndef SPIDERWIDGET_H
#define SPIDERWIDGET_H

#include <QWidget>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui {
class SpiderWidget;
}

class SpiderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpiderWidget(QWidget *parent = nullptr);
    ~SpiderWidget();

public slots:
    void readFinishedSlot();
private:
    void getPictureLinkFromHTML(const QString& strData);

    QNetworkAccessManager* mManager;
    QString qsContent;
    QStringList mDownloadList;
    Ui::SpiderWidget *ui;
};

#endif // SPIDERWIDGET_H
