#ifndef PROGRAM_H
#define PROGRAM_H
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSql>
#include <QVariant>
#include <QMainWindow>
#include <QDateTime>
#include<QSqlQuery>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include<QtDebug>
#include<QObject>
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
#include <QTimer>
#include <QDateTime>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QTime>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>

class Program
{
public:
    Program();
    Program(int,int,QString,QString,int,int,int,int,int,int);
    int getid_p();
    int getid_s();
    int getid_supp();
    QString getnom_p();
    QString getacteur();
    int getjj();
    int getmm();
    int getyyyy();
    int getheure();
    int getmin();
    int getviews();
    void setid_p(int);
    void setid_s(int);
    void setid_supp(int);
    void setnom_p(QString);
    void setacteur(QString);
    void setjj(int);
    void setmm(int);
    void setyyyy(int);
    void setheure(int);
    void setviews(int );
    void setmin(int);
    bool ajouter();
    bool supprimer(int);
    bool modifier();

    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_recherche(QString);
    QSqlQueryModel * afficher_tri();
    int calculer1(int choix,int choix2);



private:
int id_p,id_s,jj,mm,yyyy,heure,min,views;
    QString nom_p , acteur;

};
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

#endif // PROGRAM_H
