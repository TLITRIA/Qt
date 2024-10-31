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
    void showTextFrame();
private:
    Ui::FuText *ui;
};

#endif // FUTEXT_H
