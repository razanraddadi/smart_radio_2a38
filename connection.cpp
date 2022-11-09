#include "connection.h"

connection::connection(){}

    bool connection::createconnect()
    {
    /*QSqlDatabase*/ db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Smart Radio");
    db.setUserName("Nour");//inserer nom de l'utilisateur
    db.setPassword("esprit38");//inserer mot de passe de cet utilisateur

    if (db.open()) test =true;
    test=true;
        return  test;
    }
    QSqlDatabase connection::getdb()
    {
        return db;
    }
    void connection::closeconnection() {db.close();}

