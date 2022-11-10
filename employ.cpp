#include "employ.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>
Employ::Employ()
{
cin=0; cnss=0;
nom=" "; prenom=" "; poste=" ";
}
Employ::Employ(QString nom,QString prenom,int cin,int cnss ,QString poste)
{
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->cnss=cnss;
    this->poste=poste;
}
QString Employ::getnom(){return nom;}
QString Employ::getprenom(){return prenom;}
int Employ::getcin(){return cin;}
int Employ::getcnss(){return cnss;}
QString Employ::getposte(){return poste;}

void Employ::setnom(QString nom){this->nom=nom;}
void Employ::setprenom(QString prenom){this->prenom=prenom;}
void Employ::setcin(int cin){this->cin=cin;}
void Employ::setcnss(int cnss){this->cnss=cnss;}
void Employ::setposte(QString poste){this->poste=poste;}
bool Employ::ajouter()
{

    QString cin_string= QString::number(cin);
    QString cnss_string= QString::number(cnss);
    QSqlQuery query;

          query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, CIN, CNSS, POSTE) "
                        "VALUES (:nom, :prenom, :cin, :cnss, :poste );");
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":cin",cin_string);
          query.bindValue(":cnss", cnss_string);
          query.bindValue(":poste", poste);

          return query.exec();


}

bool Employ::supprimer(int cin)
{

    QSqlQuery query;

          query.prepare("DELETE FROM EMPLOYE where CIN=:cin");
          query.bindValue(":cin", cin);

          return query.exec();

}

QSqlQueryModel * Employ::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM EMPLOYE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PRENOM"));
           model->setHeaderData(2, Qt::Horizontal,  QObject::tr("CIN"));
            model->setHeaderData(3, Qt::Horizontal,  QObject::tr("CNSS"));
             model->setHeaderData(4, Qt::Horizontal,  QObject::tr("FONCTION"));

    return model;
}

bool Employ::update(Employ e)
{
    QString cin_string= QString::number(cin);
    QString cnss_string= QString::number(cnss);
    QSqlQuery  query;

query.prepare("UPDATE EMPLOYE SET NOM=:nom,PRENOM=:prenom,CNSS=:cnss,POSTE=:poste WHERE CIN=:cin");
query.bindValue(":cin",cin_string);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":cnss",cnss_string);
query.bindValue(":poste",poste);


return query.exec();
}
//tri
QSqlQueryModel* Employ::tri_cin()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM EMPLOYE ORDER BY CIN ASC");

    return model;
}

QSqlQueryModel* Employ::tri_nom()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM EMPLOYE ORDER BY NOM ");

    return model;
}

QSqlQueryModel* Employ::tri_prenom()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM EMPLOYE ORDER BY PRENOM");

    return model;
}

QSqlQueryModel* Employ::tri_cnss()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM EMPLOYE ORDER BY CNSS");

    return model;
}

QSqlQueryModel* Employ::chercher_cin(QString rech)
{
       QString sQuery="SELECT * FROM EMPLOYE WHERE CIN LIKE'%"+rech+"%'";

       QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.exec();
        model->setQuery(qry);
        return model;
}

QSqlQueryModel* Employ::chercher_nom(QString rech)
{
       QString sQuery="SELECT * FROM EMPLOYE WHERE NOM LIKE'%"+rech+"%'";

       QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.exec();
        model->setQuery(qry);
        return model;
}

QSqlQueryModel* Employ::chercher_prenom(QString rech)
{
       QString sQuery="SELECT * FROM EMPLOYE WHERE PRENOM LIKE'%"+rech+"%'";

       QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.exec();
        model->setQuery(qry);
        return model;
}

QSqlQueryModel* Employ::chercher_cnss(QString rech)
{
       QString sQuery="SELECT * FROM EMPLOYE WHERE CNSS LIKE'%"+rech+"%'";

       QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.exec();
        model->setQuery(qry);
        return model;
}

QSqlQueryModel* Employ::chercher_poste(QString rech)
{
       QString sQuery="SELECT * FROM EMPLOYE WHERE POSTE LIKE'%"+rech+"%'";

       QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.exec();
        model->setQuery(qry);
        return model;
}
