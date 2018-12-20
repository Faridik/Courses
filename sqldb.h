
#ifndef SQLDB_H
#define SQLDB_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class sqldb
{
    QSqlDatabase db;
    QSqlQuery *query;

   

public:
    sqldb();
	bool connect();
	bool connectFromUser();
	void disconnect();
	bool exec(QString q);
    ~sqldb();
};

#endif // SQLDB_H
