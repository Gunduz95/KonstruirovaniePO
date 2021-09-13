#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

#include <iostream>
#include <filesystem>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <exception>
#include "fileinfo.h"

#include <boost/math/special_functions/prime.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"

using namespace boost::math;
using namespace boost::gregorian;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    browser = findChild<QTextBrowser*>("textBrowser");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chooseButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "D://",
                "Text File (*.txt)"
                );

    currFileName = filename;
}

void MainWindow::on_RunButton_clicked()
{
    if(currFileName.length() == 0)
    {
        QMessageBox::information(this, "Error", "No file is selected! ");
        return;
    }
    FileInfo_t file_info = check(currFileName.toStdString(),this);
    browser->clear();
    browser->append(QString("Total charcaters: %1").arg(file_info.numCharacters));
    browser->append(QString("Total special symbols: %1").arg(file_info.numSpecialSymbols));
    browser->append(QString("Total newline charcaters: %1").arg(file_info.numNewLines));
    browser->append(QString("Total whitespace charcaters: %1").arg(file_info.numWhiteSpace));
}
