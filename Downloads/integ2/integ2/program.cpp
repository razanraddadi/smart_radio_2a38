#include "program.h"


Program::Program()
{
id_p=0; id_s=0; nom_p=""; acteur=""; jj=0;mm=0;yyyy=0;heure=0;min=0;
}

Program::Program(int id_p,int id_s,QString nom_p,QString acteur,int jj,int mm,int yyyy,int heure,int min,int views)
{this->id_p=id_p; this->id_s=id_s; this->nom_p=nom_p; this->acteur=acteur;this->jj=jj;this->mm=mm;this->yyyy=yyyy;this->heure=heure;this->min=min;this->views=views; }
int Program::getid_p(){return id_p;}
int Program::getid_s(){return id_s;}
int Program::getid_supp(){return id_p;}
QString Program::getnom_p(){return nom_p;}
QString Program::getacteur(){return acteur;}
int Program::getjj(){return jj;}
int Program::getmm(){return mm;}
int Program::getyyyy() {return yyyy;}
int Program::getheure(){return heure;}
int Program::getmin(){return min;}
int Program::getviews(){return views;}
void Program::setid_p(int id_p){this->id_p=id_p;}
void Program::setid_s(int id_s){this->id_s=id_s;}
void Program::setnom_p(QString nom_p){this->nom_p=nom_p;}
void Program::setacteur(QString acteur){this->acteur=acteur;}
void Program::setjj(int jj){this->jj=jj;}
void Program::setmm(int mm){this->mm=mm;}
void Program::setyyyy(int yyyy){this->yyyy=yyyy;}
void Program::setheure(int heure){this->heure=heure;}
void Program::setviews(int views){this->views=views;}
 bool Program::ajouter()
 {
    QSqlQuery query;
    QString id_string=QString ::number(id_p);
    QString id_string2=QString ::number(id_s);
    QString jjid_string=QString ::number(jj);
    QString mmid_string=QString ::number(mm);
    QString yyyyid_string=QString ::number(yyyy);
    QString heureid_string=QString ::number(heure);
    QString minid_string=QString ::number(min);
    QString jjmmyyyy=jjid_string+'/'+mmid_string+'/'+yyyyid_string;
    QString hhmin=heureid_string+':'+minid_string;
     QString viewsid_string=QString ::number(views);
          query.prepare("INSERT INTO PROGRAMMES  (id_p, id_s,nom_p,acteur,date_p,heure_p,views) "
                        "VALUES (:id_p , :id_s , :nom_p , :acteur, :date, :heure,:views)");
         query.bindValue(":id_p", id_string);
           query.bindValue(":id_s", id_string2);
          query.bindValue(":nom_p", nom_p);
          query.bindValue(":acteur", acteur);
          query.bindValue(":date", jjmmyyyy);
            query.bindValue(":heure", hhmin);
            query.bindValue(":views", views);
    return query.exec();
};
 bool Program::supprimer(int id_p)
 {
     QSqlQuery query;
     QString iden=QString::number(id_p);
     query.prepare("Delete from PROGRAMMES where id_p= :id_p");
     query.bindValue(":id_p",iden);
     return query.exec();
 }
 QSqlQueryModel * Program::afficher()
 {
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select * from PROGRAMMES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_p"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_s"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_p"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("acteur"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("heure"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("views"));
 return model;
 }
bool Program::modifier()
{
    QSqlQuery query,query2;
    QString id_string=QString ::number(id_p);
    QString id_string2=QString ::number(id_s);
    QString jjid_string=QString ::number(jj);
    QString mmid_string=QString ::number(mm);
    QString yyyyid_string=QString ::number(yyyy);
    QString heureid_string=QString ::number(heure);
    QString minid_string=QString ::number(min);
    QString jjmmyyyy=jjid_string+'/'+mmid_string+'/'+yyyyid_string;
    QString hhmin=heureid_string+':'+minid_string;
    QString viewsid_string=QString ::number(views);
          query.prepare( "UPDATE  PROGRAMMES  SET  id_p=:id_p ,id_s=:id_s , nom_p=:nom_p,acteur=:acteur,date_p=:date,heure_p=:heure ,views=:views"
                        " WHERE id_p= :id_p");
         query2.prepare( " INSERT INTO HYSTORY (id_p ,id_s,nom_p,acteur,,date_p,heure_p,views,typer)   "
                                      " VALUES (:id_p ,:id_s,:nom_p,:acteur,:date,:heure,:views,'modification')" );
         query2.bindValue(":id_p", id_string);
          query2.bindValue(":id_s", id_string2);
            query2.bindValue(":nom_p", nom_p);
            query2.bindValue(":acteur", acteur);
            query2.bindValue(":date", jjmmyyyy);
              query2.bindValue(":heure", hhmin);
              query2.bindValue(":views", views);
            query.bindValue(":id_p", id_string);
              query.bindValue(":id_s", id_string2);
             query.bindValue(":nom_p", nom_p);
             query.bindValue(":acteur", acteur);
             query.bindValue(":date", jjmmyyyy);
               query.bindValue(":heure", hhmin);
               query.bindValue(":views", views);
               query.exec();
               query2.exec();
          return query.exec();
}

QSqlQueryModel * Program::afficher_recherche(QString rech)
{
    QSqlQuery query,query2;
    QString squery="SELECT * from PROGRAMMES WHERE nom_p  LIKE'%"+rech+"' OR acteur LIKE'%"+rech+"%' OR id_p LIKE'%"+rech+"%' OR date_p LIKE'%"+rech+"%' OR heure_p LIKE'%"+rech+"%' OR id_s LIKE'%"+rech+"%' OR Views LIKE'%"+rech+"%' ";
   QString squery2=" INSERT INTO HYSTORY SELECT id_p ,id_s,nom_p,acteur,date_p,heure_p,views,'recherche' from PROGRAMMES WHERE nom_p  LIKE'%"+rech+"%' OR acteur LIKE'%"+rech+"%' OR id_p LIKE'%"+rech+"%' OR date_p LIKE'%"+rech+"%' OR heure_p LIKE'%"+rech+"%' OR id_s LIKE'%"+rech+"%' OR Views LIKE'%"+rech+"%' ";
   QSqlQueryModel*model=new QSqlQueryModel();
  query.prepare(squery);
  query.exec();
  query2.prepare(squery2);
  query2.exec();
  model->setQuery(query);
  return model;
}
QSqlQueryModel * Program::afficher_tri()
{
    QSqlQuery query;
  QString squery="SELECT * from PROGRAMMES ORDER BY ID_P";
  QSqlQueryModel*model=new QSqlQueryModel();
  query.prepare(squery);
  query.exec();
  model->setQuery(query);
  return model;
}
int Program::calculer1(int x,int x2)
{
    QSqlQuery query;
          query.prepare("SELECT * FROM PROGRAMMES WHERE views between (:x) and (:x2)  ");
          query.bindValue(":x",x);
          query.bindValue(":x2",x2);

          query.exec();
          int total = 0;
          while (query.next()) {
            total++;
 }

          return total;
}

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
bool history ::supprimertout( int id_p)
    {
    QSqlQuery query;
    QString iden=QString::number(id_p);
        query.prepare("DELETE FROM HYSTORY  ");
        query.bindValue(0,iden);
        return query.exec();
    }
