#ifndef EMPLOY_H
#define EMPLOY_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Employ
{
    QString nom, prenom, poste;
    int cin,cnss;
public:
    Employ();
    Employ(QString,QString,int,int,QString);
    QString getnom();
    QString getprenom();
    int getcin();
    int getcnss();
    QString getposte();

    void setnom(QString);
    void setprenom(QString);
    void setcin(int);
    void setcnss(int);
    void setposte(QString);

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool update(Employ);
    QSqlQueryModel* tri_cin();




};

#endif // EMPLOY_H
