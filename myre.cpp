#include "myre.h"

#include <QDebug>
#include <QRegularExpression>

MyRE::MyRE() {
    QRegularExpression re(R"(^\d\d?$)"); // R("") 使用原始字符串，无需对反斜杠转义

    qDebug() << QString("a1").indexOf(re);
    qDebug() << QString("5").indexOf(re);
    qDebug() << QString("5b").indexOf(re);
    qDebug() << QString("12").indexOf(re);
    qDebug() << QString("123").indexOf(re);
    qDebug() << QString("33").indexOf(re);

    qDebug() << "*******************";
    re.setPattern(R"(\b(mail|letter)\b)");
    qDebug() << QString("emailletter").indexOf(re);
    qDebug() << QString("my mail").indexOf(re);
    qDebug() << QString("my mail letter").indexOf(re);

    qDebug() << "*******************";
    re.setPattern("M(?!ail)");
    qDebug() << QString("this is M").replace(re, "Mail");
    qDebug() << QString("my M,your Ms,his Mail").contains(re);
    qDebug() << QString("my M,your Ms,his Mail").lastIndexOf(re);
    qDebug() << QString("my M,your Ms,his Mail").replace(re, "Mail");
    qDebug() << QString("my M,your Ms,his Mail").replace(re, "Mail").contains(re);
    re.setPatternOptions(QRegularExpression::CaseInsensitiveOption); // 设置不区分大小写
    qDebug() << QString("my M,your Ms,his Mail").replace(re, "Mail").contains(re);

    qDebug() << "获取匹配到的数目";
    QString str1 = "One Eric another Eirik, and an Ericsson. "
                   "How many Eiriks, Eric?";
    QRegularExpression re1("\\bEi?ri[ck]\\b");
    // 1.循环计数
    int pos = 0;
    int count = 0;
    while (pos >= 0) {
        pos = str1.indexOf(re1, pos);
        if (pos >= 0) {
            qDebug()  << "pos: " << pos;
            ++pos;                             // 从匹配的字符的下一个字符开始匹配
            ++count;                           // 匹配到的数目加1
        }
    }
    qDebug() << "count: " << count;
    // 2.直接求
    qDebug() << "count: " << str1.count(re1);


    // 贪婪的和非贪婪的
    QString str = "20005";
    re.setPattern("0+");
    qDebug() << "greedy count: " << str.replace(re, "1"); // 结果为215

    str = "20005";
    re.setPattern("0+?");  // 方式1
    //re.setPatternOptions(QRegularExpression::InvertedGreedinessOption); // 方式2
    qDebug() << "lazy count: " << str.replace(re, "1"); // 结果为21115
}
