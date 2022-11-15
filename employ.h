#ifndef EMPLOY_H
#define EMPLOY_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <string>
#include <iostream>

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

    std::string encryptStr(std::string str,int k);
    std::string decryptStr(std::string str,int k);

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool update(Employ);

    bool cryptage(Employ,int  );
    bool decryptage(Employ , QString );

    QSqlQueryModel* tri_cin();
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* tri_prenom();
    QSqlQueryModel* tri_cnss();
    QSqlQueryModel* chercher_cin(QString rech);
    QSqlQueryModel* chercher_nom(QString rech);
    QSqlQueryModel* chercher_prenom(QString rech);
    QSqlQueryModel* chercher_cnss(QString rech);
    QSqlQueryModel* chercher_poste(QString rech);
  //  void reverseStr(QString& str);





};

#endif // EMPLOY_H
