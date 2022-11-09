#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
class connection
{

    QSqlDatabase db;
public:
    connection();
    QSqlDatabase getdb();
    bool createconnect();
   void closeconnection();
};

#endif // CONNECTION_H
