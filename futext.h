#ifndef FUTEXT_H
#define FUTEXT_H

#include <QMainWindow>

namespace Ui {
class FuText;
}

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
private:
    Ui::FuText *ui;
};

#endif // FUTEXT_H
