#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<employ.h>
#include<QSqlQuery>
#include<QSqlQueryModel>

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

    void on_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_chercher_clicked();

    void on_trier_clicked();

    void on_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Employ E;
};

#endif // MAINWINDOW_H
