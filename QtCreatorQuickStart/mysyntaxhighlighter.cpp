#include "mysyntaxhighlighter.h"
#include <QRegularExpression>


void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat myFormat;
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::green);
    QString pattern = "\\bchar\\b";   // 匹配char
    QRegularExpression expression(pattern);
    int index = text.indexOf(expression);
    while(index>=0)
    {
        // int length = expression.
    }
}
