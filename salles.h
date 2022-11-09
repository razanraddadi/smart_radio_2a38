#ifndef SALLES_H
#define SALLES_H
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


#endif // SALLES_H
