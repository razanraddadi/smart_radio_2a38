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
