#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class MyProcess;
}

class MyProcess : public QWidget
{
    Q_OBJECT

public:
    explicit MyProcess(QWidget *parent = nullptr);
    ~MyProcess();

private slots:
    void on_pushButton_clicked();
    void showResult();
    void showState(QProcess::ProcessState);
    void showError();
    void showFinished(int, QProcess::ExitStatus);
private:
    Ui::MyProcess *ui;
    QProcess myProcess;
};

#endif // MYPROCESS_H
