#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

signals:
    void dlgReturn(int);
private:
    Ui::MyDialog *ui;

/*
 * 信号默认是public，可以从任意地方发射，单只建议在定义该信号的类及其子类中发射
 * 信号只用声明不需要实现
 * 信号没有返回值只能是void型
 * 使用信号和槽必须加Q_OBJECT
*/
private slots:
    void on_pushButton_clicked();
};

#endif // MYDIALOG_H
