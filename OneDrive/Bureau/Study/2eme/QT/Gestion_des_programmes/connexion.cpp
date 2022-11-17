#include "connexion.h"

Connection::Connection(){}
bool Connection::createconnection()
{db= QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("0000");
    if(db.open()) test=true;
    return test;
}

