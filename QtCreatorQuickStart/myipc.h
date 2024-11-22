#ifndef MYIPC_H
#define MYIPC_H

#include <QDialog>
#include <QSharedMemory>

namespace Ui {
class MyIPC;
}

class MyIPC : public QDialog
{
    Q_OBJECT

public:
    explicit MyIPC(QWidget *parent = nullptr);
    ~MyIPC();
public slots:
    void loadFromFile();
    void loadFromMemory();
private:
    void detach();
private:
    Ui::MyIPC *ui;
    QSharedMemory sharedMemory;
};

#endif // MYIPC_H
