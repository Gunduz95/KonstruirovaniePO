/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *chooseButton;
    QPushButton *RunButton;
    QTextBrowser *browser;
    QMenuBar *menubar;
    QMenu *menuMartin_s_program;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chooseButton = new QPushButton(centralwidget);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));
        chooseButton->setGeometry(QRect(30, 50, 121, 71));
        RunButton = new QPushButton(centralwidget);
        RunButton->setObjectName(QString::fromUtf8("RunButton"));
        RunButton->setGeometry(QRect(190, 50, 111, 71));
        browser = new QTextBrowser(centralwidget);
        browser->setObjectName(QString::fromUtf8("browser"));
        browser->setGeometry(QRect(20, 170, 256, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuMartin_s_program = new QMenu(menubar);
        menuMartin_s_program->setObjectName(QString::fromUtf8("menuMartin_s_program"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMartin_s_program->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        chooseButton->setText(QApplication::translate("MainWindow", "Choose Input file", nullptr));
        RunButton->setText(QApplication::translate("MainWindow", "Run", nullptr));
        menuMartin_s_program->setTitle(QApplication::translate("MainWindow", "Martin's program", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
