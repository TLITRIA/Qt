#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ getUserName WRITE setUserName NOTIFY userNameChanged)
public:
    explicit MyClass(QObject *parent = nullptr);
    QString getUserName() const         // 实现READ读函数
    {return m_userName;}
    void setUserName(QString userName)  // 实现WRITE写函数
    {
        m_userName = userName;
        emit userNameChanged(userName);
    }
signals:
    void userNameChanged(QString);
private:
    QString m_userName;
};

#endif // MYCLASS_H
