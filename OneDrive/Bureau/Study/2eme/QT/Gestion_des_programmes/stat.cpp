#include "stat.h"
#include "ui_chart.h"
#include <qvariant.h>
#include "program.h"
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
       QBarSet *set=new QBarSet("VIEWS ");
      *set<<A.calculer1(0,100)<<A.calculer1(101,200)<<A.calculer1(201,1000)<<A.calculer1(1000,10000);
       QBarSeries *series=new QBarSeries();
       *set<<10;
       series->append(set);
       QChart *chart=new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistiques des Views");
       chart->setAnimationOptions(QChart::AllAnimations);
       QStringList mois;
       mois<<"[0..100]"<<"[101..200]"<<"[201..1000]"<<"[1000..10000]";
       QBarCategoryAxis *axis=new QBarCategoryAxis();
       axis->append(mois);
       chart->createDefaultAxes();
       chart->setAxisX(axis,series);

       QChartView *chartview=new QChartView(chart);

       QGridLayout *mainLayout = new QGridLayout;
       mainLayout->addWidget(chartview, 10000, 5000  );
       this->setLayout(mainLayout);
}
statistiques ::~statistiques()
{
delete ui;
}
