#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_chooseButton_clicked();
    void on_RunButton_clicked();

private:
    Ui::MainWindow *ui;
    QTextBrowser *browser;
    QString currFileName;
};

#endif // MAINWINDOW_H
