#include "partenariats.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QTextEdit>
#include <QObject>
#include"mainwindow.h"
#include <QDate>
Partenariats::Partenariats()
{

/*ID=0;
SOCIETE="";
PRODUIT="";
BUDGET=0;
CATEGORIE="";
MATRICULE="";
DATE_P="";*/
}
Partenariats::Partenariats(QString SOCIETE,QString PRODUIT,QString CATEGORIE,int ID,int BUDGET,QString MATRICULE,QDate date)
{
this->ID=ID; this->BUDGET=BUDGET; this->SOCIETE=SOCIETE; this->CATEGORIE=CATEGORIE; this->PRODUIT=PRODUIT;this->MATRICULE=MATRICULE;this->DATE_P=date;}//besh ibadel les variables ejdod ihtohom fi blaset lokdom
int Partenariats::getID(){return ID;}//afficher
int Partenariats::getBUDGET(){return BUDGET;}
QString Partenariats::getSOCIETE(){return SOCIETE;}
QString Partenariats::getPRODUIT(){return PRODUIT;}
QString Partenariats::getCATEGORIE(){return CATEGORIE;}
QString Partenariats::getMATRICULE(){return MATRICULE;}
QDate Partenariats::getDATE_P(){return DATE_P;}
void Partenariats::setID(int ID){this->ID=ID;}//scnaf dakhel
void Partenariats::setBUDGET(int BUDGET){this->BUDGET= BUDGET;}
void Partenariats::set_SOCIETE(QString SOCIETE ){this->SOCIETE=SOCIETE;}
void Partenariats::set_PRODUIT(QString PRODUIT ){this->PRODUIT=PRODUIT;}
void Partenariats::set_CATEGORIE(QString CATEGORIE){this->CATEGORIE=CATEGORIE;}
void Partenariats::set_MATRICULE(QString MATRICULE ){this->MATRICULE=MATRICULE;}
void Partenariats::setDATE_P(QDate date ){this->DATE_P=date;}

bool Partenariats::ajouter()
{

     QSqlQuery query;//demande pour acceder el BD
     QString ID_String= QString::number(ID);
     QString BUDGET_String= QString::number(BUDGET);

              query.prepare("INSERT INTO PARTENARIATS (SOCIETE,PRODUIT,CATEGORIE,ID,BUDGET,MATRICULE,DATE_P) "
                            "VALUES (:SOCIETE,:PRODUIT,:CATEGORIE,:ID,:BUDGET,:MATRICULE,:DATE_P)");//preparer ma requete besh ndekhel les variables fel BD
              query.bindValue(":SOCIETE",SOCIETE);//faire correspendance mabin la valeur ajouter w lekdima w securite
              query.bindValue(":PRODUIT",PRODUIT);
              query.bindValue(":CATEGORIE",CATEGORIE);
              query.bindValue(":ID",ID_String);
              query.bindValue(":BUDGET",BUDGET_String);
              query.bindValue(":MATRICULE",MATRICULE);
               query.bindValue(":DATE_P",DATE_P);
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
  model->setHeaderData(5, Qt::Horizontal,QObject::tr("MATRICULE"));
   model->setHeaderData(6, Qt::Horizontal,QObject::tr("DATE_P"));
 return  model;
}


bool Partenariats::modifier(int ID)
{
    QSqlQuery query;

       QString ID_String= QString::number(ID);

       query.prepare ("UPDATE PARTENARIATS set  SOCIETE=:SOCIETE,PRODUIT=:PRODUIT,CATEGORIE=:CATEGORIE,BUDGET=:BUDGET,MATRICULE=:MATRICULE,DATE_P=:DATE_P where ID=:ID" );
       query.bindValue(":ID", ID);
       query.bindValue(":SOCIETE", SOCIETE);
       query.bindValue(":PRODUIT", PRODUIT);
       query.bindValue(":CATEGORIE", CATEGORIE);
       query.bindValue(":BUDGET",BUDGET);
       query.bindValue(":MATRICULE",MATRICULE);
       query.bindValue(":DATE_P",DATE_P);

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
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("MATRICULE"));
     model->setHeaderData(6, Qt::Horizontal,QObject::tr("DATE_P"));
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
      model->setHeaderData(5, Qt::Horizontal,QObject::tr("MATRICULE"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("DATE_P"));
  return model;
 }


QSqlQueryModel* Partenariats::afficher_Partenariats_chercher(QString rech)
{
       QString sQuery="SELECT SOCIETE,PRODUIT,CATEGORIE,ID,BUDGET,MATRICULE FROM PARTENARIATS WHERE SOCIETE LIKE'%"+rech+"%' or PRODUIT LIKE'%"+rech+"%' or CATEGORIE LIKE'%"+rech+"%' or ID LIKE'%"+rech+"%' or BUDGET LIKE'%"+rech+"%' or MATRICULE LIKE'%"+rech+"%'  or DATE_P LIKE'%"+rech+"%'";

       QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.exec();
        model->setQuery(qry);
        return model;
}


int Partenariats::Calculer()
{
    QSqlQuery query;
     query.prepare("select BUDGET from PARTENARIATS");

     query.exec();
      int total=0;

     while(query.next()){
       total=total+query.value(0).toInt();

     }

     return total;
}


QSqlQuery Partenariats::request(QString date)
{
    QSqlQuery query;
    query.prepare("select * from PARTENATIATS where DATE_P= date('"+date+"','YYYY-MM-DD')");
    query.addBindValue(date);
    query.exec();
    return query;
}

//HISTORIQUE

bool Partenariats::ajouterhistorique(QString numcard, QDateTime datetmp)
{

     QSqlQuery query;

              query.prepare("INSERT INTO HISTRORIQUE (NUMCARD,DATEAJOUT) "
                            "VALUES (:numcard,:dateaj)");   //preparer ma requete besh ndekhel les variables fel BD
              query.bindValue(":numcard",numcard);//faire correspendance mabin la valeur ajouter w lekdima w securite
              query.bindValue(":dateaj",datetmp);
              return  query.exec();//execution
}


QSqlQueryModel * Partenariats::afficherHistorieque()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from HISTRORIQUE  ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero CARD"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Date"));
    return model;
}
