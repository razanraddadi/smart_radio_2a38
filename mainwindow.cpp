#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtWidgets>
#include "employ.h"

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

    Employ E(nom,prenom,cin,cnss,poste);

    bool test= E.ajouter();

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

    Employ E2(nom,prenom,cin,cnss,poste);

    bool test= E2.update(E2);

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

void MainWindow::on_chercher_clicked()
{
    QString rech =ui->search->text();

     if(ui->rech_1->isChecked())
    {
     bool test=E.chercher_cin(rech);

    if(test)
    {

    ui->tri->setModel(E.chercher_cin(rech));

    }

    }
     else
         if(ui->rech_2->isChecked())
        {
         bool test=E.chercher_prenom(rech);

        if(test)
        {

        ui->tri->setModel(E.chercher_prenom(rech));

        }

        }
     else
             if(ui->rech_3->isChecked())
            {
             bool test=E.chercher_nom(rech);

            if(test)
            {

            ui->tri->setModel(E.chercher_nom(rech));

            }

            }
     else
                 if(ui->rech_4->isChecked())
                {
                 bool test=E.chercher_cnss(rech);

                if(test)
                {

                ui->tri->setModel(E.chercher_cnss(rech));

                }

                }
     else
                     if(ui->rech_5->isChecked())
                    {
                     bool test=E.chercher_poste(rech);

                    if(test)
                    {

                    ui->tri->setModel(E.chercher_poste(rech));

                    }

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
