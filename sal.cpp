#include "sal.h"
#include<QSqlQueryModel>
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
Salles::Salles()
{
    num=0;
    bloc=" ";
    etage=" ";

    }
    Salles::Salles(int num ,QString bloc,QString etage)
    {this->num=num;
        this->bloc=bloc;this->etage=etage;}
    int Salles::getnum (){return num;}
    QString Salles::getbloc(){return bloc;}
    QString Salles::getetage(){return etage;}
    void Salles::setnum(int num ){this->num=num;}
    void Salles::setbloc(QString bloc ){this->bloc=bloc;}
    void Salles::setetage(QString etage){this->etage=etage ;}

    bool Salles::ajouter()
    {

     QSqlQuery query;
     QString num_string=QString::number(num);
           query.prepare("INSERT INTO Salles (num, bloc, etage) "
                         "VALUES (:num, :bloc, :etage)");
           query.bindValue (":num", num_string);
           query.bindValue(":bloc", bloc);
           query.bindValue(":etage", etage);

     return query.exec();
    }
    bool Salles::modifier()
    {
     QSqlQuery query;
      QString num_string=QString::number(num);
             query.prepare ("UPDATE Salles ( num, bloc,etage)"
                             "VALUES (:num, :bloc, :etage)");
            query.bindValue(":num",num_string);
            query.bindValue(":nom",bloc);
            query.bindValue(":prenom",etage);
          return query.exec();
    }

              bool Salles::supprimer(int num)
              {
                  QSqlQuery query;
                  QString num_string=QString::number(num);
                        query.prepare("DELETE FROM Salles WHERE num=:num");
                        query.bindValue(":num", num);


                  return query.exec();
              }
    QSqlQueryModel* Salles::afficher()
    {
       QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT*   FROM Salles");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("bloc"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("etage"));
       return model ;
}
