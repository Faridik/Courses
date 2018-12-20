#include "sqldb.h"

sqldb::sqldb()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5433);
    db.setDatabaseName("KursBD");
    query = new QSqlQuery(db);
	this->connect();
}

bool sqldb::connect()
{
   db.setUserName("guest");
   db.setPassword("guest111");
   return db.open();
}

bool sqldb::exec(QString q)
{
	return query->exec(q);
}

sqldb::~sqldb()
{
    db.close();
}
