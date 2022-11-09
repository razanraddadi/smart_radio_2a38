#ifndef PARTENARIATS_H
#define PARTENARIATS_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Partenariats
{

    int ID;
    int BUDGET;
    QString SOCIETE,PRODUIT,CATEGORIE;
public:

    //Constructions//
    Partenariats ();
    Partenariats (QString,QString,QString,int,int);

    //Getters

    QString getSOCIETE();
    QString getPRODUIT();
    QString getCATEGORIE();
    int getID();
    int getBUDGET();

    //Setters
    void set_SOCIETE(QString );
    void set_PRODUIT(QString );
    void set_CATEGORIE(QString);
    void setID(int);
    void setBUDGET(int);

    //Foncctions
   bool ajouter();
  QSqlQueryModel* afficher();
   bool supprimer(int ID);
   bool modifier(int ID);
  QSqlQueryModel * afficher_Partenariats_tri_BUDGET();
  QSqlQueryModel * afficher_Partenariats_tri_SOCIETE();
  QSqlQueryModel * afficher_Partenariats_chercher(QString rech);
};

#endif // PARTENARIATS_H
