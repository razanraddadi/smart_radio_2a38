#include "dialog.h"
#include "ui_dialog.h"
#include "invite.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTextDocument>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QDesktopServices>
#include <QHeaderView>
#include "QImage"
#include <QPainter>
#include "iostream"
#include <QSqlQuery>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include "connection.h"
#include <QtWidgets/QApplication>
#include <QtCore/QTime>
#include <QTextEdit>
#include <QIntValidator>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QRadioButton>
#include <QPixmap>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include<QDir>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include<QDirModel>
#include <QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QDesktopServices>
#include <QHeaderView>
#include "QImage"
#include <QPainter>
#include "iostream"
#include "qrcode.h"
#include "qrcodegenerateworker.h"
#include <QFileDialog>
#include <QDialog>
#include "stat.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tab_invitee->setModel(I.afficher());
    }

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
       QString nom=ui->le_nom->text();
       QString prenom=ui->le_prenom->text();
       QString metier=ui->le_metier->text();
       QString access;
       int age=ui->le_age->text().toInt();
       int password=ui->le_password->text().toInt();
       QString card=ui->le_card->text();
     invite I(cin,nom,prenom,metier,access,age,password,card);
     bool test=I.ajouter();
     QMessageBox msgBox;
     if(test){
                 QMessageBox::information(nullptr, QObject::tr("ok"),
                             QObject::tr("ajout effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }
             else
                 QMessageBox::critical(nullptr, QObject::tr("not ok"),
                             QObject::tr("ajout non effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pb_supprimer_clicked()
{
    invite I1; I1.setcin(ui->le_cin_supp->text().toInt());
        bool test=I1.supprimer(I1.getcin());
        QMessageBox msgBox;
        if (test)
          {  msgBox.setText("Suppression avec succes.");
        ui->tab_invitee->setModel(I.afficher());

        }
        else
            msgBox.setText("Echec de suppression.");
        msgBox.exec();
}

void Dialog::on_pb_recherche_clicked()
{
    invite I3;
    QString rech =ui->le_r->text();
     ui->tableView->setModel(I3.chercher_invite(rech));
}

void Dialog::on_pb_update_clicked()
{
    int cin=ui->le_cin_modf->text().toInt();
       QString nom=ui->le_nom_modf->text();
       QString prenom=ui->le_prenom_modf->text();
       QString metier=ui->le_metier_modf->text();
       QString access;
       int age=ui->le_age_modf->text().toInt();
       int password=ui->le_password_modf->text().toInt();
       QString card=ui->le_card_modf->text();

       invite I2(cin,nom,prenom,metier,access,age,password,card);
   //    I2.setcin(ui->le_cin_modf->text().toInt());
       bool test=I2.modifier();
        // I2.getcin();

       QMessageBox msgBox;
       if(test){
            ui->tab_invitee->setModel(I.afficher());


                   QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("update effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                   ui->le_cin->clear();
                                         ui->le_nom_modf->clear();
                                         ui->le_prenom_modf->clear();
                                         ui->le_metier_modf->clear();
                                         ui->le_age_modf->clear();
                                         ui->le_password_modf->clear();
                                         ui->le_card_modf->clear();


               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("update non effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_pdf_clicked()
{
    QPdfWriter fichier_pdf("C:\\slayem\\invitee.pdf");


                           QPainter painter(&fichier_pdf);
                           int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Time New Roman", 25));
                                  painter.drawText(3000,1400,"Liste Des Invités");
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("Time New Roman", 15));
                                  painter.drawRect(100,100,9400,2500);
                                  painter.drawRect(100,3000,9400,500);
                                  painter.setFont(QFont("Time New Roman", 9));
                                  painter.drawText(400,3300,"CIN");
                                  painter.drawText(1350,3300,"NOM");
                                  painter.drawText(2200,3300,"PRENOM");
                                  painter.drawText(3400,3300,"METIER");
                                  painter.drawText(4500,3300,"AGE");
                                  painter.drawText(5500,3300,"PASSWORD");


                                  QSqlQuery query;
                                  query.prepare("select * from inviter");
                                  query.exec();
                                  while (query.next())
                                                            {
                                                                painter.drawText(400,i,query.value(0).toString());
                                                                painter.drawText(1350,i,query.value(1).toString());
                                                                painter.drawText(2300,i,query.value(2).toString());
                                                                painter.drawText(3400,i,query.value(3).toString());
                                                                painter.drawText(4500,i,query.value(4).toString());
                                                                painter.drawText(5500,i,query.value(5).toString());



                                                               i = i + 350;
                                                            }
                                  QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                                            QObject::tr("PDF Enregistré.\n" "Click Cancel to exit."), QMessageBox::Cancel);



}

void Dialog::on_pushButton_2_clicked()
{

    ui->tableView_2->setModel(I.afficher_tri());
}

void Dialog::on_pushButton_3_clicked()
{
    if(ui->tab_invitee->currentIndex().row()==-1)

                                          QMessageBox::information(nullptr, QObject::tr("Suppression"),

                                                                   QObject::tr("Veuillez Choisir une CIN du Tableau.\n"

                                                                               "Click Ok to exit."), QMessageBox::Ok);

                                      else

                                      {

                                           int CIN=ui->tab_invitee->model()->data(ui->tab_invitee->model()->index(ui->tab_invitee->currentIndex().row(),0)).toInt();

                                           const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(CIN).c_str(), qrcodegen::QrCode::Ecc::LOW);


                                           std::ofstream myfile;

                                           myfile.open ("qrcode.svg") ;

                                              myfile << qr.toSvgString(2);

                                              myfile.close();

                                              QSvgRenderer svgRenderer(QString("qrcode.svg"));

                                              QPixmap pix( QSize(90, 90));

                                              QPainter pixPainter( &pix );

                                              svgRenderer.render(&pixPainter);

                                           ui->label_11->setPixmap(pix);

                                      }
}

void Dialog::on_pushButton_4_clicked()
{
    int res;
                      statistiques w(this);
                      w.setWindowTitle("Statistiques Des Invités");

                      res = w.exec();
                      qDebug() << res;
                      if (res == QDialog::Rejected)
                        return;
}

void Dialog::on_pushButton_refresh_clicked()
{
    int cin=ui->le_cin_modf->text().toInt();
       QString nom=ui->le_nom_modf->text();
       QString prenom=ui->le_prenom_modf->text();
       QString metier=ui->le_metier_modf->text();
       QString access;
       int age=ui->le_age_modf->text().toInt();
       int password=ui->le_password_modf->text().toInt();
       QString card=ui->le_card_modf->text();

       invite I2(cin,nom,prenom,metier,access,age,password,card);
   //    I2.setcin(ui->le_cin_modf->text().toInt());
       bool test=I2.modifier();
        // I2.getcin();

       QMessageBox msgBox;
       if(test){
            ui->tab_invitee->setModel(I.afficher());


                   QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("Refresh effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                   ui->le_cin->clear();
                                         ui->le_nom_modf->clear();
                                         ui->le_prenom_modf->clear();
                                         ui->le_metier_modf->clear();
                                         ui->le_age_modf->clear();
                                         ui->le_password_modf->clear();
                                         ui->le_card_modf->clear();


               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("Refresh non effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

