#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtWidgets>
#include "employ.h"
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

#include<QPainter>
#include<QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>

#include <QPrinter>
#include <QPrintDialog>
#include"QPdfWriter"
#include"QDesktopServices"
#include<QtPrintSupport>
#include <QPropertyAnimation>
#include<QTextDocument>
#include<QFileDialog>
#include <QPrinterInfo>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->setModel(E.afficher());
    ui->tri->setModel(E.tri_cin());
    ui->tri->setModel(E.tri_nom());
    ui->tri->setModel(E.tri_prenom());
    ui->tri->setModel(E.tri_cnss());

    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }

         connect(this, SIGNAL(timeout()), this, SLOT(setRefSalle()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString nom=ui->nom->text();
   QString prenom=ui->prenom->text();
   int cin=ui->cin->text().toInt();
   int cnss=ui->cnss->text().toInt();
   QString poste=ui->poste->text();
   QString SALAIRE_INIT="1600";
   QString ETAT="null";

    Employ E(nom,prenom,cin,cnss,poste,SALAIRE_INIT,ETAT);

    bool test= E.ajouter();
ui->nom->clear();
ui->prenom->clear();
ui->cin->clear();
ui->cnss->clear();
ui->poste->clear();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout Effectué\n"),QMessageBox::Cancel);
        ui->table->setModel(E.afficher());
         ui->tri->setModel(E.tri_cin());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non Effectué\n"),QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimer_clicked()
{
Employ E1;
E1.setcin(ui->supp->text().toInt());
bool test=E1.supprimer(E1.getcin());
ui->supp->clear();
if (test)
{
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression Effectuée\n"),QMessageBox::Cancel);
    ui->table->setModel(E.afficher());
     ui->tri->setModel(E.tri_cin());

}
else
{
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non Effectuée\n"),QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_2_clicked()
{

    QString nom=ui->nom_2->text();
    QString prenom=ui->prenom_2->text();
    int cin=ui->cin_2->text().toInt();
    int cnss=ui->cnss_2->text().toInt();
    QString poste=ui->poste_2->text();
    QString SALAIRE_INIT="1600";
    QString ETAT="null";

    Employ E2(nom,prenom,cin,cnss,poste,SALAIRE_INIT,ETAT);

    bool test= E2.update(E2);
ui->nom_2->clear();
ui->prenom_2->clear();
ui->cin_2->clear();
ui->cnss_2->clear();
ui->poste_2->clear();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification Effectué\n"),QMessageBox::Cancel);
        ui->table->setModel(E2.afficher());
         ui->tri->setModel(E.tri_cin());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non Effectué\n"),QMessageBox::Cancel);
    }

}



void MainWindow::on_trier_clicked()
{
//tri par cin

    if(ui->tri_1->isChecked())
 {



     bool test=E.tri_cin();

    if(test)
    {
        //refresh

        ui->tri->setModel(E.tri_cin());


    }

  }

    //tri par prenom
    else if(ui->tri_2->isChecked())
 {
     bool test=E.tri_prenom();

    if(test)
    {
        //refresh

        ui->tri->setModel(E.tri_prenom());

    }

  }

    //tri par nom
    else if(ui->tri_3->isChecked())
 {



     bool test=E.tri_nom();

    if(test)
    {
        //refresh

        ui->tri->setModel(E.tri_nom());

    }

  }
    //tri par cnss
    else if(ui->tri_4->isChecked())
 {

     bool test=E.tri_cnss();

    if(test)
    {
        //refresh

        ui->tri->setModel(E.tri_cnss());


    }

  }
}


void MainWindow::on_pdf_clicked()
{

    QPdfWriter pdf("D:/Esprit/2A38/Projet C++/Atelier_Connexion/Liste_employes.pdf");

   QPainter painter(&pdf);
   int i = 4100;

          QColor dateColor(0x4a5bcf);
          painter.setPen(dateColor);

          painter.setFont(QFont("Montserrat SemiBold", 11));
          QDate cd = QDate::currentDate();
          painter.drawText(8400,250,cd.toString("Tunis"));
          painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

          QColor titleColor(0x341763);
          painter.setPen(titleColor);
          painter.setFont(QFont("Montserrat SemiBold", 25));

          painter.drawText(3000,2700,"Liste des employés");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          //painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3300,9400,500);

          painter.setFont(QFont("Montserrat SemiBold", 10));

          painter.drawText(500,3600,"Nom");
          painter.drawText(2000,3600,"Prénom");
          painter.drawText(3800,3600,"CIN");
          painter.drawText(4800,3600,"CNSS");
          painter.drawText(5800,3600,"Poste");
          painter.drawText(6800,3600,"Salaire");
          painter.drawText(7800,3600,"Etat");
          painter.setFont(QFont("Montserrat", 10));
          painter.drawRect(100,3300,9400,9000);


          QSqlQuery query;
          query.prepare("SELECT * FROM EMPLOYE");
          query.exec();
          int y=4300;
          while (query.next())
          {
              painter.drawLine(100,y,9490,y);
              y+=500;
              painter.drawText(500,i,query.value(0).toString());
              painter.drawText(2000,i,query.value(1).toString());
              painter.drawText(3800,i,query.value(2).toString());
              painter.drawText(4800,i,query.value(3).toString());
              painter.drawText(5800,i,query.value(4).toString());
              painter.drawText(6800,i,query.value(5).toString());
              painter.drawText(7800,i,query.value(6).toString());

             i = i + 500;
          }
          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
          QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_statistics_clicked()
{

        QSqlQuery query,query1,query2,query3;
            qreal c1=0 ,sum=0,c2=0,c3=0;
            query.prepare("SELECT * FROM EMPLOYE") ;
            query.exec();
            while(query.next())
            {
                    sum++ ;
            }

            query1.prepare("SELECT * FROM EMPLOYE WHERE POSTE='marketing'") ;
            query1.exec();
            while(query1.next())
            {
                    c1++ ;
            }

            query2.prepare("SELECT * FROM EMPLOYE WHERE POSTE='sponsoring' ") ;
            query2.exec();
            while(query2.next())
            {
                    c2++ ;
            }

            query3.prepare("SELECT * FROM EMPLOYE WHERE POSTE='informatique'") ;
            query3.exec();
            while(query3.next())
            {
                    c3++ ;
            }

        qreal d1,d2,d3;
        d1=(c1/sum)*100;
        d2=(c2/sum)*100;
        d3=(c3/sum)*100;
            QBarSet *set1 = new QBarSet("marketing");
            QBarSet *set2 = new QBarSet("sponsoring");
            QBarSet *set3 = new QBarSet("informatique");


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

             chartView->setMinimumSize(1021,601);
            chartView->setParent(ui->stat);

            // Used to change the palette
            QPalette pal = qApp->palette();


            // Apply palette changes to the application
            qApp->setPalette(pal);
chartView->show();
}

void MainWindow::on_cryptage_clicked()
{
    int cin=ui->cin_orig->text().toInt();

    Employ E3;


    bool test= E3.cryptage(E3,cin);
ui->cin_orig->clear();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Cryptage Effectué\n"),QMessageBox::Cancel);
        ui->table->setModel(E3.afficher());
         ui->tri->setModel(E.tri_cin());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Cryptage non Effectué\n"),QMessageBox::Cancel);
    }
}

void MainWindow::on_decryptage_clicked()
{
     QString cin=ui->cin_orig->text();
    Employ E4;


    bool test= E4.decryptage(E4,cin);
ui->cin_orig->clear();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Decryptage Effectué\n"),QMessageBox::Cancel);
        ui->table->setModel(E4.afficher());
         ui->tri->setModel(E.tri_cin());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Decryptage non Effectué\n"),QMessageBox::Cancel);
    }
}

void MainWindow::on_print_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->table->model()->rowCount();
    const int columnCount = ui->table->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg("employe")
         <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->table->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->table->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->table->isColumnHidden(column)) {
                QString data = ui->table->model()->data(ui->table->model()->index(row, column)).toString().simplified();
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

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;
}

void MainWindow::on_arduinoOne_clicked()
{

    QSqlQuery  query;


  int nb_hr = qrand()%(8-1 + 1) + 1; //resultat input
    int val = qrand()%(2-1 + 1) + 1; //resultat input


    if (val==2){
        //arduino
    QString dataSend=msg;
        A.write_to_arduino(dataSend.toStdString().c_str());
        A.write_to_arduino(("1")); //envoyer 1 à arduino
        A.write_to_arduino(dataSend.toStdString().c_str());

    //base

        QString cin="14514839";
        QString etat="A l heure";

        query.prepare("UPDATE EMPLOYE SET ETAT= :etat WHERE CIN= :cin");
        query.bindValue(":cin",cin);

        query.bindValue(":etat",etat);

        bool test=query.exec();
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Employé à l'heure\n"),QMessageBox::Cancel);
            ui->table->setModel(E.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Erreur\n"),QMessageBox::Cancel);
        }


    }
    else if (val==1){
        //arduino



        QString dataSend=msg;
            A.write_to_arduino(dataSend.toStdString().c_str());
            A.write_to_arduino(("2")); //envoyer 2 à arduino
            A.write_to_arduino(dataSend.toStdString().c_str());

       //base
            QSqlQuery exist("SELECT SALAIRE_INIT FROM EMPLOYE WHERE CIN='14514839'");
            while (exist.next()) {//check that you have next result
                QString exp = exist.value(0).toString();
                int somme=exp.toInt();

           int sal=somme-(5*(nb_hr));
           QString salaire = QString::number(sal);
            QString cin="14514839";
            QString etat="En Retard";

            query.prepare("UPDATE EMPLOYE SET SALAIRE_INIT= :sal_init, ETAT= :etat WHERE CIN= :cin");
            query.bindValue(":cin",cin);
            query.bindValue(":sal_init",salaire);
            query.bindValue(":etat",etat);

            bool test=query.exec();
            if (test)
            {
                QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Employé en retard\n"),QMessageBox::Cancel);
                ui->table->setModel(E.afficher());
            }
            else
            {
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Erreur\n"),QMessageBox::Cancel);
            }


    }
}
}



void MainWindow::on_search_textChanged(const QString &rech)
{
   Employ E;
   QString recherche=ui->search->text();
   ui->tri->setModel(E.chercher_cnss(rech));

}
