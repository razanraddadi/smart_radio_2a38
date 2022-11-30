#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<employ.h>

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
#include <arduino.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QString msg="ttttt";

private slots:
    void on_pushButton_clicked();

    void on_supprimer_clicked();

    void on_pushButton_2_clicked();

   // void on_chercher_clicked();

    void on_trier_clicked();

    void on_pdf_clicked();


    void on_statistics_clicked();

    void on_cryptage_clicked();

    void on_decryptage_clicked();

    void on_print_clicked();

    void on_arduinoOne_clicked();


    void on_search_textChanged(const QString &rech);

private:
    Ui::MainWindow *ui;
    Employ E;
    Arduino A;


};

#endif // MAINWINDOW_H
