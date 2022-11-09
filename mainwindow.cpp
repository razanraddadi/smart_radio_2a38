#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenariats.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_Partenariats->setModel(p.afficher());
     ui->le_ID->setValidator(new QIntValidator(0,9999999,this));
     //ui->tab_Partenariats->setModel(etmp.afficher_Partenariats_tri_BUDGET());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bouton_ajouter_clicked()
{


    QString SOCIETE=ui->le_SOCIETE->text();
    QString PRODUIT=ui->le_PRODUIT->text();
    QString CATEGORIE=ui->LE_CATEGORIE->text();
    int ID=ui->le_ID->text().toInt();
    int BUDGET=ui->le_BUDGET->text().toInt();
    Partenariats p(SOCIETE,PRODUIT,CATEGORIE,ID,BUDGET);
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

            Partenariats p(SOCIETE,PRODUIT,CATEGORIE,ID,BUDGET);
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
}
