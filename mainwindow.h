#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <dialog.h>
#include "connection.h"
#include "invite.h"


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
    void on_pushButton_clicked();
    void  update_label();

private:
    Ui::MainWindow *ui;
     Arduino A;
     invite I;

int k=0;
};

#endif // MAINWINDOW_H
