#ifndef SAL_H
#define SAL_H

#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>

class Salles
{
public:
    Salles();
    Salles (int ,QString,QString);
    int getnum ();
    QString getbloc();
    QString getetage();
    void setnum(int );
    void setbloc(QString);
    void setetage(QString);
    bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int );
   bool modifier ();
private :
    int num ;
    QString etage , bloc;

};



#endif // SAL_H
