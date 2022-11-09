#include "partenariats.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QTextEdit>
#include <QObject>
#include"mainwindow.h"
Partenariats::Partenariats()
{
ID=0;
SOCIETE="";
PRODUIT="";
BUDGET=0;
CATEGORIE="";
}
Partenariats::Partenariats(QString SOCIETE,QString PRODUIT,QString CATEGORIE,int ID,int BUDGET)
{
this->ID=ID; this->BUDGET=BUDGET; this->SOCIETE=SOCIETE; this->CATEGORIE=CATEGORIE; this->PRODUIT=PRODUIT;}//besh ibadel les variables ejdod ihtohom fi blaset lokdom
int Partenariats::getID(){return ID;}//afficher
int Partenariats::getBUDGET(){return BUDGET;}
QString Partenariats::getSOCIETE(){return SOCIETE;}
QString Partenariats::getPRODUIT(){return PRODUIT;}
QString Partenariats::getCATEGORIE(){return CATEGORIE;}
void Partenariats::setID(int ID){this->ID=ID;}//scnaf dakhel
void Partenariats::setBUDGET(int BUDGET){this->BUDGET= BUDGET;}
void Partenariats::set_SOCIETE(QString SOCIETE ){this->SOCIETE=SOCIETE;}
void Partenariats::set_PRODUIT(QString PRODUIT ){this->PRODUIT=PRODUIT;}
void Partenariats::set_CATEGORIE(QString CATEGORIE){this->CATEGORIE=CATEGORIE;}


bool Partenariats::ajouter()
{

     QSqlQuery query;//demande pour acceder el BD
     QString ID_String= QString::number(ID);
     QString BUDGET_String= QString::number(BUDGET);


              query.prepare("INSERT INTO PARTENARIATS (SOCIETE,PRODUIT,CATEGORIE,ID,BUDGET) "
                            "VALUES (:SOCIETE,:PRODUIT,:CATEGORIE,:ID,:BUDGET)");//preparer ma requete besh ndekhel les variables fel BD
              query.bindValue(":SOCIETE",SOCIETE);//faire correspendance mabin la valeur ajouter w lekdima w securite
              query.bindValue(":PRODUIT",PRODUIT);
              query.bindValue(":CATEGORIE",CATEGORIE);
              query.bindValue(":ID",ID_String);
              query.bindValue(":BUDGET",BUDGET_String);

              return  query.exec();//execution
}

bool Partenariats::supprimer(int ID)
{
    QSqlQuery query;
    QString ID_String= QString::number(ID);
    query.prepare("Delete from PARTENARIATS where ID=:ID");
    query.bindValue(":ID",ID_String);
    return query.exec();
}


QSqlQueryModel * Partenariats::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();//affichage
 model->setQuery("select * from PARTENARIATS");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("SOCIETE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("CATEGORIE"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("BUDGET"));
 return  model;
}


bool Partenariats::modifier(int ID)
{
    QSqlQuery query;

       QString ID_String= QString::number(ID);

       query.prepare ("UPDATE PARTENARIATS set  SOCIETE=:SOCIETE,PRODUIT=:PRODUIT,CATEGORIE=:CATEGORIE,BUDGET=:BUDGET where ID=:ID" );
       query.bindValue(":ID", ID);
       query.bindValue(":SOCIETE", SOCIETE);
       query.bindValue(":PRODUIT", PRODUIT);
       query.bindValue(":CATEGORIE", CATEGORIE);
        query.bindValue(":BUDGET",BUDGET);

          return    query.exec();
}

// tri par budget :

 QSqlQueryModel * Partenariats::afficher_Partenariats_tri_BUDGET()
{
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from PARTENARIATS order by BUDGET desc ");


     model->setHeaderData(0, Qt::Horizontal,QObject::tr("SOCIETE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("CATEGORIE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("BUDGET"));

 return model;
}

 // tri par societe :

  QSqlQueryModel * Partenariats::afficher_Partenariats_tri_SOCIETE()
 {
      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("select * from PARTENARIATS order by SOCIETE ");


      model->setHeaderData(0, Qt::Horizontal,QObject::tr("SOCIETE"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("CATEGORIE"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(4, Qt::Horizontal,QObject::tr("BUDGET"));

  return model;
 }


QSqlQueryModel* Partenariats::afficher_Partenariats_chercher(QString rech)
{
       QString sQuery="SELECT SOCIETE,PRODUIT,CATEGORIE,ID,BUDGET FROM PARTENARIATS WHERE SOCIETE LIKE'%"+rech+"%' or PRODUIT LIKE'%"+rech+"%' or CATEGORIE LIKE'%"+rech+"%' or ID LIKE'%"+rech+"%' or BUDGET LIKE'%"+rech+"%'";

       QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.exec();
        model->setQuery(qry);
        return model;
}
