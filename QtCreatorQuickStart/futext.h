#ifndef FUTEXT_H
#define FUTEXT_H

#include <QMainWindow>

namespace Ui {
class FuText;
}

class QLineEdit;
class QDialog;

class FuText : public QMainWindow
{
    Q_OBJECT

public:
    explicit FuText(QWidget *parent = nullptr);
    ~FuText();
private slots:
    void showTextFrame();   // 遍历文档框架
    void showTextBlock();   // 遍历所有文本块
    void setTextFont(bool checked); // 设置字体格式
    void insertTable(); // 插入表格
    void insertList();  // 插入列表
    void insertImage(); // 插入图片
    void textFind();    // 查找文本
    void findNext();    // 查找下一个
private:
    Ui::FuText *ui;

    QLineEdit *lineEdit;
    QDialog *findDialog;
};

#endif // FUTEXT_H
