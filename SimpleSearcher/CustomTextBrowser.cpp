#include "CustomTextBrowser.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>

CustomTextBrowser::CustomTextBrowser(QWidget *parent) : QTextBrowser(parent){}

void CustomTextBrowser::SetColor(QColor color)
{
    setTextColor(color);
}
