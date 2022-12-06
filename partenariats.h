#ifndef PARTENARIATS_H
#define PARTENARIATS_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Partenariats
{

    int ID,BUDGET;
    QString SOCIETE,PRODUIT,CATEGORIE,MATRICULE;
    QDate DATE_P;
public:

    //Constructions//
    Partenariats ();
    Partenariats (QString,QString,QString,int,int,QString,QDate);

    //Getters

     QString getSOCIETE();
     QString getPRODUIT();
     QString getCATEGORIE();
     int getID();
     int getBUDGET();
     QString getMATRICULE();
     QDate getDATE_P();
    //Setters
    void set_SOCIETE(QString );
    void set_PRODUIT(QString );
    void set_CATEGORIE(QString);
    void setID(int);
    void setBUDGET(int);
    void set_MATRICULE(QString);
    void setDATE_P(QDate);
    //Foncctions
   bool ajouter();
  QSqlQueryModel* afficher();
   bool supprimer(int ID);
   bool modifier(int ID);
  QSqlQueryModel * afficher_Partenariats_tri_BUDGET();
  QSqlQueryModel * afficher_Partenariats_tri_SOCIETE();
  QSqlQueryModel * afficher_Partenariats_chercher(QString rech);

 QString  combo;
 QSqlQuery request(QString);
 int Calculer();
 bool ajouterhistorique(QString,QDateTime);
 QSqlQueryModel* afficherHistorieque();


};
#endif // PARTENARIATS_H
