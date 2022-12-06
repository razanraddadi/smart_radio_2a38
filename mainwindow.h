#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "partenariats.h"
//#include "stat_combo.h"
#include "arduino.h"
#include <QSqlQuery>
#include <QMainWindow>

/*#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QChartView>
#include<QtCharts>
#include <QWidget>*/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bouton_ajouter_clicked();
    void on_bouton_supprimer_clicked();
    void on_bouton_modifier_clicked();
    void on_bouton_tri_clicked();
    void on_bouton_chercher_clicked();
   // void on_bouton_Stat_Partenariats_clicked();
    void on_pushButton_PDF_clicked();
    void on_pushButton_arduino_clicked();
    void on_boutton_calcul_clicked();

    void on_calendarWidget_activated(const QDate &date);

    void on_tab_Partenariats_doubleClicked(const QModelIndex &index);

    void on_bouton_Stat_Partenariats_clicked();

    void scanne();

private:
    Ui::MainWindow *ui;
     Partenariats p;
    // stat_combo *s;
     QByteArray data;
      Arduino R;
      QString c="";

};
#endif // MAINWINDOW_H
