#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CSVReader.h"
#include "CustomTextBrowser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum OutputWindows
{
    searchTB,
    addTB
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void FontColorSetter(QColor color, QString outputText, OutputWindows outputWindow);
    void ReaderCreator(QString suffix);

public slots:
    void Search();
    void AddData();
    void Explore();
    void Clear();

private:
    Ui::MainWindow *ui;
    std::vector<Serial> Serials;
};
#endif // MAINWINDOW_H
