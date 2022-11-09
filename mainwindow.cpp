#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salles.h"
#include"connection.h"
#include <QMessageBox>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabsalles->setModel(S.afficher() );
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
    bool test=S.ajouter();
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
{
Salles S1 ; S1.setnum(ui->lineEditnumsup->text().toUInt() );
bool test=S1.supprimer(S1.getnum());
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
    Salles S;
S.setnum(ui->lineEditmodif->text().toUInt() );
QString bloc=ui->lineEdit_blocmodif->text();
QString etage=ui->lineEdit_etagemodif->text();
  bool test=S.modifier();S.getnum();
    QMessageBox msgbox;
    if (test)
        msgbox.setText("modification avec succes.");
    else
        msgbox.setText("echec de modification");
    msgbox.exec();
}

