#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    QSqlDatabase getdb();
    bool createconnect();
    void closeConnection();

};

// aj
#endif // CONNECTION_H
