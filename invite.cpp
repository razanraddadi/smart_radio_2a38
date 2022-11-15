#include "invite.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
invite::invite()
{

    cin=0; nom=""; prenom="" ; metier="";age=0;


}

invite::invite(int cin,QString nom,QString prenom,QString metier,int age)
{this->cin=cin; this->nom=nom; this->prenom=prenom;this->metier=metier;this->age=age;}
int invite::getcin(){return cin;}
QString invite::getnom(){return nom;}
QString invite::getprenom(){return prenom;}
QString invite::getmetier(){return metier;}
int invite::getage(){return age;}
void invite::setcin(int cin){this->cin=cin;}
void invite::setnom(QString nom){this->nom=nom;}
void invite::setprenom(QString prenom){this->prenom=prenom;}
void invite::setmetier(QString metier){this->metier=metier;}
void invite::setage(int age){this->age=age;}
bool invite::ajouter()
{

        QString cin_string= QString::number(cin);
         QString age_string= QString::number(age);
        QSqlQuery query;
              query.prepare("INSERT INTO INVITER (CIN, NOM,PRENOM,METIER,AGE) "
                            "VALUES (:cin, :nom, :prenom, :metier, :age)");
              query.bindValue(":cin",cin_string);
              query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
               query.bindValue(":metier", metier);
               query.bindValue(":age",age_string);
              return query.exec();




        }
bool invite::supprimer(int cin)
{
    QSqlQuery query;
          query.prepare("delete from inviter where cin=:cin");
          query.bindValue(0,cin);

          return query.exec();




}







QSqlQueryModel* invite::afficher()
{
        QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM inviter ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("METIER"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));






  return model;
}
QSqlQueryModel* invite::chercher_invite(QString rech){
    QString sQuery="SELECT cin,nom,prenom,metier, age FROM inviter WHERE nom LIKE'%"+rech+"%' or prenom LIKE'%"+rech+"%'or metier LIKE'%"+rech+"%'or age LIKE'%"+rech+"%' ";

    QSqlQueryModel*model4=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare(sQuery);

    qry.exec();
    model4->setQuery(qry);
    return model4;
}

bool invite::modifier()
{
     QSqlQuery query;
     QString cin_string= QString::number(cin);
 QString age_string= QString::number(age);
     query.prepare("UPDATE inviter SET nom=:nom , prenom=:prenom , metier=:metier, age=:age "
                   " where cin= :cin");
     query.bindValue(":cin",cin_string);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":metier",metier);
      query.bindValue(":age",age_string);


     return query.exec();

}

QSqlQueryModel * invite::afficher_tri()
{
    QSqlQuery query;
  QString squery="SELECT cin ,nom,prenom,metier,age from inviter ORDER BY cin";
  QSqlQueryModel*model=new QSqlQueryModel();
  query.prepare(squery);
  query.exec();
  model->setQuery(query);
  return model;
}
int invite::calculer1(int choix,int choix2)
{
    QSqlQuery query;
          query.prepare("SELECT * FROM inviter WHERE age BETWEEN (:choix) AND (:choix2)");
          query.bindValue(":choix",choix);
          query.bindValue(":choix2",choix2);

          query.exec();
          int total = 0;
          while (query.next()) {
            total++;
 }

          return total;
}
