#ifndef CUSTOMTEXTBROWSER_H
#define CUSTOMTEXTBROWSER_H

#include <QTextBrowser>

class CustomTextBrowser: public QTextBrowser
{
public:
    CustomTextBrowser(QWidget *parent = nullptr);
    void SetColor(QColor color);
};

#endif // CUSTOMTEXTBROWSER_H
