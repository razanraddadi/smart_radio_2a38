#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QMainWindow>
#include <QDateTime>
#include<QSqlQuery>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include<QtDebug>
#include<QObject>
#include <QMessageBox>

class history
{
public:
    history();
   history(int,int,QString,QString,QString);
   void setid_p(int n);
   void setid_s(int n);
   void setnom_p(QString n);
   void setacteur(QString n);
   void settyper(QString n);
void setviews(int n);
   int get_id_p();
    int get_id_s();
     int getviews();
   QString get_nom_p();
     QString get_acteur();
QString get_typer();
QDate get_date();
QSqlQueryModel* afficherh();

   bool supprimer(int );
   bool supprimertout( int );


private:
   int id_p,id_s,views;
    QString nom_p,acteur,typer;



};

#endif // HISTORIQUE_H
