#include "historique.h"

history::history()
{
         id_p=0;
        id_s=0;
        nom_p="xx";
         acteur ="xx";

}


history::history(int id_p,int id_s,QString nom_p,QString acteur,QString typer)
{this->id_p=id_p;
this-> id_s=id_s;
 this-> acteur= acteur;
     this-> nom_p= nom_p;
     this-> typer= typer;


}

void history::setid_p(int n)
{ id_p = n;}
void history::setid_s(int n)
{ id_s = n;}
void history::setnom_p(QString n)
{ nom_p= n;}
void history::setacteur(QString n)
{ acteur= n;}
void history::settyper(QString n)
{ typer= n;}
int history ::get_id_p()
{return id_p;}




QSqlQueryModel* history::afficherh()
   {
     QSqlQueryModel* model=new QSqlQueryModel();
      model->setQuery("SELECT* FROM HYSTORY");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_P"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_S"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_P"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ACTEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Views"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPER"));

return  model;
 }

bool history ::supprimer( int id_p)
    {
    QSqlQuery query;
    QString iden=QString::number(id_p);
        query.prepare("DELETE FROM HYSTORY WHERE id_p=:id_p ");
        query.bindValue(0,iden);
        return query.exec();
    }
