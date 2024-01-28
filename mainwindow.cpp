#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QTextBrowser>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include "JSONReader.h"
#include "CustomTextBrowser.h"

std::string fileNameCSV = "serials.txt";
std::string fileNameJSON = "serials.json";
QString filePath;
QColor defaultColor = Qt::black;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 }

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::FontColorSetter(QColor color, QString outputText, CustomTextBrowser textBrowser)
//{
//    textBrowser.SetColor(color);
//    textBrowser.append(outputText);
//    textBrowser.SetColor(defaultColor);
//}

void MainWindow::FontColorSetter(QColor color, QString outputText, OutputWindows outputWindow)
{
    if (outputWindow == searchTB)
    {
        ui->searchTB->SetColor(color);
        ui->searchTB->append(outputText);
        ui->searchTB->SetColor(defaultColor);
    }

    if (outputWindow == addTB)
    {
        ui->addTB->SetColor(color);
        ui->addTB->append(outputText);
        ui->addTB->SetColor(defaultColor);
    }
}

void MainWindow::ReaderCreator(QString suffix)
{
    if (suffix == "json")
    {
        JSONReader reader(fileNameJSON);
        if(reader.is_Open())
            Serials = reader.Read();
        else
        {
            FontColorSetter(Qt::darkCyan, "No files", searchTB);
        }
    }

    if (suffix == "txt")
    {
        CSVReader reader(fileNameCSV);
        if(reader.is_Open())
            Serials = reader.Read();
        else
        {
            FontColorSetter(Qt::darkCyan, "No files", searchTB);
        }
    }
}

void MainWindow::Search()
{
    bool flag = false;
    for (const auto& s: Serials)
    {
        if (s.name == ui->searchLE->text().toStdString())
        {
            ui->searchTB->append(QString::number(s.id) + ": " + QString::fromStdString(s.name) + ", " + QString::number(s.year) + ", " + QString::number(s.seasons));
            flag = true;
        }
    }
    if (!flag)
    {
        FontColorSetter(Qt::red, "Serial not found!", searchTB);
    }
}

void MainWindow::AddData()
{
    Serial serial;
    serial.id = Serials.size();
    serial.name = ui->serialName->text().toStdString();
    serial.seasons = ui->serialSize->text().toInt();
    serial.year = ui->serialYear->text().toInt();

    CSVWriter writer(fileNameCSV);
    writer.Add(serial);
    FontColorSetter(Qt::green, "Data added!", addTB);

    Serials.push_back(serial);
}

void MainWindow::Explore()
{
    filePath = QFileDialog::getOpenFileName(this, "Choose a file to read", QDir::homePath());
    QFileInfo fileInfo(filePath);
    QString suffix = fileInfo.suffix();

    ui->searchTB->append(filePath);

    ReaderCreator(suffix);
}

void MainWindow::Clear()
{
    ui->searchTB->clear();
}







