#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<employ.h>
#include<smtp.h>
#include<QSqlQuery>
#include<QSqlQueryModel>

#include<QPainter>
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>

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


    void on_statistics_clicked();

    void on_cryptage_clicked();

    void on_decryptage_clicked();

private:
    Ui::MainWindow *ui;
    Employ E;

};

#endif // MAINWINDOW_H
