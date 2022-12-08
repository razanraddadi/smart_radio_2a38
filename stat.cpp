/*
#include "stat.h"
#include "ui_stat.h"

#include <qvariant.h>
#include "invite.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCore>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
#include <qwindow.h>

statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
   // ui->setupUi(this);
       QBarSet *set=new QBarSet("Age");
      *set<<I.calculer1(0,9)<<I.calculer1(10,18)<<I.calculer1(19,30)<<I.calculer1(31,70);
       QBarSeries *series=new QBarSeries();
       *set<<0.01;
       series->append(set);
       QChart *chart=new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistiques Des Ages");
       chart->setAnimationOptions(QChart::AllAnimations);
       QStringList Age;
       Age<<"[0ans..9ans]"<<"[10ans..18ans]"<<"[19ans..30ans]"<<"[31ans..70ans]";
       QBarCategoryAxis *axis=new QBarCategoryAxis();
       axis->append(Age);
       chart->createDefaultAxes();
       chart->setAxisX(axis,series);

       QChartView *chartview=new QChartView(chart);

       QGridLayout *mainLayout = new QGridLayout;
       mainLayout->addWidget(chartview, 1000, 500  );
       this->setLayout(mainLayout);
}
statistiques ::~statistiques()
{
delete ui;
}
*/
