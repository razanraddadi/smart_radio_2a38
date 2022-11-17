#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "program.h"
#include "historique.h"
#include <QMessageBox>
#include <QMessageBox>
#include <QTextDocument>
#include <QPrinter>
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QTextStream>
#include <game.h>
#include <QTimer>
#include <QDateTime>
#include "chart.h"
#include "slice.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QTime>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->tableView->setModel(ptmp.afficher());
 timer = new QTimer(this);
 connect (timer,SIGNAL(timeout()),this,SLOT(mygame()) );
timer->start(1000);
timer2 = new QTimer(this);
connect (timer2,SIGNAL(timeout()),this,SLOT(mygame2()) );
timer2->start(10000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_bp_ajout_clicked()
{
    int id_p =ui->le_id->text().toInt();
    QString nom_p=ui->le_nom->text();
    QString acteur=ui->le_anim->text();
    int id_s=ui->le_ids->text().toInt();
     int jj=ui->jj->text().toInt();
      int mm=ui->mm->text().toInt();
       int yyyy=ui->yyyy->text().toInt();
        int heure=ui->hh->text().toInt();
         int min=ui->min->text().toInt();
         int viwes=ui->leviwes->text().toInt();
    Program P(id_p,id_s,nom_p,acteur,jj,mm,yyyy,heure,min,viwes);
    bool test=P.ajouter();
    bool nid=P.getid_p();
    bool nids=P.getid_s();

     ui->tableView->setModel(ptmp.afficher());
     if (!nid){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer id  \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    if (!nids){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer id salle \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    if (nom_p==""){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer nom du proramme \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}

    if (acteur==""){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer nom d'acteur\n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    if(test)
    {
       QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout validé\n"
                                                                               "Click Cancel to exit"),QMessageBox::Cancel);}
            else

        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("ajout non validé\n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}

void MainWindow::on_le_id_supp_2_clicked()
{

    {
       int id_p=ui->le_id_supp->text().toInt();
         bool test=ptmp.supprimer(id_p);
         ui->tableView->setModel(ptmp.afficher());
         if(test)
         {

            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression validé\n"
                                                                                    "Click Cancel to exit"),QMessageBox::Cancel); }
                 else
             QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non validé\n"
                                                                            "Click Cancel to exit"),QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_2_clicked()
{
    {

        QString rech=ui->le_rech->text();

if(rech=="")
{
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("inserer le nom\n"
                                                                          "Click Cancel to exit"),QMessageBox::Cancel);
}
else
         ui->tableView_2->setModel(ptmp.afficher_recherche(rech));

    }}

void MainWindow::on_le_tri_clicked()
{
 ui->tableView->setModel(ptmp.afficher_tri());
}

void MainWindow::on_pdf_clicked()
{
    {

        QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tableView->model()->rowCount();
                    const int columnCount =ui->tableView->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("programme")
                            <<  "</head>\n"
                            "<body bgcolor=#FFFFFF link=#5000A0>\n"
                                "<h1>Liste des Programmes</h1>"

                                "<table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tableView->isColumnHidden(column)) {
                                       QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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
            printer.setOutputFileName("program.pdf");
            document->print(&printer);
}
}
void MainWindow::mygame()
{  Program P;
    QDate date=QDate::currentDate();
    QTime time2=QTime::currentTime();
   QString time_txt=time2.toString(" hh : mm : ss");
   QString date_text=date.toString("yyyy-MM-dd");
   ui->time->setText(time_txt);

   ui->date->setText(date_text);
}
void MainWindow::mygame2()
{  Program P;
   // int i;
    int x=rand()%24;
    const int y=rand()%60;
    const int z=rand()%60;
    QString tab1[20];
    QString game;
    /*for (i=1;i>52;i++)
    {
        tab1[i]=x+'/'+y+'/'+z;
    }*/

 QTime time =QTime(x,y,z);
 QString time_text=time.toString(" hh : mm : ss");
 //game=tab1[rand()%51];
  ui->time_2->setText(time_text);
  ui->time_3->setText(game);
}

void MainWindow::on_historique_clicked()
{
 ui->tableView_3->setModel(h.afficherh());
}




void MainWindow::on_modif_clicked()
{
    int id_p =ui->le_id->text().toInt();
    QString nom_p=ui->le_nom->text();
    QString acteur=ui->le_anim->text();
    int id_s=ui->le_ids->text().toInt();
    int jj=ui->jj->text().toInt();
     int mm=ui->mm->text().toInt();
      int yyyy=ui->yyyy->text().toInt();
       int heure=ui->hh->text().toInt();
        int min=ui->min->text().toInt();
        int views=ui->leviwes->text().toInt();
    Program P(id_p,id_s,nom_p,acteur,jj,mm,yyyy,heure,min,views);
    bool test=P.modifier();
    bool nid=P.getid_p();
    bool nids=P.getid_s();

     ui->tableView->setModel(ptmp.afficher());
     if (!nid){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer id  \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    else if (!nids){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer id salle \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    else if (nom_p==""){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer nom du proramme \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}

    else if (acteur==""){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer nom d'acteur\n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    if(test)
    {
       QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification validé\n"
                                                                               "Click Cancel to exit"),QMessageBox::Cancel);}
            else

        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non validé\n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);
}

void MainWindow::on_chart_clicked()
{
    int res;
                statistiques w(this);
                w.setWindowTitle("Statistiques des Views");

                res = w.exec();
                qDebug() << res;
                if (res == QDialog::Rejected)
                  return;
}



void MainWindow::on_supprimer_historique_clicked()
{

        int id_p =ui->le_supph->text().toInt();
            bool test=h.supprimer(id_p);
           ui->tableView_3->setModel(h.afficherh());
            if(test)
            {

               QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression validé\n"
                                                                                       "Click Cancel to exit"),QMessageBox::Cancel); }
                    else
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non validé\n"
                                                                               "Click Cancel to exit"),QMessageBox::Cancel);}
