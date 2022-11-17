#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "chart.h"
#include "slice.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QTime>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),
                             QObject::tr("connection successful.\n"
                                         "Click Cancel to exit"), QMessageBox::Cancel);

    };
    return a.exec();
}
