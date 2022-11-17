#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salles.h"
#include "smtp.h"
#include "camera.h"
#include"connection.h"
#include <QMessageBox>
#include <QTextEdit>
#include<QIntValidator>
#include <QTextDocument>
#include <QtDebug>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include<QPrinter>
#include <QMessageBox>
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QTextStream>
#include <QPdfWriter>
#include <QtQuick/QQuickItem>
#include "notification.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabsalles->setModel(S.afficher() );
    //for email tab
    connect(ui->sendBtb, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonajout_clicked()
{
    int num=ui ->lineEdit_num ->text().toInt();
    QString bloc=ui->lineEdit_bloc->text();
    QString etage=ui->lineEdit_etage->text();
    Salles S(num,bloc ,etage );
    notification n;
    bool test=S.ajouter();
    n.ajout_notification();
    QMessageBox msgbox;
    if (test)
       { msgbox.setText("ajout avec succes.");
        ui->tabsalles->setModel(S.afficher());
    }
    else
        msgbox.setText("echec de l'ajout");
    msgbox.exec();
}

void MainWindow::on_pushButtonsupprimer_clicked()
{ notification n;
Salles S1 ; S1.setnum(ui->lineEditnumsup->text().toUInt() );
bool test=S1.supprimer(S1.getnum());
n.notification_supprimer();
 QMessageBox msgbox;
 if (test)
  {   msgbox.setText("suppression avec succes.");
       ui->tabsalles->setModel(S.afficher());
 }

 else
     msgbox.setText("echec de suppression");
 msgbox.exec();
}

void MainWindow::on_pushButtonmodifier_clicked()
{
 notification n;
int num=ui->lineEditmodif->text().toUInt() ;
QString bloc=ui->lineEdit_blocmodif->text();
QString etage=ui->lineEdit_etagemodif->text();
Salles S2(num, bloc ,etage);
  bool test=S2.modifier();
n.notification_modifier();

    QMessageBox msgbox;
    if (test)
      {  msgbox.setText("modification avec succes.");
       ui->tabsalles->setModel(S2.afficher());
    }
    else
        msgbox.setText("echec de modification");
    msgbox.exec();
}


void MainWindow::on_pushButton_chercher_clicked()
{
    QString rech =ui->le_chercher->text();
bool test=S.afficher_chercher_salle(rech);
    /*if(ui->n_chercher->isChecked())
   {
    bool test=S.afficher_chercher_salle(rech);*/

   if(test)
   {

   ui->tab_sal->setModel(S.afficher_chercher_salle(rech));
   QMessageBox::information(nullptr,QObject::tr("Valider"),
                            QObject::tr("chercher s successful.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
      { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                QObject::tr("chercher s failed.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);}
}
    /*else
        if(ui->b_chercher->isChecked())
       {
        bool test=S.afficher_chercher_salle(rech);

       if(test)
       {

       ui->tab_sal->setModel(S.afficher_chercher_salle(rech));
}*/

void MainWindow::on_pushButton_tri_clicked()
{ui->tab_sal->setModel(S.afficher_tri());
   /* if(ui->tri_n->isChecked())
  {



      bool test=S.afficher_tri();

     if(test)
     {
         //refresh

         ui->tab_sal->setModel(S.afficher_tri());

     QMessageBox::information(nullptr,QObject::tr("Valider"),
                              QObject::tr("Tri n successful.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
     }
     else
        { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                  QObject::tr("Tri n failed.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);}
   } else if(ui->tri_b->isChecked())
    {



        bool test=S.afficher_tri();

       if(test)
       {
           //refresh

           ui->tab_sal->setModel(S.afficher_tri());

       QMessageBox::information(nullptr,QObject::tr("Valider"),
                                QObject::tr("Tri b successful.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
       }
       else
          { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                    QObject::tr("Tri b failed.\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);}
     }*/
}







void MainWindow::on_pdf_clicked()
{
    {

        QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tabsalles->model()->rowCount();
                    const int columnCount =ui->tabsalles->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("salles")
                            <<  "</head>\n"
                            "<body bgcolor=#FFFFFF link=#5000A0>\n"
                                "<h1>Liste des Programmes</h1>"

                                "<table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tabsalles->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tabsalles->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tabsalles->isColumnHidden(column)) {
                                       QString data = ui->tabsalles->model()->data(ui->tabsalles->model()->index(row, column)).toString().simplified();
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
                         printer.setOutputFileName("salles.pdf");
                         document->print(&printer);

}
}
//mailing
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("razan.raddadi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("razan.raddadi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("razan.raddadi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}




void MainWindow::on_sendBtb_clicked()
{
    {
        Smtp* smtp = new Smtp("razan.raddadi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        if( !files.isEmpty() )
            smtp->sendMail("razan.raddadi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
        else
            smtp->sendMail("razan.raddadi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
    }
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
void MainWindow::on_camera_2_clicked()
{
    camera camera ;
    camera.setModal(true);
    camera.exec();
}
