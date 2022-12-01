#ifndef INVITE_H
#define INVITE_H
#include <QString>
#include <QSqlQueryModel>

class invite
{
public:
    invite();
    invite(int,QString,QString,QString,QString,int,int,QString);
        int getcin();
        QString getnom();
        QString getprenom();
        QString getmetier();
        QString getaccess();
        int getage();
        int getpassword();
        QString getcard();
        void setcin(int);
        void setnom(QString);
        void setprenom(QString);
        void setmetier(QString);
        void setaccess(QString);
        void setage(int);
        void setpassword(int);
        void setcard(QString);



        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        QSqlQueryModel*chercher_invite(QString rech);
        bool modifier();
        QSqlQueryModel*afficher_tri();
        int calculer1(int choix,int choix2);
        QString serial;
private:

        int cin, age,password;
    QString nom , prenom, metier,access,card;

};

#endif // INVITE_H
