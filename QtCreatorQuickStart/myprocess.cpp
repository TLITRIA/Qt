#include "myprocess.h"
#include "ui_myprocess.h"

#include <QDebug>
#include <QTextCodec>

MyProcess::MyProcess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyProcess)
{
    ui->setupUi(this);
    connect(&myProcess, &QProcess::readyRead, this, &MyProcess::showResult);
    connect(&myProcess, &QProcess::stateChanged, this, &MyProcess::showState);
    connect(&myProcess, &QProcess::errorOccurred, this, &MyProcess::showError);
    connect(&myProcess, SIGNAL(finished(int, QProcess::ExitStatus)),
            this, SLOT(showFinished(int,QProcess::ExitStatus)));

}

MyProcess::~MyProcess()
{
    delete ui;
}

void MyProcess::on_pushButton_clicked()
{
    // myProcess.start("notepad.exe");
    QString program = "cmd.exe";
    QStringList arguments;
    arguments << "/c dir&pause";
    myProcess.start(program, arguments);
}

void MyProcess::showResult()
{
    QTextCodec *codec = QTextCodec::codecForLocale();
    qDebug() << "showResult:\n" << codec->toUnicode(myProcess.readAll());
}

void MyProcess::showState(QProcess::ProcessState state)
{
    qDebug() << "showState:";
    if(state == QProcess::NotRunning) {
        qDebug() << "NotRunning";
    }else if( state == QProcess::Starting)
    {
        qDebug() << "Starting";
    }else
    {
        qDebug() << "Running";
    }
}

void MyProcess::showError()
{
    qDebug() << "showError:\n" << myProcess.errorString();
}

void MyProcess::showFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "showFinished:\n" << exitCode << exitStatus;
}

