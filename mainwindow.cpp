#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenariats.h"
#include "arduino.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QIntValidator>
#include <QTextDocument>
#include <QMainWindow>
#include <QDebug>
#include <QTextDocument>
#include<QPrinter>
#include <QMainWindow>
#include<QSqlDatabase>
#include <QByteArray>
#include <QCalendarWidget>
#include <QDate>
#include <QDateEdit>
#include <QWidget>
#include <QWidgetData>
#include <QByteArray>
#include <QByteArrayData>
#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include<QChart>
#include<QtCharts>
#include<QChartGlobal>
#include<QChartView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->table_historique->setModel(p.afficherHistorieque());
    ui->table_historique->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tab_Partenariats->setModel(p.afficher());
    ui->le_ID->setValidator(new QIntValidator(0,9999999,this));
   int ret=R.connect_arduino(); // lancer la connexion à arduino
                             switch(ret){
                             case(0):qDebug()<< "arduino is available and connected to : "<< R.getarduino_port_name();
                                 break;
                             case(1):qDebug() << "arduino is available but not connected to :" <<R.getarduino_port_name();
                                break;
                             case(-1):qDebug() << "arduino is not available";
                             }
                              QObject::connect(R.getserial(),SIGNAL(readyRead()),this,SLOT(scanne())); // permet de lancer
                              //le slot update_label suite à la reception du signal readyRead (reception des données).

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scanne()
{
    data = R.read_from_arduino();

    c+=data;

    qDebug()<< c;
    if(c.length()==12)
    {
        QDateTime date = QDateTime::currentDateTime();

        if(p.ajouterhistorique(c,date))
        {
            ui->table_historique->setModel(p.afficherHistorieque());
        }
        c="";
    }
}

void MainWindow::on_bouton_ajouter_clicked()
{


    QString SOCIETE=ui->le_SOCIETE->text();
    QString PRODUIT=ui->le_PRODUIT->text();
    QString CATEGORIE=ui->LE_CATEGORIE->text();
    int ID=ui->le_ID->text().toInt();
    int BUDGET=ui->le_BUDGET->text().toInt();
    QString MATRICULE=ui->le_MATRICULE->text();
    QDate DATE_P=ui->le_DATE_P->date();
    Partenariats p(SOCIETE,PRODUIT,CATEGORIE,ID,BUDGET,MATRICULE,DATE_P);
bool test=p.ajouter() ;
    if (test)
    {
     ui->tab_Partenariats->setModel(p.afficher());
    QMessageBox::information(nullptr,QObject::tr("Valider"),
                             QObject::tr("Ajout successful.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
       { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                 QObject::tr("Ajout failed.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);}

}


void MainWindow::on_bouton_supprimer_clicked()
{
    int ID=ui->le_ID_Supprimer->text().toInt();
    bool test=p.supprimer(ID);
    if (test)
    {
    ui->tab_Partenariats->setModel(p.afficher());
    QMessageBox::information(nullptr,QObject::tr("Valider"),
                             QObject::tr("Suppression successful.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
       { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                 QObject::tr("Suppression failed.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);}
}



void MainWindow::on_bouton_modifier_clicked()

{


             QString SOCIETE=ui->le_SOCIETE->text();
             QString PRODUIT=ui->le_PRODUIT->text();
             QString CATEGORIE=ui->LE_CATEGORIE->text();
             int ID=ui->le_ID->text().toInt();
             int BUDGET=ui->le_BUDGET->text().toInt();
             QString MATRICULE=ui->le_MATRICULE->text();
            QDate DATE_P=ui->le_DATE_P->date();
            Partenariats p(SOCIETE,PRODUIT,CATEGORIE,ID,BUDGET,MATRICULE,DATE_P);
            bool test=p.modifier(ID);
            if(test)
            {

                ui->tab_Partenariats->setModel(p.afficher());//refresh

                       QMessageBox::information(nullptr, QObject::tr("effectué"),
                            QObject::tr(" Modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                       ui->le_ID->clear();
                       ui->le_SOCIETE->clear();
                       ui->le_PRODUIT->clear();
                       ui->LE_CATEGORIE->clear();
                       ui->le_BUDGET->clear();
                       ui->le_MATRICULE->clear();
                     //   ui->Date_P_Edit->clear();
           }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                            QObject::tr("non modifié !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);



            }

}



void MainWindow::on_bouton_tri_clicked()
{


   if(ui->Tri_B->isChecked())
{



    bool test=p.afficher_Partenariats_tri_BUDGET();

   if(test)
   {
       //refresh

       ui->tab_Partenariats->setModel(p.afficher_Partenariats_tri_BUDGET());

   QMessageBox::information(nullptr,QObject::tr("Valider"),
                            QObject::tr("Tri b successful.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
      { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                QObject::tr("Tri b failed.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);}
 }

   else if(ui->tri_S->isChecked())
{



    bool test=p.afficher_Partenariats_tri_SOCIETE();

   if(test)
   {
       //refresh

       ui->tab_Partenariats->setModel(p.afficher_Partenariats_tri_SOCIETE());

   QMessageBox::information(nullptr,QObject::tr("Valider"),
                            QObject::tr("Tri s successful.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
      { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                QObject::tr("Tri s failed.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);}
 }
}



void MainWindow::on_bouton_chercher_clicked()
{
 QString rech =ui->le_chercher->text();

 if(ui->S_chercher->isChecked())
{
 bool test=p.afficher_Partenariats_chercher(rech);

if(test)
{

ui->tab_Partenariats->setModel(p.afficher_Partenariats_chercher(rech));
QMessageBox::information(nullptr,QObject::tr("Valider"),
                         QObject::tr("chercher s successful.\n"
                                     "Click Cancel to exit."),QMessageBox::Cancel);
}
else
   { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                             QObject::tr("chercher s failed.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);}
}
 else
     if(ui->P_chercher->isChecked())
    {
     bool test=p.afficher_Partenariats_chercher(rech);

    if(test)
    {

    ui->tab_Partenariats->setModel(p.afficher_Partenariats_chercher(rech));
    QMessageBox::information(nullptr,QObject::tr("Valider"),
                             QObject::tr("chercher s successful.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
       { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                 QObject::tr("chercher s failed.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);}
    }
 else
         if(ui->C_chercher->isChecked())
        {
         bool test=p.afficher_Partenariats_chercher(rech);

        if(test)
        {

        ui->tab_Partenariats->setModel(p.afficher_Partenariats_chercher(rech));
        QMessageBox::information(nullptr,QObject::tr("Valider"),
                                 QObject::tr("chercher s successful.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
           { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                     QObject::tr("chercher s failed.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);}
        }
 else
             if(ui->ID_chercher->isChecked())
            {
             bool test=p.afficher_Partenariats_chercher(rech);

            if(test)
            {

            ui->tab_Partenariats->setModel(p.afficher_Partenariats_chercher(rech));
            QMessageBox::information(nullptr,QObject::tr("Valider"),
                                     QObject::tr("chercher s successful.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
            }
            else
               { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                         QObject::tr("chercher s failed.\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);}
            }
 else
                 if(ui->B_chercher->isChecked())
                {
                 bool test=p.afficher_Partenariats_chercher(rech);

                if(test)
                {

                ui->tab_Partenariats->setModel(p.afficher_Partenariats_chercher(rech));
                QMessageBox::information(nullptr,QObject::tr("Valider"),
                                         QObject::tr("chercher s successful.\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);
                }
                else
                   { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                             QObject::tr("chercher s failed.\n"
                                                         "Click Cancel to exit."),QMessageBox::Cancel);}
                }
 else

                     if(ui->M_chercher->isChecked())
                                {
                                 bool test=p.afficher_Partenariats_chercher(rech);

                                if(test)
                                {

                                ui->tab_Partenariats->setModel(p.afficher_Partenariats_chercher(rech));
                                QMessageBox::information(nullptr,QObject::tr("Valider"),
                                                         QObject::tr("chercher s successful.\n"
                                                                     "Click Cancel to exit."),QMessageBox::Cancel);
                                }
                                else
                                   { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                                             QObject::tr("chercher s failed.\n"
                                                                         "Click Cancel to exit."),QMessageBox::Cancel);}
                                }
}


void MainWindow::on_pushButton_PDF_clicked()
{

    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tab_Partenariats->model()->rowCount();
                const int columnCount =ui->tab_Partenariats->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("Partenariats")
                        <<  "</head>\n"
                        "<body bgcolor=#FFFFFF link=#5000A0>\n"
                            "<h1>Liste des Partenariats</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_Partenariats->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_Partenariats->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tab_Partenariats->isColumnHidden(column)) {
                                   QString data = ui->tab_Partenariats->model()->data(ui->tab_Partenariats->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("myfilepdf.pdf");
        document->print(&printer);
}

void MainWindow::on_bouton_Stat_Partenariats_clicked()
{

    QSqlQuery query,query1,query2,query3;
            qreal c1=0 ,sum=0,c2=0,c3=0;
            query.prepare("SELECT * FROM PARTENARIATS") ;
            query.exec();
            while(query.next())
            {
                    sum++ ;
            }

            query1.prepare("SELECT * FROM PARTENARIATS WHERE  BUDGET >=0 and BUDGET <=5000") ;
            query1.exec();
            while(query1.next())
            {
                    c1++ ;
            }

            query2.prepare("SELECT * FROM PARTENARIATS  WHERE BUDGET >=5999 and BUDGET <=10999 ") ;
            query2.exec();
            while(query2.next())
            {
                    c2++ ;
            }

            query3.prepare("SELECT * FROM PARTENARIATS WHERE BUDGET >=11000") ;
            query3.exec();
            while(query3.next())
            {
                    c3++ ;
            }

        qreal d1,d2,d3;
        d1=(c1/sum)*100;
        d2=(c2/sum)*100;
        d3=(c3/sum)*100;
            QBarSet *set1 = new QBarSet("BUDGET>0");
            QBarSet *set2 = new QBarSet("BUDGET>5999");
            QBarSet *set3 = new QBarSet("BUDGET>11000");


            // Assign values for each bar
             *set1 << d1 ;
             *set2 << d2 ;
             *set3 << d3 ;


            // Add all sets of data to the chart as a whole
            // 1. Bar Chart
            QBarSeries *series = new QBarSeries();

            // 2. Stacked bar chart
            // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

            series->append(set1);
            series->append(set2);
            series->append(set3);


            // Used to define the bar chart to display, title
            // legend,
            QChart *chart = new QChart();

            // Add the chart
            chart->addSeries(series);

            // Set title
            chart->setTitle("STATISTIQUE");

            // Define starting animation
            // NoAnimation, GridAxisAnimations, SeriesAnimations
            chart->setAnimationOptions(QChart::SeriesAnimations);

            // Holds the category titles
            QStringList categories;
            categories << "stats";

            // Adds categories to the axes
            QBarCategoryAxis *axis = new QBarCategoryAxis();
            axis->append(categories);
            chart->addAxis(axis, Qt::AlignBottom);
            series->attachAxis(axis);
            chart->createDefaultAxes();


            // 2. Stacked Bar chart

            // Define where the legend is displayed
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);


            // Used to display the chart
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

             chartView->setMinimumSize(550,300);
            chartView->setParent(ui->tableView_stat);

            // Used to change the palette
            QPalette pal = qApp->palette();


            // Apply palette changes to the application
            qApp->setPalette(pal);
    chartView->show();
}




void MainWindow::on_boutton_calcul_clicked()
{
    QString total=QString::number(p.Calculer());

    ui->label_total->setText(total);
}


void MainWindow::on_tab_Partenariats_doubleClicked(const QModelIndex &index)
{
    QString val = ui->tab_Partenariats->model()->data(index).toString();
    val = val.mid(0,10);
    qDebug()<< val;

    QDate date = QDate::fromString(val,"yyyy-MM-dd");
    ui->calendarWidget->setSelectedDate(date);
}

void MainWindow::on_calendarWidget_activated(const QDate &date)
{
    QDate DATE =  ui->calendarWidget->selectedDate();
    QString tmp = date.toString("yyyy-MM-dd");
   QSqlQuery query;

   query =p.request(tmp);
   bool test = false;
   if(query.exec())
   {
       //while(query.next())

           test = true;
           QMessageBox::information(nullptr, QObject::tr("Date exist"),
                       QObject::tr("Date exist.\n"
                                   "Click ok to exit."), QMessageBox::Cancel);

   }
   if(test == false )
   {
       QMessageBox::warning(nullptr, QObject::tr("Date n'existe pas "),
                   QObject::tr("Date n'existe pas.\n"
                               "Click ok to exit."), QMessageBox::Cancel);
}
}



