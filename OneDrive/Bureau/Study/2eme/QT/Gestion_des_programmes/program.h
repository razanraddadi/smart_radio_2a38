#ifndef PROGRAM_H
#define PROGRAM_H
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSql>
#include <QVariant>
#include "historique.h"

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

#endif // PROGRAM_H
